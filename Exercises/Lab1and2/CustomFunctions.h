#pragma once
#include <iostream>
#include <vector>


// Read Write
std::vector<std::vector<double>> read_file(std::string);
void print_vector(std::vector<double>,std::string delimiter = "\n");
void print_datafile(std::string, std::vector<std::vector<double>>,std::string delimiter = " ");
void write_file(std::string outputfile, std::vector<std::vector<double>> data, std::string delimiter = " ");

// Math
double magnitude(std::vector<double> data);
void fit_line(std::string inputfile);