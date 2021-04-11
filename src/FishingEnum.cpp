#include "FishingEnum.h"
#include <iostream>
#include <sstream>

using namespace std;

void FishingEnum::first(){
    read();
    next();
}
void FishingEnum::next(){
     _end = _status == abnorm ? true : false;
     if(!_end){
        for (; _status == norm; read()) {
             //cout << _data._name << _data._comp << endl;
        }
     }
}
bool FishingEnum::current() const{
    return _current;
}
bool FishingEnum::end() const{
    return _end;
}

FishingEnum::Data FishingEnum::getSmallest() const{
    return _smallest;
}

void FishingEnum::read(){

    _status = _f.fail() ? abnorm : norm;

    string fish;
    double weight;
    string line;
    getline(_f, line);
    cout << "sor:" <<line << endl;
    istringstream l(line);

    l >> _data._name >> _data._comp;
    for(l >> fish >> weight; !l.fail(); l >> fish >> weight){
        if(fish == "Ponty" && weight < _min){
            _min = weight;
            _smallest = _data;
        }
    }
}

FishingEnum::FishingEnum(const string &inp)
{
    _f.open(inp);
    _status = _f.fail() ? abnorm : norm;

    _current = false;
    _end = false;

}

FishingEnum::~FishingEnum()
{
    if(_f.is_open()){
        _f.close();
    }
}
