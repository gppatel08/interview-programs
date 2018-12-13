package main
import (
	"fmt"
	"os"
	"os/exec"
	"syscall"
)
//docker run <container> cmd args
//go run main.go run cmd args
//Example: go run container_from_scratch_in_go.go run print container camp
func main() {
	switch os.Args[1] {
		case "run":
			run()
		default:
			panic("what??")
	}
}

func run() {
	fmt.Printf("running %v\n", os.Args[2:])
	cmd := exec.Command(os.Args[2], os.Args[3:]...)
	cmd.Stdin = os.Stdin
	cmd.Stdout = os.Stdout
	cmd.Stderr = os.Stderr
	cmd.SysProcAttr = &syscall.SysProcAttr{
		//Cloneflags: syscall.CLONE_NEWWTS,
		//UidMappings: []syscall.SysProcIDMap{100},
	}
	
	must(cmd.Run())
}

func must(err error) {
	if err != nil {
		panic(err)
	}
}