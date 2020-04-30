
#include "doctest.h"
#include "solver.hpp"
#include <complex.h>

using namespace std;
// Real Variable:
using solver::solve;
solver::RealVariable x;
solver::ComplexVariable y;

TEST_CASE("Integer positive variable"){
solver::RealVariable x;
    CHECK(solve(2*x-4 == 10) == 7);
    CHECK(solve(2*x-8 == 10) == 9);
    CHECK(solve(2*x+4 == 10) == 3);
    CHECK(solve(3*x+6.5 == 18.5) == 4);
    CHECK(solve(4*x-2 == 6) == 2);
    CHECK(solve(4.5*x+2.3 == 22.3) == 5);
    CHECK(solve(2.25*x+1 == 12.25) == 5);
    CHECK(solve(4-9*x == -14) == 2);
    CHECK(solve(9*x-5 == 22) == 3);
    CHECK(solve(5*x-4 == 16) == 4);
} // 10

TEST_CASE("Integer negative variable"){
solver::RealVariable x;
    CHECK(solve(2*x-4 == -10) == -3);
    CHECK(solve(2*x+5 == -7) == -6);
    CHECK(solve(2*x-8 == -10) == -1);
    CHECK(solve(3*x-6 == -12) == -2);
    CHECK(solve(4*x+2 == -6) == -2);
    CHECK(solve(2.25*x+1 == -10.25) == -5);
    CHECK(solve(8*x+2 == -6) == -1);
    CHECK(solve(20*x+29 == -11) == -2);
    CHECK(solve(7*x+21 == 0) == -3);
    CHECK(solve(9*x+5 == -13) == -2);
} // 10

TEST_CASE("Double positive variable"){
solver::RealVariable x;
    CHECK(solve(2*x+5 == 18) == 6.5);
    CHECK(solve(5-x == 2.6) == 2.4);
    CHECK(solve(4*x-7 == 3) == 2.25);
    CHECK(solve(5*x == 14) == 2.8);
    CHECK(solve(6*x+1 == 14) == 2.5);
    CHECK(solve(5*x+6 == 14) == 1.6);
    CHECK(solve(2*x-6 == 4.6) == 5.3);
    CHECK(solve(2*x-4.3 == 8.1) == 6.2);
    CHECK(solve(3.5*x-6 == 7.65) == 3.9);
    CHECK(solve(2.5*x+2.5 == 14) == 4.6);
} // 10

TEST_CASE("Double negative variable"){
solver::RealVariable x;
    CHECK(solve(4*x-7 == -13) == -1.5);
    CHECK(solve(4.5*x+2.3 == -12.65) == -2.3);
    CHECK(solve(3+x == -8.522) == -11.522);
    CHECK(solve(2*x+4 == -0.5) == -2.25);
    CHECK(solve(x == -0.5) == -0.5);
    CHECK(solve(3*x+6 == 1.5) == -1.5);
    CHECK(solve(-2.5*x+7 == 13.875) == -2.75);
    CHECK(solve(12*x+4 == 1) == -0.25);
    CHECK(solve(10*x+10 == -5) == -1.5);
    CHECK(solve(6*x+4 == -0.5) == -0.75);
} // 10


// x in up of one degree -> x^2.. etc

TEST_CASE("Integer variable, one result"){
solver::RealVariable x;
    CHECK(solve((x^3)-3 == 6) == 3);
    CHECK(solve((x^3) == 8) == 2);
    CHECK(solve((x^3) == -27) == -9);
    CHECK(solve(8*(x^3)-12 == 60) == 2);
    CHECK(solve(3*(x^9)-1550 == -14) == 2);
} // 5


TEST_CASE("Integer variable, two results"){
solver::RealVariable x;
    CHECK((solve((x^2) == 2) == 1) || (solve((x^2) == 2) == -1));
    CHECK((solve(3*(x^2) == 12) == 2) || (solve(3*(x^2) == 12) == -2));
    CHECK((solve((x^2)-53 == 28) == 9) || (solve((x^2)-53 == 28) == -9));
    CHECK((solve(7*(x^2)-95 == 17) == 4) || (solve(7*(x^2)-95 == 17) == -4));
    CHECK((solve(5.5*(x^2)-18 == 31.5) == 3) || (solve(5.5*(x^2)-18 == 31.5) == -3));
} // 5

TEST_CASE("Comparing Equations"){
solver::RealVariable x;
    CHECK(solve(1.5*x+3*(x^2)+2 == 56) == 4);
    CHECK(solve(2*(x^2)+6 == (x^3)-3) == 3);
    CHECK(solve((x^2)+4*x+15 == 2.5*(x^2)-15) == 6);
    CHECK(solve((x^3)+3 == 3*(x^2)-x+23) == 4);
    CHECK(solve(5*x+8 == (x^2)+2*x-2) == 5);
    CHECK(solve(4*(x^2)-2*x+6.3 == 2*(x^3)-2*(x^2)-7*x+11.55) == 3.5); // 48.3 36.75
}
// 56

// Complex Variable:

TEST_CASE("simple complex"){
solver::ComplexVariable y;
    CHECK((solve((y^2) == 4) == complex<double>(2,0)) || (solve((y^2) == 4) == complex<double>(-2,0)));
    CHECK(solve((y^3) == 8) == complex<double>(2,0));
    CHECK(solve((y^5) == 32) == complex<double>(2,0));
    CHECK(solve((y^3) == 27) == complex<double>(3,0));
    CHECK((solve((y^2) == 9) == complex<double>(3,0)) || (solve((y^2) == 9) == complex<double>(-3,0)));
    CHECK((solve((y^2) == 16) == complex<double>(4,0)) || (solve((y^2) == 16) == complex<double>(-4,0)));
    CHECK((solve((y^2) == 25) == complex<double>(5,0)) || (solve((y^2) == 25) == complex<double>(-5,0)));

    CHECK(solve((y^2) == -1) == complex<double>(0,1));
    CHECK(solve((y^2) == -4) == complex<double>(0,2));
    CHECK(solve((y^2) == -9) == complex<double>(0,3));
    CHECK(solve((y^4) == -16) == complex<double>(0,4));
    CHECK(solve((y^2) == -25) == complex<double>(0,5));
    CHECK(solve((y^2) == -36) == complex<double>(0,6));
} // 13

TEST_CASE("num + 0i"){
solver::ComplexVariable y;
    CHECK(solve(2*(y^2)-4 == 10) == complex<double>(7,0));
    CHECK(solve(2*(y^2)-8 == 10) == complex<double>(9,0));
    CHECK(solve(2*(y^2)+4 == 10) == complex<double>(3,0));
    CHECK(solve(3*(y^2)+6.5 == 18.5) == complex<double>(4,0));
    CHECK(solve(4*(y^2)-2 == 6) == complex<double>(2,0));

    CHECK(solve(4.5*(y^2)+2.3 == 22.3) == complex<double>(5,0));
    CHECK(solve(2.25*(y^2)+1 == 12.25) == complex<double>(5,0));
    CHECK(solve(4-9*(y^2) == -14) == complex<double>(2,0));
    CHECK(solve(9*(y^2)-5 == 22) == complex<double>(3,0));
    CHECK(solve(5*(y^2)-4 == 16) == complex<double>(4,0));

    CHECK(solve(6*y+1 == 14) == complex<double>(2.5,0));
    CHECK(solve(5*y+6 == 14) == complex<double>(1.6,0));
    CHECK(solve(-2.5*y+7 == 13.875) == complex<double>(-2.75,0));
    CHECK(solve(12*y+4 == 1) == complex<double>(-0.25,0));
    CHECK(solve(10*y+10 == -5) == complex<double>(-1.5,0));

} // 15
    
TEST_CASE("Complex - Comparing Equations"){
solver::ComplexVariable y;
    CHECK(solve((y^2)-4 == -13) == complex<double>(0,3));
    CHECK(solve(-2*(y^2)-25 == 7) == complex<double>(0,4));
    CHECK(solve((y^4)*-4-60 == 4) == complex<double>(0,2));
    CHECK(solve(2.5*(y^2)-2 == -52.625) == complex<double>(0,4.5));
    CHECK(solve(3.7*(y^2)+5.6 == -27.7) == complex<double>(0,3));
    CHECK(solve(10.35*(y^2)+6.9 == 1.8285) == complex<double>(0,0.7));
    CHECK(solve(0.5*(y^4)+27 == -13.5) == complex<double>(0,3));

    CHECK(solve(3*(y^3)-5 == complex<double>(-5,-24)) == complex<double>(0,2));
    CHECK(solve((y^2)-5*y == complex<double>(-15,-3)) == complex<double>(2,3)); 
    CHECK(solve(2*(y^2)-2 == complex<double>(2,16)) == complex<double>(2,2));
    CHECK(solve((y^2)-3*y+complex<double>(0,6) == complex<double>(1,27)) == complex<double>(5,3));
    CHECK(solve(2.5*(y^2)+2*y+complex<double>(3,-1) == complex<double>(-5.5,35)) == complex<double>(2,3));
    CHECK(solve(5*(y^3)+2*(y^2)+complex<double>(3,-3) == complex<double>(-7,11)) == complex<double>(1,1));
    CHECK(solve(5.2*(y^4)+2*y+complex<double>(0,3) == complex<double>(-34.4,123.8)) == complex<double>(1,-2));
    CHECK(solve(7*(y^2)-6*y+complex<double>(3,-2) == complex<double>(-156,-112)) == complex<double>(2,-5));
    CHECK(solve(1.5*(y^3)-3*(y^2)+1*y+complex<double>(-6,17) == complex<double>(254.5,-330)) == complex<double>(7-2));
    CHECK(solve((y^2)-1*y-1 == (y^3)-2*(y^2)+1*y+complex<double>(47,-6)) == complex<double>(3,3));
    CHECK(solve(2*(y^2)-6.5 == (y^3)+5*(y^2)+12*y+273.5) == complex<double>(2,-6));
    CHECK(solve(-3*(y^4)+2*y+6 == -5*(y^3)+2*(y^2)+29*y-49) == complex<double>(1,2));
    CHECK(solve(2*(y^2) == 14*y-complex<double>(74,10)) == complex<double>(4,-5));
    CHECK(solve(3*(y^2)-1*y+complex<double>(25.75,16) == 10*y-31) == complex<double>(2.5,-4));

} // 21