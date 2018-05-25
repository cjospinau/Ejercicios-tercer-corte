#include <iostream>
#include <Eigen/Dense>

int main()
{
  Eigen::Matrix3f A;
  Eigen::Matrix3f I;
   A << 4,-2,1,  3,6,-4,  2,1,8;
   I << 1,0,0, 0,1,0, 0,0,1 ;
   std::cout << "Here is the matrix A:\n" << A << std::endl;
   std::cout << "Here is the vector I:\n" << I << std::endl;
   Eigen:: Matrix3f x = A.colPivHouseholderQr().solve(I);
   std::cout << "The solution is:\n" << x << std::endl;
}
