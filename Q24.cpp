#include <iostream>
#include <string>

int get_number(bool array[], int d) {
    int used_digit_count = 0;
    for (int i = 0; i < 10; i++) {
        if (!array[i]) {
            used_digit_count++;
            if (used_digit_count == d+1) {
                array[i] = true;
                return i;
            }
        }
    }
}

std::string nth_lexicographic_permutation_of_digits(int n) {
    int factorials[10] = {1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800};
    int index = 0;
    std::string number = "";
    bool is_used[10] = {false};
    for (int i = 8; i >= 0; i--) {
        if (index > n) break;
        int d = 0;
        while (true) {
            if (index + factorials[i] <= n-1) {
                d++;
                index += factorials[i];
            } else {
                break;
            }
        }
        d = get_number(is_used, d);
        number += std::to_string(d);
        d = 0;
    }
    for (int i = 0; i < 10; i++) {
        if (is_used[i] == false) return number + std::to_string(i);
    }
}

int main() {
    std::cout << nth_lexicographic_permutation_of_digits(1000000) << '\n';
}
