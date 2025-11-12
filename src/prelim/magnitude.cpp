#include <iostream>
#include <cmath>

int main(){
    double x;
    double y;
    double magnitude;

    std::cout << "Input vector compoents x and y in format _ _" << std::endl;

    std::cin >> x >> y;
    
    magnitude = sqrt(x*x + y*y);

    std::cout << "Magnitude = " << magnitude << std::endl;
    return 0;
}
