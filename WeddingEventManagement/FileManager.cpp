
#include "FileManager.h"

#include <fstream>
#include <iostream>
#include <limits>

using namespace std;

// ==================== CLIENTS ====================

bool FileManager::saveClients(Client* clients, int count)
{
    ofstream file("clients.txt");

    if (!file.is_open())
        return false;

    file << count << '\n';

    for (int i = 0; i < count; i++)
    {
        file << clients[i].getId() << '\n';
        file << clients[i].getName() << '\n';
        file << clients[i].getPhone() << '\n';
    }

    return file.good();
}

bool FileManager::loadClients(Client* clients, int& count, int maxRecords)
{
    ifstream file("clients.txt");

    if (!file.is_open())
    {
        count = 0;
        return true;
    }

    int savedCount;

    if (!(file >> savedCount) || savedCount < 0 ||
        savedCount > maxRecords)
        return false;

    file.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < savedCount; i++)
    {
        int id;
        string name, phone;

        if (!(file >> id))
            return false;

        file.ignore(numeric_limits<streamsize>::max(), '\n');

        if (!getline(file, name) || !getline(file, phone))
            return false;

        clients[i] = Client(id, name, phone);
    }

    count = savedCount;
    return true;
}

// ==================== VENUES ====================

bool FileManager::saveVenues(Venue* venues, int count)
{
    ofstream file("venues.txt");

    if (!file.is_open())
        return false;

    file << count << '\n';

    for (int i = 0; i < count; i++)
    {
        file << venues[i].getVenueId() << '\n';
        file << venues[i].getVenueName() << '\n';
        file << venues[i].getCapacity() << '\n';
        file << venues[i].getRent() << '\n';
        file << venues[i].isAvailable() << '\n';
    }

    return file.good();
}

bool FileManager::loadVenues(Venue* venues, int& count, int maxRecords)
{
    ifstream file("venues.txt");

    if (!file.is_open())
    {
        count = 0;
        return true;
    }

    int savedCount;

    if (!(file >> savedCount) || savedCount < 0 ||
        savedCount > maxRecords)
        return false;

    file.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < savedCount; i++)
    {
        int id, capacity;
        double rent;
        bool available;
        string name;

        if (!(file >> id))
            return false;

        file.ignore(numeric_limits<streamsize>::max(), '\n');

        if (!getline(file, name))
            return false;

        if (!(file >> capacity >> rent >> available))
            return false;

        file.ignore(numeric_limits<streamsize>::max(), '\n');

        venues[i] = Venue(id, name, capacity, rent, available);
    }

    count = savedCount;
    return true;
}

// ==================== SERVICES ====================

bool FileManager::saveServices(Service* services, int count)
{
    ofstream file("services.txt");

    if (!file.is_open())
        return false;

    file << count << '\n';

    for (int i = 0; i < count; i++)
    {
        file << services[i].getServiceId() << '\n';
        file << services[i].getServiceName() << '\n';
        file << services[i].getCost() << '\n';
    }

    return file.good();
}

bool FileManager::loadServices(
    Service* services, int& count, int maxRecords)
{
    ifstream file("services.txt");

    if (!file.is_open())
    {
        count = 0;
        return true;
    }

    int savedCount;

    if (!(file >> savedCount) || savedCount < 0 ||
        savedCount > maxRecords)
        return false;

    file.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < savedCount; i++)
    {
        int id;
        double cost;
        string name;

        if (!(file >> id))
            return false;

        file.ignore(numeric_limits<streamsize>::max(), '\n');

        if (!getline(file, name))
            return false;

        if (!(file >> cost))
            return false;

        file.ignore(numeric_limits<streamsize>::max(), '\n');

        services[i] = Service(id, name, cost);
    }

    count = savedCount;
    return true;
}

// ==================== BOOKINGS ====================

bool FileManager::saveBookings(Booking* bookings, int count)
{
    ofstream file("bookings.txt");

    if (!file.is_open())
        return false;

    file << count << '\n';

    for (int i = 0; i < count; i++)
    {
        file << bookings[i].getBookingId() << '\n';
        file << bookings[i].getClientId() << '\n';
        file << bookings[i].getVenueId() << '\n';
        file << bookings[i].getEventDate() << '\n';
        file << bookings[i].getTotalAmount() << '\n';
        file << bookings[i].isConfirmed() << '\n';
    }

    return file.good();
}

bool FileManager::loadBookings(
    Booking* bookings, int& count, int maxRecords)
{
    ifstream file("bookings.txt");

    if (!file.is_open())
    {
        count = 0;
        return true;
    }

    int savedCount;

    if (!(file >> savedCount) || savedCount < 0 ||
        savedCount > maxRecords)
        return false;

    file.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < savedCount; i++)
    {
        int bookingId, clientId, venueId;
        double amount;
        bool confirmed;
        string date;

        if (!(file >> bookingId >> clientId >> venueId))
            return false;

        file.ignore(numeric_limits<streamsize>::max(), '\n');

        if (!getline(file, date))
            return false;

        if (!(file >> amount >> confirmed))
            return false;

        file.ignore(numeric_limits<streamsize>::max(), '\n');

        bookings[i] = Booking(
            bookingId, clientId, venueId, date, amount
        );

        if (confirmed)
            bookings[i].confirmBooking();
    }

    count = savedCount;
    return true;
}