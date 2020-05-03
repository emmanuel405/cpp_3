#pragma once

#include <complex.h>
using namespace std;
namespace solver{
    
    class RealVariable{
    private:
        struct pow2{
            double _coff;
        } _pow2;
        struct pow1{ 
            double _coff;
        } _pow1;
        double _coff, _res;
    
    public:
		Real(double d_pow2, double d_pow1, double d){
			_pow2._coff = d_pow2;
			_pow1._coff = d_pow1;
			_coff = d;
		}
		Real(){
			_pow2._coff = 0;
			_pow1._coff = 0;
			_coff = 0;
		}


// 2*x+2 == x^2*3-5 / 9

        friend double operator==(RealVariable rv, double d);
        friend double operator==(double d, RealVariable rv);
        friend double operator==(RealVariable rv1, RealVariable rv);
        friend RealVariable operator*(double d, RealVariable rv);
        friend RealVariable operator*(RealVariable rv, double d);

        friend RealVariable operator^(RealVariable rv, int i);

        friend RealVariable operator+(RealVariable rv1, RealVariable rv);
        friend RealVariable operator+(RealVariable rv1, double d);

        friend RealVariable operator-(RealVariable rv1, RealVariable rv);
        friend RealVariable operator-(RealVariable rv1, double d);
        friend RealVariable operator-(RealVariable rv1, int i);

        friend RealVariable operator/(double d, RealVariable rv);
        friend RealVariable operator/(RealVariable rv, int i);


    };

    class ComplexVariable{
    private:
        struct pow2{
            double _re, _im;
        } _pow2;
        struct pow1{ 
            double _re, _im;
        } _pow1;
        double _re, _im, _res;
    
    public:
        ComplexVariable(double re_pow2, double im_pow2, double re_pow1, double im_pow1, double re, double im ){
            _pow2._re = re_pow2;
            _pow2.im = im_pow2;
            _pow1._re = re_pow1;
            _pow1.im = im_pow1;
			_re = re;
			_im = im;
        }
        ComplexVariable(){
            _pow2._re = 0;
            _pow2.im = 0;
            _pow1._re = 0;
            _pow1.im = 0;
			_re = 0;
			_im = 0;
        }

        friend ComplexVariable operator==(ComplexVariable cv, double d);
        friend ComplexVariable operator==(double d, ComplexVariable cv);
        friend ComplexVariable operator==(ComplexVariable cv1, complex<double> cv);
        friend ComplexVariable operator==(ComplexVariable cv1, ComplexVariable cv);


        friend ComplexVariable operator*(double d, ComplexVariable cv);
        friend ComplexVariable operator*(ComplexVariable cv, double d);
        friend ComplexVariable operator*(ComplexVariable cv, int i);
        friend ComplexVariable operator*(int i, ComplexVariable cv);

        friend ComplexVariable operator^(ComplexVariable cv, int i);

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

    };

    double solve(double d);
    complex<double> solve(ComplexVariable y);

}