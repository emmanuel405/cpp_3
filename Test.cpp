
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
    CHECK(solve(10*x+10 == 0) == -1);
    CHECK(solve(6*x+4 == -0.5) == -0.75);
} // 10


// x in up of one degree -> x^2.. etc

TEST_CASE("Integer variable, one result"){
    CHECK(solve(x^3-3 == 6) == 3);
    CHECK(solve(x^3 == 8) == 2);
    CHECK(solve(x^3 == -27) == -9);
    CHECK(solve(8*x^3-12 == 60) == 2);
    CHECK(solve(3*x^9-1550 == -14) == 2);
} // 5


TEST_CASE("Integer variable, two results"){
    CHECK((solve(x^2 == 2) == 1) || (solve(x^2 == 2) == -1));
    CHECK((solve(3*x^2 == 12) == 2) || (solve(3*x^2 == 12) == -2));
    CHECK((solve(x^2-53 == 28) == 9) || (solve(x^2-53 == 28) == -9));
    CHECK((solve(7*x^2-95 == 17) == 4) || (solve(7*x^2-95 == 17) == -4));
    CHECK((solve(5.5*x^2-18 == 31.5) == 3) || (solve(5.5*x^2-18 == 31.5) == -3));
} // 5
