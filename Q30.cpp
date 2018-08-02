#include <iostream>

int fp(int n) {
    return n*n*n*n*n;
}

int main() {
    int sum = 0;
    for (int i = 2; i <= 355000; i++) { //=~9^5
        int sum_of_5th_power_of_digits = 0;
        int n = i;
        do {
            sum_of_5th_power_of_digits += fp(n % 10);
            n /= 10;
        } while(n != 0);
        if (sum_of_5th_power_of_digits == i) sum += i;
    }
    std::cout << sum << '\n';
}
