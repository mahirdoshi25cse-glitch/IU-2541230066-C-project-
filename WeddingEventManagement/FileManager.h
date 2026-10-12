
#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "Client.h"
#include "Venue.h"
#include "Service.h"
#include "Booking.h"

#include <string>

using namespace std;

class FileManager
{
public:
    static bool saveClients(Client* clients, int count);
    static bool loadClients(Client* clients, int& count, int maxRecords);

    static bool saveVenues(Venue* venues, int count);
    static bool loadVenues(Venue* venues, int& count, int maxRecords);

    static bool saveServices(Service* services, int count);
    static bool loadServices(Service* services, int& count, int maxRecords);

    static bool saveBookings(Booking* bookings, int count);
    static bool loadBookings(Booking* bookings, int& count, int maxRecords);
};

#endif