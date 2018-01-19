#include <iostream>
#include <iomanip>

unsigned long long collatz_sequence(unsigned long long n, unsigned long long * counter) {
        (*counter)++;
        // std::cout << '\r' << std::setw(2) << (*counter) << std::flush;
        if (n % 2 == 0) {
                return collatz_sequence(n/2, counter);
        } else if (n == 1) {
                return *counter;
        } else {
                return collatz_sequence(3*n+1, counter);
        }
}

int main() {
        unsigned long long i = 0, max_number = 0, max_counter = 0;
        unsigned long long counter = 0;
        unsigned long long *cp = &counter;
        for (i = 1; i <= 1000000; i++) {
          counter = 0;
          collatz_sequence(i, cp);
          if (max_counter < counter) {
            max_counter = counter;
            max_number = i;
          }

          std::cout << '\r' << std::setw(2) << i << "\t\t" << counter << "\t\t" << max_number << "\t\t" << max_counter << std::flush;
        }
        std::cout << '\r' << std::setw(2) << max_number << "\t\t" << max_counter << std::flush;
}
