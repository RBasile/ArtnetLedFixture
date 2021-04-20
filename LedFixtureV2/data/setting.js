var DHCPon = 1;
var currentIP = String(window.location.hostname);

var ssidname = document.getElementById("ssidname");
var pass = document.getElementById("pass");
var dhcpON = document.getElementById("dhcpON");

var ip = document.getElementById("ip");
var mask = document.getElementById("mask");
var gateway = document.getElementById("gateway");
var univ = document.getElementById("univ");
var brightV = document.getElementById("brightV");
var bright = document.getElementById("bright");

var popbox = document.getElementById("popbox");

function chgBright() {
brightV.innerHTML = bright.value;
}

window.onload = function(){
  popbox.style.display = "none";
  console.log(currentIP);
};

function newIP() {popbox.style.display = "none";window.location = "http://"+ip.value;}
function clearbox() {popbox.style.display = "none";}
function startSi(){
    var message = "";
    message = "ssid="+ssidname.value;
    message += ";pass="+pass.value;
    message += ";dhcp=" + (dhcpON.checked ? 1 : 0 );
    message += ";ip="+ip.value;
    message += ";mask="+ mask.value;
    message += ";gateway="+ gateway.value;
    message += ";univ="+ univ.value;
    message += ";bright=" + bright.value;
    console.log(message);
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
          if (currentIP!=ip.value){
            setTimeout(newIP, 1000);}
          popbox.style.display = "block";
          document.getElementById("poptext").innerHTML = this.responseText;
          setTimeout(clearbox, 5000);
        };
      };
    
    xhttp.open("POST","/newconf", true);
    xhttp.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
    xhttp.send(message);
    
}
function LockDown(){
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
          popbox.style.display = "block";
          document.getElementById("poptext").innerHTML = this.responseText;
          
        };
      };
    xhttp.open("POST","/LockDownHTML", true);
    xhttp.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
    xhttp.send("LOCKdown=yesLock");
    
}