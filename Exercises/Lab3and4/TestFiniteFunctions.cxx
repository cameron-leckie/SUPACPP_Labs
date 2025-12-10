#include <iostream>
#include "FiniteFunctions.h"
#include "ReadWrite.h"
#include "ChildFunctions.h"

using namespace std;

int main(){

    vector<vector<double>> data2D = read("Outputs/data/MysteryData21212.txt", false);
    vector<double> data1D;
    double temp;
    for (int i = 0; i<data2D.size(); i++){
        data1D.push_back(data2D[i][0]);
    }

    FiniteFunction func(-10,10,"out");

    func.printInfo();
    func.plotData(data1D,100);
    func.plotFunction();

    cout << "Function 1 completed, moving to normal \n \n";

    Normal funcNorm(-10,10,-1,2,"outNorm"); // Correct Function
    funcNorm.printInfo();
    funcNorm.plotData(data1D,100);
    funcNorm.plotFunction();

    cout << "Function 2 completed, moving to Cauchy-Lorentz \n \n";

    CauchyLorentz funcCL(-10,10,1.5,-1,"outCL");
    funcCL.printInfo();
    funcCL.plotData(data1D,100);
    funcCL.plotFunction();

    cout << "Function 3 completed, moving to Crystal Ball \n \n";
    
    CrystalBall funcCB(-10,10,1,5,-1,1.5,"outCB");
    funcCB.printInfo();
    funcCB.plotData(data1D,100);
    funcCB.plotFunction();    
}