#include <cmath>
#include <vector>
#include "CustomFunctions.h"


int main(){
    std::string inputfile = "input2D_float.txt"; // filename
    std::string errorfile = "error2D_float.txt"; // error data
						 
    // Read in data 
    std::vector<std::vector<double>> data = read(inputfile, true);
    std::vector<std::vector<double>> errortemp = read(errorfile, true);
    
    // Remove x error 
    std::vector<double> error;
    for (int i = 0; i < errortemp.size(); i++){
    	error.push_back(errortemp[i][1]);
    }

    int option = 0;
    while (option != 5){
	// Select option
        std::cout << std::endl;
        std::cout << "Please select an option by entering an integer:" << std::endl;
        std::cout << "  1 Print N lines from " << inputfile << std::endl;
        std::cout << "  2 Print the magnitude of the vectors in " << inputfile << std::endl;
        std::cout << "  3 Calcuate the line of best fit for the data in " << inputfile << std::endl;
	std::cout << "  4 Calculate x^y for all data points in " << inputfile << std::endl;
        std::cout << "  5 Exit" << std::endl;
        std::cin >> option;

	// Vector used for magnitude and powers function
        std::vector<double> outputData = {}; 

	// N rows to print
	int nRows = 0;
	std::vector<std::vector<double>> subdata;

        switch (option){
            case 1:
	        // Ask how many rows of data to be printed
                std::cout << "How many rows of " << inputfile << " do you want printed?" << std::endl;
                std::cin >> nRows;
            	nRows = abs(nRows);
	        // Prevent out of range
                if (nRows > data.size()) nRows = 5;   // prevent out-of-range
		subdata.assign(data.begin(), data.begin() + nRows);
                // Print data to terminal
                write(subdata,std::cout);
                // Write data to file
                write(subdata,"raw_data.txt");
                break;
            case 2:
                // Calculate magnitude
                outputData = magnitude(data);
		// Write to terminal and file
                write(outputData,std::cout);
		write(outputData,"magnitude.txt");
                break;
            case 3:
                // Fit Data
                fit_line(data,error);
                break;
	    case 4:
		// Powers
		for (int i = 0; i < data.size(); i++){
		    outputData.push_back(power(data[i][0],std::round(data[i][1])));
		}
                // Write to terminal and file
                write(outputData,std::cout);
                write(outputData,"powers.txt");
		break;
            case 5:
		// Exit
		std::cout << "Exiting";
		break;
            default:
                std::cout << "Selected option is invalid" << std::endl;
                break;
        }
    }
    return 0;
}
