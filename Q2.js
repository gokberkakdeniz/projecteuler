function* fibonacci() {
  let [fn1, fn2] = [0, 1]
  while (true) {
		[fn1, fn2] = [fn2, fn1 + fn2]
    yield fn1
  }
}

var fs_filtered = [];
for (let x of fibonacci()) {
	if (x % 2 == 0) {
		fs_filtered.push(x)
	}
	if (x >= 4000000) {
			break
	}
}
fs_filtered_sum = fs_filtered.reduce((a, b) => a+b, 0)
console.log(fs_filtered_sum)
