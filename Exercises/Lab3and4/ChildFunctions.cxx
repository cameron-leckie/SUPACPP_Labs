#include <cmath>
#include "ChildFunctions.h"
#include "FiniteFunctions.h"

#define _USE_MATH_DEFINES

using namespace std;

/*
########################################################################################################################################################################
Normal
########################################################################################################################################################################
*/
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
{
    if (std <= 0){
        cout << "Standard deviation (std) must be greater than 0. Setting std to 1 \n";
        m_std = 1;
    };
    return;
}

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
double Normal::NormalEval(double x) {
    double N = 1/(m_std*sqrt(2*M_PI));
    double exponent = exp(-0.5*pow(((x-m_mean)/m_std),2));
    return N*exponent;
};
double Normal::callFunction(double x) {return this->NormalEval(x);}; //(overridable)

/*
########################################################################################################################################################################
Cauchy-Lorentz
########################################################################################################################################################################
*/
/* 
###################
//Constrcutors
###################
*/

CauchyLorentz::CauchyLorentz() :
    FiniteFunction(),
    m_gamma(1),
    m_x0(0)
{}

CauchyLorentz::CauchyLorentz(double range_min, double range_max, double gamma, double x0, string outfile) :
    FiniteFunction(range_min, range_max, outfile),
    m_gamma(gamma),
    m_x0(x0)
{
    if (gamma <= 0){
        cout << "Gamma must be greater than 0. Setting gamma to 1 \n";
        m_gamma = 1;
    };
    return;
}

/*
###################
//Setters
###################
*/ 
void CauchyLorentz::setGamma(double gamma){m_gamma = gamma; return;};
void CauchyLorentz::setX0(double x0){m_x0 = x0; return;};

/*
###################
//Getters
###################
*/ 
double CauchyLorentz::gamma(){return m_gamma;};
double CauchyLorentz::x0(){return m_x0;};
void CauchyLorentz::printInfo(){
    cout << "gamma: " << m_gamma << endl;
    cout << "x0: " << m_x0 << endl;
    FiniteFunction::printInfo();
    return;
}

/*
###################
//Function eval
###################
*/ 
double CauchyLorentz::CauchyLorentzEval(double x) {return 1/(M_PI*m_gamma*(1 + pow((x-m_x0)/m_gamma,2) ));};
double CauchyLorentz::callFunction(double x) {return this->CauchyLorentzEval(x);}; //(overridable)

/*
########################################################################################################################################################################
Crystal Ball
########################################################################################################################################################################
*/
/* 
###################
//Constrcutors
###################
*/

CrystalBall::CrystalBall() :
    FiniteFunction(),
    m_alpha(1),
    m_n(1),
    m_x0(0),
    m_std(1)
{}

CrystalBall::CrystalBall(double range_min, double range_max, double alpha, unsigned int n, double x0, double std, string outfile) :
    FiniteFunction(range_min, range_max, outfile),
    m_alpha(alpha),
    m_n(n),
    m_x0(x0),
    m_std(std)
{
    if (alpha <= 0){
        cout << "Alpha must be greater than 0. Setting alpha to 1 \n";
        m_alpha = 1;
    };
    if (n <= 0){
        cout << "n must be greater than 0. Setting n to 1 \n";
        m_n = 1;
    };
    if (std <= 0){
        cout << "Standard deviation (std) must be greater than 0. Setting std to 1 \n";
        m_std = 1;
    };
    return;
}

/*
###################
//Setters
###################
*/ 
void CrystalBall::setAlpha(double alpha){m_alpha = alpha; return;};
void CrystalBall::setX0(double x0){m_x0 = x0; return;};
void CrystalBall::setN(unsigned int n){m_n = n; return;};
void CrystalBall::setStd(double std){m_std = std; return;};

/*
###################
//Getters
###################
*/ 
double CrystalBall::alpha(){return m_alpha;};
double CrystalBall::x0(){return m_x0;};
unsigned int CrystalBall::n(){return m_n;};
double CrystalBall::std(){return m_std;};

void CrystalBall::printInfo(){
    cout << "alpha: " << m_alpha << endl;
    cout << "x0: " << m_x0 << endl;
    cout << "n: " << m_n << endl;
    cout << "std: " << m_std << endl;
    FiniteFunction::printInfo();
    return;
}

/*
###################
//Function eval
###################
*/ 
double CrystalBall::CrystalBallEval(double x) {
    double A = pow(m_n/m_alpha,m_n);
    double B = m_n/m_alpha - m_alpha;
    double C = (m_n/m_alpha)*(1/(m_n - 1))*exp(-m_alpha*m_alpha/2);
    double D = sqrt(M_PI/2)*(1 + erf(m_alpha/sqrt(2)));
    double E = (x - m_x0)/m_std;
    double N = 1/(m_std*(C + D));
    double y; // function solution

    if ( E > -m_alpha){
        y = exp(-E*E/2);
    } else {
        y = A*pow(B - E, m_n);
    };

    y *= N;

    return y;
};
double CrystalBall::callFunction(double x) {return this->CrystalBallEval(x);}; //(overridable)