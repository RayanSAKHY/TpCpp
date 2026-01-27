#include "catch.hpp"
#include "batiment.hpp"


TEST_CASE("Adresse1") {
    const char * nom     = "ISIMA";
    const double latitude   = 45.75919091728384;
    const double longitude  = 3.1103735526660263;
    
    const Adresse isima;

    REQUIRE( nom       == isima.getNom());
    REQUIRE( latitude  == isima.getLatitude());
    REQUIRE( longitude == isima.getLongitude());
}

TEST_CASE("Adresse2") {
    const char * nom     = "eiffel";
    const double latitude   = 48.858518304726736;
    const double longitude  = 3.1103735526660263;

    const Adresse tour(nom, latitude, longitude);

    REQUIRE( nom       == tour.getNom());
    REQUIRE( latitude  == tour.getLatitude());
    REQUIRE( longitude == tour.getLongitude());
}


TEST_CASE("Adresse3") {
    const char * nom     = "ISIMA";
    // vous pouvez adapter ces chiffres si vous n'y arrivez pas
    const double latitude   = 45.75919091728384;
    const double longitude  = 3.1103735526660263;
    
    const Adresse isima(nom, latitude, longitude);

    std::stringstream stream;

    isima.toStream(stream);
    isima.toStream(std::cout);
    isima.toStream();

    REQUIRE( "ISIMA ( 45.7592 ; 3.1104 )" == stream.str());
}


TEST_CASE("Ouvrier0") {
    REQUIRE(0 == Ouvrier::getCompteur());
}

TEST_CASE("Ouvrier1") {
    const Ouvrier o;
    std::stringstream stream;

    o.travailler(std::cout);
    o.travailler(stream);

    REQUIRE("Ouvrier #1 travaille à ISIMA ( 45.7592 ; 3.1104 )" == stream.str());
    
}

TEST_CASE("Ouvrier2") {
    Ouvrier o;
    std::stringstream stream;

    o.setChantier(Adresse("notre dame", 48.85313053968921, 2.349869910510209));
    o.getChantier().toStream(stream);

    REQUIRE("notre dame ( 48.8531 ; 2.3499 )" == stream.str());
    
}

TEST_CASE("Ouvrier3") {
    int n = Ouvrier::getCompteur();
    
    REQUIRE(n == Ouvrier::getCompteur());
    Ouvrier o1;
    REQUIRE((n+1) == o1.getId());
    Ouvrier o2;
    REQUIRE((n+1) == o1.getId());
    REQUIRE((n+2) == o2.getId());

    REQUIRE((n+2) == Ouvrier::getCompteur());
}

TEST_CASE("Ouvrier4") {
    int n = Ouvrier::getCompteur();
    
    Ouvrier o1;
    Ouvrier o2;
    Ouvrier o3 = o1;
    REQUIRE(o3.getId() == o1.getId()+2);
    REQUIRE(o3.isDisponible() == o1.isDisponible());
    REQUIRE(o3.getChantier().getNom() == o1.getChantier().getNom());

    REQUIRE((n+3) == Ouvrier::getCompteur());
}


TEST_CASE("Indisponible1") {
    Ouvrier o;
    std::stringstream stream;
    int result = 0;

    o.setDisponible(false);
    
    try {
        o.travailler(stream);
    } catch(const IndisponibleException & e) {
        result = 3;
    } catch(const std::exception & e) {
        result = 2;
    } catch(...) {
        result = 1;
    }
    
    CHECK(2 <= result);
}

TEST_CASE("Chef1") {
    int n = Ouvrier::getCompteur() +1 ;
    Ouvrier * c = new Chef();

    CHECK(n == c->getId());
    CHECK(n == Ouvrier::getCompteur());

    delete c;
}

TEST_CASE("Chef2") {
    Ouvrier o1;
    Ouvrier o2;
    Chef * c = new Chef();
    std::stringstream ss[6];

    c->getChantier().toStream(ss[0]);
    o1.getChantier().toStream(ss[1]);
    o2.getChantier().toStream(ss[2]);
    for(int i = 0; i< 3 ; ++i)
        CHECK( "ISIMA ( 45.7592 ; 3.1104 )" == ss[i].str());

    c->ajouter(&o1);
    c->ajouter(&o2);
    c->setChantier(Adresse("notre dame", 48.8531, 2.3499));

    c->getChantier().toStream(ss[3]);
    o1.getChantier().toStream(ss[4]);
    o2.getChantier().toStream(ss[5]);

    for(int i = 3; i< 6 ; ++i)
        CHECK( "notre dame ( 48.8531 ; 2.3499 )" == ss[i].str());

    delete c;
}

TEST_CASE("Indisponible2") {
    Ouvrier * c = new Chef;
    std::stringstream stream;
    int result = 0;

    c->setDisponible(false);
    
    try {
        c->travailler(stream);
    } catch(const IndisponibleException & e) {
        result = 3;
    } catch(const std::exception & e) {
        result = 2;
    } catch(...) {
        result = 1;
    }
    
    CHECK(2 <= result);
    delete c;
}

TEST_CASE("Chef3") {
    int n = Ouvrier::getCompteur() + 1;
    Ouvrier o1;
    Ouvrier o2;
    Chef * c = new Chef();
    std::stringstream resultat;
    std::stringstream cherche;

    c->ajouter(&o1);
    c->ajouter(&o2);

    c->travailler(resultat);
    cherche << "Chef #" << (n+2) << " travaille à ISIMA ( 45.7592 ; 3.1104 )" << std::endl;
    cherche << " avec Ouvrier #" << n << std::endl;
    cherche << " avec Ouvrier #" << (n+1);
    
    REQUIRE( cherche.str() == resultat.str());
    
    delete c;
}

TEST_CASE("Chef4") {
    int n = Ouvrier::getCompteur() + 1;
    Ouvrier o1;
    Ouvrier o2;
    Chef * c = new Chef();
    std::stringstream resultat;
    std::stringstream cherche;

    c->ajouter(&o1);
    c->ajouter(&o2);

    o1.setDisponible(false);

    c->travailler(resultat);
    cherche << "Chef #" << (n+2) << " travaille à ISIMA ( 45.7592 ; 3.1104 )" << std::endl;
    cherche << " avec Ouvrier #" << (n+1);
    
    REQUIRE( cherche.str() == resultat.str());
    
    delete c;
}

TEST_CASE("Chef5") {
    Ouvrier o1;
    Ouvrier o2;
    Chef c;
    std::stringstream resultat;
    std::stringstream cherche;

    c.ajouter(&o1);
    c.ajouter(&o2);

    c.travailler(resultat);
    cherche << c;
    REQUIRE( cherche.str() == resultat.str());
}

TEST_CASE("Tri") {
    const Comparateur c;
    Ouvrier * o1 = new Ouvrier();
    Ouvrier * o2 = new Ouvrier();

    REQUIRE( true == c(o1, o2));
    
    delete o1;
    delete o2;
}

TEST_CASE("Chef6") {
    int n = Ouvrier::getCompteur() + 1;
    Ouvrier o1;
    Ouvrier o2;
    Ouvrier o3;
    Chef * c = new Chef();
    std::stringstream resultat;
    std::stringstream cherche;

    c->ajouter(&o2);
    c->ajouter(&o3);
    c->ajouter(&o1);

    c->travailler(resultat);
    cherche << "Chef #" << (n+3) << " travaille à ISIMA ( 45.7592 ; 3.1104 )" << std::endl;
    cherche << " avec Ouvrier #" << (n)   << std::endl;
    cherche << " avec Ouvrier #" << (n+1) << std::endl;;
    cherche << " avec Ouvrier #" << (n+2);
    
    REQUIRE( cherche.str() == resultat.str());
    
    delete c;
}

TEST_CASE("Specialite1") {
    // vrai si Specialite est abstraite
    //REQUIRE(true == std::is_abstract_v<Specialite>);
    //REQUIRE(false == std::is_abstract_v<Electricite>);
}

TEST_CASE("Specialite2") {
    const Specialite * s1 = new Electricite();
    const Specialite * s2 = new Chauffage();
    const Specialite * s3 = new Plomberie();
    REQUIRE("electricite" == s1->getNom());
    REQUIRE("chauffage"   == s2->getNom());
    REQUIRE("plomberie"   == s3->getNom());
    
    delete s1;
    delete s2;
    delete s3;
}

TEST_CASE("Specialite3") {
    const Plomberie * s1  = new PlomberieChauffage();
    const Chauffage * s2  = new PlomberieChauffage();

    REQUIRE("plomberie-chauffage" == s1->getNom());
    REQUIRE("plomberie-chauffage" == s2->getNom());

    delete s1;
    delete s2;
}
