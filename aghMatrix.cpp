/**
* \file aghMatrix.cpp
* \author Arkadiusz Blasiak, Piotr Jaromin
* \date 17.05.2014
* \brief Definicje metod specjalizowanych dla klasy aghMatrix
*/
// -------------------------------------------------------------------------

#include "aghMatrix.h"

template<>
void aghMatrix<char*>::setItem(int r, int c, char* elem)
{
     if( r>=0 && r<=wier && c>=0 && c<=kol)
     {
        if(tab[r][c] != NULL)
           delete[] tab[r][c];

        if(elem != NULL) {
           tab[r][c] = new char[strlen(elem) + 1];
           strcpy(tab[r][c], elem);
     }
     else
           throw aghException(0, "Nieprawidlowy index", __FILE__, __LINE__);
   }
}
// -------------------------------------------------------------------------

template<>
void aghMatrix<char>::setItems(int r, int c, ...)
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
            tab[i][j]=va_arg(wart, int);
         }
      va_end(wart);
   }
}
// -------------------------------------------------------------------------

template<>
void aghMatrix<char*>::setItems(int r, int c, ...) {
   if(tab != NULL) {
      zwolnij();
   }

   rezerwuj(r, c);

   va_list lista;
   va_start(lista, c);
   for(int i = 0; i < r; i++) {
      for(int j = 0; j < c; j++) {
         tab[i][j] = new char[strlen(va_arg(lista, char*)) + 1];
      }
   }
   va_start(lista, c);
   for(int i = 0; i < r; i++) {
      for(int j = 0; j < c; j++) {
         strcpy(tab[i][j], va_arg(lista, char*));
      }
   }
   va_end(lista);
}
// -------------------------------------------------------------------------

template<>
const aghMatrix<char> aghMatrix<char>::operator+(const aghMatrix<char>& A)
{
   aghMatrix<char> Temp(wier, kol);
   if(wier==A.wier && kol==A.kol)
   {
      for(int i = 0; i < wier; i++)
         for(int j = 0; j < kol; j++)
            {  if( ((int(tab[i][j])-97) + (int(A.tab[i][j])-97) )<=25)
                   Temp.tab[i][j]=char( (int(tab[i][j])-97) + (int(A.tab[i][j])-97)  + 97);
               else
                   Temp.tab[i][j]=char( (int(tab[i][j])-97) + (int(A.tab[i][j])-97)  + 97 - 26);
            }
      Temp.wier=wier;
      Temp.kol=kol;

      return Temp;
   }
   else
   throw aghException(0, "Macierze nie sa takie same", __FILE__, __LINE__);
}
// -------------------------------------------------------------------------

template<>
const aghMatrix<char> aghMatrix<char>::operator*(const aghMatrix<char>& A)
{
   aghMatrix<char> Temp(wier, A.kol);

   for(int i=0; i<wier; i++)
      for(int j=0; j<A.kol; j++)
         Temp.tab[i][j]=0;

   if(kol==A.wier)
   {
      for (int i=0; i<wier; i++)
          for (int j=0; j<A.kol; j++)
         {
            for (int p=0; p<kol; p++)
            {
               Temp.tab[i][j] = Temp.tab[i][j] +  ((tab[i][p]-'a') * (A.tab[p][j]-'a'))  % (( 'z' - 'a') +1 ) ;
            }
            Temp.tab[i][j] = Temp.tab[i][j] % ( ('z' - 'a') +1 ) + 'a';
         }

   Temp.wier=wier;
   Temp.kol=A.kol;


   return Temp;
   }
   else
   throw aghException(0, "Zle rozmiary macierzy", __FILE__, __LINE__);

}
// -------------------------------------------------------------------------

template<>
aghMatrix<char*> const & aghMatrix<char*>::operator=(aghMatrix<char*> const & A)
{
      if(&A==this) return *this;
      zwolnij();

      rezerwuj(A.wier, A.kol);
      for(int i = 0; i < wier; i++)
      {
         for(int j = 0; j<kol; j++)
         {
            tab[i][j] = new char[strlen(A.tab[i][j]) + 1];
            strcpy(tab[i][j], A.tab[i][j]);

         }
      }
   wier=A.wier;
   kol=A.kol;
   return *this;
}
// -------------------------------------------------------------------------

template<>
bool aghMatrix<char*>::operator==(aghMatrix<char*> & A) const
{

   if((wier == A.wier) && (kol == A.kol))
   {
      for(int i = 0; i < wier; i++)
         for(int j = 0; j < kol ; j++)
            if(strcmp(tab[i][j], A.tab[i][j])!=0 )
               return false;

   }
    else
        return false;

   return true;
}
// -------------------------------------------------------------------------

template<>
bool aghMatrix<char*>::operator!=(aghMatrix<char*> & A) const
{
   return !(*this == A);
}

template<>
const aghMatrix<char*> aghMatrix<char*>::operator+(aghMatrix<char*> const& A)
{
   aghMatrix<char*> Temp(wier, kol);
   if(wier==A.wier && kol==A.kol)
   {
      for(int i = 0; i < wier; i++)
         for(int j = 0; j < kol; j++)
         {

            char *wyr1, *wyr2;
            int dl1, dl2, il=0;
            wyr1=tab[i][j];
            wyr2=A.tab[i][j];


            dl1 = strlen(wyr1);
            dl2 = strlen(wyr2);
              char* bufor = new char[dl1 + dl2 + 1];

            for(int k = 0; k < dl1; k++)
               if(strchr(bufor, wyr1[k]) == NULL)
                   bufor[il++] = wyr1[k];

            for(int k = 0; k < dl2; k++)
               if(strchr(bufor, wyr2[k]) == NULL)
                 bufor[il++] = wyr2[k];

            bufor[il] = '\0';
            Temp.tab[i][j]  = new char[il + 1];
            strcpy(Temp.tab[i][j] , bufor);
            delete [] bufor;

         }
      Temp.wier=wier;
      Temp.kol=kol;

      return Temp;
   }
   else
   throw aghException(0, "Zle rozmiary macierzy", __FILE__, __LINE__);
}
// -------------------------------------------------------------------------

template<>
const aghMatrix<char*> aghMatrix<char*>::operator*(aghMatrix<char*> const& A)
{
   aghMatrix Temp(wier, A.kol);
   if(kol==A.wier)
   {
      for(int i = 0; i < wier; i++)
         for(int j = 0; j < A.kol; j++)
            for (int p=0; p<kol; p++)
            {
                char* result = NULL;
                char *c1, *c2;
                c1=tab[i][p];
                c2=A.tab[p][j];

                int c1Length = strlen(c1);
                int c2Length = strlen(c2);

                char* buffer = new char[((c1Length > c2Length) ? c1Length : c2Length) + 1];

                int counter = 0;
                for(int k = 0; k < c1Length; k++)
                {
                   char temp = c1[k];
                   if(strchr(c2, temp) != NULL)
                   if(strchr(buffer, temp) == NULL)
                      buffer[counter++] = temp;
                }


                buffer[counter] = '\0';
                result = new char[counter + 1];
                strcpy(result, buffer);
                delete[] buffer;

                char* kopia1=Temp.tab[i][j];
                char* kopia2=result;

                char* result1;
                char* a=kopia1;
                char* b=kopia2;
                int a_Length, b_Length;

                if(a == NULL)
                   a_Length = 0;
                else
                   a_Length = strlen(a);

                if(b == NULL)
                   b_Length = 0;
                else
                  b_Length = strlen(b);

                char* buffer1 = new char[a_Length + b_Length + 1];

                int licznik = 0;
                for(int k = 0; k < a_Length; k++)
                   if(strchr(buffer1, a[k]) == NULL)
                      buffer1[licznik++] = a[k];

                for(int k = 0; k < b_Length; k++)
                   if(strchr(buffer1, b[k]) == NULL)
                      buffer1[licznik++] = b[k];

                buffer1[licznik] = '\0';
                result1 = new char[licznik + 1];
                strcpy(result1, buffer1);
                Temp.tab[i][j]=result1;
                delete[] buffer1;
        }
        return Temp;
        }
        else
          throw aghException(0, "Zle rozmiary macierzy", __FILE__, __LINE__);

}
// -------------------------------------------------------------------------
