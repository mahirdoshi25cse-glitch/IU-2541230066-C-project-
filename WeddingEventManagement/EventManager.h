
#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include "Client.h"
#include "Venue.h"
#include "Service.h"
#include "Booking.h"

class EventManager
{
private:
    Client* clients;
    Venue* venues;
    Service* services;
    Booking* bookings;

    int clientCount;
    int venueCount;
    int serviceCount;
    int bookingCount;

    static const int MAX_RECORDS = 100;

    bool clientExists(int id);
    bool venueExists(int id);

    void saveAll();

    void addClient();
    void addVenue();
    void addService();
    void addBooking();

    void displayClients();
    void displayVenues();
    void displayServices();
    void displayBookings();
    void displayAll();

    void searchRecord();
    void updateRecord();
    void deleteRecord();

public:
    EventManager();
    ~EventManager();

    void menu();
};

#endif