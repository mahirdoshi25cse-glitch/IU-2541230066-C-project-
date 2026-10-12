#ifndef VENUE_H
#define VENUE_H

#include <string>
using namespace std;

class Venue
{
private:
    int venueId;
    string venueName;
    int capacity;
    double rent;
    bool available;

public:
    Venue();
    Venue(int id, string name, int cap, double r, bool avail);

    void display();

    int getVenueId();
    string getVenueName();
    int getCapacity();
    double getRent();
    bool isAvailable();

    void setVenueName(string name);
    void setCapacity(int cap);
    void setRent(double r);
    void setAvailability(bool avail);
};

#endif