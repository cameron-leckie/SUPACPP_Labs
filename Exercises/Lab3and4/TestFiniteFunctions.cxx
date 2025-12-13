#include <iostream>
#include "FiniteFunctions.h"
#include "ReadWrite.h"
#include "ChildFunctions.h"

using namespace std;

int main(){

    double minVal = -100;
    double maxVal = 100;
    uint intervals = 1000;
    uint samples = 100000;
    uint seed = 9999;
    double std = 2;

    vector<vector<double>> data2D = read("Outputs/data/MysteryData21212.txt", false);
    vector<double> data1D;
    double temp;
    for (int i = 0; i<data2D.size(); i++){
        data1D.push_back(data2D[i][0]);
    }

    FiniteFunction func(minVal,maxVal,"out");
    func.printInfo();
   // func.plotData(data1D,intervals);
    vector<double> new_data = func.metropolis(samples,std,seed);
    write(new_data,"./Outputs/data/SampledData1.txt");
    func.plotData(new_data,intervals);
    func.plotFunction();




    cout << "Function 1 completed, moving to normal \n \n";

    Normal funcNorm(minVal,maxVal,-1,2,"outNorm"); // Correct Function
    funcNorm.printInfo();
  //  funcNorm.plotData(data1D,intervals);
    new_data = funcNorm.metropolis(samples,std,seed);
    write(new_data,"./Outputs/data/SampledData2.txt");
    funcNorm.plotData(new_data,intervals);
    funcNorm.plotFunction();



    cout << "Function 2 completed, moving to Cauchy-Lorentz \n \n";

    CauchyLorentz funcCL(minVal,maxVal,1.5,-1,"outCL");
    funcCL.printInfo();
   // funcCL.plotData(data1D,intervals);
    new_data = funcCL.metropolis(samples,std,seed);
    write(new_data,"./Outputs/data/SampledData2.txt");
    funcCL.plotData(new_data,intervals);
    funcCL.plotFunction();



    cout << "Function 3 completed, moving to Crystal Ball \n \n";
    
    CrystalBall funcCB(minVal,maxVal,1,5,-1,1.5,"outCB");
    funcCB.printInfo();
    //funcCB.plotData(data1D,intervals);
    new_data = funcCB.metropolis(samples,std,seed);
    write(new_data,"./Outputs/data/SampledData2.txt");
    funcCB.plotData(new_data,intervals);
    funcCB.plotFunction();    
    




}