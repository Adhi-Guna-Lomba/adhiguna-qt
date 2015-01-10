#adhiguna Sql.

- `driver(string,string): bool`
- `query(string,string): Qvariant

## How to use API ##
```
var sql = adhiguna.sql();
$(document).ready (function(){
	var driver = sql.driver{"mysql","localhost:root:qazwsx:qt");
	var qry = sql.query("select * from peserta");
	if (driver) {
		$(".json").html(JSON.stringify(qry));
		var query =qry;
		var html ="";
		$("h1").html("status database connection:"+query.status);
		if(query.status){
			$.each(query.content,function(data){
				html +="No : "+this.no+"<br>";
				html +="Nama : "+this.nama+"<br>";
				html +="Alamat : "+this.alamat+"<br><hr>";
				});
			}
			$(".data").html(html);
		}
});
```


