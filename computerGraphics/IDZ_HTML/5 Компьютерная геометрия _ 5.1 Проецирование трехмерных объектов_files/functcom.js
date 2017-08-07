var layerStyleRef = null;
    layerRef = null;
    styleSwitch = null;
    winOpen = true;
    audio = false;
var tagWin;

function lnk(l) {
     window.open(l);
     }


	 mouseX=0;
mouseY=0;

	 
function init() {
	Name = navigator.appName.substring(0,1);
	Version = navigator.appVersion.substring(0,1);
	Nflag = 0;
	if ((Name == "N" && (Version > 2)) || ((Name == "M") && (Version > 3))) {
		Nflag = 1;
		about1=new Image();
		about2=new Image();
		about1.src="ris/about.gif";
		about2.src="ris/about_a.gif";
		content1=new Image();
		content2=new Image();
		content1.src="ris/content.gif";
		content2.src="ris/content_a.gif";
		control1=new Image();
		control2=new Image();
		control1.src="ris/control.gif";
		control2.src="ris/control_a.gif";
		gloss1=new Image();
		gloss2=new Image();
		gloss1.src="ris/gloss.gif";
		gloss2.src="ris/gloss_a.gif";
		author1=new Image();
		author2=new Image();
		author1.src="ris/author.gif";
		author2.src="ris/author_a.gif";
		help1=new Image();
		help2=new Image();
		help1.src="ris/help.gif";
		help2.src="ris/help_a.gif";
		}
  if (navigator.appName == "Netscape") {
    layerStyleRef="layer.";
    layerRef="document.layers";
    styleSwitch="";
  }else{
    layerStyleRef="layer.style.";
    layerRef="document.all";
    styleSwitch=".style";
  }
  // =======================================================================================
	if (document.all){
	  document.onmousemove=setmousepos;
	} else {
	  window.captureEvents(Event.MOUSEMOVE);
	  window.onmousemove=setmousepos;
	}
}

// =======================================================================================
function setmousepos(e) {
  if (!e) e=window.event;
  if (e.pageX||e.pageY) {
    mouseX=e.pageX;
    mouseY=e.pageY;
  } else if (e.clientX||e.clientY) {
    mouseX=e.clientX+(document.documentElement.scrollLeft||document.body.scrollLeft)-document.documentElement.clientLeft;
    mouseY=e.clientY+(document.documentElement.scrollTop||document.body.scrollTop)-document.documentElement.clientTop;
  }
}
// ======================================================================================
function getElementPosition(id) {
  var elem=document.getElementById(id);
  var w=elem.offsetWidth;
  var h=elem.offsetHeight;
  var l=0;                                             
  var t=0;
  while (elem) {
    l+=elem.offsetLeft;
    t+=elem.offsetTop;
    elem=elem.offsetParent;
  }
  return {"left":l,"top":t,"width":w,"height":h};
}
//========================================================================================
function switch_img(imgName, srcName) {	
  if (Nflag) {		
    document.images[imgName].src = eval(srcName + '.src');
  }	
}

function showLayer(layerName){
  eval(layerRef+'["'+layerName+'"]'+styleSwitch+'.visibility="visible"');
}


function upLayer(layerName,event){
  eval(layerRef+'["'+layerName+'"]'+styleSwitch+'.visibility="visible"');
  eval(layerRef+'["'+layerName+'"]'+styleSwitch+'.top ="'  + mouseY + 'px"');
}


function hideLayer(layerName){
  eval(layerRef+'["'+layerName+'"]'+styleSwitch+'.visibility="hidden"');
}

function changeLayer(layerName1, layerName2){
  hideLayer(layerName1);
  showLayer(layerName2);
}

function showIt(someURL) {
   if(tagWin.winOpen) {
	tagWin.document.location = someURL;
   } else {
	tagWin = window.open(someURL, "tagWin",
          "width=400,height=300,toolbar=no,scrollbars=yes");
//	tagWinOpen = true;   
   } 
}

function showWithSize(someURL, wid, hei) {
   if(tagWin && tagWin.openWin) {
	tagWin.location = someURL;	
	tagWin.focus();
   } else {
	tagWin = window.open(someURL, "tagWin",
          "width=" + wid + ",height=" + hei + 	  
          ",toolbar=no,scrollbars=yes,resizable=yes");
//	tagWinOpen = true;
   } 
}

function closeChild() {   
   if(tagWin.winOpen) {      
	tagWin.close();
   }
}

function showWin() {  
   if(tagWin && tagWin.winOpen) {
       alert("Window exist\n Location is" + tagWin.location);
   } else {    
       alert("Window don't exist");  
   }
}

function playAudio() {
   if(audio) {
      document.embeds[0].stop();
      audio = false;
   } else {
      document.embeds[0].play();
      audio = true;
   }
} 
