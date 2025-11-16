#include <vector>
#include "CustomFunctions.h"

int main(){
    std::string inputfile = "input2D_float.txt"; // filename
    
    // Read in data 
    std::vector<std::vector<double>> data = read(inputfile);
    data.erase(data.begin());

    std::cout << "Please select an option by entering an integer:" << std::endl;
    std::cout << "  1 Print N lines from the inputfile" << std::endl;
    std::cout << "  2 Print the magnitude of the vectors in " << inputfile << std::endl;
    std::cout << "  3 Calcuate the line of best fit for the data in " << inputfile << std::endl;
    std::cout << "  4 Exit";

    int option = 4; // Exit by default
    std::cin >> option;

    while (option != 4){
        std::vector<double> magnitudes;
	int nRows;
	std::vector<std::vector<double>> subdata;
        switch (option){
            case 1:
	        // Ask how many rows of data to be printed
                std::cout << "How many rows of " << inputfile << " do you want printed?" << std::endl;
                std::cin >> nRows;
            
	        // Prevent out of range
                if (nRows > data.size()) nRows = 10;   // prevent out-of-range
		subdata.assign(data.begin(), data.begin() + nRows);
                // Print data to terminal
                print(subdata);
                // Write data to file
                write(subdata,"raw_data.txt");
                break;
            case 2:
                // Calculate magnitude
                magnitudes = magnitude(data);
                print(magnitudes);
                break;
            case 3:
                // Fit Data
                fit_line(inputfile);
                break;
            case 4:
		// Exit
		std::cout << "Exiting";
		break;
            default:
                std::cout << "Selected option is invalid" << std::endl;
		option = 4;
                break;
        }
    }
    return 0;
}
