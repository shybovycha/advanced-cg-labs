// Anisimov S.Y. 1998 for PMG

var yes_color_m=0;

if ((navigator.appName.indexOf('Microsoft')>=0) && (parseInt(navigator.appVersion) >= 4))
	yes_color_m=1;

function event_over
	( obj, txt )
{
	if ( yes_color_m==1 ) obj.style.color = 0x0000FF;
	//window.status=txt;
	return false;
}

function event_out
	( obj )
{
	if ( yes_color_m==1 ) obj.style.color = 0xD621AD;
	//window.status="";
	return false;
}

function getCookie(name) {
    var arg = name+"=";
    var arglength=arg.length;
    var cookielength=document.cookie.length;
    var i=0;
    while(i<cookielength) {
        var valStart=i+arglength;
        if(document.cookie.substring(i,valStart)==arg) {
            var end=document.cookie.indexOf (";",valStart);
            if(end==-1) end=document.cookie.length;
            return unescape(document.cookie.substring(valStart,end));
        }
        i=document.cookie.indexOf(" ",i)+1;
        if(i==0) break;
    }
    return null;
}

var browser = navigator.appName;
var browserNum = parseInt(navigator.appVersion);
var N4 = false;
var N6 = false;
var IE = false;

var layerRef;
var endLayerRef;
var styleRef;
var yes_ns;

if ((browser == "Netscape") && (browserNum < 5))
{
	// Netscape 4.x
	layerRef = "document.layers['";
	endLayerRef = "']";
	styleRef = "";
	N4 = true;
	yes_ns=true;
}
else if ((browser == "Netscape") && (browserNum >= 5))
{
	// Netscape 6
	layerRef = "document.getElementById('";
	styleRef = ".style";
	endLayerRef = "')";
	N6 = true;
	yes_ns=true;
}
else
{
	// Internet Explorer
	layerRef = "document.all['";
	endLayerRef = "']";
	styleRef = ".style";
	IE = true;
	yes_ns=false;
}

function form_print
	( )
{
	var value=getCookie("NeHePrint");
	var flag=0;
	var w;
		
	if ( value!=null && value=="Y" ) flag=1;
	
	if ( flag==1 )
	{
		if ( yes_ns ) w="'95%'";
		else w="'100%'";
	}
	else
	{
		if ( yes_ns ) w="'1000px'";
		else w="'1000px'";
	}
	if ( yes_ns==0 )
		eval(layerRef + 'top' + endLayerRef + styleRef + ".width = " + w);
	else		
		if ( flag==1 ) eval(layerRef + 'top' + endLayerRef + styleRef + ".width = '97%'");
	eval(layerRef + 'head' + endLayerRef + styleRef + ".width = " + w);
	eval(layerRef + 'main' + endLayerRef + styleRef + ".width = " + w);
	eval(layerRef + 'end' + endLayerRef + styleRef + ".width = " + w);
}

