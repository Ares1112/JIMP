/**
* \file aghComplex.h
* \author Arkadiusz B³asiak, Piotr Jaromin
* \date 15.05.2014
* \brief Klasa aghComplex
*/
// -------------------------------------------------------------------------

#ifndef AGHCOMPLEX_H
#define AGHCOMPLEX_H
// -------------------------------------------------------------------------

/**
* \class aghComplex
* \author Arkadiusz B³asiak, Piotr Jaromin
* \date 15.05.2014
* \brief Klasa reprezentuj¹ca liczbê zespolon¹
*/

class aghComplex{
private:
    double re; ///< czêœæ rzeczywista
    double im; ///< czêœæ urojona
public:
   /// \brief Konstruktor bezparametrowy
    aghComplex(){ re = 0; im = 0;}
    /// \brief Konstruktor parametrowy
    ///
    /// \param re - czêœæ rzeczywista
    /// \param im - czêœæ urojona
    aghComplex(double re, double im);

    /// \brief Destruktor
    ~aghComplex();

    /// \brief przeci¹¿ony operator dodawania
    ///
    /// \return dodana liczba
    const aghComplex operator+ (const aghComplex&);

    /// \brief przeci¹¿ony operator mno¿enia
    ///
    /// \return pomno¿ona liczba
    const aghComplex operator* (const aghcomplex&);

    /// \brief przeci¹¿ony operator przypisania
    ///
    /// \return dodana liczba
    void operator+=(const aghComplex&);

    /// \brief przeci¹¿ony operator porównania
    ///
    /// \return TRUE jeœli liczby s¹ równe
    bool operator==(const aghComplex&);

    /// \brief przeci¹¿ony operator relacji
    ///
    /// \return TRUE jeœli liczby s¹ ró¿ne
    bool operator!=(const aghComplex&);
};

#endif
