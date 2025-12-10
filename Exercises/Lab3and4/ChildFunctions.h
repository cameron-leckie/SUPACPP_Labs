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
        double NormalEval(double x);

};

class CauchyLorentz : public FiniteFunction {

    public:
        // Constructors
        CauchyLorentz();
        CauchyLorentz(double range_min, double range_max, double gamma, double x0, string outfile);
        // Setters
        void setGamma(double gamma);
        void setX0(double x0);

        // Getters
        double gamma();
        double x0();
        void printInfo();

        // Function
        double callFunction(double x);


    protected:
        double m_gamma;
        double m_x0;

    private:
        double CauchyLorentzEval(double x);

};

class CrystalBall : public FiniteFunction {

    public:
        // Constructors
        CrystalBall();
        CrystalBall(double range_min, double range_max, double alpha, double n, double x0, double std, string outfile);
        // Setters
        void setAlpha(double alpha);
        void setX0(double x0);
        void setN(double n);
        void setStd(double std);

        // Getters
        double alpha();
        double x0();
        double n();
        double std();
        void printInfo();

        // Function
        double callFunction(double x);


    protected:
        double m_alpha;
        double m_n;
        double m_x0;
        double m_std;

    private:
        double CrystalBallEval(double x);

};