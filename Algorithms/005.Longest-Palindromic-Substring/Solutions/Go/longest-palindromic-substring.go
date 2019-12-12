package main

import (
	"fmt"
	"os"
)

func getTheLengthOfPossiblePalindrome(s string, left int, right int) int {

	var L = left
	var R = right
	lenOfString := len(s)
	for L >= 0 && R < lenOfString && s[L] == s[R] {
		L = L - 1
		R = R + 1
	}
	return R - L - 1

}

func longestPalindrome(s string) string {

	/*
		for i, _ := range s
		 {
			//c := string(r)

			c := string(s[i])
			fmt.Println(i, c)

		}*/

	lenOfString := len(s)

	if lenOfString == 0 {
		return s
	}

	var i int
	var start, end int
	for i = 0; i < lenOfString; i++ {
		//fmt.Println(string(s[i]))
		len1 := getTheLengthOfPossiblePalindrome(s, i, i)
		len2 := getTheLengthOfPossiblePalindrome(s, i, i+1)
		//fmt.Println(i, len1, len2)
		var length int
		if len1 > len2 {
			length = len1
		} else {
			length = len2
		}
		if length > (end - start + 1) {
			start = i - (length-1)/2
			end = i + length/2
		}
	}

	newString := []rune(s)
	palindromeString := string(newString[start : end+1])

	return palindromeString
}

func main() {
	if len(os.Args) < 2 {
		return
	}
	//fmt.Println(os.Args[1])
	palindrome := longestPalindrome(os.Args[1])
	fmt.Println(palindrome)
}
