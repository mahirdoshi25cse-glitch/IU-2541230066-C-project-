#include "Client.h"
#include <iostream>
using namespace std;

Client::Client()
{
    phone = "";
}

Client::Client(int id, string name, string phoneNumber)
    : Person(id, name)
{
    phone = phoneNumber;
}

void Client::display()
{
    cout << "Client ID: " << getId() << endl;
    cout << "Client Name: " << getName() << endl;
    cout << "Phone: " << phone << endl;
}

string Client::getPhone()
{
    return phone;
}