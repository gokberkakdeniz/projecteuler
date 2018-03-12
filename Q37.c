#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

int *ESieve(int bound) {
  int numbers[bound-2];
  int i, j, prime_count=0;
  for(i=0; i<bound-2; i++)
    numbers[i]=i+2;
  for(i=0; i<bound-2; i++) {
    if (numbers[i] != 0){
      prime_count++;
      for (j=numbers[i]+i; j<bound-2; j+=numbers[i])
        numbers[j]=0;
    }
  }
  int *primes_p = malloc((prime_count+1)*sizeof(int));
  if (!primes_p)
    return NULL;

  i=1;
  primes_p[0]=prime_count+1; //array size
  for(j=0; j<bound-2; j++)
    if(numbers[j]!=0)
      primes_p[i++]=numbers[j];

  return primes_p;
}

int digit_count(int number) {
  int i, j=1;
  for(i = 10;; i*=10, j++)
    if (number < i)
      return j;
}

int is_prime(int number, int primes_list[]) {
  int primes_list_length = primes_list[0];
  if (primes_list[primes_list_length-1] < number)
    return -1;

  int start_index=0, stop_index=primes_list_length, index;
  index = (start_index+stop_index)/2;
  while (stop_index - start_index > 1) {
    if (primes_list[index] > number) {
      stop_index = index;
      index = (index + start_index)/2;
    } else if (primes_list[index] < number) {
      start_index = index;
      index = (index + stop_index)/2;
    } else {
      return true;
    }
  }
  return false;
}

int is_truncation_prime(int number, int primes_list[]) {
  //from right to left
  int number_copy=number;
  while (number != 0){
    number = (number - number % 10)/10;
    if (!is_prime(number, primes_list) && number !=0)
      return false;
  }
  //from left to right
  number=number_copy;
  int number_of_digits = digit_count(number);
  int modulo=10, i;
  for(i=2; i < number_of_digits; i++)
    modulo*=10;

  while (number != number % 10) {
    number = number % modulo;
    modulo/=10;
    if (!is_prime(number, primes_list))
      return false;
  }
  return true;
}

int main() {
  int truncatable_primes_count = 0, truncatable_primes_sum = 0, i;
  int *primes_list = ESieve(1000000);
  for (i = 5; i < primes_list[0]; i++) {
    if (truncatable_primes_count>11)
      break;
    if (is_truncation_prime(primes_list[i], primes_list)) {
      truncatable_primes_sum += primes_list[i];
      printf("%d ", primes_list[i]);
      truncatable_primes_count++;
    }
  }
  printf("\n%d\n", truncatable_primes_sum);
  return 0;
}
