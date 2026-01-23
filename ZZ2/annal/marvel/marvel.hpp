#ifndef marvel__hpp
#define marvel__hpp

#include <string>
#include <vector>
#include <exception>

class Personne {
    public:
        enum Genre {
            HOMME,
            FEMME,
            INDETERMINE,
        };
        class INCONNU {
            public:
                std::string getNom() const {
                    return "Inconnu";
                }
                std::string getPrenom() const {
                    return "Inconnu";
                }
                Personne::Genre getGenre() const {
                    return Personne::INDETERMINE;
                }
        };

    private:
        std::string prenom;
        std::string nom;
        Genre genre;
    public:
        static const Personne INCONNU;
        Personne(std::string prenom,std::string nom,Genre genre);
        Personne(std::string prenom,std::string nom);
        std::string getPrenom() const;
        std::string getNom() const;
        Genre getGenre() const;
        std::stringstream& afficher(std::stringstream & ss) const;

        bool operator==(const Personne& other) const;
};

class Capacite {
    protected:
        std::string nom;
        int niveau;
    public:
        virtual std::stringstream& utiliser(std::stringstream& ss);
        Capacite(std::string nom,int niveau);
        virtual ~Capacite() = default;
        int getNiveau() const {return niveau;} ;
        virtual Capacite * clone() const;
        std::string getNom() const {return nom;}
};

class Super {
    private:
        std::string nom;
        Personne identite;
        bool anonyme;
        std::vector<Capacite *> listCapacite;
    public:
        Super(std::string nom,Personne identite);
        Super& operator=(const Super &);
        bool estAnonyme() const {return anonyme;}
        std::string getNom() const {return nom;}
        void enregistrer();
        Personne getIdentite() const;
        void setIdentite(Personne identite);
        void ajouter(Capacite * capa);
        int getNiveau() const;
        void setNom(std::string Nom);
};

class AnonymeException : public std::exception {
    public:
        virtual const char* what() const noexcept{return "identite anonyme";}
};


class Materiel : public Capacite {
    public:
        std::stringstream& utiliser(std::stringstream& ss) override;
        std::stringstream& actionner(std::stringstream& ss);
        Materiel(std::string nom,int niveau);
        virtual Materiel * clone() const override;

};
class Physique : public Capacite {
    public:
        std::stringstream& utiliser(std::stringstream& ss) override;
        std::stringstream& exercer(std::stringstream& ss);
        Physique(std::string nom,int niveau);
        virtual Physique * clone() const override;
};
class Psychique : public Capacite {
    public:
        std::stringstream& utiliser(std::stringstream& ss) override;
        std::stringstream& penser(std::stringstream& ss);
        Psychique(std::string nom,int niveau);
        virtual Psychique * clone() const override;
};

class Equipe {
    private:
        std::string nom;
        std::vector<Super *> listSuper;

    public:
        Equipe(std::string nom);
        void ajouter(Super * super);
        int getNiveau() const;
        int getNombre() const;

};

std::stringstream& operator<<(std::stringstream& a, const Personne& b);

#endif
