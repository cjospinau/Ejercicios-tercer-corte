#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
// Resolviendo la ED del oscilador armónico

const double W = 2.98768765; // omega, in rad/s arbitrario

void euler(double ta, double tb, double h, std::vector<double> & y);
void rk4(double ta, double tb, double h, std::vector<double> & y);
double f(double t, const std::vector<double> & y, int id);

int main (void)
{
  const double N  = 2;
  const double TA = 0;
  const double TB = 16.4;
  const double H  = 0.01; //Paso del tiempo
  std::vector<double> y = {0.12, 0}; // {x0, v0} vector que va cambiando

  rk4(TA, TB, H, y);

  return 0;
}

/*void euler(double ta, double tb, double h, std::vector<double> & y)
{
  const int N = (tb-ta)/h;
  std::vector<double> yaux(y.size()); //para no utilizar los valores sobreescritos del vector y
  for (int nt = 0; nt < N; ++nt) {
    double t = ta + h*nt;
    std::copy(y.begin(), y.end(), yaux.begin());
    for(int id = 0; id < y.size(); ++id) {
      y[id] = y[id] + h*f(t, yaux, id); // euler
    }
    std::cout << t << "\t" << y[0] << "\t" << y[1] << std::endl;
  }
  }*/

void rk4(double ta, double tb, double h, std::vector<double> & y)
{
  std::vector<double> k1, k2, k3, k4, aux;
  k1.resize(y.size());
  k2.resize(y.size());
  k3.resize(y.size());
  k4.resize(y.size());
  aux.resize(y.size());

  const int N = (tb-ta)/h;
  for (int nt = 0; nt < N; ++nt) {
    double t = ta + h*nt;
    // k1
    for(int ii = 0; ii < y.size(); ++ii) {
      k1[ii] = h*f(t, y, ii);
    }
    // k2 aux
    for(int ii = 0; ii < y.size(); ++ii) {
      aux[ii] = y[ii] + k1[ii]/2;
    }
    //k2
    for(int ii = 0; ii < y.size(); ++ii) {
      k2[ii] = h*f(t + h/2, aux, ii);
    }
    // k3 aux
    for(int ii = 0; ii < y.size(); ++ii) {
      aux[ii] = y[ii] + k2[ii]/2;
    }
    //k3
    for(int ii = 0; ii < y.size(); ++ii) {
      k3[ii] = h*f(t + h/2, aux, ii);
    }
    // k4 aux
    for(int ii = 0; ii < y.size(); ++ii) {
      aux[ii] = y[ii] + k3[ii];
    }
    //k4
    for(int ii = 0; ii < y.size(); ++ii) {
      k4[ii] = h*f(t + h, aux, ii);
    }
    // write new y
    for(int ii = 0; ii < y.size(); ++ii) {
      y[ii] = y[ii] + (k1[ii] + 2*k2[ii] + 2*k3[ii] + k4[ii])/6.0;
    }
    std::cout << t << "\t" << y[0] << "\t" << y[1] << std::endl;
  }
}

double f(double t, const std::vector<double> & y, int id)//retorna las derivadas
{
  if (0 == id) {  //Derivada de la posición (Velocidad)
    return y[1];  
  }
  else if (1 == id) {  // Derivada de la velocidad (F)
    return -W*W*y[0] - 1.23*y[1]; //fuerza viscosa 
  }
  else {
    std::cerr << "ERROR!!!!!!!! Id does not exists -> " << id << std::endl;
    exit(1);
  }
}
