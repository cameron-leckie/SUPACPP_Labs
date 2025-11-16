#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>

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


//// MATH ////
double magnitude(std::vector<double> data){
    // Calculatethe magnitude for an array of vectors
    double mag = 0; // magnitude of currect vector
    // Loop over the components of each vector
    for (int i = 0; i < data.size(); i++){
        mag += data[i]*data[i];
    }
    return sqrt(mag);
}

std::vector<double> magnitude(std::vector<std::vector<double>> data){
    // Calculatethe magnitude for an array of vectors
    std::vector<double> magVec; // magnitude of all vectors
    // Loop over each vector
    for (int i = 0; i<data.size(); i++){
        // Calculate the magnitude for each vector
        magVec.push_back(magnitude(data[i]));
    }

    return magVec;
}

double chi_squared(std::vector<double> observed, std::vector<double> expected, std::vector<double> error){
    double chi2 = 0;
    for (int i = 0; i < error.size(); i++){
	chi2 += (observed[i] - expected[i])*(observed[i] - expected[i])/(error[i]*error[i]);
    }
    return chi2;
}

void fit_line(std::vector<std::vector<double>> data, std::vector<double> error){
    // Reads in data from a data file then fits a line to the data.
    // The data must only have 2 components.

    //// Start Least squares
    double sumX = 0;
    double sumY = 0;
    double sumProdXY = 0;
    double sumX2 = 0;

    for (int i = 0; i<data.size(); i++){
        sumX += data[i][0];
        sumY += data[i][1];
        sumProdXY += data[i][0]*data[i][1];
        sumX2 += data[i][0]*data[i][0];
    }

    // Calculate fitted line constants
    double p = (data.size()*sumProdXY - sumX*sumY)/(data.size()*sumX2 - sumX*sumX);
    double q = (sumX2*sumY - sumProdXY*sumX)/(data.size()*sumX2 - sumX*sumX);
        // Create equation string
    std::string equation = "Fitted line equation: y = " + std::to_string(p) + "*x + " + std::to_string(q);


    //// chi2 calculation
    if (!error.empty()){
	// Calculate expected and observed vectors
	std::vector<double> observed;
	std::vector<double> expected;
        for (int i = 0; i < error.size(); i++){
	    observed.push_back(data[i][1]);
	    expected.push_back(p*data[i][0] + q);
	}
        
	// Calculate chi2
        double chi2 = chi_squared(observed,expected,error);
        double chi2_DOF = chi2/error.size();

	// Extend output
	equation += ",	Chi2 = " + std::to_string(chi2) + ",	Chi2/DOF = " + std::to_string(chi2_DOF);	
    }

    // Print equation to terminal and file
    std::cout << equation << std::endl;
    std::ofstream outputFile("fitted_line_equation.txt");
    outputFile << equation << std::endl;
    outputFile.close();

    return;
}

double power(double x, int y){
    

    if (y < 0){
        return 1/power(x,-y);
    }	
    switch (y){
	case 0:
	    return 1;    
        case 1:
    	    return x;	    
	default:
	    return x*power(x,y-1);
      
    }
}
