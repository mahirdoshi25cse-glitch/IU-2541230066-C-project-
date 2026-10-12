#ifndef BOOKING_H
#define BOOKING_H

#include <string>
using namespace std;

class Booking
{
private:
    int bookingId;
    int clientId;
    int venueId;
    string eventDate;
    double totalAmount;
    bool confirmed;

public:
    Booking();
    Booking(int bId, int cId, int vId, string date, double amount);

    void display();

    int getBookingId();
    int getClientId();
    int getVenueId();
    string getEventDate();
    double getTotalAmount();
    bool isConfirmed();

    void setEventDate(string date);
    void setTotalAmount(double amount);
    void confirmBooking();
};

#endif