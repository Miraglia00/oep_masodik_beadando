#ifndef FISHINGENUM_H
#define FISHINGENUM_H

#include <string>
#include <fstream>
#include <vector>

using namespace std;


class FishingEnum
{
    public:
        struct Data{
            string _name;
            string _comp;
        };
        void first();
        void next();
        bool current() const;
        bool end() const;

        Data getSmallest() const;

        FishingEnum(const string &inp);
        virtual ~FishingEnum();

    protected:

    private:
        enum Status{
            abnorm, norm
        };

        ifstream _f;
        Data _data;
        Status _status;
        bool _current;
        bool _end;
        Data _smallest;
        double _min = 100.00;

        void read();

};

#endif // FISHINGENUM_H
