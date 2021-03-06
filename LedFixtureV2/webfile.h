const char ColorPicker[] PROGMEM = R"=====(

function KellyColorPicker(ca){function T(){w={};w.size;w.sizePercentage=10;w.position;w.paddingY=4;w.paddingX=4;w.imageData=[];w.lineWidth=2;w.color="#c1ebf5";w.updateSize=function(){this.size=parseInt(u-u/100*(100-this.sizePercentage));16>this.size&&(this.size=16);this.position={x:this.paddingX,y:this.paddingY}};w.draw=function(){var a,b;if(this.imageData[B])e.putImageData(this.imageData[B],this.position.x,this.position.y);else{var c=Z(this.color);v.width=this.size;v.height=this.size;f.clearRect(0,
0,this.size,this.size);f.beginPath();var d="triangle";"triangle"==B&&(d="quad");f.beginPath();35>this.size?b=a=v.width/2:(a=v.width/2-this.lineWidth,f.arc(this.size/2,this.size/2,a,0,2*I),f.strokeStyle="rgba(0, 0, 0, 0.4)",f.lineWidth=this.lineWidth,f.stroke(),b=a-6,f.closePath(),f.beginPath(),f.arc(this.size/2,this.size/2,b,0,2*I),f.strokeStyle="rgba(0, 0, 0, 0.4)",f.lineWidth=this.lineWidth,f.stroke(),f.closePath());f.beginPath();if("quad"==d)d=Math.floor((2*b-4)/Math.sqrt(2)),b=(this.size-d)/2,
a=b+d,b=b+d/2-d/2,f.moveTo(a,b),f.lineTo(a-d,b),f.lineTo(a-d,b+d),f.lineTo(a,b+d);else{d=Math.floor((2*b-4)*Math.sin(I/180*60));a=2*b+(a-b);b=this.size/2;var fa=Math.sqrt(3)/2*d;f.moveTo(a,b);f.lineTo(a-fa,b-d/2);f.lineTo(a-fa,b+d/2);f.lineTo(a,b)}f.lineTo(a,b);f.fillStyle="rgba("+c.r+","+c.g+","+c.b+", 1)";f.fill();f.lineWidth=this.lineWidth;f.strokeStyle="rgba(0, 0, 0, 0.6)";f.stroke();f.closePath();this.imageData[B]=f.getImageData(0,0,v.width,v.width);e.drawImage(v,this.position.x,this.position.y)}};
w.isDotIn=function(a){return a.x>=this.position.x&&a.x<=this.position.x+this.size&&a.y>=this.position.y&&a.y<=this.position.y+this.size?!0:!1}}function W(a,b,c){b=b?!0:!1;var d={};d.width;d.widthPercentage=22;d.imageData=null;d.align=a;d.selected=b;d.color="#ffffff";d.position;d.paddingY=-4;d.paddingX=4;d.lineWidth=1;d.selectSize=4;"right"==a&&(d.paddingX*=-1);d.selected&&(d.color=D);c&&(d.color=c);d.updateSize=function(){this.width=parseInt(u-u/100*(100-this.widthPercentage));"left"==this.align?
this.position={x:0,y:u-this.width}:"right"==this.align&&(this.position={x:u-this.width,y:u-this.width})};d.calcS=function(a){return Math.abs((a[1].x-a[0].x)*(a[2].y-a[0].y)-(a[2].x-a[0].x)*(a[1].y-a[0].y))/2};d.isDotIn=function(a){var b=[];"left"==this.align?(b[0]={x:this.position.x,y:this.position.y},b[1]={x:this.position.x,y:this.position.y+this.width},b[2]={x:this.position.x+this.width,y:this.position.y+this.width}):(b[0]={x:this.position.x+this.width,y:this.position.y},b[1]={x:b[0].x,y:b[0].y+
this.width},b[2]={x:b[0].x-this.width,y:this.position.y+this.width});for(var c=0;c<=b.length-1;++c)b[c].x+=this.paddingX,b[c].y+=this.paddingY;c=this.calcS(b);a=[{x:b[0].x,y:b[0].y},{x:b[1].x,y:b[1].y},{x:a.x,y:a.y}];var d=this.calcS(a);a[1]={x:b[2].x,y:b[2].y};d+=this.calcS(a);a[0]={x:b[1].x,y:b[1].y};d+=this.calcS(a);return Math.ceil(d)==Math.ceil(c)?!0:!1};d.draw=function(){v.width=this.width;v.height=this.width;f.clearRect(0,0,this.width,this.width);f.beginPath();"left"==this.align&&(f.moveTo(this.lineWidth/
2,this.width-this.lineWidth),f.lineTo(this.width,this.width-this.lineWidth),f.lineTo(this.lineWidth,this.lineWidth),f.lineTo(this.lineWidth,this.width-this.lineWidth));"right"==this.align&&(f.moveTo(this.lineWidth/2,this.width-this.lineWidth),f.lineTo(this.width-this.lineWidth,this.width-this.lineWidth),f.lineTo(this.width-this.lineWidth,this.lineWidth),f.lineTo(this.lineWidth,this.width-this.lineWidth));this.selected&&(f.fillStyle="rgba(255,255,255, 1)",f.fill(),f.strokeStyle="rgba(0, 0, 0, 1)",
f.stroke(),f.closePath(),f.beginPath(),f.lineWidth=this.lineWidth,"left"==this.align&&(f.moveTo(this.selectSize,this.width-this.selectSize),f.lineTo(this.width-2*this.selectSize,this.width-this.selectSize),f.lineTo(this.selectSize,2*this.selectSize),f.lineTo(this.selectSize,this.width-this.selectSize)),"right"==this.align&&(f.moveTo(2*this.selectSize,this.width-this.selectSize),f.lineTo(this.width-this.selectSize,this.width-this.selectSize),f.lineTo(this.width-this.selectSize,2*this.selectSize),f.lineTo(2*
this.selectSize,this.width-this.selectSize)));var a=Z(this.color);f.fillStyle="rgba("+a.r+","+a.g+","+a.b+", 1)";f.fill();f.strokeStyle="rgba(0, 0, 0, 1)";f.stroke();this.imageData=f.getImageData(0,0,this.width,this.width);e.drawImage(v,this.position.x+this.paddingX,this.position.y+this.paddingY)};m[m.length]=d}function S(a){var b=a.getBoundingClientRect(),c=0,d=0;E&&(d=t.width+2*t.padding);a===n?b.width<=b.height?c=b.height:b.height<b.width&&(c=b.width):aa?"height"==aa?c=b.height:"width"==aa&&(c=
b.width):b.width>b.height?c=b.height:b.height>=b.width&&(c=b.width);c=parseInt(c);E&&(c-=d);return 0>=c?!1:c}function N(a,b){var c=1,d=!1;if("string"==typeof a)if(a=a.trim(a),-1==a.indexOf("(")){if("#"==a.charAt(0)&&(a=a.slice(1)),a=a.substr(0,8),3<=a.length){6<a.length&&8>a.length&&(a=a.substr(0,6));3<a.length&&6>a.length&&(a=a.substr(0,3));d=a;if(3<=a.length&&4>=a.length)for(var d="",e=0;e<a.length;e++)d+=a[e]+a[e];8==d.length&&(c=(parseInt(d,16)&255)/255)}}else{if(vals=a.split(","),3<=vals.length){switch(a.substring(0,
3)){case "rgb":vals[0]=vals[0].replace("rgba(","");vals[0]=vals[0].replace("rgb(","");e={r:parseInt(vals[0]),g:parseInt(vals[1]),b:parseInt(vals[2])};255>=e.r&&255>=e.g&&255>=e.b&&(d=U(e));break;case "hsl":vals[0]=vals[0].replace("hsl(","");vals[0]=vals[0].replace("hsla(","");var e=parseFloat(vals[0])/360,f=parseFloat(vals[1])/100,g=parseFloat(vals[2])/100;0<=e&&1>=f&&1>=g&&(d=U(O(e,f,g)))}if(4==vals.length){c=parseFloat(vals[3]);if(!c||0>c)c=0;1<c&&(c=1)}}}else"object"==typeof a&&("undefined"!=typeof a.r&&
"undefined"!=typeof a.g&&"undefined"!=typeof a.b?d=U(a):"undefined"!=typeof a.h&&"undefined"!=typeof a.s&&"undefined"!=typeof a.l&&(a.h=parseFloat(a.h)/360,a.s=parseFloat(a.s)/100,a.l=parseFloat(a.l)/100,0<=a.h&&1>=a.s&&1>=a.l&&(d=U(O(a.h,a.s,a.l)))),"undefined"!=typeof a.a&&(c=a.a));if(!1===d&&b)return!1;!1===d&&(d="000000");"#"!=d.charAt(0)?(d=d.substr(0,6),d="#"+d):d=d.substr(0,7);return{h:d,a:c}}function ga(){if(V.quad)return V.quad;var a={};a.size;a.padding=2;a.path;a.imageData=null;a.dotToSv=
function(a){return{s:Math.abs(this.path[3].x-a.x)/this.size,v:Math.abs(this.path[3].y-a.y)/this.size}};a.svToDot=function(a){var c=this.path[0].x,d=this.path[0].y,e=.02;150>u?e=.07:100>u&&(e=.16);for(var f=0;f<this.size;f++)for(var g=0;g<this.size;g++){var l={x:g+c,y:f+d},h=this.dotToSv(l),k=Math.abs(h.v-a.v);if(Math.abs(h.s-a.s)<e&&k<e)return l}return{x:0,y:0}};a.limitDotPosition=function(a){var c=a.x;a=a.y;c<this.path[0].x&&(c=this.path[0].x);c>this.path[0].x+this.size&&(c=this.path[0].x+this.size);
a<this.path[0].y&&(a=this.path[0].y);a>this.path[0].y+this.size&&(a=this.path[0].y+this.size);return{x:c,y:a}};a.draw=function(){this.imageData||(this.imageData=e.createImageData(this.size,this.size));for(var a=0,c=this.path[0].x,d=this.path[0].y,f=0;f<this.size;f++)for(var g=0;g<this.size;g++){var h=this.dotToSv({x:g+c,y:f+d}),h=O(l.h,h.s,h.v);this.imageData.data[a+0]=h.r;this.imageData.data[a+1]=h.g;this.imageData.data[a+2]=h.b;this.imageData.data[a+3]=255;a+=4}e.putImageData(this.imageData,c,d);
e.beginPath();e.strokeStyle="rgba(0,0,0, 0.2)";e.lineWidth=2;for(a=0;a<=this.path.length-1;++a)0==a?e.moveTo(this.path[a].x,this.path[a].y):e.lineTo(this.path[a].x,this.path[a].y);e.stroke();e.closePath()};a.updateSize=function(){this.size=Math.floor((2*h.innerRadius-2*x.paddingX-2*this.padding)/Math.sqrt(2));this.path=[];this.path[0]={x:this.size/2*-1,y:this.size/2*-1};this.path[1]={x:this.path[0].x+this.size,y:this.path[0].y};this.path[2]={x:this.path[1].x,y:this.path[1].y+this.size};this.path[3]=
{x:this.path[2].x-this.size,y:this.path[2].y};this.path[4]={x:this.path[0].x,y:this.path[0].y};for(var a=0;a<=this.path.length-1;++a)this.path[a].x+=h.pos.x,this.path[a].y+=h.pos.y};a.isDotIn=function(a){return a.x<this.path[0].x||a.x>this.path[0].x+this.size||a.y<this.path[0].y||a.y>this.path[0].y+this.size?!1:!0};return V.quad=a}function ha(){if(V.triangle)return V.triangle;var a={};a.size;a.padding=2;a.path;a.imageData=null;a.followWheel=!0;a.s;a.sOnTop=!1;a.outerRadius;a.limitDotPosition=function(a){var c=
a.x;a=a.y;var d=this.path[2].x,e,f=a;e=Math.min(Math.max(d,c),this.path[0].x);var g=(this.path[0].y-this.path[1].y)/(this.path[0].x-this.path[1].x),h=Math.ceil(this.path[1].y+g*(e-this.path[1].x)),g=(this.path[0].y-this.path[2].y)/(this.path[0].x-this.path[2].x),g=Math.floor(this.path[2].y+g*(e-this.path[2].x));c<d&&(f=a);f=Math.min(Math.max(h,f),g);return{x:e,y:f}};a.svToDot=function(a){var c=.02;150>u?c=.07:100>u&&(c=.16);for(var d=0;d<this.size;d++)for(var e=0;e<this.size;e++){var f={x:this.path[1].x+
e,y:this.path[1].y+d};if(y.isDotIn(f)){var g=this.dotToSv(f),h=Math.abs(g.v-a.v);if(Math.abs(g.s-a.s)<c&&h<c)return f}}return{x:0,y:0}};a.draw=function(){this.imageData||(this.imageData=f.createImageData(this.size,this.size));v.width=this.size;v.height=this.size;for(var a=this.path[1].x,c=this.path[1].y,d=0,g=0;g<this.size;g++)for(var h=0;h<this.size;h++){var k={x:this.path[1].x+h,y:this.path[1].y+g};y.isDotIn(k)?(k=this.dotToSv(k),k=O(l.h,k.s,k.v),this.imageData.data[d+0]=k.r,this.imageData.data[d+
1]=k.g,this.imageData.data[d+2]=k.b,this.imageData.data[d+3]=255):(this.imageData.data[d+0]=0,this.imageData.data[d+1]=0,this.imageData.data[d+2]=0,this.imageData.data[d+3]=0);d+=4}f.putImageData(this.imageData,0,0);e.drawImage(v,a,c);e.beginPath();e.strokeStyle="rgba(0, 0, 0, 0.3)";e.lineWidth=2;a=this.path;for(d=0;d<=a.length-1;++d)0==d?e.moveTo(a[d].x,a[d].y):e.lineTo(a[d].x,a[d].y);e.stroke();e.closePath()};a.calcS=function(a){return Math.abs((a[1].x-a[0].x)*(a[2].y-a[0].y)-(a[2].x-a[0].x)*(a[1].y-
a[0].y))/2};a.dotToSv=function(a){var c=this.vol,d=((a.x-c[0].x)*(c[1].x-c[0].x)+(a.y-c[0].y)*(c[1].y-c[0].y))/((c[0].x-c[1].x)*(c[0].x-c[1].x)+(c[0].y-c[1].y)*(c[0].y-c[1].y));0>d&&(d=0);1<d&&(d=1);var e=this.vol[0],c=Math.sqrt(Math.pow(c[0].x+d*(c[1].x-c[0].x)-e.x,2)+Math.pow(c[0].y+d*(c[1].y-c[0].y)-e.y,2));1>c&&(c=Math.floor(c));c>this.h-1&&(c=this.h);c/=this.h;a=Math.abs(ia(a,this.sSide));30>a&&(a=30);return{s:(60-(a-30))/60,v:c}};a.isDotIn=function(a){a=[{x:this.path[0].x,y:this.path[0].y},
{x:this.path[1].x,y:this.path[1].y},{x:a.x,y:a.y}];var c=this.calcS(a);a[1]={x:this.path[2].x,y:this.path[2].y};c+=this.calcS(a);a[0]={x:this.path[1].x,y:this.path[1].y};c+=this.calcS(a);return Math.ceil(c)==Math.ceil(this.s)?!0:!1};a.updateSize=function(){this.outerRadius=h.innerRadius-x.paddingX-this.padding;this.size=Math.floor(2*this.outerRadius*Math.sin(I/180*60));var a=Math.sqrt(3)/2*this.size;this.h=Math.sqrt(3)/2*this.size;this.path=[];this.path[0]={x:this.outerRadius,y:0};this.path[1]={x:this.path[0].x-
a,y:this.size/2*-1};this.path[2]={x:this.path[1].x,y:this.size/2};this.path[3]={x:this.path[0].x,y:this.path[0].y};for(a=0;a<=this.path.length-1;++a)this.path[a].x+=h.pos.x,this.path[a].y+=h.pos.y;this.vol=[];this.s=this.calcS(this.path);this.sOnTop?(a=ja(this.path[0],this.path[2]),this.vol[0]={x:this.path[1].x,y:this.path[1].y},this.vol[1]={x:a.x,y:a.y},this.sSide=this.path[1]):(a=ja(this.path[0],this.path[1]),this.vol[0]={x:this.path[2].x,y:this.path[2].y},this.vol[1]={x:a.x,y:a.y},this.sSide=this.path[2])};
return V.triangle=a}function z(a,b,c,d){"object"!==typeof a&&(a=document.getElementById(a));if(!a)return!1;d||(d="");P[d+b]=c;a.addEventListener?a.addEventListener(b,P[d+b]):a.attachEvent("on"+b,P[d+b]);return!0}function q(a,b,c){"object"!==typeof a&&(a=document.getElementById(a));if(!a)return!1;c||(c="");if(!P[c+b])return!1;a.removeEventListener?a.removeEventListener(b,P[c+b]):a.detachEvent("on"+b,P[c+b]);P[c+b]=null;return!0}function O(a,b,c){var d,e,f,g,h,k;a&&void 0===b&&void 0===c&&(b=a.s,c=
a.v,a=a.h);g=Math.floor(6*a);h=6*a-g;a=c*(1-b);k=c*(1-h*b);b=c*(1-(1-h)*b);switch(g%6){case 0:d=c;e=b;f=a;break;case 1:d=k;e=c;f=a;break;case 2:d=a;e=c;f=b;break;case 3:d=a;e=k;f=c;break;case 4:d=b;e=a;f=c;break;case 5:d=c,e=a,f=k}return{r:Math.floor(255*d),g:Math.floor(255*e),b:Math.floor(255*f)}}function ka(a,b,c){a&&void 0===b&&void 0===c&&(b=a.g,c=a.b,a=a.r);a/=255;b/=255;c/=255;var d=Math.max(a,b,c),e=Math.min(a,b,c),f,g=d-e;if(d==e)f=0;else{switch(d){case a:f=(b-c)/g+(b<c?6:0);break;case b:f=
(c-a)/g+2;break;case c:f=(a-b)/g+4}f/=6}return{h:f,s:0==d?0:g/d,v:d}}function Z(a){a=parseInt("#"==a.charAt(0)?a.slice(1):a,16);return{r:a>>16,g:a>>8&255,b:a&255}}function U(a){var b=function(a){a=a.toString(16);return 1===a.length?"0"+a:a};return"#"+b(a.r)+b(a.g)+b(a.b)}function ja(a,b){return{x:(a.x+b.x)/2,y:(a.y+b.y)/2}}function ia(a,b,c){b||(b={x:0,y:0});a=180*Math.atan2(a.y-b.y,a.x-b.x)/I;c&&0>a&&(a=360+a);return a}function da(){la=2+x.paddingX;L=!1;h.imageData=null;J=u/2;h.pos={x:J,y:J};h.outerRadius=
J-la;h.innerRadius=h.outerRadius-h.width;x.path=[{x:h.innerRadius-x.paddingX,y:-1*x.height},{x:h.outerRadius+x.paddingX,y:-1*x.height},{x:h.outerRadius+x.paddingX,y:x.height},{x:h.innerRadius-x.paddingX,y:x.height},{x:h.innerRadius-x.paddingX,y:-1*(x.height+x.lineWeight/2)}];var a=u;E&&(a+=t.width+2*t.padding);"canvas"!=F.tagName.toLowerCase()&&(F.style.width=a+"px",F.style.height=u+"px");n.width=a;n.height=u;Q!=n&&(n.style.width=a+"px",n.style.height=u+"px");for(a=0;a<=m.length-1;++a)m[a].updateSize();
w&&(w.imageData.triangle=null,w.imageData.quad=null,w.updateSize());y.updateSize();E&&t.updateSize()}function X(a){if(r&&(!k.updateinput||(0,k.updateinput)(g,r,a))){var b=G.toFixed(2),c="rgba("+H.r+", "+H.g+", "+H.b+", "+b+")";if(!a)switch(ma){case "mixed":r.value=1>G?c:D;break;case "hex":r.value=D;break;case "hsla":r.value="hsla("+(360*l.h).toFixed(2)+", "+(100*l.s).toFixed(2)+"%, "+(100*l.v).toFixed(2)+"%, "+b+")";break;default:r.value=c}na&&(r.style.color=.5>l.v?"#FFF":"#000",r.style.background=
c)}}function ta(){if(!F)return!1;"CANVAS"!=F.tagName?(n=document.createElement("CANVAS"),F.appendChild(n)):n=F;"undefined"!=typeof window.G_vmlCanvasManager&&(n=window.G_vmlCanvasManager.initElement(n),v=window.G_vmlCanvasManager.initElement(v));return n.getContext&&n.getContext("2d")?(e=n.getContext("2d"),f=v.getContext("2d"),!0):!1}function ba(){z(n,"mousedown",function(a){g.mouseDownEvent(a)},"wait_action_");z(n,"touchstart",function(a){g.mouseDownEvent(a)},"wait_action_");z(n,"mouseout",function(a){g.mouseOutEvent(a)},
"wait_action_");z(window,"touchmove",function(a){g.touchMoveEvent(a)},"wait_action_");z(n,"mousemove",function(a){g.mouseMoveRest(a)},"wait_action_")}function oa(){q(n,"mousedown","wait_action_");q(n,"touchstart","wait_action_");q(n,"mouseout","wait_action_");q(window,"touchmove","wait_action_");q(n,"mousemove","wait_action_")}function R(a){a=a||window.event;var b,c=document.body.scrollLeft+document.documentElement.scrollLeft,d=document.body.scrollTop+document.documentElement.scrollTop;"touchend"==
a.type?(b=a.changedTouches[0].clientX+c,a=a.changedTouches[0].clientY+d):"touchmove"==a.type||a.touches?(b=a.touches[0].clientX+c,a=a.touches[0].clientY+d):(b=a.clientX+c,a=a.clientY+d);var e=n.getBoundingClientRect();b-=e.left+c;a-=e.top+d;return{x:b,y:a}}function pa(a){for(var b=!1,c=0;c<=m.length-1;++c)m[c].selected&&(b=c),m[c].selected=!1;for(var d=!1,c=0;c<=m.length-1;++c)if(c==a){m[c].selected=!0;g.setColorByHex(m[c].color);d=!0;break}d&&k.selectcolorsaver&&(0,k.selectcolorsaver)(g,m[a]);d||
!1===b||(m[b].selected=!0);return d}function ea(){for(var a=0;a<=m.length-1;++a)m[a].selected&&(m[a].color=D)}function qa(){if(m.length)for(var a=0;a<=m.length-1;++a)m[a].draw()}function ua(){if(!e)return!1;e.clearRect(0,0,n.width,n.height);if(L)return e.putImageData(Y,0,0),qa(),!0;h.draw();y.draw();E&&t.draw();qa();w&&w.draw();A||(Y=e.getImageData(0,0,n.width,n.height),L=!0);return!0}function M(){if(!ua())return!1;var a=360*l.h-h.startAngle;E&&(e.beginPath(),e.rect(t.pos.x-2,t.padding+t.height*(1-
G)-1,t.width+4,2),e.strokeStyle="rgba(0,0,0, 0.8)",e.lineWidth=2,e.stroke(),e.closePath());e.beginPath();var b=x.path,c;c=I/180*a;for(var a=[],d=0;d<=b.length-1;++d)a[d]={x:b[d].x*Math.cos(c)-b[d].y*Math.sin(c),y:b[d].x*Math.sin(c)+b[d].y*Math.cos(c)};for(b=0;b<=a.length-1;++b)a[b].x+=h.pos.x,a[b].y+=h.pos.y,0==b?e.moveTo(a[b].x,a[b].y):e.lineTo(a[b].x,a[b].y);e.strokeStyle="rgba(0,0,0,0.8)";e.lineWidth=x.lineWeight;e.stroke();e.closePath();e.strokeStyle=.5<l.v&&.5>l.s?"rgba(0, 0, 0, 1)":"rgba(255, 255, 255, 1)";
e.beginPath();e.lineWidth=2;e.arc(l.x,l.y,ra.radius,0,2*I);e.stroke();e.closePath();return!1}var I=Math.PI,y,sa=!0,ra={radius:4},n=!1,e=!1,B="quad",E=!1,A=!1,K=!0,P=[],k=[],v=document.createElement("canvas"),f=!1,L=!1,Y=null,r=!1,na=!0,ma="mixed",p={tag:!1,margin:6},F=!1,g=this,la,u=200,J,l,H,D="#000000",G=1,Q=!1,aa=!1,m=[],w=!1,V=[],h={width:18,imageData:null};h.innerRadius;h.startAngle=0;h.outerRadius;h.outerStrokeStyle="rgba(0,0,0,0.2)";h.innerStrokeStyle="rgba(0,0,0,0.2)";h.pos;h.draw=function(){if(this.imageData)e.putImageData(this.imageData,
0,0);else{for(var a=this.startAngle,b=0;360>=b;b++){var c=I/180*(b-2),d=I/180*b;e.beginPath();e.moveTo(J,J);e.arc(J,J,this.outerRadius,c,d,!1);e.closePath();c=O(a/360,1,1);e.fillStyle="rgb("+c.r+", "+c.g+", "+c.b+")";e.fill();a++;360<=a&&(a=0)}e.globalCompositeOperation="destination-out";e.beginPath();e.arc(J,J,this.innerRadius,0,2*I);e.fill();e.globalCompositeOperation="source-over";e.strokeStyle=this.innerStrokeStyle;e.lineWidth=2;e.stroke();e.closePath();e.beginPath();e.arc(J,J,this.outerRadius,
0,2*I);e.strokeStyle=this.outerStrokeStyle;e.lineWidth=2;e.stroke();e.closePath();this.imageData=e.getImageData(0,0,u,u)}};h.isDotIn=function(a){return Math.pow(this.pos.x-a.x,2)+Math.pow(this.pos.y-a.y,2)<Math.pow(this.outerRadius,2)&&Math.pow(this.pos.x-a.x,2)+Math.pow(this.pos.y-a.y,2)>Math.pow(this.innerRadius,2)?!0:!1};var x={lineWeight:2,height:4,paddingX:2};x.path;var t={width:18,padding:4,outerStrokeStyle:"rgba(0,0,0,0.2)",innerStrokeStyle:"rgba(0,0,0,0.2)"};t.height;t.pos;t.updateSize=function(){this.pos=
{x:u+t.padding,y:t.padding};this.height=u-2*t.padding};t.draw=function(){var a=e.createLinearGradient(0,0,0,this.height),b=O(l.h,1,1);a.addColorStop(0,"rgba("+b.r+","+b.g+","+b.b+",1)");a.addColorStop(1,"rgba("+b.r+","+b.g+","+b.b+",0)");e.beginPath();e.rect(this.pos.x,this.pos.y,this.width,this.height);e.fillStyle="white";e.fill();e.fillStyle=a;e.fill();e.strokeStyle="rgba(0,0,0, 0.2)";e.lineWidth=2;e.stroke();e.closePath()};t.dotToAlpha=function(a){return 1-Math.abs(this.pos.y-a.y)/this.height};
t.alphaToDot=function(a){return{x:0,y:this.height-this.height*a}};t.limitDotPosition=function(a){a=a.y;a<this.pos.y&&(a=this.pos.y);a>this.pos.y+this.height&&(a=this.pos.y+this.height);return{x:this.pos.x,y:a}};t.isDotIn=function(a){return a.x<this.pos.x||a.x>this.pos.x+t.width||a.y<this.pos.y||a.y>this.pos.y+this.height?!1:!0};var C={svCursorData:null,stCursor:null,curType:0,size:16};C.cEl=document.body;C.initSvCursor=function(){if(!n)return!1;this.curType=1;this.stCursor||(this.stCursor=window.getComputedStyle(this.cEl).cursor,
this.stCursor||(this.stCursor="auto"));if(this.svCursorData)return this.cEl.style.cursor=this.svCursorData,!0;if(!v)return!1;var a=this.size+2;v.width=a;v.height=a;f.clearRect(0,0,this.size,this.size);f.strokeStyle="rgba(255, 255, 255, 1)";f.beginPath();f.lineWidth=2;f.arc(a/2,a/2,this.size/2,0,2*I);f.stroke();f.closePath();var b=v.toDataURL();this.svCursorData="url("+b+") "+a/2+" "+a/2+", auto";if(!this.svCursorData)return!1;this.cEl.style.cursor=this.svCursorData;-1===this.cEl.style.cursor.indexOf(b)&&
(this.svCursorData="crosshair",this.cEl.style.cursor="crosshair");return!0};C.initStandartCursor=function(){this.stCursor&&(C.curType=0,this.cEl.style.cursor=this.stCursor)};C.updateCursor=function(a){sa&&(KellyColorPicker.cursorLock||(y.isDotIn(a)?C.initSvCursor():C.initStandartCursor()))};this.popUpClose=function(a){if(!1!==p.tag){if(a&&(a.target==r||a.target==n||a.target==p.tag))return!1;if(!k.popupclose||k.popupclose(g,a))p.tag.style.display="none",KellyColorPicker.activePopUp==g&&(KellyColorPicker.activePopUp=
!1)}};this.popUpShow=function(a){if(!1!==p.tag&&(!k.popupshow||k.popupshow(g,a))){KellyColorPicker.popupEventsInclude||(z(document,"click",function(a){return KellyColorPicker.activePopUp?KellyColorPicker.activePopUp.popUpClose(a):!1},"popup_close_"),z(window,"resize",function(a){if(KellyColorPicker.activePopUp)return KellyColorPicker.activePopUp.popUpShow(a)},"popup_resize_"),KellyColorPicker.popupEventsInclude=!0);KellyColorPicker.activePopUp&&KellyColorPicker.activePopUp.popUpClose(!1);a=g.getCanvas().width;
var b=g.getAlphaFig();b&&(a-=b.width+b.padding);b=window.getComputedStyle(p.tag);b=parseInt(b.paddingBottom)+parseInt(b.paddingTop);0>=b&&(b=0);var c=r.getBoundingClientRect(),d=c.left+(window.scrollX||window.pageXOffset||document.body.scrollLeft);p.tag.style.top=c.top+(window.scrollY||window.pageYOffset||document.body.scrollTop)-b-a-p.margin+"px";p.tag.style.left=d+"px";p.tag.style.display="block";KellyColorPicker.activePopUp=g;return!1}};this.setHueByDot=function(a){a=ia(a,h.pos)+h.startAngle;0>
a&&(a=360+a);l.h=a/360;H=O(l.h,l.s,l.v);D=U(H);ea();k.change&&(0,k.change)(g);X();L=!1;M()};this.setColorForColorSaver=function(a,b){var c=N(a,!0);if(c){var d=g.getColorSaver(b);d.selected?this.setColorByHex(a,!1):(d.color=c.h,M());return!0}};this.setColor=function(a,b){g.setColorByHex(a,b)};this.setColorByHex=function(a,b){b||(b=!1);var c=G;if(!1!==a){if(!a||!a.length)return;var d=N(a,!0);if(!d)return;a=d.h;E&&(c=d.a)}else a=D;E&&a==D&&L&&c!=G?(G=c,M()):D&&a==D&&L||(G=c,H=Z(a),D=a,l=ka(H),c=y.svToDot(l),
l.x=c.x,l.y=c.y,L=!1,ea(),M(),k.change&&(0,k.change)(g),X(b))};this.setAlphaByDot=function(a){G=t.dotToAlpha(a);k.change&&(0,k.change)(g);X();M()};this.setAlpha=function(a){G=a;X();M()};this.setColorByDot=function(a){var b=y.dotToSv(a);l.s=b.s;l.v=b.v;l.x=a.x;l.y=a.y;1<l.s&&(l.s=1);0>l.s&&(l.s=0);1<l.v&&(l.v=1);0>l.v&&(l.v=0);H=O(l.h,l.s,l.v);D=U(H);ea();k.change&&(0,k.change)(g);X();M()};this.mouseOutEvent=function(a){0<C.curType&&!KellyColorPicker.cursorLock&&C.initStandartCursor()};this.mouseMoveRest=
function(a){if(!A&&K){K=!1;var b=R(a);C.updateCursor(b);requestAnimationFrame(function(){K=!0});k.mousemoverest&&(0,k.mousemoverest)(a,g,b)}};this.touchMoveEvent=function(a){A&&event.preventDefault()};this.mouseDownEvent=function(a){a.preventDefault();var b,c=!1,d=R(a);if(h.isDotIn(d))A="wheel",g.setHueByDot(d),b=function(a){g.wheelMouseMove(a,d)},c=function(a){KellyColorPicker.cursorLock=!1;g.wheelMouseUp(a,d)};else if(y.isDotIn(d))A="sv",g.setColorByDot(d),b=function(a){g.svMouseMove(a,d)},c=function(a){KellyColorPicker.cursorLock=
!1;g.svMouseUp(a,d)};else if(E&&t.isDotIn(d))A="alpha",g.setAlphaByDot(d),b=function(a){g.alphaMouseMove(a,d)},c=function(a){KellyColorPicker.cursorLock=!1;g.alphaMouseUp(a,d)};else if(w&&w.isDotIn(d))g.setMethod();else if(m.length)for(a=0;a<=m.length-1;++a)if(m[a].isDotIn(d)){pa(a);break}b&&c&&(oa(),KellyColorPicker.cursorLock=g,z(document,"mouseup",c,"action_process_"),z(document,"mousemove",b,"action_process_"),z(document,"touchend",c,"action_process_"),z(document,"touchmove",b,"action_process_"))};
this.wheelMouseMove=function(a,b){a.preventDefault();if(A&&K){K=!1;var c=R(a);requestAnimationFrame(function(){K=!0});g.setHueByDot(c);k.mousemoveh&&(0,k.mousemoveh)(a,g,c)}};this.wheelMouseUp=function(a,b){a.preventDefault();if(A){q(document,"mouseup","action_process_");q(document,"mousemove","action_process_");q(document,"touchend","action_process_");q(document,"touchmove","action_process_");ba();L=A=!1;M();var c=R(a);C.updateCursor(c);k.mouseuph&&(0,k.mouseuph)(a,g,c)}};this.alphaMouseMove=function(a,
b){a.preventDefault();if(A&&K){K=!1;var c=R(a),c=t.limitDotPosition(c);requestAnimationFrame(function(){K=!0});g.setAlphaByDot(c);k.mousemovealpha&&(0,k.mousemovealpha)(a,g,c)}};this.alphaMouseUp=function(a,b){a.preventDefault();if(A){q(document,"mouseup","action_process_");q(document,"mousemove","action_process_");q(document,"touchend","action_process_");q(document,"touchmove","action_process_");ba();A=!1;var c=R(a);C.updateCursor(c);k.mouseupalpha&&(0,k.mouseupalpha)(a,g,c)}};this.svMouseMove=function(a,
b){a.preventDefault();if(A&&K){K=!1;var c=R(a),c=y.limitDotPosition(c);requestAnimationFrame(function(){K=!0});g.setColorByDot(c);k.mousemovesv&&(0,k.mousemovesv)(a,g,c)}};this.svMouseUp=function(a,b){a.preventDefault();if(A){q(document,"mouseup","action_process_");q(document,"mousemove","action_process_");q(document,"touchend","action_process_");q(document,"touchmove","action_process_");ba();A=!1;var c=R(a);C.updateCursor(c);E&&(L=!1,M());k.mouseupsv&&(0,k.mouseupsv)(a,g,c)}};this.addUserEvent=function(a,
b){k[a]=b;return!0};this.removeUserEvent=function(a){if(!k[a])return!1;k[a]=null;return!0};this.getCanvas=function(){return e?n:!1};this.getCtx=function(){return e?e:!1};this.getInput=function(){return r};this.getSvFig=function(){return y};this.getSvFigCursor=function(){return ra};this.getWheel=function(){return h};this.getWheelCursor=function(){return x};this.getCurColorHsv=function(){return l};this.getCurColorRgb=function(){return H};this.getCurColorHex=function(){return D};this.getCurColorRgba=
function(){return{r:H.r,g:H.g,b:H.b,a:G}};this.getCurAlpha=function(){return G};this.getAlphaFig=function(){return E?t:!1};this.getPopup=function(){return p};this.getSize=function(){return u};this.getColorSaver=function(a){for(var b=0;b<=m.length-1;++b)if(!a&&m[b].selected||m[b].align==a)return m[b].rgb=Z(m[b].color),m[b].hsv=ka(m[b].rgb.r,m[b].rgb.g,m[b].rgb.b),m[b]};this.setColorSaver=function(a){if(!a)return!1;for(var b=0;b<=m.length-1;++b)if(m[b].align==a)return pa(b),m[b]};this.updateView=function(a){if(!e)return!1;
a&&(h.imageData=null,Y=y.imageData=null);L=!1;da();M();return!0};this.resize=function(a,b){if(!e)return!1;if(a==u&&!b)return!0;L=!1;h.imageData=null;Y=y.imageData=null;u=a;da();g.setColorByHex(!1);return!1};this.syncSize=function(a){if(!Q)return!1;(a=S(Q))&&g.resize(a);return!1};this.setMethod=function(a){a||(a="triangle","triangle"==B&&(a="quad"));if(a==B||"quad"!=B&&"triangle"!=B)return!1;B=a;"quad"==B&&(y=ga());"triangle"==B&&(y=ha());g.resize(u,!0);k.setmethod&&(0,k.setmethod)(g,B);return!0};
this.destroy=function(){if(!g)return!1;0<C.curType&&(KellyColorPicker.cursorLock=!1,C.initStandartCursor());A&&(q(document,"mouseup","action_process_"),q(document,"mousemove","action_process_"),q(document,"touchend","action_process_"),q(document,"touchmove","action_process_"),A=!1);p.tag&&q(r,"click","popup_");r&&(q(r,"click","input_edit_"),q(r,"change","input_edit_"),q(r,"keyup","input_edit_"),q(r,"keypress","input_edit_"));KellyColorPicker.popupEventsInclude&&P.popup_close_click&&(KellyColorPicker.activePopUp&&
KellyColorPicker.activePopUp.popUpClose(!1),q(document,"click","popup_close_"),q(window,"resize","popup_resize_"),KellyColorPicker.popupEventsInclude=!1);h.imageData=null;v=Y=y.imageData=null;F&&F.parentNode&&F.parentNode.removeChild(F);Q&&q(window,"resize","canvas_");oa();g=null};(function(a){var b="",c="";void 0!==a.alpha_slider&&(a.alphaSlider=a.alpha_slider);void 0!==a.input_color&&(a.inputColor=a.input_color);void 0!==a.input_format&&(a.inputFormat=a.input_format);a.input&&"object"!==typeof a.input?
(a.input=document.getElementById(a.input),r=a.input):"object"===typeof a.input&&(r=a.input);void 0!==a.changeCursor&&(sa=a.changeCursor);void 0!==a.alpha&&(G=a.alpha);void 0!==a.alphaSlider&&(E=a.alphaSlider);void 0!==a.inputColor&&(na=a.inputColor);void 0!==a.inputFormat&&(ma=a.inputFormat);a.userEvents&&(k=a.userEvents);a.place&&"object"!==typeof a.place&&(c=a.place,a.place=document.getElementById(a.place));a.place?F=a.place:r?(p.tag=document.createElement("div"),p.tag.className="popup-kelly-color",
a.popupClass?p.tag.className=a.popupClass:(p.tag.className="popup-kelly-color",p.tag.style.position="absolute",p.tag.style.bottom="0px",p.tag.style.left="0px",p.tag.style.display="none",p.tag.style.backgroundColor="#e1e1e1",p.tag.style.border="1px solid #bfbfbf",p.tag.style.boxShadow="7px 7px 14px -3px rgba(0,0,0,0.24)",p.tag.style.borderTopLeftRadius="4px",p.tag.style.borderTopRightRadius="4px",p.tag.style.borderBottomLeftRadius="4px",p.tag.style.borderBottomRightRadius="4px",p.tag.style.padding=
"12px",p.tag.style.boxSizing="content-box"),F=p.tag,document.getElementsByTagName("body")[0].appendChild(p.tag),z(r,"click",function(a){return g.popUpShow(a)},"popup_")):b+='| "place" ('+c+") not not found";c=!1;a.color?c=N(a.color):r&&r.value&&(c=N(r.value));c&&(D=c.h,E&&(G=c.a));!a.method||"triangle"!=a.method&&"quad"!=a.method||(B=a.method);ta()||(b+=" | cant init canvas context");a.resizeWith&&("object"!==typeof a.resizeWith&&"boolean"!==typeof a.resizeWith&&(a.resizeWith=document.getElementById(a.resizeWith)),
Q=!0===a.resizeWith?n:a.resizeWith,a.resizeSide&&(aa=a.resizeSide),Q&&(S(Q)&&(a.size=S(Q)),z(window,"resize",function(a){return g.syncSize(a)},"canvas_")));a.size&&0<a.size&&(u=a.size);b?"undefined"!==typeof console&&console.log("KellyColorPicker : "+b):("quad"==B&&(y=ga()),"triangle"==B&&(y=ha()),r&&(b=function(a){a=a||window.event;a.target||(a.target=a.srcElement);g.setColorByHex(a.target.value,!0)},z(r,"click",b,"input_edit_"),z(r,"change",b,"input_edit_"),z(r,"keyup",b,"input_edit_"),z(r,"keypress",
b,"input_edit_")),a.colorSaver&&(W("left",!0),W("right")),a.methodSwitch&&T(),ba(),da(),g.setColorByHex(!1))})(ca)}KellyColorPicker.cursorLock=!1;KellyColorPicker.activePopUp=!1;KellyColorPicker.popupEventsInclude=!1;KellyColorPicker.attachToInputByClass=function(ca,T){for(var W=[],S=document.getElementsByClassName(ca),N=0;N<S.length;N++)T?T.input=S[N]:T={input:S[N],size:150},W.push(new KellyColorPicker(T));return W};
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
a.Cbutton {
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
.button {
color: aliceblue;
border-style: solid;
border-radius: 20px;
border-width: 3px;
padding: 4px 10px;
text-align: center;
text-decoration: none;
display: inline-block;
font-size: 22px;
margin: 0px 6px;
cursor: pointer;
background-color: black;
vertical-align: super;
}
)=====";

const char colorJS[] PROGMEM = R"=====(
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
    setTimeout(function(){WebSocketEnable = 1;sliderSender();},40)
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
    setTimeout(function(){WebSocketEnable = 1;ColorSender(self);},40)
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
)=====";

const char indexHTML[] PROGMEM = R"=====(
<!DOCTYPE html><html><head><meta name="viewport" content="width=device-width, initial-scale=0.8 user-scalable=no">
<meta charset="UTF-8">
<title>Color FixtureName</title>

<link href="css.css" rel="stylesheet" type="text/css">
<link rel="ICON" type="image" href="http://rbwork.fr/img/Icone.ico" />
<style type="text/css">
</style>
</head>
<body>
<a href="/" class="Cbutton back">Home</a>
<a href="/rainbow" class="Cbutton back" style="top: 100px;">Rainbow</a>
<section>
    <h1>Color FixtureName</h1>
</section>

<canvas id="picker"></canvas><br>
<input id="color" value="rgb(0, 0, 0)">
<section>
  <div class="block">
    <h1>Brightness </h1><h1 id="brightV"> 50</h1><br>
    <input oninput="chgSlider()" class="slider" id="bright" type="range" min="0" max="255" value="50" step="1">
  </div>
  <div class="block">
    <h1>Pulse </h1><h1 id="pulseV">5s</h1><button onclick="PulseSync(true)" class="button">Sync</button><button onclick="PulseSync(false)" class="button">UnSync</button><br>
    <input oninput="chgSlider()" class="slider" id="pulse" type="range" min="0" max="30" value="0" step=".1">
  </div>
</section>
<section>
  <a onclick="coloroff()" class="Cbutton">Disable Color</a>
</section>

%syncSection%

<div onclick="clearbox()" id="popbox" class="pop" style="display: none;">
  <h2 id="poptext">Universe</h2>
</div>

<script src="colorpicker.min.js" type="text/javascript"></script>
<script src="color.js" type="text/javascript"></script>

</body></html>

)=====";
