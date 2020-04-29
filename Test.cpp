
#include "doctest.h"
#include "solver.hpp"

// Real Variable:

// x in one degree -> x

TEST_CASE("Integer positive variable"){
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
    CHECK(solve((x^3)-3 == 6) == 3);
    CHECK(solve((x^3) == 8) == 2);
    CHECK(solve((x^3) == -27) == -9);
    CHECK(solve(8*(x^3)-12 == 60) == 2);
    CHECK(solve(3*(x^9)-1550 == -14) == 2);
} // 5


TEST_CASE("Integer variable, two results"){
    CHECK((solve((x^2) == 2) == 1) || (solve(x^2 == 2) == -1));
    CHECK((solve(3*(x^2) == 12) == 2) || (solve(3*x^2 == 12) == -2));
    CHECK((solve((x^2)-53 == 28) == 9) || (solve(x^2-53 == 28) == -9));
    CHECK((solve(7*(x^2)-95 == 17) == 4) || (solve(7*x^2-95 == 17) == -4));
    CHECK((solve(5.5*(x^2)-18 == 31.5) == 3) || (solve(5.5*x^2-18 == 31.5) == -3));
} // 5

TEST_CASE("Comparing Equations"){
    CHECK(solve(1.5*x+3*(x^2)+2 == 56) == 4);
    CHECK(solve(2*(x^2)+6 == (x^3)-3) == 3);
    CHECK(solve((x^2)+4*x+15 == 2.5*(x^2)-15) == 6);
    CHECK(solve((x^3)+3 == 3*(x^2)-x+23) == 4);
    CHECK(solve(5*x+8 == (x^2)+2*x-2) == 5);
    CHECK(solve(4*(x^2)-2*x+6.3 == 2(x^3)-2(x^2)-7*x+11.55) == 3.5); // 48.3 36.75
}
// 56

// Complex Variable:

TEST_CASE("simple complex"){
    CHECK((solve((x^2) == 4) == 2+0i) || (solve((x^2) == 4) == -2+0i));
    CHECK(solve((x^3) == 8) == 2+0i);
    CHECK(solve((x^5) == 32) == 2+0i);
    CHECK(solve((x^3) == 27) == 3+0i);
    CHECK((solve((x^2) == 9) == 3+0i) || (solve((x^2) == 9) == -3+0i));
    CHECK((solve((x^2) == 16) == 4+0i) || (solve((x^2) == 16) == -4+0i));
    CHECK((solve((x^2) == 25) == 5+0i) || (solve((x^2) == 25) == -5+0i));

    CHECK(solve((x^2) == -1) == 0+1i);
    CHECK(solve((x^2) == -4) == 0+2i);
    CHECK(solve((x^2) == -9) == 0+3i);
    CHECK(solve((x^4) == -16) == 0+4i);
    CHECK(solve((x^2) == -25) == 0+5i);
    CHECK(solve((x^2) == -36) == 0+6i);
} // 13

TEST_CASE("num + 0i"){
    CHECK(solve(2*(x^2)-4 == 10) == 7+0i);
    CHECK(solve(2*(x^2)-8 == 10) == 9+0i);
    CHECK(solve(2*(x^2)+4 == 10) == 3+0i);
    CHECK(solve(3*(x^2)+6.5 == 18.5) == 4+0i);
    CHECK(solve(4*(x^2)-2 == 6) == 2+0i);

    CHECK(solve(4.5*(x^2)+2.3 == 22.3) == 5+0i);
    CHECK(solve(2.25*(x^2)+1 == 12.25) == 5+0i);
    CHECK(solve(4-9*(x^2) == -14) == 2+0i);
    CHECK(solve(9*(x^2)-5 == 22) == 3+0i);
    CHECK(solve(5*(x^2)-4 == 16) == 4+0i);

    CHECK(solve(6*x+1 == 14) == 2.5+0i);
    CHECK(solve(5*x+6 == 14) == 1.6+0i);
    CHECK(solve(-2.5*x+7 == 13.875) == -2.75+0i);
    CHECK(solve(12*x+4 == 1) == -0.25+0i);
    CHECK(solve(10*x+10 == -5) == -1.5+0i);

} // 15
    
TEST_CASE("Complex"){
    CHECK(solve((x^2)-4 == -13) == 0+3i);
    CHECK(solve(-2*(x^2)-25 == 7) == 0+4i);
    CHECK(solve((x^4)*-4-60 == 4) == 0+2i);
    CHECK(solve(2.5*(x^2)-2 == -52.625) == 0+4.5i);
    CHECK(solve(3.7*(x^2)+5.6 == -27.7) == 0+3i);
    CHECK(solve(10.35*(x^2)+6.9 == 1.8285) == 0+0.7i);
    CHECK(solve(0.5*(x^4)+27 == -13.5) == 0+3i);

    CHECK(solve(3*(x^3)-5 == -5-24i) == 0+2i);
    CHECK(solve((x^2)-5x == -15-3i) == 2+3i); 
    CHECK(solve(2*(x^2)-2 == 2+16i) == 2+2i);
    CHECK(solve((x^2)-3*x+6i == 1+27i) == 5+3i);
    CHECK(solve(2.5*(x^2)+2x+3-1i == -5.5+35i) == 2+3i);
    CHECK(solve(5*(x^3)+2*(x^2)+3-3i== -7+11i) == 1+1i);
    CHECK(solve(5.2*(x^4)+2*x+3i == -34.4+123.8i) == 1-2i);
    CHECK(solve(7*(x^2)-6*x+3-2i == -156-112i) == 2-5i);
    CHECK(solve(1.5*(x^3)-3(x^2)+x-6+17i == 254.5-330i) == 7-2i);
    CHECK(solve((x^2)-x-1 == (x^3)-2*(x^2)+x+47-6i) == 3+3i);
    CHECK(solve(2*(x^2)-6.5 == (x^3)+5*(x^2)+12*x+273.5) == 2-6i);
    CHECK(solve(-3*(x^4)+2*x+6 == -5*(x^3)+2*(x^2)+29*x-49) == 1+2i);
    CHECK(solve(2*(x^2) == 14*x-74-10i) == 4-5i);
    CHECK(solve(3*(x^2)-x+25.75+16i == 10*x-31) == 2.5-4i);

} // 21
