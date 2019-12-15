package main

import (
	"fmt"
	"os"
)

var intMax = int32((^uint32(0) >> 1))
var intMin = ^intMax

func myAtoi(str string) int {
	var res int
	var strlen = len(str)
	if strlen == 0 {
		return 0
	}
	fmt.Println(str)
	var start bool
	var sign bool
	for _, c := range str {
		if (start == false) && (c == ' ') {
			continue
		} else if start == false && c == '+' {
			start = true
		} else if (start == false) && (c == '-') {
			start = true

			sign = true
		} else if c > '9' || c < '0' {
			break
		} else if (start == false) && (c >= '0' && c <= '9') {
			if sign == true {
				res = 0 - int(c-'0')
			} else {
				res = int(c - '0')
			}
			start = true
		} else if start == true && (c >= '0' && c <= '9') {
			if sign == true {
				if int32(res) < intMin/10 || (int32(res) == intMin/10 && c-'0' > 8) {
					res = int(intMin)
					break
				}
				res = res*10 - int(c-'0')
			} else {
				if int32(res) > intMax/10 || (int32(res) == intMax/10 && c-'0' > 7) {

					res = int(intMax)
					break
				}
				res = res*10 + int(c-'0')
			}
		}

	}
	return res
}

func main() {
	length := len(os.Args)
	if length < 2 {
		return
	}
	myAtoi(os.Args[1])
}
