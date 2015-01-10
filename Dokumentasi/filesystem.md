#adhiguna filesystem

- `fileRemove(String) : bool`
- `fileWrite(String) : bool`
- `fileRead(String) : String`
- `appPath() : string`
- `homePath() : string`
- `dir(String) : bool`
- `isExist(String) : bool`
- `isDirectory(String) : bool`
- `isFile(String): bool`
- `isAbsolute(String) : bool`
- `isExecutable(String) : bool`
- `isSymlink(String) : bool`
- `isReadable(String) : bool`
- `isWritable(String) : bool`
- `copy(String) : bool`
- `openFileDialog() : string`
- `openDirDialog() : string`
- `list(String) : string`
- `info(String) : variant`

## How to use filesystem API ##
```
<script>
	var fs adhiguna.filesystem();
	function makedir (opt,path){
		var fs = adhiguna.filesystem();
		if (opt=='create'){
			adhiguna.showMessage('created');
			}
			else if (opt=='remove'){
				adhiguna.showMessage('remove');
				}
				fs.dir(opt,path);
				return fs;
			}
</script>
```
