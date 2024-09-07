var height = document.getElementById("header-fixed").offsetHeight;
var content = document.getElementById("content")

if ( height >= 84) {
		if ( height >= 127) {
    		content.classList.add("content-two");
    		}
    	else {
    		content.classList.add("content-one");
    	}
    }