#include "FiniteFunctions.h"

#pragma once

using namespace std;

class Normal : public FiniteFunction {

    public:
        // Constructors
        Normal();
        Normal(double range_min, double range_max, double mean, double std, string outfile);
        // Setters
        void setMean(double mean);
        void setStd(double std);

        // Getters
        double mean();
        double std();
        void printInfo();

        // Function
        double callFunction(double x);


    protected:
        double m_mean;
        double m_std;

    private:
        double normal(double x);

};