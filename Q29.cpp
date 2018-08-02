#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
#include <set>
using namespace boost::multiprecision;

int main() {
    std::set<cpp_int> numbers;
    int i = 0;
    for(int a = 2; a <= 100; a++) {
        for(int b = 2; b <= 100; b++) numbers.insert(pow(cpp_int(a), b));
    }
    std::cout << numbers.size() << '\n';
}
