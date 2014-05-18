/**
* \file aghMatrix.h
* \author Arkadiusz Blasiak, Piotr Jaromin
* \date 17.05.2014
* \brief Klasa aghMatrix i definicje jej metod szablonowych
*/
// -------------------------------------------------------------------------

#ifndef 	AGHMATRIX_H
#define AGHMATRIX_H

#include "aghInclude.h"
// -------------------------------------------------------------------------

/**
* \class aghMatrix
* \author Arkadiusz Blasiak, Piotr Jaromin
* \date 17.05.2014
* \brief Klasa reprezentujaca macierz N x M
*/

template <class T>
class aghMatrix
{
private:
	int wier;  ///< liczba wierszy
   int kol;   ///< liczba kolumn
   T** tab;   ///< Tablica zawierajaca elementy macierzy

   /// \brief Metoda rezerwujaca pamiec dla macierzy (tworzaca ja)
   ///
   /// \param w - ilosc wierszy
   /// \param k - ilosc kolumn
   void rezerwuj(int w, int k);

   /// \brief Metoda zwalniajaca pamiec zarezerwowana dla macierzy
	void zwolnij();

public:
   /// \brief Konstruktor bezparametrowy klasy
   aghMatrix();

   /// \brief Konstruktor parametrowy
   ///
   /// \param w - ilosc wierszy
   /// \param k - ilosc kolumn
   aghMatrix(int w, int k);

   /// \brief Destruktor klasy
   ~aghMatrix();

   /// \brief Metoda ustawiajaca element macierzy na podany
   ///
   /// \param w - wiersz
   /// \param k - kolumna
   /// \param el - element
   void setItem(int w, int k, T el);

   /// \brief Metoda ustawiaj¹ca podane elementy w macierzy
   ///
   /// \param elem - Tablica elementow
   void setItems(T* elem);

   /// \brief Metoda ustawiajaca podane elementy w macierzy
   ///
   /// \param r - ilosc wierszy
   /// \param c - ilosc kolmn
   /// \param ... - kolejne elementy
   void setItems(int r, int c, ...);

   /// \brief Metoda wypisujaca elementy macierzy
	void wypisz();

	/// \brief Przeciazony operator przypisania
	///
	/// \return Macierz po przypisaniu
   aghMatrix const & operator=(aghMatrix<T> const &A);

   /// \brief przeciazony operator dodawania
   ///
   /// \return Dodana macierz
   const aghMatrix operator+ (const aghMatrix&);

   /// \brief przeciazony operator mnozenia
   ///
   /// \return Pomnozona macierz
   const aghMatrix operator* (const aghMatrix&);

   /// \brief przeciazony operator porownania
   ///
   /// \return TRUE jesli macierze sa rowne
   bool operator==(aghMatrix<T>& A) const;

   /// \brief przeciazony operator relacji
   ///
   /// \return TRUE jesli macierze sa rozne
	bool operator!=(aghMatrix<T>& A) const;

	/// \brief przeciazony operator dostepu
   ///
   /// \param w - wiersz
   /// \param k - kolumna
   /// \return element macierzy
   T operator() (int w, int k) const;

};
// -------------------------------------------------------------------------

   /// \brief Metoda specjalizowana dla char* ustawiajaca podany element w macierzy
   ///
   /// \param r - wiersz
   /// \param c - kolumna
   /// \param el - element
   template<>
   void aghMatrix<char*>::setItem(int r, int c, char* el);

   /// \brief Metoda specjalizowana dla char ustawiajaca podane elementy w macierzy
   ///
   /// \param r - ilosc wierszy
   /// \param c - ilosc kolumn
   /// \param ... - kolejne elementy
   template<>
   void aghMatrix<char>::setItems(int r, int c, ...);

   /// \brief Metoda specjalizowana dla char* ustawiajaca podane elemeny w macierzy
   ///
   /// \param r - ilosc wierszy
   /// \param c - ilosc kolumn
   /// \param ... - kolejne elementy
   template<>
   void aghMatrix<char*>::setItems(int r, int c, ...);

   /// \brief Przeciazony specjalizowany dla char* operator przypisania
   ///
   /// \return Macierz po przypisaniu
   template<>
   aghMatrix<char*> const & aghMatrix<char*>::operator=(aghMatrix<char*> const& A);

   /// \brief Przeciazony specjalizowany dla char operator dodawania
   ///
   /// Kolejne litery alfabetu sa tutaj traktowane jako liczby (a=0, b=1, c=2 itd.)
   /// czyli a+c=c -> 0+2=2
   /// \return Macierz po dodaniu
   template<>
   const aghMatrix<char> aghMatrix<char>::operator+(aghMatrix<char> const & A);

   /// \brief Przeciazony specjalizowany dla char* operator dodawania
   ///
   /// Sklejanie wyrazow, ale tylko niepowtarzajace sie litery
   /// \return Macierz po dodaniu
   template<>
   const aghMatrix<char*> aghMatrix<char*>::operator+(aghMatrix<char*> const & A);


   /// \brief Przeciazony specjalizowany dla char operator mnozenia
   ///
   /// Kolejne litery alfabetu sa tutaj traktowane jako liczby (a=0, b=1, c=2 itd.)
   /// czyli d*c=f -> 3*2=6
   /// \return Macierz po pomnozeniu
   template<>
   const aghMatrix<char> aghMatrix<char>::operator*(aghMatrix<char> const& A);

   /// \brief Przeciazony specjalizowany dla char* operator mnozenia
   ///
   /// Pojedynczy element macierzy zwracanej to suma iloczynow wyrazow z odpowiedniego wiersza i kolumny
   /// Wynik mnozenia dwoch wyrazow to zbior liter powtarzajacych sie w obu
   /// \return Macierz po pomnozeniu
   template<>
   const aghMatrix<char*> aghMatrix<char*>::operator*(aghMatrix<char*> const & A);

   /// \brief Przeciazony specjalizowany dla char* operator porownania
   ///
   /// \return TRUE jesli macierze sa takie same
   template<>
   bool aghMatrix<char*>::operator==(aghMatrix<char*> & A) const;

   /// \brief Przeciazony specjalizowany dla char* operator relacji
   ///
   /// \return TRUE jesli macierza sa rozne
   template<>
   bool aghMatrix<char*>::operator!=(aghMatrix<char*> & A) const;
// -------------------------------------------------------------------------

template<class T>
aghMatrix<T>::aghMatrix(int w, int k)
{
   rezerwuj(w, k);
}
// -------------------------------------------------------------------------

template<class T>
aghMatrix<T>::aghMatrix()
{
	wier=0;
	kol=0;
	tab=NULL;
}
// -------------------------------------------------------------------------

template<class T>
aghMatrix<T>::~aghMatrix()
{
   zwolnij();
}
// -------------------------------------------------------------------------

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
// -------------------------------------------------------------------------

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
// -------------------------------------------------------------------------

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
// -------------------------------------------------------------------------

template<class T>
void aghMatrix<T>::setItem(int w, int k, T el)
{
	if(w>=0 && w<=wier && k>=0 && k<=kol)
   	tab[w][k]=el;
	else
		throw aghException(0, "Zle wymiary macierzy", __FILE__, __LINE__);
}
// -------------------------------------------------------------------------

template<class T>
void aghMatrix<T>::setItems(T* elementy)
{
  if(!elementy) throw aghException(0, "Brak elementow", __FILE__, __LINE__);
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
// -------------------------------------------------------------------------

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
// -------------------------------------------------------------------------

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
// -------------------------------------------------------------------------

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
// -------------------------------------------------------------------------

template<class T>
bool aghMatrix<T>::operator!=(aghMatrix<T> & A) const
{
	if (*this==A) return false;
	   else
	return true;
}
// -------------------------------------------------------------------------

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
// -------------------------------------------------------------------------

template<class T>
const aghMatrix<T> aghMatrix<T>::operator*(aghMatrix<T> const& A)
{
	aghMatrix<T> Temp(wier, A.kol);

   if(kol==A.wier)
   {
   	for (int i=0; i<wier; i++){
    		for (int j=0; j<A.kol; j++){

      		for (int p=0; p<kol; p++){
						Temp.tab[i][j] = Temp.tab[i][j] + tab[i][p]*A.tab[p][j];
            }
    		}
   	}
	Temp.wier = wier;
	Temp.kol = A.kol;
	return Temp;
	}
	else
	   throw aghException(0, "Zle wymiary macierzy", __FILE__, __LINE__);
}
// -------------------------------------------------------------------------

template<class T>
T aghMatrix<T>::operator() (int w, int k) const
{
   if(w<0 || w>wier || k<0 || k>kol)
      throw aghException(0, "Zly index", __FILE__, __LINE__);
	else
	   return tab[w][k];
}
// -------------------------------------------------------------------------

#endif
