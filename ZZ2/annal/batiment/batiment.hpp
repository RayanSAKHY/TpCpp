#ifndef batiment__hpp
#define batiment__hpp

#include <iomanip>
#include <iostream>
#include <string>
#include <sstream>
#include <map>

char  const * const nom_zz = "ISIMA";
const double latitude_zz   = 45.75919091728384;
const double longitude_zz  = 3.1103735526660263;

class Specialite {
    protected:
        std::string nom;
    public:
        virtual std::string getNom() const = 0;
        virtual ~Specialite()= default;
};

class Plomberie : public Specialite {
    public:
        virtual std::string getNom() const override;
};

class Chauffage : public Specialite {
    public:
        virtual std::string getNom() const override;
};

class Electricite : public Specialite {
    public:
        virtual std::string getNom() const override;
};

class PlomberieChauffage : public Plomberie, public Chauffage {
    public:
        virtual std::string getNom() const override;
};

class Adresse {
    private:
        std::string nom;
        double latitude;
        double longitude;
    public:
        Adresse(std::string nom, double latitude, double longitude);
        Adresse();
        std::string getNom() const;
        double getLatitude() const;
        double getLongitude() const;
        std::ostream& toStream(std::ostream& flux = std::cout) const;
};

class Ouvrier {
    protected:
        static int compteur;
        bool disponible;
        int id;
        Adresse adresse;
    public:
        Ouvrier(Adresse adresse);
        Ouvrier();
        virtual std::ostream& travailler(std::ostream& flux) const; 
        static int getCompteur();
        virtual void setChantier(Adresse adresse);
        Adresse getChantier() const;
        int getId() const;
        bool isDisponible() const;
        Ouvrier(const Ouvrier& ouvrier);
        void setDisponible(bool dispo);
        virtual ~Ouvrier();
};

class IndisponibleException : public std::exception {
    public:
        const char * what() const noexcept override;
};


class Chef : public Ouvrier {
    private:
        std::map<int,Ouvrier*> equipe;
    public:
        void ajouter(Ouvrier*);
        void setChantier(Adresse adresse) override;
        std::ostream& travailler(std::ostream& flux) const override;

};

class Comparateur {
    public:
        bool operator()(const Ouvrier * o1,const Ouvrier * o2) const;
};


std::ostream& operator<<(std::ostream& flux,const Ouvrier& ouvrier);
#endif
