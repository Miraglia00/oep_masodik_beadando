/*
Az Országos Horgász Bajnokság mindegyik versenyén feljegyezték a versenyzõk
eredményeit, és egy szöveges állományban rögzítették az adatokat. Ennek minden sora
tartalmazza a versenyzõ horgász és a verseny azonosítóját (szóközök nélküli sztring),
majd halfajta-súly párok (szóközök nélküli sztring és valósszám párok) formájában az
adott versenyen elért fogásokat. Az adatok szóközökkel vagy tabulátorjelekkel vannak egy
soron belül elválasztva. A szöveges állomány sorait a horgászok szerint rendezték.
Feltehetjük, hogy a szöveges állomány helyesen van kitöltve. Példa az állomány egy
sorára:
JANIBÁ Kiliti0512 Ponty 4.5 Ponty 5.3 Harcsa 9.6
(1) Mennyi volt a legkisebb kifogott ponty súlya? Ki és melyik versenyen fogta? (Nem
biztos, hogy fogtak pontyot a horgászok!)
(2) Igaz-e, hogy minden horgász legalább két versenyen fogott pontyot?
*/

#include <iostream>
#include "FishingEnum.h"

#define DEBUG

#ifndef DEBUG

using namespace std;

int main()
{
    try{
        FishingEnum e("inp.txt");

        bool c = false;

        for (e.first(); !e.end(); e.next()) {
           c = e.current();
        }
        (e.getSmallest()._name == "" || e.getSmallest()._comp == "") ? cout << "Nobody caught a Ponty!" : cout << e.getSmallest()._name <<"-"<< e.getSmallest()._comp;

        cout << endl;

        (c) ? cout << "Everybody caught Ponty at least twice on different competitions" : cout << "Nobody caught Ponty at least twice on different competitions";

    }catch(char const* err){
        cout << err << endl;
    }
    return 0;
}

#else

#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "FishingEnum.h"

TEST_CASE("FishingEnum()", "[FishingEnum]"){

    CHECK_NOTHROW(FishingEnum e("inp.txt"));

    CHECK_THROWS(FishingEnum e("notexist.txt"));

    CHECK_THROWS(FishingEnum e("empty.txt"));
}

TEST_CASE("FishingEnum in action", "[FishingEnum]"){

    FishingEnum e("inp.txt");

    bool c = false;

    for (e.first(); !e.end(); e.next()) {
       c = e.current();
    }

    CHECK(e.getSmallest()._name == "PISTABA");
    CHECK(e.getSmallest()._comp == "Kiliti0512");

    CHECK_FALSE(e.getSmallest()._name == "JANIBA");
    CHECK_FALSE(e.getSmallest()._comp == "Biliti0512");

    REQUIRE(c == true);

    REQUIRE_FALSE(c == false);
}
#endif
