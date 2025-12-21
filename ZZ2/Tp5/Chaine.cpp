#include "Chaine.hpp"
#include <cstring>

Chaine::Chaine() noexcept : capacite(0), tab(nullptr)
{
}

int Chaine::getCapacite() const noexcept
{
    return capacite < 0 ? 0:capacite;
}

const char* Chaine::c_str() const
{
    return tab;
}

Chaine::~Chaine() {
    delete [] tab;
}

char * Chaine::allocateNewTab(int capacite) {
    try {
        tab = new char[capacite +1];
        return tab;
    }catch (const std::bad_alloc &) {
        delete [] tab;
        throw;
    }

}

Chaine::Chaine(const char* inCS)
{
    //std::cout << inCS << std::endl;
    if (inCS) {

        capacite = static_cast<int>(std::strlen(inCS));
        tab = allocateNewTab(capacite);
        std::strcpy(tab, inCS);
    }
    else
    {
        capacite = 0;
        tab = nullptr;
    }
}

Chaine::Chaine(int inCapacite) : capacite(inCapacite>0 ? inCapacite:0), tab(nullptr)
{
    if (capacite)
    {
        tab = allocateNewTab(capacite);
        tab[0] ='\0';
    }
}

Chaine::Chaine(const Chaine& uC) : capacite(uC.capacite), tab(nullptr)
{
    if (capacite >0 && uC.tab != nullptr)
    {
        tab = allocateNewTab(capacite);
        std::strcpy(tab, uC.tab);

    } else tab = nullptr;
}

void Chaine::afficher(std::ostream& o) const
{
    if (tab) o << tab;
}

Chaine& Chaine::operator=(const Chaine& uC) {
    if (&uC != this) {
        delete [] tab;
        capacite = uC.capacite;
        //std::cout << capacite << std::endl;
        if (capacite) {
            tab = allocateNewTab(capacite);
            strcpy(tab,uC.tab);
            //std::cout << this->tab << std::endl;
        } //else tab = nullptr;
    }
    return *this;
}

std::ostream & operator<<(std::ostream & o, const Chaine & chaine) {
    const int capacite = chaine.getCapacite();
    for(int i = 0;i<capacite;i++) {
        o << chaine.c_str()[i] << "\n";
        }
    //if (chaine.c_str()) o << chaine.c_str();
    return o;
}

char& Chaine::operator[](int index) const {
    int i = index;
    //null_pointer
    if (tab == nullptr) {
        throw null_pointer();
    }
    if (index < 0 || index >= capacite) {
        throw std::out_of_range("Out of range");
        //throw Chaine::OutOfRangeException();
    }
    while (i-- > 0) (*tab)++;
    return *tab;
}

Chaine operator+(const Chaine & c1,const Chaine & c2) {
    char * tab =new char[c1.getCapacite() +c2.getCapacite() + 1];
    strcpy(tab,c1.c_str());
    strcat(tab,c2.c_str());
    Chaine temp(tab);
    delete [] tab;

    return temp;
}

void afficherParValeur(Chaine chaine) {
    std::cout << "passage par valeur : ";
    chaine.afficher(std::cout);
}

void afficherParReference(const Chaine & chaine) {
    std::cout << "passage par reference : ";
    chaine.afficher(std::cout);
}