#pragma once
#include <iostream>
#include <vector>


//// Read
std::vector<std::vector<double>> read(std::string inputfile, bool header = false);

//// Write
void write(std::vector<double>& data, std::ostream& output = std::cout, std::string delimiter = "\n");
void write(std::vector<std::vector<double>>& data, std::ostream& output = std::cout, std::string delimiter = " ");
void write(std::vector<double>& data, std::string outputFile, std::string delimiter = "\n");
void write(std::vector<std::vector<double>>& data, std::string outputFile, std::string delimiter = " ");

//// Math
double magnitude(std::vector<double> data);
std::vector<double> magnitude(std::vector<std::vector<double>> data);
double chi_squared(std::vector<double> observed, std::vector<double> expected, std::vector<double> error);
void fit_line(std::vector<std::vector<double>> data, std::vector<double> error = {});
double power(double x, int y);
