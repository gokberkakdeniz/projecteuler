#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;
using namespace std;
int main() {

  cpp_int number = 1;
  for (int i = 2; i <= 100; number*=i++);
  cpp_int sum = 0;
  while (number >=1) {
    sum+=number % 10;
    number/=10;
  }
  cout << sum << '\n';
}
