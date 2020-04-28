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
        x = pow(x, 1.0 / this->power);
        x = x / this->coff;
        x = x - this->sum;
        this->value = x;
        return *this;
    }
    RealVariable& RealVariable::operator==(RealVariable& x) {
        return *this;
    }

    RealVariable& RealVariable::operator+(RealVariable &x) {
        this->sum = this->sum + x.sum;
        this->coff = this->coff + x.coff;
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
        return x.value;
    }

    std::complex<double> solve(ComplexVariable& x) {
        return x.value;
    }

};
