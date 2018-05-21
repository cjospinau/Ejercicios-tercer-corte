#include <iostream>
#include <vector>
#include <cmath>

int main(){
  std::vector<double> a(9); 
  a[5] = 1;
  a[9] = 3*a[5];
  a[0] = 3*a[9] - a[9]/a[5];
  a[3] = (a[0] + a[9])/a[5];

 std::cout << a[3] << std::endl;
 return 0; }
