#include <vector>
#include "CustomFunctions.h"

int main(){
    std::string inputfile = "input2D_float.txt"; // filename
    
    // Read in data 
    std::vector<std::vector<double>> data = read_file(inputfile);

    std::cout << "Please select an option by entering an integer:" <<std::endl;
    std::cout << "  1 Print N lines from the inputfile" <<std::endl;
    std::cout << "  2 Print the magnitude of the vectors in " << inputfile <<std::endl;
    std::cout << "  3 Calcuate the line of best fit for the data in " << inputfile <<std::endl;
    int option;
    std::cin >> option;

    std::vector<double> magnitudes;
    switch (option)
        {
        case 1:
            // Print data to terminal
            print_datafile(inputfile,data," ");
            write_file("raw_data.txt", data);
            break;
        case 2:
            // Calculate magnitude
            for (int i = 0; i<data.size(); i++){
                // Calculate the magnitude for each vector
                magnitudes.push_back(magnitude(data[i]));
            }
            print_vector(magnitudes);
            break;
        case 3:
            // Fit Data
            fit_line(inputfile);
            break;
        default:
            std::cout << "Selected option is invalid" << std::endl;
            break;
    }
    return 0;
}