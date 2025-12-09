#include <cmath>
#include "Normal.h"
#include "FiniteFunctions.h"

#define _USE_MATH_DEFINES

using namespace std;
/* 
###################
//Constrcutors
###################
*/

Normal::Normal() :
    FiniteFunction(),
    m_mean(0),
    m_std(1)
{}

Normal::Normal(double range_min, double range_max, double mean, double std, string outfile) :
    FiniteFunction(range_min, range_max, outfile),
    m_mean(mean),
    m_std(std)
{}

/*
###################
//Setters
###################
*/ 
void Normal::setMean(double mean){m_mean = mean; return;};
void Normal::setStd(double std){m_std = std; return;};

/*
###################
//Getters
###################
*/ 
double Normal::mean(){return m_mean;};
double Normal::std(){return m_std;};
void Normal::printInfo(){
    cout << "mean: " << m_mean << endl;
    cout << "std: " << m_std << endl;
    FiniteFunction::printInfo();
    return;
}

/*
###################
//Function eval
###################
*/ 
double Normal::normal(double x) {
    double N = 1/(m_std*sqrt(2*M_PI));
    double exponent = exp(-0.5*pow(((x-m_mean)/m_std),2));
    return N*exponent;
};
double Normal::callFunction(double x) {return this->normal(x);}; //(overridable)