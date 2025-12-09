#include <iostream>
#include <vector>
#pragma once

//// Read
std::vector<std::vector<double>> read(std::string inputfile, bool header = false);

//// Write
void write(std::vector<double>& data, std::ostream& output = std::cout, std::string delimiter = "\n");
void write(std::vector<std::vector<double>>& data, std::ostream& output = std::cout, std::string delimiter = " ");
void write(std::vector<double>& data, std::string outputFile, std::string delimiter = "\n");
void write(std::vector<std::vector<double>>& data, std::string outputFile, std::string delimiter = " ");
