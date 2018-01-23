#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;
int main() {
  cpp_int limit = pow(cpp_int(10), 999);
  cpp_int f1 = 1, f2 = 1, temp;
  int i=2;
  while (f2 <= limit) {
      i++;
      temp = f1;
      f1 = f2;
      f2 += temp;
  }
  std::cout << i << '\n';
}
