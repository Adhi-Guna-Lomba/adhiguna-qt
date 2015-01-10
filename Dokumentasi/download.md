#adhiguna Download API.

- `setTarget(string): void`
- `save (string): Void`
- `downloadFinished(QNetworkReply *data) : void`
- `download(): void`
- `downloadProgress(qint64 recieved, qint64 total): void`

## How To use Download API ##
<html>
<head>
<script>type="text/javascript" src="qrc:///js/jquery.js"> </script>
<script> type="text/javascript" src="qrc:///js/adhiguna.js"></script>
<script>
	
adhiguna.widgetSize(550,400);
$(document).ready (function(){
$(".meter > span ").each(function(){
			$(this)
				.data ("origwidth",$(this).width())
				.width (0)
				.animate ({
					width: $(this).data("origwidth")
				}, 1200);
			});
});
//use slot
var url= "http://dinacom.org/peserta/asset/template-apps.docx";
adhiguna.download(url,"/home/igos/dekstop/");
//use adhiguna signal
adhiguna.downloadProgress,conect(function(r,s){
		$(".r").text (r);
		$(".s").text (s);
	var presentation = (r/s)*100;
	$(".p").text(parseint(persentation)+"%");
	$("#progress").css('width',parseint(persentation)+"%");
});	
</script>
</head>
<body>
<h2>adhiguna downloadProgress()</h2>
download file http://dinacom.org/peserta/asset/template-apps.docx:
<div class="meter" id="meter"><span id="progress"></span> </div>
<br>received:<div class="r"></div>
<br>total:<div class="s"></div>
<br>presentation :<div class="p">0%</div>
</body>
</html>
