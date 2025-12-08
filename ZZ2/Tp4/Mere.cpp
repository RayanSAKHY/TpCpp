#include <iostream>


class Mere {
    public:
        virtual void afficher() const { std::cout << "Mere" ;}
    };

    class Fille : public Mere {
    public:
        virtual void afficher() const { std::cout << "Fille" ;}
    };

    void afficher1(Mere m) {
        m.afficher();
    }

    void afficher2(Mere &m) {
        m.afficher();
    }

    void afficher3(Mere * m) {
        m->afficher();
    }

    int main(int, char**) {
        Fille fille;

        afficher1(fille);
        afficher2(fille);
        afficher3(&fille);

        return 0;
}