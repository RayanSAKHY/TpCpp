#include <iostream>

class Mere {
protected:
    std::string nom;
public:
    Mere(std::string s="pas fourni") : nom(s) {
    }

    virtual void methode1() {
        std::cout << "Methode1(): " << nom << std::endl;
    }
};

class Fille : public Mere {
private:
    std::string nom;
public:

    Fille() : Mere("noname") {
    }

    void methode2() {
        std::cout << "Methode2(): " << Mere::nom << std::endl;
    }

};

int main(int, char**) {
    Fille f;

    f.methode1();
    f.methode2();
}