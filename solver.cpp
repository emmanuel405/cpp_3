
#include <iostream>
#include <complex.h>
#include <math.h>

#include "solver.hpp"

using namespace std;
using namespace solver;

    
    //////////////////////////////////////
    //////////// RealVariable ////////////
    //////////////////////////////////////

    RealVariable& solver::operator==(RealVariable& rv, double d){
        return operator-(rv, d);
        
    }
    RealVariable& solver::operator==(double d, RealVariable& rv){
        return operator==(rv,d);
    }
    RealVariable& solver::operator==(RealVariable& rv, RealVariable& rv1){
        return operator-(rv, rv1);
    }

    RealVariable& solver::operator*(RealVariable& rv, double d){
        rv._pow2._coff *= d;
        rv._pow1._coff *= d;
        rv._coff *= d;
        return rv;
    }
    RealVariable& solver::operator*(double d, RealVariable& rv){
        return operator*(rv, d);
    }
    // RealVariable& operator*(RealVariable& rv, RealVariable& rv1){
    //     rv._pow2._coff *= rv1._pow2._coff;
    //     rv._pow1._coff *= rv1._pow1._coff;
    //     rv._coff *= rv1._coff;
    //     return rv;
    // }

    RealVariable& solver::operator/(RealVariable& rv, double d){
        if(d == 0)
            throw runtime_error("divide by zero");
        rv._pow2._coff /= d;
        rv._pow1._coff /= d;
        rv._coff /= d;
        return rv;
    }
    RealVariable& solver::operator/(RealVariable& rv, int i){
        if(i == 0)
            throw runtime_error("divide by zero");
        rv._pow2._coff /= i;
        rv._pow1._coff /= i;
        rv._coff /= i;
        return rv;
    }

    RealVariable& solver::operator+(RealVariable& rv, RealVariable& rv1){
        rv._pow2._coff += rv1._pow2._coff;
        rv._pow1._coff += rv1._pow1._coff;
        rv._coff += rv1._coff;
        return rv;
    }
    RealVariable& solver::operator+(RealVariable& rv, double d){
        rv._coff += d;
        return rv;
    }
    RealVariable& solver::operator+(double d, RealVariable& rv){
        rv._coff += d;
        return rv;
    }

    RealVariable& solver::operator-(RealVariable& rv, RealVariable& rv1){
        rv._pow2._coff -= rv1._pow2._coff;
        rv._pow1._coff -= rv1._pow1._coff;
        rv._coff -= rv1._coff;
        return rv;
    }
    RealVariable& solver::operator-(RealVariable& rv, double d){
        rv._coff -= d;
        return rv;
    }
    RealVariable& solver::operator-(RealVariable& rv, int i){
        rv._coff -= i;
        return rv;
    }

    
    RealVariable& solver::operator^(RealVariable& rv, const int degree){
        switch (degree){
        case 0:
            rv._pow2._coff = rv._pow1._coff = 0;
            rv._coff = 1;
            break;
        
        case 1:
            ;
            break;
        
        case 2:
            if(rv._pow2._coff != 0)
                throw runtime_error("The degree should be: 0 <= degree <= 2");
            else
                if(rv._pow1._coff == 0)
                    rv._coff *= rv._coff;
                else{
                    rv._pow2._coff = rv._pow1._coff * rv._pow1._coff;
                    rv._pow1._coff = 2 * rv._pow1._coff * rv._coff;
                    rv._coff *= rv._coff;
                }

            break;

        default:
            throw runtime_error("The degree should be: 0 <= degree <= 2");
            break;
        }
        return rv;
    }



    ///////////////////////////////////////
    /////////// ComplexVariable ///////////
    ///////////////////////////////////////


    // ComplexVariable solver::operator==(ComplexVariable cv, double d){
    //     return cv;
    // }

    // ComplexVariable solver::operator==(double d, ComplexVariable cv){
    //     return cv;
    // }

    // ComplexVariable solver::operator==(ComplexVariable cv1, complex<double> cv){
    //     return cv1;
    // }
    // ComplexVariable solver::operator==(ComplexVariable cv1, ComplexVariable cv){
    //     return cv1;
    // }

    // ComplexVariable& solver::operator*(double d, ComplexVariable cv){
    //     return cv;
    // }
    // ComplexVariable& solver::operator*(ComplexVariable cv, double d){
    //     return cv;
    // }
    // ComplexVariable& solver::operator*(ComplexVariable cv, int i){
    //     return cv;
    // }
    // ComplexVariable& solver::operator*(int i, ComplexVariable cv){
    //     return cv;
    // }
    
    // ComplexVariable& solver::operator+(double d, ComplexVariable cv){
    //     return cv;
    // }
    // ComplexVariable& solver::operator+(ComplexVariable cv, double d){
    //     return cv;
    // }

    // ComplexVariable& solver::operator+(ComplexVariable cv, int i){
    //     return cv;
    // }
    // ComplexVariable& solver::operator+(ComplexVariable cv1, ComplexVariable cv){
    //     return cv;
    // }
    // ComplexVariable& solver::operator+(ComplexVariable cv1, complex<double> cv){
    //     return cv1;
    // }
    // ComplexVariable& solver::operator-(double d, ComplexVariable cv){
    //     return cv;
    // }
    // ComplexVariable& solver::operator-(ComplexVariable cv1, ComplexVariable cv){
    //     return cv;
    // }

    // ComplexVariable& solver::operator-(ComplexVariable cv, int i){
    //     return cv;
    // }
    // ComplexVariable& solver::operator-(ComplexVariable cv, double d){
    //     return cv;
    // }
    // ComplexVariable& solver::operator-(ComplexVariable cv1, complex<double> cv){
    //     return cv1;
    // }

    // ComplexVariable& solver::operator/(double d, ComplexVariable cv){
    //     return cv;
    // }
    // ComplexVariable& solver::operator/(ComplexVariable cv, int i){
    //     return cv;
    // }

    // ComplexVariable solver::operator^(ComplexVariable cv, int i){
    //     return cv;
    // }
    // complex<double> solver::solve(ComplexVariable y){
    //     complex<double> d;
    //     return d;
    // }

    /**
     * 3x-6 == 6
     * x^2+3x-6 == 0
     * x^2-6 == 0
     * x^2+3x == 0
     */
    double solver::solve(const RealVariable rv){
        double ans = 0;
        cout << "the exescise:\n" << rv._pow2._coff << "x^2 + " << rv._pow1._coff << "x + " << rv._coff << endl;
        if(rv._pow2._coff == 0){
            if(rv._pow1._coff == 0){
                if(rv._coff == 0)
                    return 0.0;
                else 
                    throw runtime_error("There is no solution");
            }
            else{
                ans = -1*(rv._coff);
                ans = ans / rv._pow1._coff;
            }
        }
        else{
            if(rv._pow1._coff == 0){
                ans = -1*(rv._coff);
                ans = ans / rv._pow2._coff;
                ans = sqrt(ans);
            }
            else
                ans = Quadratic_Equation(rv);
        }
            
        return ans;
    }
    

/**
 * @param RealVariable rv
 * 
 * result of < a*x^2 + b*x + c = 0 >
 * 
 * @result x1
 */
double solver::Quadratic_Equation(const RealVariable rv){
    double a = rv._pow2._coff, b = rv._pow1._coff , c = rv._coff;
    double delta = b*b - 4*a*c;

    if (delta > 0){
        double x1 = (-1*b + sqrt(delta)) / (2*a);
        double x2 = (-1*b - sqrt(delta)) / (2*a);
        return x1;
    }
    else if (delta == 0){
        double x1 = (-1*b) / (2*a);
        return x1;
    }
    else
        throw runtime_error("Error! Delta is smaller than 0...\n");
    }
