#include <iostream>

int main() {
  long long i, j, divisor_count=2;
  long long number;
  for (i = 1;divisor_count <=500;i++) {
    number = i*(i+1)/2;
    divisor_count = 2;
    for (j = 2; j < number; j++) {
      if (number % j == 0) divisor_count++;
    }
    //std::cout << number << " with " << divisor_count << std::endl;
  }
  std::cout << number << " with " << divisor_count << " divisors.";
}
