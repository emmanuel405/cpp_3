
#include <iostream>
#include <complex.h>
#include <math.h>

#include "solver.hpp"

using namespace std;
using namespace solver;

    //////////////////////////////////////
    //////////// RealVariable ////////////
    //////////////////////////////////////

  RealVariable solver::operator==(RealVariable rv, double d){
        return operator-(rv,d);
    }
    RealVariable solver::operator==(double d, RealVariable rv){
        return operator==(rv,d);
    }
    RealVariable solver::operator==(RealVariable rv, RealVariable rv1){
        return operator-(rv, rv1);
    }

    RealVariable solver::operator*(RealVariable rv, const double d){
        RealVariable newRv(rv); // copy
        newRv._pow2._coff *= d;
        newRv._pow1._coff *= d;
        newRv._coff *= d;
  
        return newRv;
    }
    RealVariable solver::operator*(const double d, RealVariable rv){
        return operator*(rv, d);
    }
    RealVariable solver::operator*(RealVariable rv, const int i){
        RealVariable newRv(rv); // copy
        newRv._pow2._coff *= i;
        newRv._pow1._coff *= i;
        newRv._coff *= i;
  
        return newRv;
    }
    RealVariable solver::operator*(const int i, RealVariable rv){
        return operator*(rv, i);
    }

    RealVariable solver::operator/(RealVariable rv, const double d){ 
        if(d == 0)
            throw runtime_error("divide by zero");

        RealVariable newRv(rv); // copy
        newRv._pow2._coff /= d;
        newRv._pow1._coff /= d;
        newRv._coff /= d;
        return newRv;
    }
    RealVariable solver::operator/(RealVariable rv, const int i){
        if(i == 0)
            throw runtime_error("divide by zero");

        RealVariable newRv(rv); // copy
        newRv._pow2._coff /= i;
        newRv._pow1._coff /= i;
        newRv._coff /= i;
        return newRv;
    }

    RealVariable solver::operator+(RealVariable rv, const RealVariable rv1){
        RealVariable newRv(rv); // copy
        newRv._pow2._coff += rv1._pow2._coff;
        newRv._pow1._coff += rv1._pow1._coff;
        newRv._coff += rv1._coff;

        return newRv;
    }
    RealVariable solver::operator+(RealVariable rv, const double d){
        rv._coff += d;
        return rv;
    }
    RealVariable solver::operator+(const double d, RealVariable rv){
        rv._coff += d;
        return rv;
    }

    RealVariable solver::operator-(RealVariable rv, const RealVariable rv1){
        RealVariable newRv(rv); // copy
        newRv._pow2._coff -= rv1._pow2._coff;
        newRv._pow1._coff -= rv1._pow1._coff;
        newRv._coff -= rv1._coff;

        return newRv;
        
    }
    RealVariable solver::operator-(RealVariable rv, const double d){
        rv._coff -= d;
        return rv;
    }
    RealVariable solver::operator-(const double d, RealVariable rv){
        return operator-(rv, d);
    }
    RealVariable solver::operator-(RealVariable rv, const int i){
        rv._coff -= i;
        return rv;
    }
    RealVariable solver::operator-(const int i, RealVariable rv){
        return operator-(rv, i);
    }

    RealVariable solver::operator^(RealVariable rv, const int degree){
        RealVariable newRv(rv); // copy
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
        return newRv;
    }

    /**
     * 3x-6 == 6
     * x^2+3x-6 == 0
     * x^2-6 == 0
     * x^2+3x == 0
     */
    double solver::solve(const RealVariable x){
        double ans = 0;
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
                if(x._coff > 0)
                    throw runtime_error("There is no solution");
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

///////////////////////////////////////
/////////// ComplexVariable ///////////
///////////////////////////////////////


ComplexVariable solver::operator==(ComplexVariable cv, double d){
    cv.v.real(cv.v.real()+(-1)*d);
    return cv;
}

ComplexVariable solver::operator==(double d, ComplexVariable cv){
    return cv==d;
}

ComplexVariable solver::operator==(ComplexVariable cv1, complex<double> cv){
    cv1.v.real(cv1.v.real()+(-1)*cv.real());
    cv1.v.imag(cv1.v.imag()+(-1)*cv.imag());
    return cv1;
}

ComplexVariable  solver::operator==(ComplexVariable cv1, ComplexVariable cv){
    cv1=cv1+((-1)*cv);
    return cv1;
}


ComplexVariable solver::operator*(double d, ComplexVariable& cv){
    complex<double> a,b,c;
    a.real(cv._pow2.v.real()*d);
    a.imag(cv._pow2.v.imag()*d);
    b.real(cv._pow1.v.real()*d);
    b.imag(cv._pow1.v.imag()*d);
    c.real(cv.v.real()*d);
    c.imag(cv.v.imag()*d );
    return ComplexVariable(a, b, c);

}

ComplexVariable solver::operator*(ComplexVariable cv, double d){
    return d*cv;
}

//why operator * for double AND for int?

ComplexVariable solver::operator*(ComplexVariable cv, int i){
    /*
        if(cv.isInit)
        {
            ComplexVariable d((0,0),(i,i),(0,0));
            d.isInit=false;
            return d;
        }*/
            complex<double> a,b,c;
            a.real(cv._pow2.v.real()*i);
            a.imag(cv._pow2.v.imag()*i);
            b.real(cv._pow1.v.real()*i);
            b.imag(cv._pow1.v.imag()*i);
            c.real(cv.v.real()*i);
            c.imag(cv.v.imag()*i);
              return ComplexVariable(a, b, c);

}

ComplexVariable solver::operator*(int i, ComplexVariable cv){
    return cv*i;
}

ComplexVariable solver::operator+(double d, ComplexVariable cv){
    complex<double> a,b,c;
    a.real(cv._pow2.v.real());
    a.imag(cv._pow2.v.imag());
    b.real(cv._pow1.v.real() );
    b.imag(cv._pow1.v.imag() );
    c.real(cv.v.real()+d);
    c.imag(cv.v.imag());
    return ComplexVariable(a,b,c);
}

ComplexVariable solver::operator+(ComplexVariable cv, double d){
    return d+cv;
}

//why operator + for double AND int?

ComplexVariable solver::operator+(ComplexVariable cv, int i){
    return i+cv;
}
//std::complex + std::complex is defined
ComplexVariable solver::operator+(ComplexVariable cv1, ComplexVariable cv){
    cv1._pow2.v+=cv._pow2.v;
    cv1._pow1.v+=cv._pow1.v;
    cv1.v+=cv.v;
    return cv1;
}

//adding just the variable without no power.std::complex * int is defined
ComplexVariable solver::operator+(ComplexVariable cv1, complex<double> cv){
    complex<double> a,b,c;
    a.real(cv1._pow2.v.real());
    a.imag(cv1._pow2.v.imag());
    b.real(cv1._pow1.v.real() );
    b.imag(cv1._pow1.v.imag());
    c.real(cv1.v.real()+cv.real());
    c.imag(cv1.v.imag()+cv.imag() );
    return ComplexVariable(a,b,c);
}

ComplexVariable solver::operator-(double d, ComplexVariable cv){
    complex<double> a,b,c;
    a.real(cv._pow2.v.real());
    a.imag(cv._pow2.v.imag());
    b.real(cv._pow1.v.real() );
    b.imag(cv._pow1.v.imag());
    c.real(d-cv.v.real());
    c.imag(d-cv.v.imag() );
    return ComplexVariable(a,b,c);
}

    ComplexVariable solver::operator-(ComplexVariable cv1, ComplexVariable cv){
       cv1._pow2.v-=cv._pow2.v;
       cv1._pow1.v-=cv._pow1.v;
       cv.v-=cv.v;
       return cv1;
   }


//why - for double AND int?
ComplexVariable solver::operator-(ComplexVariable cv, int i){
    complex<double> a,b,c;
    a.real(cv._pow2.v.real());
    a.imag(cv._pow2.v.imag());
    b.real(cv._pow1.v.real());
    b.imag(cv._pow1.v.imag());
    c.real(cv.v.real()-i);
    c.imag(cv.v.imag());
    return ComplexVariable(a,b,c);
}

ComplexVariable solver::operator-(ComplexVariable cv, double d){
    complex<double> a=cv._pow2.v;
    complex<double> b=cv._pow1.v;
    complex<double> c=(cv.v.real()-d,cv.v.imag());
    return ComplexVariable(a,b,c);
}

ComplexVariable solver::operator-(ComplexVariable cv1, complex<double> cv){
    return ComplexVariable(cv1._pow2.v,cv1._pow1.v,cv1.v-cv);
}

//TO CHECK IF WE NEED TO DIVIDE ALSO THE REAL AND THE IMAGINERY NUMBER OR JUST THE REAL
ComplexVariable solver::operator/(double d, ComplexVariable cv){
    complex<double> a,b,c;
    a.real(d/cv._pow2.v.real());
    a.imag(d/cv._pow2.v.imag());
    b.real(d/cv._pow1.v.real() );
    b.imag(d/cv._pow1.v.imag());
    c.real(d/cv.v.real());
    c.imag(d/cv.v.imag() );
    return ComplexVariable(a, b, c);

}

ComplexVariable solver::operator/(ComplexVariable cv, int i){
    complex<double> a,b,c;
    a.real(cv._pow2.v.real()/i);
    a.imag(cv._pow2.v.imag()/i);
    b.real(cv._pow1.v.real()/i );
    b.imag(cv._pow1.v.imag()/i );
    c.real(cv.v.real()/i);
    c.imag(cv.v.imag()/i );
    return ComplexVariable(a, b, c);
}

ComplexVariable solver::operator^(ComplexVariable& cv, int i){
    if(i!=2)
        throw new invalid_argument("cant perform a power of a number other then 2");
    complex<double> b=(pow(cv._pow1.v.real(), i),pow(cv._pow1.v.imag(), i));
    complex<double> a=(pow(cv._pow2.v.real(), i),pow(cv._pow2.v.imag(), i));
    complex<double> c=(pow(cv.v.real(), i),pow(cv.v.imag(), i));
    if(a.real()==0)
        a.real(1);
    return ComplexVariable(a,b,c);
}



complex<double> solver::solve(ComplexVariable y){
    complex<double> d;
    if(y.v.real()==0&&y.v.imag()==0) {//if there is no numbers without variables,we check if the equation is quadratic
        if (y._pow2.v.real() != 0) {
            return y.qe();
        }
        else return (0,0);//if the equation is not quadratic,the solution to the equation is (0,0)
    }
    else{//there is a numbers without variables,we check if the equation is quadratic
        if(y._pow2.v.real()!=0)
        {
            //sending  to quadratic solving function
            return y.qe();
        } else//the equation probaly has a solotion,but not quadratic
        {
            d.real((y.v.real()*(-1))/y._pow1.v.real());
            d.imag((y.v.imag()*(-1))+y._pow1.v.imag());
            d.imag(d.imag()/y._pow1.v.real());
            return d;
        }
    }
    y._pow2.v.imag(0);
    y._pow2.v.real(0);
    y._pow1.v.imag(0);
    y._pow1.v.real(1);
    y.v.imag(0);
    y.v.real(0);
    return d;
}



 // * @param RealVariable rv
//  *
//  * result of < a*x^2 + b*x + c = 0 >
//  *
//  * @result vector with x1 and x2
//  */
/*
vector<double> Quadratic_Equation(RealVariable rv){
    double a = rv._pow2._coff, b = rv._pow1._coff , c = rv._coff;
     double delta = b*b-4*a*c;
     vector<double> ans;
     if (delta > 0){
         double x1 = (-1*b + sqrt(delta)) / (2*a);
         double x2 = (-1*b - sqrt(delta)) / (2*a);
         ans.push_back(x1);
         ans.push_back(x2);
     }
     else if (delta == 0){
         double x1 = (-1*b) / (2*a);
         ans.push_back(x1);
     }
         else
             cout << "Error! Delta is smaller than 0...\n";
     return ans;
 }
 */
