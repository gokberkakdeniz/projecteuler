prime_numbers = []

for (let i = 2; prime_numbers.length != 10001; i++) {
  isPrime =  true;
  for (let j = 2; j*j <= i; j++) {
    if (i % j == 0) {
      isPrime = false
      break;
    }
  }
  if (isPrime) {
    prime_numbers.push(i)
  }
}

console.log(prime_numbers[10000])
