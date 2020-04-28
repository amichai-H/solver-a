//
// Created by amichai hadad on 26/04/2020.
//

#ifndef SOLVER_A_MASTER_SOLVER_HPP
#define SOLVER_A_MASTER_SOLVER_HPP
#include <iostream>
#include <complex>
using namespace std;
namespace solver {
    class RealVariable {
    public:
        double coff = 1;
        double power = 1;
        double sum = 0;
        double value;
        RealVariable& operator==(double x);

        RealVariable &operator==(RealVariable &x);

        RealVariable &operator+(double x);

        RealVariable &operator+(RealVariable &x);

        RealVariable &operator-(double x);

        RealVariable &operator-(RealVariable &x);

        RealVariable &operator*(double x);

        RealVariable &operator*(RealVariable &x);

        RealVariable &operator^(double x);

        RealVariable &operator^(RealVariable &x);

        RealVariable &operator/(double x);

        RealVariable &operator/(RealVariable &x);

    };

    class ComplexVariable {
    public:
        std::complex<double> coff = 1;
        std::complex<double> power = 1;
        std::complex<double> sum = 0;

        std::complex<double> value;

        ComplexVariable &operator+(std::complex<double> x);
        ComplexVariable &operator==(std::complex<double> x);

        ComplexVariable &operator+(ComplexVariable &x);
        ComplexVariable &operator==(ComplexVariable &x);

        ComplexVariable &operator-(std::complex<double> x);

        ComplexVariable &operator-(ComplexVariable &x);

        ComplexVariable &operator*(std::complex<double> x);

        ComplexVariable &operator*(ComplexVariable &x);

        ComplexVariable &operator^(std::complex<double> x);

        ComplexVariable &operator^(ComplexVariable &x);

        ComplexVariable &operator/(std::complex<double> x);

        ComplexVariable &operator/(ComplexVariable &x);
    };




    RealVariable& operator==(double x, RealVariable &y);

    RealVariable &operator+(double x, RealVariable &y);

    RealVariable &operator-(double x, RealVariable &y);

    RealVariable &operator*(double x, RealVariable &y);

    RealVariable &operator/(double x, RealVariable &y);

    ComplexVariable& operator==(std::complex<double> x, ComplexVariable &y);

    ComplexVariable &operator+(std::complex<double> x, ComplexVariable &y);

    ComplexVariable &operator-(std::complex<double> x, ComplexVariable &y);

    ComplexVariable &operator*(std::complex<double> x, ComplexVariable &y);

    ComplexVariable &operator/(std::complex<double> x, ComplexVariable &y);

         double solve(RealVariable& x);

         std::complex<double> solve(ComplexVariable& x);



};


#endif //SOLVER_A_MASTER_SOLVER_HPP
