package main

import "fmt"

func min(a, b int) int {
	if a > b {
		return b
	}

	return a
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
func median(a []int, b []int) float32 {
	n := len(a)
	m := len(b)
	if n > m {
		return median(b, a)
	}

	k := (n + m - 1) / 2
	l := 0
	r := min(n, k)
	for l < r {
		midA := (l + r) / 2
		midB := k - midA

		if k > midB || a[midA] < b[midB] {
			l = midA + 1
		} else {
			r = midA
		}
	}

	x1 := 0
	if l > 0 {
		x1 = a[l-1]
	}
	x2 := -1
	if (k - l) > 0 {
		x2 = a[k-l]
	}

	x := max(x1, x2)

	if (n+m)&1 == 1 {
		return float32(x)
	}

	y1 := 1000
	if l < n {
		y1 = a[l]
	}
	y2 := 1000
	if (k - l + 1) < m {
		y2 = b[k-l+1]
	}

	y := min(y1, y2)

	return float32((x + y) / 2.0)
}

func main() {

	a := []int{1, 2, 3}
	b := []int{2, 3, 4, 5, 6, 7, 8, 9, 10}
	fmt.Println(median(a, b))
}
