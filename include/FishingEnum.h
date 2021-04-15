#ifndef FISHINGENUM_H
#define FISHINGENUM_H

#include <string>
#include <fstream>
#include <vector>

using namespace std;


class FishingEnum
{
    private:
        struct Data{
            string _name;
            string _comp;
        };
        enum Status{
            abnorm, norm
        };

        bool _caught;
        int _caught_num = 0;

        ifstream _f;
        Data _data;
        Status _status;
        bool _current = true;
        bool _end;
        Data _smallest;
        double _min = 100.00;

        void read();

    public:

        void first();
        void next();
        int current() const;
        bool end() const;

        Data getSmallest() const;

        FishingEnum(const string &inp);
        virtual ~FishingEnum();



};

#endif // FISHINGENUM_H
