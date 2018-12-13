package main

import (
	"golang.org/x/tour/wc"
	"strings"
	"fmt"
)

func WordCount(s string) map[string]int {
	wo := strings.Fields(s)
	c := make(map[string]int, len(wo))
	for _, w := range wo {
	  c[w] += 1
	}
	return c
}

func WordCount_1(s string) map[string]int {
	m := make(map[string]int)
	words := strings.Split(s, " ")
	for _, v := range words {
		_, ok := m[v]

		if !ok {
			m[v] = 1
		} else {
			m[v] += 1
		}
	}
	return m
}

func main() {
	wc.Test(WordCount)
	fmt.Println("--------------------------------------------------")
	wc.Test(WordCount_1)
}