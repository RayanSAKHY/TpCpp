#include "catch.hpp"
#include <cstring>
#include <sstream>
#include "AgregateurG.hpp"

TEST_CASE("Constructeur par defaut") {
    AgregateurG<int> p;

    CHECK(  p.empty() );
    CHECK(  0 == p.size() );
}


TEST_CASE("Exceptions de mauvaise construction") {
    // fait appel à une exception standard en cas d'erreur
    REQUIRE_THROWS_AS( AgregateurG<int>(-1).empty(), std::invalid_argument );
    REQUIRE_THROWS_AS( AgregateurG<double>( 0).empty(), std::invalid_argument );

}


TEST_CASE("Live Agregateur") {
    AgregateurG<int> p(10);

    CHECK(  p.empty()     );
    CHECK(  0 == p.size() );

    p.pushBack(5);

    CHECK( !p.empty()    );
    CHECK( 1 == p.size() );

    p.pushBack(2);
    p.pushBack(1);

    CHECK( 3 == p.size() );
}