#include "aghComplex.h"
#include "aghInclude.h"
aghComplex::aghComplex(double _re, double _im){
    this->re = _re;
    this->im = _im;
}

aghComplex::~aghComplex(){

}

const aghComplex aghComplex::operator+ (const aghComplex& A){
    return aghComplex(re+A.re, im+A.im);
}

const aghComplex aghComplex::operator* (const aghComplex& A){
    return aghComplex(re*A.re-im*A.im, re*A.im+im*A.re);
}

void aghComplex::operator+=(const aghComplex& A){
   this->re += A.re;
   this->im += A.im;
}

bool aghComplex::operator==(const aghComplex& A){
   return((re == A.re) && (im == A.im));
}

bool aghComplex::operator!=(const aghComplex& A){
   return!((re == A.re) && (im == A.im));
}

