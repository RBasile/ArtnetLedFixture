const char ColorPicker[] PROGMEM = R"=====(
function KellyColorPicker(U){function M(a,h){var c=1,d=!1;a=a.trim(a);if(7>=a.length)"#"==a.charAt(0)&&(a=a.slice(1)),3==a.length?d=a+a:6==a.length&&(d=a);else if("rgb"==a.substring(0,3)){var b=a.split(",");if(3<=b.length&&4>=b.length){b[0]=b[0].replace("rgba(","");b[0]=b[0].replace("rgb(","");var e={r:parseInt(b[0]),g:parseInt(b[1]),b:parseInt(b[2])};if(255>=e.r&&255>=e.g&&255>=e.b&&(d=W(e),4==b.length)){c=parseFloat(b[3]);if(!c||0>c)c=0;1<c&&(c=1)}}}if(!1===d&&h)return!1;!1===d&&(d="000000");"#"!=
d.charAt(0)&&(d="#"+d);return{h:d,a:c}}function R(){var a={};a.size;a.padding=2;a.path;a.imageData=null;a.dotToSv=function(a){return{s:Math.abs(this.path[3].x-a.x)/this.size,v:Math.abs(this.path[3].y-a.y)/this.size}};a.svToDot=function(a){var c=this.path[0].x,d=this.path[0].y,b=.02;150>u?b=.07:100>u&&(b=.16);for(var e=0;e<this.size;e++)for(var f=0;f<this.size;f++){var k={x:f+c,y:e+d},g=this.dotToSv(k),m=Math.abs(g.v-a.v);if(Math.abs(g.s-a.s)<b&&m<b)return k}return{x:0,y:0}};a.limitDotPosition=function(a){var c=
a.x;a=a.y;c<this.path[0].x&&(c=this.path[0].x);c>this.path[0].x+this.size&&(c=this.path[0].x+this.size);a<this.path[0].y&&(a=this.path[0].y);a>this.path[0].y+this.size&&(a=this.path[0].y+this.size);return{x:c,y:a}};a.draw=function(){this.imageData||(this.imageData=b.createImageData(this.size,this.size));for(var a=0,c=this.path[0].x,d=this.path[0].y,V=0;V<this.size;V++)for(var e=0;e<this.size;e++){var f=this.dotToSv({x:e+c,y:V+d}),f=N(k.h,f.s,f.v);this.imageData.data[a+0]=f.r;this.imageData.data[a+
1]=f.g;this.imageData.data[a+2]=f.b;this.imageData.data[a+3]=255;a+=4}b.putImageData(this.imageData,c,d);b.beginPath();b.strokeStyle="rgba(0,0,0, 0.2)";b.lineWidth=2;for(a=0;a<=this.path.length-1;++a)0==a?b.moveTo(this.path[a].x,this.path[a].y):b.lineTo(this.path[a].x,this.path[a].y);b.stroke();b.closePath()};a.updateSize=function(){this.size=Math.floor((2*e.innerRadius-2*v.paddingX-2*this.padding)/Math.sqrt(2));this.path=[];this.path[0]={x:this.size/2*-1,y:this.size/2*-1};this.path[1]={x:this.path[0].x+
this.size,y:this.path[0].y};this.path[2]={x:this.path[1].x,y:this.path[1].y+this.size};this.path[3]={x:this.path[2].x-this.size,y:this.path[2].y};this.path[4]={x:this.path[0].x,y:this.path[0].y};for(var a=0;a<=this.path.length-1;++a)this.path[a].x+=e.pos.x,this.path[a].y+=e.pos.y};a.isDotIn=function(a){return a.x<this.path[0].x||a.x>this.path[0].x+this.size||a.y<this.path[0].y||a.y>this.path[0].y+this.size?!1:!0};return a}function O(){var a={};a.size;a.padding=2;a.path;a.imageData=null;a.followWheel=
!0;a.s;a.sOnTop=!1;a.outerRadius;a.limitDotPosition=function(a){var c=a.x;a=a.y;var d=this.path[2].x,b,e=a;b=Math.min(Math.max(d,c),this.path[0].x);var f=(this.path[0].y-this.path[1].y)/(this.path[0].x-this.path[1].x),k=Math.ceil(this.path[1].y+f*(b-this.path[1].x)),f=(this.path[0].y-this.path[2].y)/(this.path[0].x-this.path[2].x),f=Math.floor(this.path[2].y+f*(b-this.path[2].x));c<d&&(e=a);e=Math.min(Math.max(k,e),f);return{x:b,y:e}};a.svToDot=function(a){var c=.02;150>u?c=.07:100>u&&(c=.16);for(var d=
0;d<this.size;d++)for(var b=0;b<this.size;b++){var e={x:this.path[1].x+b,y:this.path[1].y+d};if(x.isDotIn(e)){var f=this.dotToSv(e),k=Math.abs(f.v-a.v);if(Math.abs(f.s-a.s)<c&&k<c)return e}}return{x:0,y:0}};a.draw=function(){this.imageData||(this.imageData=G.createImageData(this.size,this.size));C.width=this.size;C.height=this.size;for(var a=this.path[1].x,c=this.path[1].y,d=0,e=0;e<this.size;e++)for(var f=0;f<this.size;f++){var g={x:this.path[1].x+f,y:this.path[1].y+e};x.isDotIn(g)?(g=this.dotToSv(g),
g=N(k.h,g.s,g.v),this.imageData.data[d+0]=g.r,this.imageData.data[d+1]=g.g,this.imageData.data[d+2]=g.b,this.imageData.data[d+3]=255):(this.imageData.data[d+0]=0,this.imageData.data[d+1]=0,this.imageData.data[d+2]=0,this.imageData.data[d+3]=0);d+=4}G.putImageData(this.imageData,0,0);b.drawImage(C,a,c);b.beginPath();b.strokeStyle="rgba(0, 0, 0, 0.3)";b.lineWidth=2;a=this.path;for(d=0;d<=a.length-1;++d)0==d?b.moveTo(a[d].x,a[d].y):b.lineTo(a[d].x,a[d].y);b.stroke();b.closePath()};a.calcS=function(a){return Math.abs((a[1].x-
a[0].x)*(a[2].y-a[0].y)-(a[2].x-a[0].x)*(a[1].y-a[0].y))/2};a.dotToSv=function(a){var c=this.vol,d=((a.x-c[0].x)*(c[1].x-c[0].x)+(a.y-c[0].y)*(c[1].y-c[0].y))/((c[0].x-c[1].x)*(c[0].x-c[1].x)+(c[0].y-c[1].y)*(c[0].y-c[1].y));0>d&&(d=0);1<d&&(d=1);var b=this.vol[0],c=Math.sqrt(Math.pow(c[0].x+d*(c[1].x-c[0].x)-b.x,2)+Math.pow(c[0].y+d*(c[1].y-c[0].y)-b.y,2));1>c&&(c=Math.floor(c));c>this.h-1&&(c=this.h);c/=this.h;a=Math.abs(Z(a,this.sSide));30>a&&(a=30);return{s:(60-(a-30))/60,v:c}};a.isDotIn=function(a){a=
[{x:this.path[0].x,y:this.path[0].y},{x:this.path[1].x,y:this.path[1].y},{x:a.x,y:a.y}];var c=this.calcS(a);a[1]={x:this.path[2].x,y:this.path[2].y};c+=this.calcS(a);a[0]={x:this.path[1].x,y:this.path[1].y};c+=this.calcS(a);return Math.ceil(c)==Math.ceil(this.s)?!0:!1};a.updateSize=function(){this.outerRadius=e.innerRadius-v.paddingX-this.padding;this.size=Math.floor(2*this.outerRadius*Math.sin(I/180*60));var a=Math.sqrt(3)/2*this.size;this.h=Math.sqrt(3)/2*this.size;this.path=[];this.path[0]={x:this.outerRadius,
y:0};this.path[1]={x:this.path[0].x-a,y:this.size/2*-1};this.path[2]={x:this.path[1].x,y:this.size/2};this.path[3]={x:this.path[0].x,y:this.path[0].y};for(a=0;a<=this.path.length-1;++a)this.path[a].x+=e.pos.x,this.path[a].y+=e.pos.y;this.vol=[];this.s=this.calcS(this.path);this.sOnTop?(a=aa(this.path[0],this.path[2]),this.vol[0]={x:this.path[1].x,y:this.path[1].y},this.vol[1]={x:a.x,y:a.y},this.sSide=this.path[1]):(a=aa(this.path[0],this.path[1]),this.vol[0]={x:this.path[2].x,y:this.path[2].y},this.vol[1]=
{x:a.x,y:a.y},this.sSide=this.path[2])};return a}function r(a,h,c,d){"object"!==typeof a&&(a=document.getElementById(a));if(!a)return!1;d||(d="");J[d+h]=c;a.addEventListener?a.addEventListener(h,J[d+h]):a.attachEvent("on"+h,J[d+h]);return!0}function n(a,h,c){"object"!==typeof a&&(a=document.getElementById(a));if(!a)return!1;c||(c="");if(!J[c+h])return!1;a.removeEventListener?a.removeEventListener(h,J[c+h]):a.detachEvent("on"+h,J[c+h]);J[c+h]=null;return!0}function N(a,h,c){var d,b,e,f,g,k;a&&void 0===
h&&void 0===c&&(h=a.s,c=a.v,a=a.h);f=Math.floor(6*a);g=6*a-f;a=c*(1-h);k=c*(1-g*h);h=c*(1-(1-g)*h);switch(f%6){case 0:d=c;b=h;e=a;break;case 1:d=k;b=c;e=a;break;case 2:d=a;b=c;e=h;break;case 3:d=a;b=k;e=c;break;case 4:d=h;b=a;e=c;break;case 5:d=c,b=a,e=k}return{r:Math.floor(255*d),g:Math.floor(255*b),b:Math.floor(255*e)}}function W(a){var b=function(a){a=a.toString(16);return 1===a.length?"0"+a:a};return"#"+b(a.r)+b(a.g)+b(a.b)}function aa(a,b){return{x:(a.x+b.x)/2,y:(a.y+b.y)/2}}function Z(a,b,c){b||
(b={x:0,y:0});a=180*Math.atan2(a.y-b.y,a.x-b.x)/I;c&&0>a&&(a=360+a);return a}function X(){ba=2+v.paddingX;H=!1;e.imageData=null;A=u/2;e.pos={x:A,y:A};e.outerRadius=A-ba;e.innerRadius=e.outerRadius-e.width;v.path=[{x:e.innerRadius-v.paddingX,y:-1*v.height},{x:e.outerRadius+v.paddingX,y:-1*v.height},{x:e.outerRadius+v.paddingX,y:v.height},{x:e.innerRadius-v.paddingX,y:v.height},{x:e.innerRadius-v.paddingX,y:-1*v.height}];var a=u;D&&(a+=p.width+2*p.padding);"CANVAS"!=y.tagName&&(y.style.width=a+"px",
y.style.height=u+"px");q.width=a;q.height=u;x.updateSize();D&&p.updateSize()}function P(a){if(l&&(!m.updateinput||(0,m.updateinput)(f,l,a))){var b="rgba("+t.r+", "+t.g+", "+t.b+", "+z.toFixed(2)+")";a||(l.value=1>z&&"mixed"===S?b:"hex"===S||"mixed"===S?E:b);ca&&(l.style.color=.5>k.v?"#FFF":"#000",l.style.background=b)}}function fa(){if(!y)return!1;"CANVAS"!=y.tagName?(q=document.createElement("CANVAS"),y.appendChild(q)):q=y;"undefined"!=typeof window.G_vmlCanvasManager&&(q=window.G_vmlCanvasManager.initElement(q),
C=window.G_vmlCanvasManager.initElement(C));return q.getContext&&q.getContext("2d")?(b=q.getContext("2d"),G=C.getContext("2d"),!0):!1}function T(){r(q,"mousedown",function(a){f.mouseDownEvent(a)},"wait_action_");r(q,"touchstart",function(a){f.mouseDownEvent(a)},"wait_action_");r(q,"mouseout",function(a){f.mouseOutEvent(a)},"wait_action_");r(window,"touchmove",function(a){f.touchMoveEvent(a)},"wait_action_");r(q,"mousemove",function(a){f.mouseMoveRest(a)},"wait_action_")}function da(){n(q,"mousedown",
"wait_action_");n(q,"touchstart","wait_action_");n(q,"mouseout","wait_action_");n(window,"touchmove","wait_action_");n(q,"mousemove","wait_action_")}function K(a){a=a||window.event;var b,c=document.body.scrollLeft+document.documentElement.scrollLeft,d=document.body.scrollTop+document.documentElement.scrollTop;a.touches?(b=a.touches[0].clientX+c,a=a.touches[0].clientY+d):(b=a.clientX+c,a=a.clientY+d);var e=q.getBoundingClientRect();b-=e.left+c;a-=e.top+d;return{x:b,y:a}}function ga(){if(!b)return!1;
b.clearRect(0,0,q.width,q.height);if(H)return b.putImageData(Q,0,0),D&&p.draw(),!0;e.draw();x.draw();D&&p.draw();w||(Q=b.getImageData(0,0,u,u),H=!0);return!0}function L(){if(!ga())return!1;var a=360*k.h-e.startAngle;D&&(b.beginPath(),b.rect(p.pos.x-2,p.padding+p.height*(1-z)-1,p.width+4,2),b.strokeStyle="rgba(0,0,0, 0.8)",b.lineWidth=2,b.stroke(),b.closePath());b.beginPath();var h=v.path,c;c=I/180*a;for(var a=[],d=0;d<=h.length-1;++d)a[d]={x:h[d].x*Math.cos(c)-h[d].y*Math.sin(c),y:h[d].x*Math.sin(c)+
h[d].y*Math.cos(c)};for(h=0;h<=a.length-1;++h)a[h].x+=e.pos.x,a[h].y+=e.pos.y,0==h?b.moveTo(a[h].x,a[h].y):b.lineTo(a[h].x,a[h].y);b.strokeStyle="rgba(0,0,0,0.8)";b.lineWidth=v.lineWeight;b.stroke();b.closePath();b.strokeStyle=.5<k.v&&.5>k.s?"rgba(0, 0, 0, 1)":"rgba(255, 255, 255, 1)";b.beginPath();b.lineWidth=2;b.arc(k.x,k.y,ea.radius,0,2*I);b.stroke();b.closePath();return!1}var I=Math.PI,x,ea={radius:4},q=!1,b=!1,Y="quad",D=!1,w=!1,B=!0,J=[],m=[],C=document.createElement("canvas"),G=!1,H=!1,Q=null,
l=!1,ca=!0,S="mixed",g={tag:!1,margin:6},y=!1,f=this,ba,u=200,A,k,t,E="#000000",z=1,e={width:18,imageData:null};e.innerRadius;e.startAngle=0;e.outerRadius;e.outerStrokeStyle="rgba(0,0,0,0.2)";e.innerStrokeStyle="rgba(0,0,0,0.2)";e.pos;e.draw=function(){if(this.imageData)b.putImageData(this.imageData,0,0);else{for(var a=this.startAngle,h=0;360>=h;h++){var c=I/180*(h-2),d=I/180*h;b.beginPath();b.moveTo(A,A);b.arc(A,A,this.outerRadius,c,d,!1);b.closePath();c=N(a/360,1,1);b.fillStyle="rgb("+c.r+", "+
c.g+", "+c.b+")";b.fill();a++;360<=a&&(a=0)}b.globalCompositeOperation="destination-out";b.beginPath();b.arc(A,A,this.innerRadius,0,2*I);b.fill();b.globalCompositeOperation="source-over";b.strokeStyle=this.innerStrokeStyle;b.lineWidth=2;b.stroke();b.closePath();b.beginPath();b.arc(A,A,this.outerRadius,0,2*I);b.strokeStyle=this.outerStrokeStyle;b.lineWidth=2;b.stroke();b.closePath();this.imageData=b.getImageData(0,0,u,u)}};e.isDotIn=function(a){return Math.pow(e.pos.x-a.x,2)+Math.pow(e.pos.y-a.y,2)<
Math.pow(e.outerRadius,2)&&Math.pow(e.pos.x-a.x,2)+Math.pow(e.pos.y-a.y,2)>Math.pow(e.innerRadius,2)?!0:!1};var v={lineWeight:2,height:4,paddingX:2};v.path;var p={width:18,padding:4,outerStrokeStyle:"rgba(0,0,0,0.2)",innerStrokeStyle:"rgba(0,0,0,0.2)"};p.height;p.pos;p.updateSize=function(){this.pos={x:u+p.padding,y:p.padding};this.height=u-2*p.padding};p.draw=function(){var a=b.createLinearGradient(0,0,0,this.height);a.addColorStop(0,"rgba("+t.r+","+t.g+","+t.b+",1)");a.addColorStop(1,"rgba("+t.r+
","+t.g+","+t.b+",0)");b.beginPath();b.rect(this.pos.x,this.pos.y,this.width,this.height);b.fillStyle="white";b.fill();b.fillStyle=a;b.fill();b.strokeStyle="rgba(0,0,0, 0.2)";b.lineWidth=2;b.stroke();b.closePath()};p.dotToAlpha=function(a){return 1-Math.abs(this.pos.y-a.y)/this.height};p.alphaToDot=function(a){return{x:0,y:this.height-this.height*a}};p.limitDotPosition=function(a){a=a.y;a<this.pos.y&&(a=this.pos.y);a>this.pos.y+this.height&&(a=this.pos.y+this.height);return{x:this.pos.x,y:a}};p.isDotIn=
function(a){return a.x<this.pos.x||a.x>this.pos.x+p.width||a.y<this.pos.y||a.y>this.pos.y+this.height?!1:!0};var F={svCursorData:null,stCursor:null,curType:0,size:16,initSvCursor:function(){if(!q)return!1;var a=document.body;this.curType=1;this.stCursor||(this.stCursor=a.style.cursor);this.stCursor||(this.stCursor="auto");if(this.svCursorData)return a.style.cursor=this.svCursorData,!0;if(!C)return!1;var b=this.size+2;C.width=b;C.height=b;G.clearRect(0,0,this.size,this.size);G.strokeStyle="rgba(255, 255, 255, 1)";
G.beginPath();G.lineWidth=2;G.arc(b/2,b/2,this.size/2,0,2*I);G.stroke();G.closePath();var c=C.toDataURL();this.svCursorData="url("+c+") "+b/2+" "+b/2+", auto";if(!this.svCursorData)return!1;a.style.cursor=this.svCursorData;-1===a.style.cursor.indexOf(c)&&(this.svCursorData="crosshair",a.style.cursor="crosshair");return!0},initStandartCursor:function(){this.stCursor&&(F.curType=0,document.body.style.cursor=this.stCursor)},updateCursor:function(a){KellyColorPicker.cursorLock||(x.isDotIn(a)?F.initSvCursor():
F.initStandartCursor())}};this.popUpClose=function(a){if(!1!==g.tag){if(a&&(a.target==l||a.target==q||a.target==g.tag))return!1;g.tag.style.display="none";KellyColorPicker.activePopUp==f&&(KellyColorPicker.activePopUp=!1)}};this.popUpShow=function(a){if(!1!==g.tag&&(!m.popupshow||(0,m.popupshow)(f,a))){KellyColorPicker.popupEventsInclude||(r(document,"click",function(a){return KellyColorPicker.activePopUp?KellyColorPicker.activePopUp.popUpClose(a):!1},"popup_close_"),r(window,"resize",function(a){if(KellyColorPicker.activePopUp)return KellyColorPicker.activePopUp.popUpShow(a)},
"popup_resize_"),KellyColorPicker.popupEventsInclude=!0);KellyColorPicker.activePopUp&&KellyColorPicker.activePopUp.popUpClose(!1);a=f.getCanvas().width;var b=f.getAlphaFig();b&&(a-=b.width+b.padding);b=parseInt(g.tag.style.paddingBottom)+parseInt(g.tag.style.paddingTop);0>=b&&(b=0);var c=l.getBoundingClientRect(),d=c.left+(window.scrollX||window.pageXOffset||document.body.scrollLeft);g.tag.style.top=c.top+(window.scrollY||window.pageYOffset||document.body.scrollTop)-b-a-g.margin+"px";g.tag.style.left=
d+"px";g.tag.style.display="block";KellyColorPicker.activePopUp=f;return!1}};this.setHueByDot=function(a){a=Z(a,e.pos)+e.startAngle;0>a&&(a=360+a);k.h=a/360;t=N(k.h,k.s,k.v);E=W(t);m.change&&(0,m.change)(f);P();H=!1;L()};this.setColorByHex=function(a,b){b||(b=!1);var c=z;if(!1!==a){if(!a||!a.length)return;var d=M(a,!0);if(!d)return;a=d.h;D&&(c=d.a)}else a=E;if(D&&a==E&&H&&c!=z)z=c,L();else if(!E||a!=E||!H){z=c;c=a;c=parseInt("#"==c.charAt(0)?c.slice(1):c,16);t={r:c>>16,g:c>>8&255,b:c&255};E=a;var c=
t,e=d=void 0;c&&void 0===d&&void 0===e&&(d=c.g,e=c.b,c=c.r);var c=c/255,d=d/255,e=e/255,g=Math.max(c,d,e),n=Math.min(c,d,e),l,p=g-n;if(g==n)l=0;else{switch(g){case c:l=(d-e)/p+(d<e?6:0);break;case d:l=(e-c)/p+2;break;case e:l=(c-d)/p+4}l/=6}k={h:l,s:0==g?0:p/g,v:g};l=x.svToDot(k);k.x=l.x;k.y=l.y;H=!1;L();m.change&&(0,m.change)(f);P(b)}};this.setAlphaByDot=function(a){z=p.dotToAlpha(a);m.change&&(0,m.change)(f);P();L()};this.setAlpha=function(a){z=a;P();L()};this.setColorByDot=function(a){var b=x.dotToSv(a);
k.s=b.s;k.v=b.v;k.x=a.x;k.y=a.y;1<k.s&&(k.s=1);0>k.s&&(k.s=0);1<k.v&&(k.v=1);0>k.v&&(k.v=0);t=N(k.h,k.s,k.v);E=W(t);m.change&&(0,m.change)(f);P();L()};this.mouseOutEvent=function(a){0<F.curType&&!KellyColorPicker.cursorLock&&F.initStandartCursor()};this.mouseMoveRest=function(a){if(!w&&B){B=!1;var b=K(a);F.updateCursor(b);requestAnimationFrame(function(){B=!0});m.mousemoverest&&(0,m.mousemoverest)(a,f,b)}};this.touchMoveEvent=function(a){w&&event.preventDefault()};this.mouseDownEvent=function(a){a.preventDefault();
var b,c=!1,d=K(a);e.isDotIn(d)?(w="wheel",f.setHueByDot(d),b=function(a){f.wheelMouseMove(a,d)},c=function(a){KellyColorPicker.cursorLock=!1;f.wheelMouseUp(a,d)}):x.isDotIn(d)?(w="sv",f.setColorByDot(d),b=function(a){f.svMouseMove(a,d)},c=function(a){KellyColorPicker.cursorLock=!1;f.svMouseUp(a,d)}):D&&p.isDotIn(d)&&(w="alpha",f.setAlphaByDot(d),b=function(a){f.alphaMouseMove(a,d)},c=function(a){KellyColorPicker.cursorLock=!1;f.alphaMouseUp(a,d)});b&&c&&(da(),KellyColorPicker.cursorLock=f,r(document,
"mouseup",c,"action_process_"),r(document,"mousemove",b,"action_process_"),r(document,"touchend",c,"action_process_"),r(document,"touchmove",b,"action_process_"))};this.wheelMouseMove=function(a,b){a.preventDefault();if(w&&B){B=!1;var c=K(a);requestAnimationFrame(function(){B=!0});f.setHueByDot(c);m.mousemoveh&&(0,m.mousemoveh)(a,f,c)}};this.wheelMouseUp=function(a,b){a.preventDefault();if(w){n(document,"mouseup","action_process_");n(document,"mousemove","action_process_");n(document,"touchend","action_process_");
n(document,"touchmove","action_process_");T();H=w=!1;L();var c=K(a);F.updateCursor(c);m.mouseuph&&(0,m.mouseuph)(a,f,c)}};this.alphaMouseMove=function(a,b){a.preventDefault();if(w&&B){B=!1;var c=K(a),c=p.limitDotPosition(c);requestAnimationFrame(function(){B=!0});f.setAlphaByDot(c);m.mousemovealpha&&(0,m.mousemovealpha)(a,f,c)}};this.alphaMouseUp=function(a,b){a.preventDefault();if(w){n(document,"mouseup","action_process_");n(document,"mousemove","action_process_");n(document,"touchend","action_process_");
n(document,"touchmove","action_process_");T();w=!1;var c=K(a);F.updateCursor(c);m.mouseupalpha&&(0,m.mouseupalpha)(a,f,c)}};this.svMouseMove=function(a,b){a.preventDefault();if(w&&B){B=!1;var c=K(a),c=x.limitDotPosition(c);requestAnimationFrame(function(){B=!0});f.setColorByDot(c);m.mousemovesv&&(0,m.mousemovesv)(a,f,c)}};this.svMouseUp=function(a,b){a.preventDefault();if(w){n(document,"mouseup","action_process_");n(document,"mousemove","action_process_");n(document,"touchend","action_process_");
n(document,"touchmove","action_process_");T();w=!1;var c=K(a);F.updateCursor(c);m.mouseupsv&&(0,m.mouseupsv)(a,f,c)}};this.addUserEvent=function(a,b){m[a]=b;return!0};this.removeUserEvent=function(a){if(!m[a])return!1;m[a]=null;return!0};this.getCanvas=function(){return b?q:!1};this.getCtx=function(){return b?b:!1};this.getInput=function(){return l};this.getSvFig=function(){return x};this.getSvFigCursor=function(){return ea};this.getWheel=function(){return e};this.getWheelCursor=function(){return v};
this.getCurColorHsv=function(){return k};this.getCurColorRgb=function(){return t};this.getCurColorHex=function(){return E};this.getCurColorRgba=function(){return{r:t.r,g:t.g,b:t.b,a:z}};this.getCurAlpha=function(){return z};this.getAlphaFig=function(){return D?p:!1};this.getPopup=function(){return g};this.getSize=function(){return u};this.updateView=function(a){if(!b)return!1;a&&(e.imageData=null,Q=x.imageData=null);H=!1;X();L();return!0};this.resize=function(a){if(!b)return!1;if(a==u)return!0;H=
!1;e.imageData=null;Q=x.imageData=null;u=a;X();f.setColorByHex(!1);return!1};this.destroy=function(){0<F.curType&&(KellyColorPicker.cursorLock=!1,F.initStandartCursor());w&&(n(document,"mouseup","action_process_"),n(document,"mousemove","action_process_"),n(document,"touchend","action_process_"),n(document,"touchmove","action_process_"),w=!1);g.tag&&n(l,"click","popup_");l&&(n(l,"click","input_edit_"),n(l,"change","input_edit_"),n(l,"keyup","input_edit_"),n(l,"keypress","input_edit_"));KellyColorPicker.popupEventsInclude&&
J.popup_close_click&&(KellyColorPicker.activePopUp&&KellyColorPicker.activePopUp.popUpClose(!1),n(document,"click","popup_close_"),n(window,"resize","popup_resize_"),KellyColorPicker.popupEventsInclude=!1);e.imageData=null;C=Q=x.imageData=null;y&&y.parentNode&&y.parentNode.removeChild(y);da();f=null};(function(a){var b="",c="";a.input&&"object"!==typeof a.input?(a.input=document.getElementById(a.input),l=a.input):"object"===typeof a.input&&(l=a.input);void 0!==a.alpha&&(z=a.alpha);void 0!==a.alpha_slider&&
(D=a.alpha_slider);void 0!==a.input_color&&(ca=a.input_color);void 0!==a.input_format&&(S=a.input_format);a.userEvents&&(m=a.userEvents);a.place&&"object"!==typeof a.place&&(c=a.place,a.place=document.getElementById(a.place));a.place?y=a.place:l?(g.tag=document.createElement("div"),g.tag.className="popup-kelly-color",a.popupClass?g.tag.className=a.inputClassName:(g.tag.className="popup-kelly-color",g.tag.style.position="absolute",g.tag.style.bottom="0px",g.tag.style.left="0px",g.tag.style.display=
"none",g.tag.style.backgroundColor="#e1e1e1",g.tag.style.border="1px solid #bfbfbf",g.tag.style.boxShadow="7px 7px 14px -3px rgba(0,0,0,0.24)",g.tag.style.borderTopLeftRadius="4px",g.tag.style.borderTopRightRadius="4px",g.tag.style.borderBottomLeftRadius="4px",g.tag.style.borderBottomRightRadius="4px",g.tag.style.padding="12px",g.tag.style.boxSizing="content-box"),y=g.tag,document.getElementsByTagName("body")[0].appendChild(g.tag),r(l,"click",function(a){return f.popUpShow(a)},"popup_")):b+='| "place" ('+
c+") not not found";a.size&&0<a.size&&(u=a.size);a.color?E=a.color:l&&l.value&&(c=M(l.value),E=c.h,D&&(z=c.a));!a.method||"triangle"!=a.method&&"quad"!=a.method||(Y=a.method);fa()||(b+=" | cant init canvas context");b?"undefined"!==typeof console&&console.log("KellyColorPicker : "+b):("quad"==Y&&(x=R()),"triangle"==Y&&(x=O()),l&&(a=function(a){a=a||window.event;a.target||(a.target=a.srcElement);f.setColorByHex(a.target.value,!0)},r(l,"click",a,"input_edit_"),r(l,"change",a,"input_edit_"),r(l,"keyup",
a,"input_edit_"),r(l,"keypress",a,"input_edit_")),T(),X(),f.setColorByHex(!1))})(U)}KellyColorPicker.cursorLock=!1;KellyColorPicker.activePopUp=!1;KellyColorPicker.popupEventsInclude=!1;KellyColorPicker.attachToInputByClass=function(U,M){for(var R=[],O=document.getElementsByClassName(U),r=0;r<O.length;r++)M?M.input=O[r]:M={input:O[r],size:150},R.push(new KellyColorPicker(M));return R};

)=====";

const char CSS[] PROGMEM = R"=====(
body {
    text-align: center;
    background-color: black;
    font-family: Helvetica Neue, sans-serif;
    color: aliceblue;
}
h3 {
    color: aliceblue;
}
div {
    margin: 0px;
}
section {
    margin: 30px 0px;
    display: block;
}
.block {
    display: block;
    margin: 3px auto;
}
a.button {
    color: aliceblue;
    border-style: solid;
    border-radius: 45px;
    text-decoration: none;
    padding: 10px 35px;
    transition: 0.01s;
    font-size: 40px;
    border-width: 5px;
    margin: auto;
    display: inline-block;
    -webkit-user-select: none;
}
.imputT {
    color: aliceblue;
    border-style: solid;
    border-radius: 20px;
    text-decoration: none;
    padding: 6px 15px;
    margin: 3px;
    transition: 0.01s;
    font-size: 40px;
    border-width: 5px;
    background-color: black;
}
.imputT:invalid {
    border-color: red;
}
h1 {
    display: inline;
    font-size: 40px;
}
h2 {
  display: inline;
  font-size: 25px;
  }
.pop {
    position: fixed;
    bottom: 10%;
    left: 0px;
    margin: 3px auto;
    padding: 35px 20px;
    border-radius: 45px;
    background-color: aliceblue;
    color: black;
}
.Boxscrool {
    border-radius: 35px;
    border-width: 5px;
    border-style: solid;
    border-color: aliceblue;
    width: 400px;
    max-height: 220px;
    overflow: auto;
    font-size: 25px;
    padding: 8px 15px;
    text-align: left;
    -webkit-user-select: none;
}
.back {
    top: 20px;
    position: absolute;
    padding: 10px 10px !important;
    left: 20px;
    width: 150px !important;
}
@media only screen and (max-width: 1200px) {
    .back {
        position: inherit;
    }
    h2 {
      font-size: 15px;
    }
    .pop {
    padding: 5px 20px 12px;}
}
.slider {
    -webkit-appearance: none;
    width: 50%;
    height: 30px;
    background: aliceblue;
    outline: none;
    opacity: 1;
    -webkit-transition: 0.2s;
    transition: opacity 0.2s;
    border-radius: 10px;
}
)=====";
