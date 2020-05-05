
#include <iostream>
#include <complex.h>
#include <math.h>

#include "solver.hpp"

using namespace std;
using namespace solver;

    double a, b, c;
    //////////////////////////////////////
    //////////// RealVariable ////////////
    //////////////////////////////////////

    RealVariable solver::operator==(RealVariable rv, double d){
        cout << "\nop rv == d\n";
        return operator-(rv, d);
        
    }
    RealVariable solver::operator==(double d, RealVariable rv){
        return operator==(rv,d);
    }
    RealVariable solver::operator==(RealVariable rv, RealVariable rv1){
        return operator-(rv, rv1);
    }

    RealVariable solver::operator*(RealVariable rv, double d){
        cout << "\nop rv * d\n";
        cout << "Before * "<< rv._pow2._coff << rv._pow1._coff << rv._coff << endl;
        
        RealVariable newRv(rv._pow2._coff, rv._pow1._coff, rv._coff);
        newRv._pow2._coff *= d;
        newRv._pow1._coff *= d;
        newRv._coff *= d;
        cout << "after * "<< newRv._pow2._coff << newRv._pow1._coff << newRv._coff << endl;        

        return newRv;
    }
    RealVariable solver::operator*(double d, RealVariable rv){
        return operator*(rv, d);
    }
    // RealVariable& operator*(RealVariable& rv, RealVariable& rv1){
    //     rv._pow2._coff *= rv1._pow2._coff;
    //     rv._pow1._coff *= rv1._pow1._coff;
    //     rv._coff *= rv1._coff;
    //     return rv;
    // }

    RealVariable solver::operator/(RealVariable rv, double d){
        cout << "\nop rv / d\n";
        
        if(d == 0)
            throw runtime_error("divide by zero");
        a = rv._pow2._coff; b = rv._pow1._coff; c = rv._coff;
        RealVariable newRv(a,b,c);
        newRv._pow2._coff /= d;
        newRv._pow1._coff /= d;
        newRv._coff /= d;
        return newRv;
    }
    RealVariable solver::operator/(RealVariable rv, int i){
        cout << "\nop rv / i\n";
        
        if(i == 0)
            throw runtime_error("divide by zero");
        a = rv._pow2._coff; b = rv._pow1._coff; c = rv._coff;
        RealVariable newRv(a,b,c);
        newRv._pow2._coff /= i;
        newRv._pow1._coff /= i;
        newRv._coff /= i;
        return newRv;
    }

    RealVariable solver::operator+(RealVariable rv, RealVariable rv1){
        cout << "\nop rv + rv1\n";
        cout << "Before + " << rv._pow2._coff << rv._pow1._coff << rv._coff << endl;
        
        a = rv._pow2._coff; b = rv._pow1._coff; c = rv._coff;
        RealVariable newRv(a,b,c);
        newRv._pow2._coff += rv1._pow2._coff;
        newRv._pow1._coff += rv1._pow1._coff;
        newRv._coff += rv1._coff;

        cout << "after + " << newRv._pow2._coff << newRv._pow1._coff << newRv._coff << endl;

        return newRv;
    }
    RealVariable solver::operator+(RealVariable rv, double d){
        cout << "\nop rv + d\n";
        
        rv._coff += d;
        return rv;
    }
    RealVariable solver::operator+(double d, RealVariable rv){
        cout << "\nop d + rv\n";
        
        rv._coff += d;
        return rv;
    }

    RealVariable solver::operator-(RealVariable rv, RealVariable rv1){
        cout << "\nop rv - rv1\n";
        cout << "after - " << rv._pow2._coff << rv._pow1._coff << rv._coff << endl;
        
        a = rv._pow2._coff; b = rv._pow1._coff; c = rv._coff;
        RealVariable newRv(a,b,c);
        newRv._pow2._coff -= rv1._pow2._coff;
        newRv._pow1._coff -= rv1._pow1._coff;
        newRv._coff -= rv1._coff;
        cout << "after - " << newRv._pow2._coff << newRv._pow1._coff << newRv._coff << endl;
        
        return newRv;
        
    }
    RealVariable solver::operator-(RealVariable rv, double d){
        cout << "\nop rv - d\n";
        
        rv._coff -= d;
        return rv;
    }
    RealVariable solver::operator-(RealVariable rv, int i){
        cout << "\nop rv - i\n";
        
        rv._coff -= i;
        return rv;
    }

    
    RealVariable solver::operator^(RealVariable rv, const int degree){
        cout << "op rv ^ degree\n";
        cout << "Before ^ " << rv._pow2._coff << rv._pow1._coff << rv._coff << endl;
        a = rv._pow2._coff; b = rv._pow1._coff; c = rv._coff;
        RealVariable newRv(a,b,c);
        switch (degree){
        case 0:
            newRv._pow2._coff = newRv._pow1._coff = 0;
            newRv._coff = 1;
            break;
        
        case 1:
            ;
            break;
        
        case 2:
            if(newRv._pow2._coff != 0)
                throw runtime_error("The degree should be: 0 <= degree <= 2");
            else
                if(newRv._pow1._coff == 0)
                    newRv._coff *= newRv._coff;
                else{
                    newRv._pow2._coff = newRv._pow1._coff * newRv._pow1._coff;
                    newRv._pow1._coff = 2 * newRv._pow1._coff * newRv._coff;
                    newRv._coff *= newRv._coff;
                    
                }
            break;

        default:
            throw runtime_error("The degree should be: 0 <= degree <= 2");
            break;
        }
        cout << "after ^ " << newRv._pow2._coff << newRv._pow1._coff << newRv._coff << endl;

        return newRv;
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
    double solver::solve(const RealVariable x){
        double ans = 0;
        cout << "the exescise:\n" << x._pow2._coff << "x^2 + " << x._pow1._coff << "x + " << x._coff << endl;
        if(x._pow2._coff == 0){
            if(x._pow1._coff == 0){
                if(x._coff == 0)
                    return 0.0;
                else 
                    throw runtime_error("There is no solution");
            }
            else{
                ans = -1*(x._coff);
                ans = ans / x._pow1._coff;
            }
        }
        else{
            if(x._pow1._coff == 0){
                ans = -1*(x._coff);
                ans = ans / x._pow2._coff;
                ans = sqrt(ans);
            }
            else
                ans = Quadratic_Equation(x);
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
double solver::Quadratic_Equation(RealVariable rv){
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
