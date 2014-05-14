#ifndef AGHMATRIX_H
#define AGHMATRIX_H

template <class T>
class aghMatrix{
    private:
        int wier;
        int kol;
        T** tab;
        T elem[]; 
    public:
        aghMatrix(){wier=0;kol=0;}
        aghMatrix(int wier, int kol);
        ~aghMatrix();
        void setItem(int wier, int kol, T el);
        void setItems(T* elem);
        void setItems(int r, int c, ...);
        aghMatrix& operator= (const aghMatrix&);
        aghMatrix operator+ (const aghMatrix&);
        aghMatrix operator* (const aghMatrix&);
        aghMatrix operator== (const aghMatrix&);
        aghMatrix operator!= (const aghMatrix&);
        T operator() (int a, int b); 
};

#endif
