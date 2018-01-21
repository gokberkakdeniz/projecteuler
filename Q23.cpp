#include <iostream>

enum Number { PERFECT, DEFICIENT, ABUNDANT};

int sum_of_proper_divisors(int n) {
    int sum = 1;
    for (int i = 2; i*i<=n; i++) {
        if (n % i == 0) {
            if (i == n/i) {
                sum +=i;
            } else {
                sum += i + n/i;
            }
        }
    }
    return sum;
}

Number typeofnumber(int n) {
    int m = sum_of_proper_divisors(n);
    if (n > m) {
        return DEFICIENT;
    } else if (n < m) {
        return ABUNDANT;
    } else {
        return PERFECT;
    }
}

int main() {
    int abundant_numbers[6965];
    for (int n = 1, i = 0; n <= 28123; n++) {
        if (typeofnumber(n) == ABUNDANT) {
            abundant_numbers[i++] = n;
        }
    }
    int sum = 28123*(28123+1)/2;
    for (int n = 1; n <= 28123; n++) {
        bool flag = true;
        for(int i = 0; flag && i < 6965 && abundant_numbers[i] < n; i++) {
            for (int j = i; j < 6965 && abundant_numbers[i]+abundant_numbers[j] <= n; j++) {
                if (abundant_numbers[i]+abundant_numbers[j]==n) {
                    sum -=n;
                    flag = false;
                }
            }
        }
    }
    std::cout << sum << '\n';
}
