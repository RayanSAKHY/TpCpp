#ifndef musique__hpp
#define musique__hpp

#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

class Personne {
    private:
        std::string nom;
        std::string prenom;
    public:
        Personne(std::string nom, std::string prenom);
        Personne();
        std::string getNom() const;
        std::string getPrenom() const;
        void setNom(std::string _nom);
        void setPrenom(std::string _prenom);
        virtual std::ostream& sePresenter(std::ostream& flux) const;
        virtual ~Personne() = default;

};

class Partition {

};

class Instrument {
    private:
        int identifiant;
        static int compteur;
        bool fonctionnel;
        std::string nom;
    public:
        Instrument(std::string getNom);
        virtual std::ostream& jouer(Partition,std::ostream&) = 0;
        static int getCompteur();
        int getIdentifiant() const;
        std::string getNom() const;
        bool isFonctionnel() const;
        virtual ~Instrument() = default;
        void setFonctionnel(bool);
};

class Violon : public Instrument {
    public:
        virtual std::ostream& jouer(Partition,std::ostream& flux =std::cout) override;
        Violon();
};

class Piano : public Instrument {
    public:
        virtual std::ostream& jouer(Partition,std::ostream& flux =std::cout) override;
        Piano();
};

class Flute : public Instrument {
    public:
        virtual std::ostream& jouer(Partition,std::ostream& flux =std::cout) override;
        Flute();
        
};

class ImpossibleException : public std::exception {
    public:
        virtual const char* what() const noexcept;
};

class Facteur : public Personne {
    private:
        Instrument& instr;
    public:
        Facteur(Instrument& instr) : instr(instr) {}
        void reviser(Instrument& instr);

};

class Foncteur {
    public:
        bool operator()(Instrument * instru1, Instrument * instru2) const;
};

class Musicien : public Personne {
    private:
        std::multiset<Instrument*,Foncteur> listInstrument;
    public:
        Musicien(std::string nom,std::string prenom);
        virtual std::ostream& sePresenter(std::ostream& flux) const override;
        std::ostream& listerInstruments(std::ostream& flux) const;
        void apprendre(Instrument*);
        virtual ~Musicien() override;

};



std::ostream& operator<<(std::ostream& flux,const Personne);
std::ostream& operator<<(std::ostream& flux,const Musicien&);
#endif
