
#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person
{
private:
    int id;
    string name;

public:
    Person();
    Person(int i, string n);

    virtual ~Person() = default;

    virtual void display();

    int getId();
    string getName();
};

#endif
