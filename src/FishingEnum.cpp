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
    string name = _data._name;

    if(!_end){
        for (; _status == norm && name == _data._name; read()) {
            if(_caught){
                _caught_num++;
            }
        }
        if(_caught_num < 2 && _current){
            _current = false;
        }

        _caught_num = 0;
    }
}
int FishingEnum::current() const{
    return _current;
}
bool FishingEnum::end() const{
    return _end;
}

FishingEnum::Data FishingEnum::getSmallest() const{
    return _smallest;
}

void FishingEnum::read(){
    _caught = false;
    _status = _f.fail() ? abnorm : norm;
    string fish;
    double weight;
    string line;
    getline(_f, line);
    if(line != ""){
        istringstream l(line);

        l >> _data._name >> _data._comp;
        for(l >> fish >> weight; !l.fail(); l >> fish >> weight){
            if(fish == "Ponty"){
                _caught = true;
            }
            if(fish == "Ponty" && weight < _min){
                _min = weight;
                _smallest = _data;
            }
        }
    }else{
        _status = abnorm;
    }
}

FishingEnum::FishingEnum(const string &inp)
{
    _f.open(inp);
    _status = _f.fail() ? abnorm : norm;

    if(_status == abnorm) throw "Failed to open file!";

    int c = _f.peek();

    if ( c == 10 ) throw "Empty file!";

    _current = true;
    _end = false;

}

FishingEnum::~FishingEnum()
{
    if(_f.is_open()){
        _f.close();
    }
}
