#ifndef marvel__hpp
#define marvel__hpp

#include <string>

class Personne {
    public:
        enum Genre {
            HOMME,
            FEMME,
            INDETERMINE,
        };

    private:
        std::string prenom;
        std::string nom;
        Genre genre;
    public:
        Personne(std::string prenom,std::string nom,Genre genre);
        std::string getPrenom() const;
        std::string getNom() const;
        Genre getGenre() const;
        std::stringstream& afficher(std::stringstream & ss) const;
};

#endif
