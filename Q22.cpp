#include <iostream>
#include <fstream>
#include <string>
#define LENGTH 5163

bool is_pair_sorted(std::string first, std::string second) {
    int a = first.length();
    int b = second.length();
    int c = a > b ? a : b;
    for (int i = 0; i < a; i++) {
        if (first[i] < second[i]) {
            return true;
        } else if (first[i] > second[i]) {
            return false;
        }
    }
    return a > b ? false : true;
}

void bubble_sort_string(std::string array[], int length) {
    for (int i = 0; i < length -1; i++) {
        bool flag = true;
        for(int j = 0; j < length-i-1; j++) {
            if (is_pair_sorted(array[j], array[j+1]) == false) {
                std::string temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
                flag = false;
            }
        }
        if (flag) break;
    }
}

int get_char_point(std::string name) {
    int sum = 0;
    for (int i = 0; i < name.length(); i++) {
        sum += ((int)name[i])-64;
    }
    return sum;
}

int main() {
    std::ifstream input("Q22.txt", std::ios::in);
    std::string names[LENGTH];
    char c;
    int l=0;
    while(!input.eof()) {
      input.get(c);
      switch (c) {
        case '"':
          break;
        case ',':
          l++;
          break;
        default:
          names[l] += c;
      }
    }
    bubble_sort_string(names, LENGTH);
    int sum = 0;
    for (int i = 0; i < LENGTH; i++) {
        sum += (i+1) * get_char_point(names[i]);
    }
    std::cout << "Total score: " << sum << '\n';
}
