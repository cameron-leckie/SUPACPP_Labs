#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>

std::vector<std::vector<double>> read_file(std::string inputfile){
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
    // Skip the header line that contains text not data
    std::getline(dataFile,line);
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

void write_file(std::string outputfile, std::vector<std::vector<double>> data, std::string delimiter){
    // Writes 2D data to a file

    std::ofstream dataFile; // file object

    dataFile.open(outputfile); // Open the output file
    // loop over the rows
    for (int i = 0; i < data.size(); i++){
        // loop over the columns
        for (int j = 0; j< data[i].size()-1; j++){
            // write all values apart from last
            dataFile << data[i][j] << delimiter;
        }
        // write last value and take a new line
        dataFile << data[i].back() << std::endl;
    }
    return;
}

void print_vector(std::vector<double> data, std::string delimiter){
    // Print all apart from last value
    for (int i = 0; i < data.size()-1; i++){
        // Print each value
        std::cout << data[i] << delimiter;
    }
    // Print last value
    std::cout << data.back() << std::endl;
    return;
}

void print_datafile(std::string inputfile, std::vector<std::vector<double>> data, std::string delimiter){
    
    int nRows;
    std::cout << "How many rows of " << inputfile << " do you want printed?" << std::endl;
    std::cin >> nRows;

    //while ( (0 > nRows) || (nRows > data.size())){
    //    std::cout << "Invalid number of rows. Please enter a value between 0 and " << data.size() << std::endl;
    //    std::cin >> nRows;
    //}

    if  ( (0 > nRows) || (nRows > data.size())){
        std::cout << "Invalid number of rows" << std::endl;
        nRows = 5;
        if (nRows > data.size()){
            nRows = data.size();
        }
    }
    
    // Print filename
    std::cout << "First " << nRows << " rows in  data file: " << inputfile << std::endl;
    // Loop over the rows
    for (int i = 0; i < nRows; i++){
        // Print each row
        print_vector(data[i],delimiter);
    }
    return;
}

double magnitude(std::vector<double> data){
    // Calculatethe magnitude for an array of vectors
    double mag = 0; // magnitude of currect vector
    // Loop over the components of each vector
    for (int i = 0; i < data.size(); i++){
        mag += data[i]*data[i];
    }
    return sqrt(mag);
}

void fit_line(std::string inputfile){
    // Reads in data from a data file then fits a line to the data.
    // The data must only have 2 components.

    // Load data
    std::vector<std::vector<double>> data = read_file(inputfile);

    // Start Least squares
    double sumX = 0;
    double sumY = 0;
    double sumProdXY = 0;
    double sumX2 = 0;

    for (int i = 0; i<data.size(); i++){
        sumX += data[i][1];
        sumY += data[i][2];
        sumProdXY += data[i][1]*data[i][2];
        sumX2 += data[i][1]*data[i][1];
    }

    // Calculate fitted line constants
    double p = (data.size()*sumProdXY - sumX*sumY)/(data.size()*sumX2 - sumX*sumX);
    double q = (sumX2*sumY - sumProdXY*sumX)/(data.size()*sumX2 - sumX*sumX);

    // Create equation string
    std::string equation = "Fitted line equation: y = " + std::to_string(p) + "*x + " + std::to_string(q);

    // Print equation to terminal and file
    std::cout << equation << std::endl;
    std::ofstream outputFile("fitted_line_equation.txt");
    outputFile << equation << std::endl;
    outputFile.close();

    return;
}