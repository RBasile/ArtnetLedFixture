var gateway =  `ws://${window.location.hostname}:81/`; //`ws://192.168.0.3:81/ws`;//
var websocket;
var websocketSync = [];   
var colorPicker =new KellyColorPicker({place : 'picker', input : 'color', size : 400 });
var wsClientNum;

var pulse = document.getElementById("pulse");
var pulseV = document.getElementById("pulseV");
var bright = document.getElementById("bright");
var brightV = document.getElementById("brightV");

var syncBox = document.getElementById("SyncBox");
var syncCheck = document.getElementsByClassName("checkboxS");

var WebSocketEnable = 1;

function chgSlider(){
  if (WebSocketEnable) {
    WebSocketEnable = 0;
    setTimeout(function(){WebSocketEnable = 1;sliderSender();},100)
  }
}

function sliderSender() {
  pulseV.innerHTML = pulse.value+"s";
  brightV.innerHTML = bright.value;
  
  const typedArray1 = new Uint8Array(4);
  typedArray1[0] = 20;
  typedArray1[1] = (pulse.value*10)>>8;
  typedArray1[2] = (pulse.value*10);
  typedArray1[3] = bright.value;
  WebSocketSender(typedArray1);
}

function ColorChange(self){
  if (WebSocketEnable) {
    WebSocketEnable = 0;
    setTimeout(function(){WebSocketEnable = 1;ColorSender(self);},100)
  }
}


function coloroff(){
  const typedArray1 = new Uint8Array(2);
  typedArray1[0] = 40;
  typedArray1[1] = 245;
  WebSocketSender(typedArray1);
}

function ColorSender(self){
  var colorpick = self.getCurColorRgb();
  const typedArray1 = new Uint8Array(4);
  typedArray1[0] = 10;
  typedArray1[1] = colorpick.r;
  typedArray1[2] = colorpick.g;
  typedArray1[3] = colorpick.b;
  //console.log(typedArray1)
  WebSocketSender(typedArray1);
}

function PulseSync(state) {
  const typedArray1 = new Uint8Array(2);
  typedArray1[0] = 30;
  typedArray1[1] = state;
  console.log(typedArray1);
  WebSocketSender(typedArray1);
}


function WebSocketSender(message) {
  if (websocket.readyState === WebSocket.OPEN){
    websocket.send(message);
    syncMessage(message);
  }
}

function syncMessage(message){
  for (var i = 0; i < websocketSync.length; i++) {
    if(websocketSync[i].readyState === WebSocket.OPEN){
      websocketSync[i].send(message);
      //console.log(syncCheck[i].id)
    }
  }
}

function syncChange() {
  for (var i = 0; i < syncCheck.length; i++) {
    if(syncCheck[i].checked){
      websocketSync[i] = new WebSocket(`ws://${syncCheck[i].id}:81/ws`);
      websocketSync[i].binaryType = 'arraybuffer';
      websocketSync[i].onopen  = onOpenSync;
      websocketSync[i].onclose = onCloseSync;
      websocketSync[i].onmessage = onMessageSync;
      console.log("SyncOpen")
    }
    else{
      if (websocketSync[i] != undefined){
        if (websocketSync[i].readyState === WebSocket.OPEN) {websocketSync[i].close(1000, "Deliberate disconnection");} 
      }
      //else {websocketSync[i] = none;console.log("noneSet");}
    }
  }
  //console.log(websocketSync)
}
function onOpenSync(event,index){
  popBOX("Connected:"+event.target.url.slice(5,-6),2500);
}
function onCloseSync(event){
   popBOX("Disconnected:"+event.target.url.slice(5,-6),2500);
}
function onMessageSync(event){
  //console.log(event);
}


window.addEventListener('load', onLoad);
function initWebSocket() {
  console.log('Trying to open a WebSocket connection...');
  websocket = new WebSocket(gateway);
  websocket.binaryType = 'arraybuffer';
  websocket.onopen    = onOpen;
  websocket.onclose   = onClose;
  websocket.onmessage = onMessage; // <-- add this line
}
function onOpen(event) {
  console.log('Connection opened');
}
function onClose(event) {
  console.log('Connection closed');
  popBOX("Disconnected",2500);
  setTimeout(initWebSocket, 2000);
}
function onMessage(event) {
  //var msg = JSON.parse(event.data);
  var byteArray = new Uint8Array(event.data);
  //console.log(event)
  switch(byteArray[0]){
    case 1:
      wsClientNum = byteArray[1];

      colorPicker.removeUserEvent("change")
      colorPicker.setColor("rgb("+byteArray[2]+","+byteArray[3]+","+byteArray[4]+")");
      colorPicker.addUserEvent("change", ColorChange)

      pulse.value = ((byteArray[5]<<8) | byteArray[6])/10;
      bright.value = byteArray[7]
      pulseV.innerHTML = pulse.value+"s";
      brightV.innerHTML = bright.value;
      popBOX("Connected",2500);

    break;
    case 21:
      if (wsClientNum != byteArray[1]) {
        pulse.value = ((byteArray[2]<<8) | byteArray[3])/10;
        bright.value = byteArray[4]
        pulseV.innerHTML = pulse.value+"s";
        brightV.innerHTML = bright.value;
      }
      break;
    case 11:
      if (wsClientNum != byteArray[1]) {
        colorPicker.removeUserEvent("change") 
        colorPicker.setColor("rgb("+byteArray[2]+","+byteArray[3]+","+byteArray[4]+")");
        colorPicker.addUserEvent("change", ColorChange)
      }
      break;
  }
}
function clearbox() {popbox.style.display = "none";}
function popBOX(printText,duration) {
  popbox.style.display = "block";
  document.getElementById("poptext").innerHTML = printText;
  setTimeout(clearbox, duration);
}


function onLoad(event) {
  initWebSocket();
  colorPicker.addUserEvent("change", ColorChange)
}