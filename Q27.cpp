#include <iostream>
#include <vector>

int f(int n, int a, int b) {
    return n*n+a*n+b;
}

bool is_prime(std::vector<long> primes, long number) {
    //https://www.geeksforgeeks.org/binary-search/
    long r = primes.size()-1;
    long l = 0;
    while (l <= r) {
        int m = l + (r-l)/2;
        // Check if x is present at mid
        if (primes[m] == number) return true;
        // If x greater, ignore left half
        if (primes[m] < number) l = m + 1;
        // If x is smaller, ignore right half
        else r = m - 1;
    }
    return false;
}

std::vector<long> ESieve(long upper_limit) {
    std::vector<long> numbers;
    for(long n = 2; n <= upper_limit; n++) numbers.push_back(n);

    for (long i = 0; i < upper_limit; i++) {
        if (numbers[i]!=0) {
            for(long j = i+numbers[i]; j < upper_limit; j+=numbers[i]) {
                numbers[j] = 0;
            }
        }
    }
    std::vector<long> primes;
    for(long i = 0; i < upper_limit; i++) {
        if (numbers[i]!=0) {
            primes.push_back(numbers[i]);
        }
    }
    return primes;
}

int main() {
    std::vector<long> primes = ESieve(87400);
    int current = 0, max = 0, product_of_coefficients;
    for (int a = -999; a <= 999; a++) {
        for (int b = -1000; b <= 1000; b++) {
            current = 0;
            for (int i = 0; is_prime(primes, f(i, a, b)); i++) {
                current++;
                if (current > max) {
                    max = current;
                    product_of_coefficients = a*b;
                }
            }
        }
    }

    std::cout << product_of_coefficients << '\n';
}
