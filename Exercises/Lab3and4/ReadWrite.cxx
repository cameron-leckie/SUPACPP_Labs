#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

//// READ ////
std::vector<std::vector<double>> read(std::string inputfile, bool header){
    std::ifstream dataFile; // file object
    std::vector<std::vector<double>> data; // 2D data vector

    dataFile.open(inputfile); // Open file

    // Verify the file is open and exit with error if it is now
    if (!dataFile.is_open()){
        std::cout << "Error opening file: " << inputfile << std::endl;
        return data;
    }else{
        std::cout << "File: " << inputfile << " opened successfully" << std::endl;
    }

    // Read in data from file into variable data
    std::string line;
    if (header) {
	    std::getline(dataFile, line);
    }

    while (std::getline(dataFile, line)) { // Loop over the lines
        
        // Store current line into row vector that can then be stored in data
        std::stringstream ss(line); 
        std::string value;
        std::vector<double> row;
        while (std::getline(ss, value, ',')) {
            row.push_back(std::stod(value));
      }
      data.push_back(row);
    }
    dataFile.close(); // Data read so file can be closed
    
    return data;
}

//// WRITE ////
void write(std::vector<double>& data, std::ostream& output, std::string delimiter){
    // Writes 1D data to a file
    // loop over values
    for (int i = 0; i< data.size()-1; i++){
        // write all values apart from last
        output << data[i] << delimiter;
    }
    // write last value and take a new line
    output << data.back() << std::endl;
    return;
}

void write(std::vector<std::vector<double>>& data, std::ostream& output, std::string delimiter){
    // Writes 2D data to a file
    // loop over the rows
    for (int i = 0; i < data.size(); i++){
        write(data[i], output, delimiter);
    }
    return;
}

void write(std::vector<double>& data, std::string outputFile, std::string delimiter){
        // This function will open a file with the provided filename then pass the open file to the other write function
        std::ofstream output;
        output.open(outputFile);
        write(data, output, delimiter);
        output.close();
        return;
}

void write(std::vector<std::vector<double>>& data, std::string outputFile, std::string delimiter){
	// This function will open a file with the provided filename then pass the open file to the other write function
	std::ofstream output;
	output.open(outputFile);
	write(data, output, delimiter);
	output.close();
	return;
}