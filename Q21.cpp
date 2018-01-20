#include <iostream>

int d(int n) {
        int sum = 1;
        for (int i = 2; i<n; i++) {
                if (n % i == 0) {
                        sum+=i;
                }
        }
        return sum;
}

int main() {
        int sum = 0;
        int pass;
        for (int i = 2; i <10000; i++) {
                if (i == pass) continue;
                int a = d(i);
                int b = d(a);
                if (b == i && a != i) {
                        pass = a;
                        std::cout << "d(" << i << ")=" << a << "\t & \t" << "d(" << a << ")=" << i << '\n';
                        sum += i;
                        sum += a;
                }
        }
        std::cout << "\nSum:\t" << sum << '\n';
}
