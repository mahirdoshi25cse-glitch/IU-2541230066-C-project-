#include "Venue.h"
#include <iostream>
using namespace std;

Venue::Venue()
{
    venueId = 0;
    venueName = "";
    capacity = 0;
    rent = 0;
    available = true;
}

Venue::Venue(int id, string name, int cap, double r, bool avail)
{
    venueId = id;
    venueName = name;
    capacity = cap;
    rent = r;
    available = avail;
}

void Venue::display()
{
    cout << "Venue ID: " << venueId << endl;
    cout << "Venue Name: " << venueName << endl;
    cout << "Capacity: " << capacity << endl;
    cout << "Rent: " << rent << endl;
    cout << "Availability: " << (available ? "Available" : "Booked") << endl;
}

int Venue::getVenueId()
{
    return venueId;
}

string Venue::getVenueName()
{
    return venueName;
}

int Venue::getCapacity()
{
    return capacity;
}

double Venue::getRent()
{
    return rent;
}

bool Venue::isAvailable()
{
    return available;
}

void Venue::setVenueName(string name)
{
    venueName = name;
}

void Venue::setCapacity(int cap)
{
    capacity = cap;
}

void Venue::setRent(double r)
{
    rent = r;
}

void Venue::setAvailability(bool avail)
{
    available = avail;
}