#include <type_traits>
#include "catch.hpp"
#include "musique.hpp"


TEST_CASE("Personne1") {
    const char * nom     = "rampal";
    const char * prenom  = "jean-pierre";
    
    Personne flutiste(nom, prenom);

    CHECK( nom     == flutiste.getNom());
    CHECK( prenom  == flutiste.getPrenom());

    flutiste.setNom("baxtresser");
    flutiste.setPrenom("jeanne");

    CHECK( "baxtresser" == flutiste.getNom());
    CHECK( "jeanne"     == flutiste.getPrenom());

}

TEST_CASE("Personne2") {
    const char * nom     = "galway";
    const char * prenom  = "james";
    
    const Personne flutiste(nom, prenom);

    CHECK( nom     == flutiste.getNom());
    CHECK( prenom  == flutiste.getPrenom());
}

TEST_CASE("Personne3") {
    const char * nom     = "galway";
    const char * prenom  = "james";
    std::stringstream ss;

    const Personne flutiste(nom, prenom);


    flutiste.sePresenter(std::cout);
    flutiste.sePresenter(ss);
    CHECK( "je m'appelle james galway." == ss.str());
}

TEST_CASE("Personne4") {
    const char * nom     = "galway";
    const char * prenom  = "james";
    std::stringstream ss;

    const Personne flutiste(nom, prenom);

    ss << flutiste;
    CHECK( "je m'appelle james galway." == ss.str());
}

TEST_CASE("Impossible1") {
    ImpossibleException e;
    REQUIRE(std::string("operation impossible") == e.what());
}


TEST_CASE("Instrument1") {
    int i = Instrument::getCompteur();

    Violon v;
    CHECK( i == v.getIdentifiant());
    CHECK( "violon" == v.getNom());
    
    Flute f;
    CHECK( i     == v.getIdentifiant());
    CHECK( (i+1) == f.getIdentifiant());
    CHECK( "flute" == f.getNom());

    REQUIRE((i+2) == Instrument::getCompteur());

}
/*
TEST_CASE("Instrument2") {
    CHECK(true == std::is_abstract_v<Instrument>);
}
*/

TEST_CASE("Instrument3") {
    std::stringstream ss;

    Violon v;
    REQUIRE(true == v.isFonctionnel());

    // la classe Partition est une classe "vide"
    v.jouer(Partition(), ss);
    v.jouer(Partition(), std::cout);
    v.jouer(Partition());
    
    REQUIRE("partition jouee par violon" == ss.str());
}

TEST_CASE("Instrument4") {
    std::stringstream ss;

    Instrument * i = new Flute();

    i->jouer(Partition(), ss);
    delete i;
    
    REQUIRE("partition jouee par flute" == ss.str());
}

TEST_CASE("Instrument5") {
    int etat = 0;
    std::stringstream ss;

    Violon v;
    v.setFonctionnel(false);

    try {
        v.jouer(Partition(), ss);
    } catch (ImpossibleException& e) {
        etat = 3;
    } catch (std::exception& e) {
        etat = 2;
    } catch (...) {
        etat = 1;
    }

    REQUIRE(etat >= 2);
    REQUIRE(3 == etat);
}

TEST_CASE("Facteur0") {
    Flute flute;
    Flute flute_a_reviser;

    Facteur facteur(flute);

    facteur.reviser(flute_a_reviser);
    REQUIRE(true == flute_a_reviser.isFonctionnel());
}

TEST_CASE("Facteur1") {
    Flute flute;
    Flute flute_a_reviser;
    flute_a_reviser.setFonctionnel(false);

    Facteur facteur(flute);
    facteur.reviser(flute_a_reviser);    

    REQUIRE(true == flute_a_reviser.isFonctionnel());
}

TEST_CASE("Facteur2") {
    Flute flute;
    Violon violon;
    int etat = 0;

    Facteur facteur(flute);
    try {
        facteur.reviser(violon);
    } catch (...) {
        etat = 1;
    }
    REQUIRE( 1 == etat);
}


TEST_CASE("Musicien0") {
    std::stringstream ss;

    Musicien musicien("vivaldi", "antonio");
    musicien.apprendre(new Violon());

    musicien.sePresenter(std::cout);
    musicien.sePresenter(ss);
    
    REQUIRE("je m'appelle antonio vivaldi. je joue violon" == ss.str());
}




TEST_CASE("Musicien1") {
    std::stringstream ss;

    Musicien musicien("vivaldi", "antonio");
    musicien.apprendre(new Violon());
    musicien.apprendre(new Violon());

    musicien.sePresenter(std::cout);
    musicien.sePresenter(ss);
    
    REQUIRE("je m'appelle antonio vivaldi. je joue violon" == ss.str());
}

TEST_CASE("Musicien2") {
    std::stringstream ss;

    Musicien musicien("doe", "john");
    musicien.apprendre(new Violon());
    musicien.apprendre(new Piano());
    
    musicien.sePresenter(std::cout);
    musicien.sePresenter(ss);
    
    REQUIRE("je m'appelle john doe. je joue piano, violon" == ss.str());
}

TEST_CASE("Foncteur1") {
    Foncteur comp;

    Violon * v = new Violon();
    Flute  * f = new Flute();
    REQUIRE(false  == comp(v, v));
    REQUIRE(false == comp(v, f));
    REQUIRE(true == comp(f, v));

    delete f;
    delete v;
} 

TEST_CASE("Foncteur2") {
    Foncteur comp;

    Flute *  f1 = new Flute();
    Flute  * f2 = new Flute();
    REQUIRE((f1->getIdentifiant()<f2->getIdentifiant())  == comp(f1, f2));
    REQUIRE((f1->getIdentifiant()>f2->getIdentifiant())  == comp(f2, f1));

    delete f1;
    delete f2;
}

TEST_CASE("Musicien3") {
    std::stringstream ss;

    Musicien musicien("vivaldi", "antonio");
    musicien.apprendre(new Violon());
    musicien.apprendre(new Piano());
    musicien.apprendre(new Flute());
    musicien.apprendre(new Violon());

    std::cout << "Exemple de sortie :\n";
    std::cout << "flute (22) :\n";
    std::cout << "piano (21) :\n";
    std::cout << "violon (20) :\n";
    std::cout << "violon (23) :\n";

    musicien.listerInstruments(ss);
    
    // les instruments sont listés dans l'ordre lexicographique
    REQUIRE(ss.str().find("flute")<ss.str().find("violon"));
    REQUIRE(ss.str().find("flute")<ss.str().find("piano"));
    REQUIRE(ss.str().find("piano")<ss.str().find("violon"));
    REQUIRE(ss.str().find("violon")<ss.str().rfind("violon"));
}

TEST_CASE("Musicien4") {
    std::stringstream ss;

    Musicien musicien("vivaldi", "antonio");

    musicien.apprendre(new Violon());
    musicien.apprendre(new Piano());
    musicien.apprendre(new Flute());
    musicien.apprendre(new Violon());

    std::cout << "Exemple de sortie :\n";
    std::cout << "je m'appelle antonio vivaldi.\n";
    std::cout << "je possede :\n";
    std::cout << "flute (22) :\n";
    std::cout << "piano (21) :\n";
    std::cout << "violon (20) :\n";
    std::cout << "violon (23) :\n";

    std::cout << "Ce que vous avez fait :\n";
    std::cout << musicien;
    ss << musicien;
    
    CHECK(ss.str().find("antonio vivaldi")>0);
    CHECK(ss.str().find("flute")<ss.str().find("violon"));
    CHECK(ss.str().find("flute")<ss.str().find("piano"));
    CHECK(ss.str().find("piano")<ss.str().find("violon"));
    CHECK(ss.str().find("violon")<ss.str().rfind("violon"));
}

// IL N'Y A PAS DE FUITE DE MEMOIRE

