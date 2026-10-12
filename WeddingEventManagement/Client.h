#ifndef CLIENT_H
#define CLIENT_H

#include "Person.h"
using namespace std;

class Client : public Person
{
private:
    string phone;

public:
    Client();
    Client(int id, string name, string phone);

    void display() override;

    string getPhone();
};

#endif