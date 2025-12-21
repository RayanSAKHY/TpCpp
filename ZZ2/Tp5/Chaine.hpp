#ifndef CPP5__CHAINE_HPP
#define CPP5__CHAINE_HPP

#include <iostream>
#include <fstream>
#include <cstring>
#include <exception>



class Chaine  {

private:
    int capacite;
    char * tab;
    char * allocateNewTab(int capacite );
public:
    Chaine() noexcept;
    const char * c_str() const;
    int getCapacite() const noexcept;
    Chaine(const char * inCS);
    Chaine(int inCapacite);
    ~Chaine();
    Chaine(const Chaine & uC);

    void afficher(std::ostream & o) const;
    Chaine & operator=(const Chaine & uC);
    char & operator[](int index) const;

    class OutOfRangeException : public std::exception {
        const char* what() const noexcept{
            return "Out-of-range exception occurred in Chaine";
        }
    };
};

class null_pointer : public std::logic_error {
public:
    null_pointer() : logic_error("Null pointer exception occurred in Chaine"){

    };
};

std::ostream & operator<<(std::ostream & o, const Chaine & chaine);
Chaine operator+(const Chaine & c1,const Chaine & c2);
void afficherParValeur(Chaine chaine);
void afficherParReference(const Chaine & chaine);

#endif
