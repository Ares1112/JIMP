#ifndef 	AGHMATRIX_H
#define AGHMATRIX_H
#include <iostream>
using namespace std;
template <class T>
class aghMatrix
{
private:
	int wier;
   int kol;
   T** tab;
   void rezerwuj(int w, int k);
	void zwolnij();

public:
   aghMatrix();
   aghMatrix(int w, int k);
   ~aghMatrix();
   void setItem(int w, int k, T el);
   void setItems(T* elem);
   void setItems(int r, int c, ...);
	void wypisz();
   aghMatrix const & operator=(aghMatrix<T> const &A);

   const aghMatrix operator+ (const aghMatrix&);
   const aghMatrix operator* (const aghMatrix&);
   bool operator==(aghMatrix<T>& A) const;
	bool operator!=(aghMatrix<T>& A) const;
   T operator() (int w, int k) const;

};


template<class T>
aghMatrix<T>::aghMatrix(int w, int k)
{
   rezerwuj(w, k);
}


template<class T>
aghMatrix<T>::aghMatrix()
{
	wier=0;
	kol=0;
	tab=NULL;
}




template<class T>
aghMatrix<T>::~aghMatrix()
{
   zwolnij();
}

template<class T>
void aghMatrix<T>::wypisz()
{
	for(int i=0; i<wier; i++)
	{
		for(int j=0; j<kol; j++)
			cout<<tab[i][j]<<" ";
	   cout<<endl;
	}
}

template<class T>
void aghMatrix<T>::rezerwuj(int w, int k)
{
   if(w>0 && k>0)
	{
      wier=w;
		kol=k;
		tab=new T * [w];

		for(int i=0; i<w; i++){
			tab[i]=new T [k];
      for(int j = 0; j < kol; j++)
            tab[i][j] = T();
	   }

	}
	else
		throw aghException(0, "Zle wymiary macierzy", __FILE__, __LINE__);
}


template<class T>
void aghMatrix<T>::zwolnij()
{
	for(int i = 0; i < wier; i++)
   {
      delete [] tab[i];
   }
   delete [] tab;
	wier=0;
	kol=0;
	tab=NULL;
}



template<class T>
void aghMatrix<T>::setItem(int w, int k, T el)
{
	if(w>=0 && w<=wier && k>=0 && k<=kol)
   	tab[w][k]=el;
	else
		throw aghException(0, "Zle wymiary macierzy", __FILE__, __LINE__);
}



template<class T>
void aghMatrix<T>::setItems(T* elementy)
{
  if(!elementy) cout<<"brak elementow";
	else
	{
    	for(int i=0; i<wier; i++)
		{
			for(int j=0; j<kol; j++)
			{
				tab[i][j]=(*elementy);
				elementy++;
			}
		}
   }
}


template<class T>
void aghMatrix<T>::setItems(int r, int c, ...)
{
	if(tab)
		zwolnij();
	else
	{
		rezerwuj(r, c);
      va_list wart;
      va_start(wart, c);

		for(int i=0; i<r; i++)
			for(int j=0; j<c; j++)
			{
				tab[i][j]=va_arg(wart, T);
			}
	   va_end(wart);
	}
}


template<class T>
aghMatrix<T> const & aghMatrix<T>::operator=(aghMatrix<T> const& A)
{
   if(&A==this) return *this;

   zwolnij();

   rezerwuj(A.wier, A.kol);

  for(int i=0; i<A.wier; i++)
	for(int j=0; j<A.kol; j++)
		tab[i][j]=A.tab[i][j];

	wier=A.wier;
	kol=A.kol;
	return *this;
}


template<class T>
bool aghMatrix<T>::operator==(aghMatrix<T> & A) const
{

	if( (wier==A.wier) && (kol==A.kol))
	{
		for(int i=0; i<wier; i++)
			for(int j=0; j<kol; j++)
			{
				if( (tab[i][j]) != (A.tab[i][j]) )
					return false;
			}
	   return true;
	}
	else

	return false;
}

template<class T>
bool aghMatrix<T>::operator!=(aghMatrix<T> & A) const
{
	if (*this==A) return false;
	   else
	return true;
}


template<class T>
const aghMatrix<T> aghMatrix<T>::operator+(aghMatrix<T> const& A)
{
	aghMatrix<T> Temp(wier, kol);
   if(wier==A.wier && kol==A.kol)
	{
      for(int i = 0; i < wier; i++)
         for(int j = 0; j < kol; j++)
				Temp.tab[i][j]=tab[i][j]+A.tab[i][j];

      Temp.wier=wier;
		Temp.kol=kol;

      return Temp;
	}
	else
	throw aghException(0, "Zle rozmiary macierzy", __FILE__, __LINE__);

}

template<class T>
const aghMatrix<T> aghMatrix<T>::operator*(aghMatrix<T> const& A)
{
	aghMatrix<T> Temp(wier, A.kol);

   for(int i=0; i<wier; i++)
		for(int j=0; j<A.kol; j++)
			Temp.tab[i][j]=0;

   if(kol==A.wier)
   {
   	for (int i=0; i<wier; i++)
    		for (int j=0; j<A.kol; j++)
      		for (int p=0; p<kol; p++)
						Temp.tab[i][j] = Temp.tab[i][j] + tab[i][p]*A.tab[p][j];

	Temp.wier=wier;
	Temp.kol=A.kol;
   for(int i=0; i<wier; i++)

	return Temp;
	}
	else
	   throw aghException(0, "Zle wymiary macierzy", __FILE__, __LINE__);
}

template<class T>
T aghMatrix<T>::operator() (int w, int k) const
{
   if(w<0 || w>wier || k<0 || k>kol)
      throw aghException(0, "Zly index", __FILE__, __LINE__);
	else
	   return tab[w][k];
}


#endif
