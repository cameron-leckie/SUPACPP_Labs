#pragma once
#include <iostream>
#include <vector>


// Read
std::vector<std::vector<double>> read(std::string);

// Write
void write(std::vector<std::vector<double>> data, std::string outputfile = "out.txt", std::string delimiter = " ");

// Print
void print(std::vector<double>,std::string delimiter = "\n");
void print(std::vector<std::vector<double>>,std::string delimiter = " ");

// Math
double magnitude(std::vector<double> data);
double magnitude(std::vector<std::vector<double>> data);
void fit_line(std::string inputfile);
