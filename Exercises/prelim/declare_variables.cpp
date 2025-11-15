#include <iostream>
#include <cmath>

int main(){
    double x = 7.5;
    double y = 3.4;
    double magnitude;

    magnitude = std::sqrt(y*y + x*x);

    std::cout << "Magnitude of x=" << x <<" and y=" << y << " is " << magnitude << std::endl;
    return 0;   
}