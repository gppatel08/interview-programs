/*
go run hello.go
You can point your browser to http://localhost:9999/world
*/

package main
    
import (
    "github.com/hoisie/web"
)
    
func hello(val string) string { return "hello " + val } 
    
func main() {
    web.Get("/(.*)", hello)
    web.Run("0.0.0.0:9999")
}

//Control Panel\System and Security\System