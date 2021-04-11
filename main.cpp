/*
Az Orsz�gos Horg�sz Bajnoks�g mindegyik verseny�n feljegyezt�k a versenyz�k
eredm�nyeit, �s egy sz�veges �llom�nyban r�gz�tett�k az adatokat. Ennek minden sora
tartalmazza a versenyz� horg�sz �s a verseny azonos�t�j�t (sz�k�z�k n�lk�li sztring),
majd halfajta-s�ly p�rok (sz�k�z�k n�lk�li sztring �s val�ssz�m p�rok) form�j�ban az
adott versenyen el�rt fog�sokat. Az adatok sz�k�z�kkel vagy tabul�torjelekkel vannak egy
soron bel�l elv�lasztva. A sz�veges �llom�ny sorait a horg�szok szerint rendezt�k.
Feltehetj�k, hogy a sz�veges �llom�ny helyesen van kit�ltve. P�lda az �llom�ny egy
sor�ra:
JANIB� Kiliti0512 Ponty 4.5 Ponty 5.3 Harcsa 9.6
(1) Mennyi volt a legkisebb kifogott ponty s�lya? Ki �s melyik versenyen fogta? (Nem
biztos, hogy fogtak pontyot a horg�szok!)
(2) Igaz-e, hogy minden horg�sz legal�bb k�t versenyen fogott pontyot?
*/

#include <iostream>
#include "FishingEnum.h"

using namespace std;

int main()
{
    FishingEnum e("inp.txt");

    for (e.first(); !e.end(); e.next()) {

    }
    cout << e.getSmallest()._name << e.getSmallest()._comp;
    return 0;
}
