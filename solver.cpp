
#include <iostream>
#include <complex.h>
#include <math.h>
#include <vector>

#include "solver.hpp"

using namespace std;
using namespace solver;
    
    //////////////////////////////////////
    //////////// RealVariable ////////////
    //////////////////////////////////////

    double solver::operator==(RealVariable rv, double d){
        return d;
    }
    double solver::operator==(double d, RealVariable rv){
        return solver::operator==(rv,d);
    }
    double solver::operator==(RealVariable rv, RealVariable rv1){
        return 0.0;
    }

    RealVariable& solver::operator*(RealVariable rv, double d){
        rv._pow2._coff *= d;
        rv._pow1._coff *= d;
        rv._coff *= d;
        return rv;
    }
    RealVariable& solver::operator*(double d, RealVariable rv){
        return solver::operator*(rv, d);
    }

    RealVariable& solver::operator/(RealVariable rv, double d){
        rv._pow2._coff /= d;
        rv._pow1._coff /= d;
        rv._coff /= d;
        return rv;
    }
    RealVariable& solver::operator/(RealVariable rv, int i){
        rv._pow2._coff /= i;
        rv._pow1._coff /= i;
        rv._coff /= i;
        return rv;
    }

    RealVariable& solver::operator+(RealVariable rv, RealVariable rv1){
        rv._pow2._coff += rv1._pow2._coff;
        rv._pow1._coff += rv1._pow1._coff;
        rv._coff += rv1._coff;
        return rv;
    }
    RealVariable& solver::operator+(RealVariable rv, double d){
        rv._coff += d;
        return rv;
    }
    RealVariable& solver::operator+(double d, RealVariable rv){
        rv._coff += d;
        return rv;
    }

    RealVariable& solver::operator-(RealVariable rv, RealVariable rv1){
        rv._pow2._coff -= rv1._pow2._coff;
        rv._pow1._coff -= rv1._pow1._coff;
        rv._coff -= rv1._coff;
        return rv;
    }
    RealVariable& solver::operator-(RealVariable rv, double d){
        rv._coff -= d;
        return rv;
    }
    RealVariable& solver::operator-(RealVariable rv, int i){
        rv._coff -= i;
        return rv;
    }

    // maybe no?
    RealVariable solver::operator^(RealVariable rv, int i){
        return rv;
    }


    ///////////////////////////////////////
    /////////// ComplexVariable ///////////
    ///////////////////////////////////////


    ComplexVariable solver::operator==(ComplexVariable cv, double d){
        return cv;
    }

    ComplexVariable solver::operator==(double d, ComplexVariable cv){
        return cv;
    }

    ComplexVariable solver::operator==(ComplexVariable cv1, complex<double> cv){
        return cv1;
    }
    ComplexVariable solver::operator==(ComplexVariable cv1, ComplexVariable cv){
        return cv1;
    }

    ComplexVariable& solver::operator*(double d, ComplexVariable cv){
        return cv;
    }
    ComplexVariable& solver::operator*(ComplexVariable cv, double d){
        return cv;
    }
    ComplexVariable& solver::operator*(ComplexVariable cv, int i){
        return cv;
    }
    ComplexVariable& solver::operator*(int i, ComplexVariable cv){
        return cv;
    }
    
    ComplexVariable& solver::operator+(double d, ComplexVariable cv){
        return cv;
    }
    ComplexVariable& solver::operator+(ComplexVariable cv, double d){
        return cv;
    }

    ComplexVariable& solver::operator+(ComplexVariable cv, int i){
        return cv;
    }
    ComplexVariable& solver::operator+(ComplexVariable cv1, ComplexVariable cv){
        return cv;
    }
    ComplexVariable& solver::operator+(ComplexVariable cv1, complex<double> cv){
        return cv1;
    }
    ComplexVariable& solver::operator-(double d, ComplexVariable cv){
        return cv;
    }
    ComplexVariable& solver::operator-(ComplexVariable cv1, ComplexVariable cv){
        return cv;
    }

    ComplexVariable& solver::operator-(ComplexVariable cv, int i){
        return cv;
    }
    ComplexVariable& solver::operator-(ComplexVariable cv, double d){
        return cv;
    }
    ComplexVariable& solver::operator-(ComplexVariable cv1, complex<double> cv){
        return cv1;
    }

    ComplexVariable& solver::operator/(double d, ComplexVariable cv){
        return cv;
    }
    ComplexVariable& solver::operator/(ComplexVariable cv, int i){
        return cv;
    }

    ComplexVariable solver::operator^(ComplexVariable cv, int i){
        return cv;
    }

    double solver::solve(double d){
        return d;
    }
    complex<double> solver::solve(ComplexVariable y){
        complex<double> d;
        return d;
    }


// /**
//  * @param RealVariable rv
//  * 
//  * result of < a*x^2 + b*x + c = 0 >
//  * 
//  * @result vector with x1 and x2
//  */
// vector<double> Quadratic_Equation(RealVariable rv){
//     double a = rv._pow2._coff, b = rv._pow1._coff , c = rv._coff;
//     double delta = b*b-4*a*c;
//     vector<double> ans;
//     if (delta > 0){
//         double x1 = (-1*b + sqrt(delta)) / (2*a);
//         double x2 = (-1*b - sqrt(delta)) / (2*a);
//         ans.push_back(x1); 
//         ans.push_back(x2); 
//     }
//     else if (delta == 0){
//         double x1 = (-1*b) / (2*a);
//         ans.push_back(x1);
//     }
//         else
//             cout << "Error! Delta is smaller than 0...\n";
//     return ans;
// }
