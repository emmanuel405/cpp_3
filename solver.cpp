
#include <iostream>
#include <complex.h>

#include "solver.hpp"

using namespace std;
using namespace solver;

    double solver::operator==(RealVariable rv, double d){
        return d;
    }
    double solver::operator==(double d, RealVariable rv){
        return d;// operator==(rv,d);
    }
    double solver::operator==(RealVariable rv1, RealVariable rv){
        return 0.0;
    }

    RealVariable solver::operator*(double d, RealVariable rv){
        return rv;
    }
    RealVariable solver::operator^(RealVariable rv, int i){
        return rv;
    }
    RealVariable solver::operator+(RealVariable rv1, RealVariable rv){
        return rv;
    }
    RealVariable solver::operator+(RealVariable rv, double d){
        return rv;
    }
    RealVariable solver::operator-(RealVariable rv1, RealVariable rv){
        return rv;
    }
    RealVariable solver::operator-(RealVariable rv, double d){
        return rv;
    }
    double solver::operator-(RealVariable rv, int i){
        return 0.0;
    }
    RealVariable solver::operator/(double d, RealVariable rv){
        return rv;
    }
    RealVariable solver::operator/(RealVariable rv, int i){
        return rv;
    }





    double solver::operator==(ComplexVariable cv, double d){
        return d;
    }

    double solver::operator==(double d, ComplexVariable cv){
        return d;
    }

    double solver::operator==(ComplexVariable cv1, ComplexVariable cv){
        return 0.0;
    }

    ComplexVariable solver::operator*(double d, ComplexVariable cv){
        return cv;
    }
    ComplexVariable solver::operator^(ComplexVariable cv, int i){
        return cv;
    }
    
    ComplexVariable solver::operator+(double d, ComplexVariable cv){
        return cv;
    }
    ComplexVariable solver::operator+(ComplexVariable cv, int i){
        return cv;
    }
    ComplexVariable solver::operator+(ComplexVariable cv1, ComplexVariable cv){
        return cv;
    }
    double solver::operator+(ComplexVariable cv1, std::complex<double> cv){
        return 0.0;
    }
    ComplexVariable solver::operator-(double d, ComplexVariable cv){
        return cv;
    }
    ComplexVariable solver::operator-(ComplexVariable cv1, ComplexVariable cv){
        return cv;
    }

    double solver::operator-(ComplexVariable cv, int i){
        return 0.0;
    }

    ComplexVariable solver::operator/(double d, ComplexVariable cv){
        return cv;
    }
    ComplexVariable solver::operator/(ComplexVariable cv, int i){
        return cv;
    }

    double solver::solve(double d){
        return d;
    }
    std::complex<double> solver::solve(ComplexVariable y){
        std::complex<double> d;
        return d;
    }
/*
 *
 * operator == 
 * operator ^
 * 
 * 
 */