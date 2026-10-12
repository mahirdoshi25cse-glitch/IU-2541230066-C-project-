#include "Booking.h"
#include <iostream>
using namespace std;

Booking::Booking()
{
    bookingId = 0;
    clientId = 0;
    venueId = 0;
    eventDate = "";
    totalAmount = 0;
    confirmed = false;
}

Booking::Booking(int bId, int cId, int vId, string date, double amount)
{
    bookingId = bId;
    clientId = cId;
    venueId = vId;
    eventDate = date;
    totalAmount = amount;
    confirmed = false;
}

void Booking::display()
{
    cout << "Booking ID: " << bookingId << endl;
    cout << "Client ID: " << clientId << endl;
    cout << "Venue ID: " << venueId << endl;
    cout << "Event Date: " << eventDate << endl;
    cout << "Total Amount: " << totalAmount << endl;
    cout << "Status: " << (confirmed ? "Confirmed" : "Pending") << endl;
}

int Booking::getBookingId()
{
    return bookingId;
}

int Booking::getClientId()
{
    return clientId;
}

int Booking::getVenueId()
{
    return venueId;
}

string Booking::getEventDate()
{
    return eventDate;
}

double Booking::getTotalAmount()
{
    return totalAmount;
}

bool Booking::isConfirmed()
{
    return confirmed;
}

void Booking::setEventDate(string date)
{
    eventDate = date;
}

void Booking::setTotalAmount(double amount)
{
    totalAmount = amount;
}

void Booking::confirmBooking()
{
    confirmed = true;
}