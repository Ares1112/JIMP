#ifndef AGHCOMPLEX_H
#define AGHCOMPLEX_H
class aghComplex{
private:
    double re;
    double im;
public:
    aghComplex(){ re = 0; im = 0;}
    aghComplex(double re, double im);
    ~aghComplex();
    aghComplex& operator+ (const aghComplex&);
    aghComplex& operator* (const aghcomplex&);
    //cos przeciazyc zeby dzialalo z aghMatrix
};

#endif
