#include <iostream>

int letter_count(int n) {
        int digits[] = {4, 3, 3, 5, 4, 4, 3, 5, 5, 4, 3, 6, 6, 8, 8, 7, 7, 9, 8, 8, 6, 6, 5, 5, 5, 7, 6, 6, 7, 8}; // 1..20, 20-30-40..90, 100, 1000
        if (n < 21) {
                return digits[n];
        } else if (n < 100) {
                return digits[18+n/10] + ( n % 10 == 0 ? 0 : digits[n % 10]);
        } else if (n != 1000 && n % 100 == 0) {
                return digits[n/100] + digits[28];
        } else if (n < 1000) {
                return digits[n/100] + digits[28] + letter_count(n % 100) + 3; // x(hundred)y(and)z
        } else {
                return digits[1] + digits[29];
        }
}

int main() {
        int sum = 0;
        for (int i=1; i <= 1000; i++) {
                sum += letter_count(i);
        }
        std::cout << sum << '\n';
        return 0;
}
