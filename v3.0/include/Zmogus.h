#ifndef  ZMOGUS_H_INCLUDED
#define ZMOGUS_H_INCLUDED
#include <iostream>
#include <string>

using std::string;

class Zmogus{
    protected:
        string vardas_;
        string pavarde_;

        Zmogus(){ };
        Zmogus(const string& vardas, const string& pavarde)
            : vardas_(vardas), pavarde_(pavarde) {}

    public:
        virtual ~Zmogus() = default;

        virtual string getVardas() const = 0;
        virtual string getPavarde() const = 0;
};

#endif