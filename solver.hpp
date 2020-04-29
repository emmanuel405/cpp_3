#pragma once


namespace solver{
    
    class RealVariable{
    private:
    
        double _coff, _deg;
    
    public:
    RealVariable(double coff = 0, double deg = 0): _coff(coff), _deg(deg) {}


// 2*x+2 == x^2*3-5 / 9

    friend double operator==(RealVariable rv, double d);
    friend double operator==(double d, RealVariable rv);
    friend double operator==(RealVariable rv1, RealVariable rv);
    friend RealVariable operator*(double d, RealVariable rv);
    friend RealVariable operator^(RealVariable rv, int i);
    friend RealVariable operator+(RealVariable rv1, RealVariable rv);
    friend RealVariable operator+(RealVariable rv1, double d);
    friend RealVariable operator-(RealVariable rv1, RealVariable rv);
    friend RealVariable operator-(RealVariable rv1, double d);
    friend double operator-(RealVariable rv1, int i);
    friend RealVariable operator/(double d, RealVariable rv);
    friend RealVariable operator/(RealVariable rv, int i);


    };

    class ComplexVariable{
    private:

        double _re, _im;
    
    public:
    ComplexVariable(double re = 0, double im = 0): _re(re), _im(im){}

    friend double operator==(ComplexVariable cv, double d);
    friend double operator==(double d, ComplexVariable cv);
    friend double operator==(ComplexVariable cv1, ComplexVariable cv);
    friend ComplexVariable operator*(double d, ComplexVariable cv);
    friend ComplexVariable operator^(ComplexVariable cv, int i);
    friend ComplexVariable operator+(double d, ComplexVariable cv);
    friend ComplexVariable operator+(ComplexVariable cv, int i);
    friend ComplexVariable operator+(ComplexVariable cv1, ComplexVariable cv);
    friend double operator+(ComplexVariable cv1, std::complex<double> cv);
    friend ComplexVariable operator-(double d, ComplexVariable cv);
    friend ComplexVariable operator-(ComplexVariable cv1, ComplexVariable cv);
    friend double operator-(ComplexVariable cv, int i);
    friend ComplexVariable operator/(double d, ComplexVariable cv);
    friend ComplexVariable operator/(ComplexVariable cv, int i);

    };

    double solve(double x);
    std::complex<double> solve(ComplexVariable y);

}