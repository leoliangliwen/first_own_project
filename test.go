package main

import (
	"fmt"
    "time"
)

func foo() {
    go func() {
        defer func() {
            fmt.Println("End Routine")
        }()
        time.Sleep(10 * time.Second)
        fmt.Println("Hello")
    }()
    time.Sleep(3 * time.Second)
	fmt.Println("End foo")
}

func main() {
    foo()
    time.Sleep(30 * time.Second)
}
