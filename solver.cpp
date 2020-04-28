//
// Created by amichai hadad on 26/04/2020.
//

#include "solver.hpp"
#include <iostream>
#include <complex>
using namespace std;

namespace solver {



    RealVariable& operator==(double x, RealVariable& y) {
        return y == x;
    }

    RealVariable& operator+(double x, RealVariable &y) {
        cout << "gere " <<x<<"+y" << endl;
        return y + x;
    }

    RealVariable& operator-(double x, RealVariable &y) {
        y = y * -1;
        return x + y;
    }

    RealVariable& operator*(double x, RealVariable &y) {
        return y * x;
    }

    RealVariable& RealVariable::operator+(double x) {
        this->sum = this->sum + x;
        return *this;
    }

    RealVariable& RealVariable::operator==(double x) {
        this->coff = this->coff*-1;
        this->sum= (this->sum*-1)+x;
        return *this;
    }
    RealVariable& RealVariable::operator==(RealVariable& x) {
        cout << "here x == x"<< endl;
        this->coff = this->coff*-1;
        this->sum= this->sum*-1;
        return *this;
    }

    RealVariable& RealVariable::operator+(RealVariable &x) {
        return *this;
    }

    RealVariable& RealVariable::operator-(double x) {
        this->sum = this->sum - x;
        this->coff = this->coff - x;
        return *this;
    }

    RealVariable& RealVariable::operator-(RealVariable &x) {
        this->sum = this->sum - x.sum;
        return *this;
    }

    RealVariable& RealVariable::operator*(double x) {
        this->coff = this->coff * x;
        this->sum = this->sum * x;
        return *this ;

    }

    RealVariable& RealVariable::operator*(RealVariable &x) {
        this->coff = this->coff * x.coff;
        return *this ;
    }

    RealVariable& RealVariable::operator^(double x) {
        this->power = this->power * x;
        return *this;
    }

    RealVariable& RealVariable::operator/(RealVariable &x) {
        this->coff = this->coff / x.coff;
        return *this;
    }

    RealVariable& RealVariable::operator/(double x) {
        this->coff = this->coff / x;
        return *this;
    }


    ComplexVariable& operator==(std::complex<double> x, ComplexVariable &y) {
        return y == x;
    }

    ComplexVariable& operator+(std::complex<double> x, ComplexVariable &y) {
        return y + x;
    }

    ComplexVariable& operator-(std::complex<double> x, ComplexVariable &y) {
        y = y * -1;
        return x - y;
    }

    ComplexVariable& operator*(std::complex<double> x, ComplexVariable &y) {
        return y * x;
    }

    ComplexVariable& ComplexVariable::operator+(std::complex<double> x){
        this->sum = this->sum+x;
        return *this;
    }
    ComplexVariable& ComplexVariable::operator==(std::complex<double> x){
        return *this;
    }

    ComplexVariable& ComplexVariable::operator+(ComplexVariable &x){
        this->sum = this->sum+x.sum;
        return *this;
    }
    ComplexVariable& ComplexVariable::operator==(ComplexVariable &x){
        return *this;
    }

    ComplexVariable &ComplexVariable::operator-(std::complex<double> x){
        return *this;
    }

    ComplexVariable &ComplexVariable::operator-(ComplexVariable &x){
        return *this;

    }

    ComplexVariable &ComplexVariable::operator*(std::complex<double> x){
        return *this;

    }

    ComplexVariable &ComplexVariable::operator*(ComplexVariable &x){
        return *this;

    }

    ComplexVariable &ComplexVariable::operator^(std::complex<double> x){
        return *this;

    }

    ComplexVariable &ComplexVariable::operator^(ComplexVariable &x){
        return *this;

    }

    ComplexVariable &ComplexVariable::operator/(std::complex<double> x){
        return *this;

    }

    ComplexVariable &ComplexVariable::operator/(ComplexVariable &x){
        return *this;

    }
    double solve(RealVariable& x) {

        try {
            double temp = x.sum;
            if (x.coff == 0) {
                cout << "err" << endl;

                return 0;
            }
            temp = temp / x.coff;
            temp = pow(temp, 1.0 / x.power);
            x.coff=1;
            x.sum=0;
            x.power=1;
            return temp;
        }

        catch (const std::exception &e) {
            cout << e.what() << endl;
            return 0;
        }
    }


    std::complex<double> solve(ComplexVariable& x) {
        return x.value;
    }

};
