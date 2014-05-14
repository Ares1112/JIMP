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
        T setItems(T* elem);
        void setItems(int r, int c, ...);
        aghMatrix& operator= (const aghMatrix&);
        aghMatrix operator+ (const aghMatrix&);
        aghMatrix operator* (const aghMatrix&);
        aghMatrix operator== (const aghMatrix&);
        aghMatrix operator!= (const aghMatrix&);
        T operator() (int a, int b); 
};

aghMatrix::setItem(int wier, int kol, T el)
{
   tab[wier][kol]=el;
}

aghMatrix::setItems(T*elem)
{
  
}

aghMatrix::aghMatrix& operator= (const aghMatrix& A)
{
  if(tab!=NULL)   //trzeba sprawdzic,czy tablica jest utworzona
  { 
	for(int i=0; i<wier; i++)       //nie wiem czy wiersze,czy kolumny
      		delete [] tab[i];
  	delete [] tab;
  }
  for(int i=0; i<A.wier; i++)
	tab[i]=new T[A.kol];
  
  for(int i=0; i<A.wier; i++)
	for(int j=0; i<A.wier; i++)
		tab[i][j]=A.tab[i][j];

	wier=A.wier;
	kol=A.kol;
    elem[]  //nie wiem co z tym zrobic;	

   return ... //     
}

aghMatrix::aghMatrix operator+(const aghMatrix& A)
{
	aghMatrix Temp;
    
    for(int i=0; i<A.wier; i++)   ///czy kol czy wier
	   tab[i]=new T[A.kol]; 

	for(int i=0; i<wier; i++)
		for(int j=0; j<kol; j++)
			Temp.tab[i][j]=tab[i][j]+A.tab[i][j];
	Temp.wier=wier;
	Temp.kol=kol;
	elem[] //nie wiem co z tym zrobic
	return Temp;
}

aghMatrix operator*(aghMatrix& A)
{
	aghMatrix Temp;
   for(int i=0; i<wier; i++)   ///czy kol czy wier
	   tab[i]=new T[A.kol];
	
    for(int i=0; i<wier; i++)
		for(int j=0; j<A.kol; i++)
			Temp.tab[i][j]=0; 

  for (int i=0; i<wier; i++)
    for (int j=0; i<A.kol; i++)
      for (int p=0; p=kol; p++)
        Temp.tab[i][j]:=Temp.tab[i][j]+tab[i][p]*A.tab[p][j];
	Temp.wier=wier;
	Temp.kol=A.kol;
	Temp.elem[];//nie wiem co to

}



#endif
