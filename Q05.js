n = 20;
prime_numbers = []

for (let i = 2; i <=n; i++) {
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

number = 1;
for (p of prime_numbers) {
  let current = 0, max = 0;
  for (let i = 2; i <=n; i++) {
    let j = i;
    while (j % p == 0) {
      if (j % p == 0) {
        current++;
        j/=p;
      }
    }
    max = max > current ? max : current
    current = 0
  }
  number *= p ** max
}
console.log(number)
