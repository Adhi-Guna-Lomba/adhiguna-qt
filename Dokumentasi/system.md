#adhiguna system API

- `cliOut(string) : string`
- `hash(string) : string`
- `desktopService(string) : void`
- `exec(string):void`
- `_out():void`
- `kill():void`

## How To use system API ##
```
<script>
		adhiguna.setDev(true);
		adhiguna.setDevRemote(8080);
		var sys = adhiguna.sys()
		$(function(){
			$('#req').click(function(){
				//init system module
				var sys = adhiguna.sys();
				var input = $('#inputval').val();
			$('#res').html(sys.cliOut(input));
			});
		})
</script>
```
