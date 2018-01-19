#include <iostream>
#include <fstream>
#include <string>

#define LINE 100
int main() {
        int numbers[LINE][LINE] = {0};
        int i=0;
        std::ifstream input("Q67.txt");
        for(std::string line; getline(input, line); ++i) {
                std::string number;
                line += " ";
                int n=0;
                for(int c=0; line[c] != '\0'; c++) {
                        if(line[c] !=' ') {
                                number += line[c];
                        } else {
                                numbers[i][n++]=std::stoi(number, nullptr);
                                number="";
                        }
                }
        }

        for (int j = LINE-1; j > 0; j--) {
                for (int k = 0; k < j; k++) {
                        numbers[j-1][k] += numbers[j][k] > numbers[j][k+1] ? numbers[j][k] : numbers[j][k+1];

                }
        }
        std::cout << numbers[0][0] << '\n';
        return 0;
}
