/**
* \file aghComplex.h
* \author Arkadiusz Blasiak, Piotr Jaromin
* \date 15.05.2014
* \brief Klasa aghComplex
*/
// -------------------------------------------------------------------------

#ifndef AGHCOMPLEX_H
#define AGHCOMPLEX_H
// -------------------------------------------------------------------------

/**
* \class aghComplex
* \author Arkadiusz Blasiak, Piotr Jaromin
* \date 15.05.2014
* \brief Klasa reprezentujaca liczbe zespolona
*/

class aghComplex{
private:
    double re; ///< czesc rzeczywista
    double im; ///< czesc urojona
public:
   /// \brief Konstruktor bezparametrowy
    aghComplex(){ re = 0; im = 0;}
    /// \brief Konstruktor parametrowy
    ///
    /// \param re - czesc rzeczywista
    /// \param im - czesc urojona
    aghComplex(double re, double im);

    /// \brief Destruktor
    ~aghComplex();

    /// \brief przeciazony operator dodawania
    ///
    /// \return dodana liczba
    const aghComplex operator+ (const aghComplex&);

    /// \brief przeciazony operator mnozenia
    ///
    /// \return pomnozona liczba
    const aghComplex operator* (const aghComplex&);

    /// \brief przeciazony operator przypisania
    ///
    /// \return dodana liczba
    void operator+=(const aghComplex&);

    /// \brief przeciazony operator porownania
    ///
    /// \return TRUE jesli liczby sa równe
    bool operator==(const aghComplex&);

    /// \brief przeciazony operator relacji
    ///
    /// \return TRUE jesli liczby sa rozne
    bool operator!=(const aghComplex&);

};

#endif
