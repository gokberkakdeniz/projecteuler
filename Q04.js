function isPalindrome(number) {
  number = number.toString()
  length = number.length
  for (let i = 0; i < Math.floor(length / 2); i++) {
    if (number[i] != number[length - i - 1]) {
      return false
    }
  }
  return true
}

list = []
for (let x = 999; x >= 100; x--) {
  for (let y = 999; y >= 100; y--) {
    if (isPalindrome(x*y)) {
      list.push(x*y)
    }
  }
}
max = Math.max(...list)
console.log(max)
