function largest_prime_factor(number) {
  let lpf;
  for (let i = 2; number != 1;i++) {
    if (number % i == 0) {
      lpf = i;
      number /= i;
    }
  }
  return lpf
}

console.log(largest_prime_factor(600851475143))
