package main

import (
	"fmt"
	"os"
	"time"
)

func main() {
	fmt.Printf("PID: %d\n", os.Getpid())
	time.Sleep(time.Hour)
}
