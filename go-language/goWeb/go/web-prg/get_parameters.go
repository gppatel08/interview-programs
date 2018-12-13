/*
Getting parameters:
--------------------
Route handlers may contain a pointer to web.Context as their first parameter. 
This variable serves many purposes -- it contains information about the request, and it provides methods to control the http connection. 
For instance, to iterate over the web parameters, either from the URL of a GET request, or the form data of a POST request, 
you can access ctx.Params, which is a map[string]string:

visit http://localhost:9999/?a=1&b=2, you'll see the following printed out in the terminal:
		a 1
		b 2
*/

package main

import (
    "github.com/hoisie/web"
)
    
func hello(ctx *web.Context, val string) { 
    for k,v := range ctx.Params {
		println(k, v)
	}
}   
    
func main() {
    web.Get("/(.*)", hello)
    web.Run("0.0.0.0:9999")
}