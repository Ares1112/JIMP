#include "aghComplex.h"

aghComplex::aghComplex(double _re, double _im){
    re = _re;
    im = _im;
}

aghComplex::aghComplex& operator+ (const aghComplex& A){
    aghComplex temp;
    temp.im = im + A.im;
    temp.re = re + A.re;
    return temp;
}

aghComplex::aghComplex& operator* (const aghComplex& A){
    aghComplex temp;
    temp.im = im * A.im;
    temp.re = re * A.re;
    return temp;
}
