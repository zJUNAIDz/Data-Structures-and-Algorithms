func leastInterval(tasks []byte, n int) int {
	var charMap [26]int
	for _, t := range tasks {
		charMap[t-'A']++
	}

}
