/**
* \file aghComplex.h
* \author Arkadiusz B�asiak, Piotr Jaromin
* \date 15.05.2014
* \brief Klasa aghComplex
*/
// -------------------------------------------------------------------------

#ifndef AGHCOMPLEX_H
#define AGHCOMPLEX_H
// -------------------------------------------------------------------------

/**
* \class aghComplex
* \author Arkadiusz B�asiak, Piotr Jaromin
* \date 15.05.2014
* \brief Klasa reprezentuj�ca liczb� zespolon�
*/

class aghComplex{
private:
    double re; ///< cz�� rzeczywista
    double im; ///< cz�� urojona
public:
   /// \brief Konstruktor bezparametrowy
    aghComplex(){ re = 0; im = 0;}
    /// \brief Konstruktor parametrowy
    ///
    /// \param re - cz�� rzeczywista
    /// \param im - cz�� urojona
    aghComplex(double re, double im);

    /// \brief Destruktor
    ~aghComplex();

    /// \brief przeci��ony operator dodawania
    ///
    /// \return dodana liczba
    const aghComplex operator+ (const aghComplex&);

    /// \brief przeci��ony operator mno�enia
    ///
    /// \return pomno�ona liczba
    const aghComplex operator* (const aghcomplex&);

    /// \brief przeci��ony operator przypisania
    ///
    /// \return dodana liczba
    void operator+=(const aghComplex&);

    /// \brief przeci��ony operator por�wnania
    ///
    /// \return TRUE je�li liczby s� r�wne
    bool operator==(const aghComplex&);

    /// \brief przeci��ony operator relacji
    ///
    /// \return TRUE je�li liczby s� r�ne
    bool operator!=(const aghComplex&);
};

#endif
