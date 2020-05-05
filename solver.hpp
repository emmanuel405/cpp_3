#pragma once

#include <complex.h>
using namespace std;
namespace solver{
    
    class RealVariable{
    public:
        struct pow2{
            double _coff;
        } _pow2;
        struct pow1{ 
            double _coff;
        } _pow1;
        double _coff;
    
    
		RealVariable(double d_pow2, double d_pow1, double d){
			_pow2._coff = d_pow2;
			_pow1._coff = d_pow1;
			_coff = d;
		}
		RealVariable(){
			_pow2._coff = 0;
			_pow1._coff = 1;
			_coff = 0;
        }

        friend RealVariable operator==(RealVariable rv, double d);
        friend RealVariable operator==(double d, RealVariable rv);
        friend RealVariable operator==(RealVariable rv, RealVariable rv1);


        friend RealVariable operator*(RealVariable rv, double d);
        friend RealVariable operator*(double d, RealVariable rv);

        friend RealVariable operator/(RealVariable rv, double d);
        friend RealVariable operator/(RealVariable rv, int i);

        friend RealVariable operator+(RealVariable rv, RealVariable rv1);
        friend RealVariable operator+(RealVariable rv, double d);
        friend RealVariable operator+(double d, RealVariable rv);

        friend RealVariable operator-(RealVariable rv, RealVariable rv1);
        friend RealVariable operator-(RealVariable rv, double d);
        friend RealVariable operator-(RealVariable rv, int i);

        friend RealVariable operator^(RealVariable rv, const int degree);

        friend double Quadratic_Equation(const RealVariable rv);


    };
    double solve(const RealVariable rv);
  

 class ComplexVariable{
    private:
        /*
         * changed the class members to be std::complex so it will be more efficient
         * in the init of the variable,when we want to multiply/divide we will conflict a problem because we are dealing with zero
         * and we will lose the value.i generated a boolean
         *  added boolean variable to check whatever we passed the == operator and we need to flip the sign of all the number
         *  afterwords
         *  TRYING SPLITTING THE EQUATION INTO 2 HALVES
         */
            struct pow2 {
                std::complex<double> v;
            } _pow2;
            struct pow1 {
                std::complex<double> v;
            } _pow1;
            std::complex<double> v;
            bool isInit= true;
    public:

        ComplexVariable(std::complex<double> pow2,std::complex<double> pow1, std::complex<double> pow0 ){
            _pow2.v=pow2;
            _pow1.v=pow1;
            v=pow0;
        }

        ComplexVariable(){
            _pow2.v.imag(0);
            _pow2.v.real(0);
            _pow1.v.imag(0);
            _pow1.v.real(1);
            v.imag(0);
            v.real(0);
        }

        /*
         * changed all the friend functions to get refrence variable of cv instead of cv so the changed wil be saved
         */
        friend ComplexVariable operator==(ComplexVariable cv, double d);
        friend ComplexVariable operator==(double d, ComplexVariable cv);
        friend ComplexVariable operator==(ComplexVariable cv1, complex<double> cv);
        friend ComplexVariable operator==(ComplexVariable cv1, ComplexVariable cv);

        friend ComplexVariable operator*(double d, ComplexVariable& cv);
        friend ComplexVariable operator*(ComplexVariable cv, double d);
        friend ComplexVariable operator*(ComplexVariable cv, int i);
        friend ComplexVariable operator*(int i, ComplexVariable cv);

        friend ComplexVariable operator^(ComplexVariable& cv, int i);

        friend ComplexVariable operator+(double d, ComplexVariable cv);
        friend ComplexVariable operator+(ComplexVariable cv, double d);
        friend ComplexVariable operator+(ComplexVariable cv, int i);
        friend ComplexVariable operator+(ComplexVariable cv1, ComplexVariable cv);
        friend ComplexVariable operator+(ComplexVariable cv1, complex<double> cv);

        friend ComplexVariable operator-(double d, ComplexVariable cv);
        friend ComplexVariable operator-(ComplexVariable cv1, ComplexVariable cv);
        friend ComplexVariable operator-(ComplexVariable cv, int i);
        friend ComplexVariable operator-(ComplexVariable cv, double d);
        friend ComplexVariable operator-(ComplexVariable cv1, complex<double> cv);


        friend ComplexVariable operator/(double d, ComplexVariable cv);
        friend ComplexVariable operator/(ComplexVariable cv, int i);

        friend  complex<double> solve(ComplexVariable y);

    };

}
