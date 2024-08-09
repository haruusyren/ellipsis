
#include <iostream>
#include <cmath>
#include <chrono>

using namespace std;

int main() {
  /*
   * Calculates radii a and b based on perimeter and aspect ratio
   * Made using Newton's Method and https://mpewsey.github.io/2021/11/07/minimum-distance-between-ellipse-and-point.html
   
   * P: Perimeter (≈ π * ( 3(a + b) - √( (3a + b)(a + 3b) ) )
   * AR: Aspect Ratio
   * a: Major radius (Long axis);
   * b: Minor radius (Short axis);
  */
  
  double P;
  double AR;
  
  cout << "Perimeter: ";
  cin >> P;
  cout << "Aspect ratio: ";
  cin >> AR;
  
  auto start = chrono::high_resolution_clock::now();
  
  double b = P / (2 * M_PI * (1 + AR));
  double difference = 1;
  const double tolerance = 1e-6;
  const double derivative = M_PI * (3 * (AR + 1) - (9 * AR + 1) / (2 * sqrt((3 * AR + 1) * (AR + 3))));
    
  while (difference > tolerance) {
    double a = AR * b;
    double approximation = M_PI * (3 * (a + b) - sqrt((3 * a + b) * (a + 3 * b)));
    
    double b_ = b - (approximation - P) / derivative;
    difference = fabs(b_ - b);
    b = b_;
  }
  
  double a = AR * b;

  cout << "Major radius (a): " << a << endl;
  cout << "Minor radius (b): " << b << endl;
  
  auto end = chrono::high_resolution_clock::now();
  chrono::duration<double, milli> duration = end - start;
  
  cout << "Program completed in " << duration.count() << "ms";
    
  return 0x45;
}
    