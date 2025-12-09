#include <iostream>
#include "FiniteFunctions.h"
#include "ReadWrite.h"

using namespace std;

int main(){
    FiniteFunction func(-5,5,"out");

    func.printInfo();
    //func.plotData;
    //func.plotFunction

}