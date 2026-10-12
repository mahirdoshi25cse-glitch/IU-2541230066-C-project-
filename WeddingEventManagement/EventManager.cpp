
#include "EventManager.h"
#include "FileManager.h"

#include <iostream>
#include <limits>
#include <string>

using namespace std;

// ==================== INPUT HELPERS ====================

int readInt(string prompt)
{
    int value;

    while (true)
    {
        cout << prompt;

        if (cin >> value)
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }

        cout << "Invalid input. Please enter a number.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

double readDouble(string prompt)
{
    double value;

    while (true)
    {
        cout << prompt;

        if (cin >> value)
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }

        cout << "Invalid input. Please enter a valid number.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int readPositiveInt(string prompt)
{
    int value;

    do
    {
        value = readInt(prompt);

        if (value <= 0)
            cout << "Value must be greater than zero.\n";

    } while (value <= 0);

    return value;
}

double readNonNegativeDouble(string prompt)
{
    double value;

    do
    {
        value = readDouble(prompt);

        if (value < 0)
            cout << "Amount cannot be negative.\n";

    } while (value < 0);

    return value;
}

string readText(string prompt)
{
    string value;

    do
    {
        cout << prompt;
        getline(cin, value);

        if (value.empty())
            cout << "This field cannot be empty.\n";

    } while (value.empty());

    return value;
}

// ==================== CONSTRUCTOR ====================

EventManager::EventManager()
{
    clients = new Client[MAX_RECORDS];
    venues = new Venue[MAX_RECORDS];
    services = new Service[MAX_RECORDS];
    bookings = new Booking[MAX_RECORDS];

    clientCount = 0;
    venueCount = 0;
    serviceCount = 0;
    bookingCount = 0;

    bool clientsLoaded =
        FileManager::loadClients(clients, clientCount, MAX_RECORDS);

    bool venuesLoaded =
        FileManager::loadVenues(venues, venueCount, MAX_RECORDS);

    bool servicesLoaded =
        FileManager::loadServices(services, serviceCount, MAX_RECORDS);

    bool bookingsLoaded =
        FileManager::loadBookings(bookings, bookingCount, MAX_RECORDS);

    if (clientsLoaded && venuesLoaded &&
        servicesLoaded && bookingsLoaded)
    {
        cout << "Saved records loaded successfully.\n";
    }
    else
    {
        cout << "Warning: One or more data files could not be loaded.\n";
    }
}

// ==================== DESTRUCTOR ====================

EventManager::~EventManager()
{
    delete[] clients;
    delete[] venues;
    delete[] services;
    delete[] bookings;
}

// ==================== SAVE ALL DATA ====================

void EventManager::saveAll()
{
    bool clientsSaved =
        FileManager::saveClients(clients, clientCount);

    bool venuesSaved =
        FileManager::saveVenues(venues, venueCount);

    bool servicesSaved =
        FileManager::saveServices(services, serviceCount);

    bool bookingsSaved =
        FileManager::saveBookings(bookings, bookingCount);

    if (clientsSaved && venuesSaved &&
        servicesSaved && bookingsSaved)
    {
        cout << "All records saved successfully.\n";
    }
    else
    {
        cout << "Warning: Some records could not be saved.\n";
    }
}

// ==================== ID CHECKS ====================

bool EventManager::clientExists(int id)
{
    for (int i = 0; i < clientCount; i++)
    {
        if (clients[i].getId() == id)
            return true;
    }

    return false;
}

bool EventManager::venueExists(int id)
{
    for (int i = 0; i < venueCount; i++)
    {
        if (venues[i].getVenueId() == id)
            return true;
    }

    return false;
}

// ==================== ADD CLIENT ====================

void EventManager::addClient()
{
    if (clientCount >= MAX_RECORDS)
    {
        cout << "Client storage is full.\n";
        return;
    }

    cout << "\n========== ADD CLIENT ==========\n";

    int id = readPositiveInt("Enter Client ID: ");

    if (clientExists(id))
    {
        cout << "A client with this ID already exists.\n";
        return;
    }

    string name = readText("Enter Client Name: ");
    string phone = readText("Enter Phone Number: ");

    clients[clientCount] = Client(id, name, phone);
    clientCount++;

    cout << "Client added successfully.\n";
    saveAll();
}

// ==================== ADD VENUE ====================

void EventManager::addVenue()
{
    if (venueCount >= MAX_RECORDS)
    {
        cout << "Venue storage is full.\n";
        return;
    }

    cout << "\n========== ADD VENUE ==========\n";

    int id = readPositiveInt("Enter Venue ID: ");

    if (venueExists(id))
    {
        cout << "A venue with this ID already exists.\n";
        return;
    }

    string name = readText("Enter Venue Name: ");
    int capacity = readPositiveInt("Enter Venue Capacity: ");
    double rent = readNonNegativeDouble("Enter Venue Rent: ");

    venues[venueCount] = Venue(id, name, capacity, rent, true);
    venueCount++;

    cout << "Venue added successfully.\n";
    saveAll();
}

// ==================== ADD SERVICE ====================

void EventManager::addService()
{
    if (serviceCount >= MAX_RECORDS)
    {
        cout << "Service storage is full.\n";
        return;
    }

    cout << "\n========== ADD SERVICE ==========\n";

    int id = readPositiveInt("Enter Service ID: ");

    for (int i = 0; i < serviceCount; i++)
    {
        if (services[i].getServiceId() == id)
        {
            cout << "A service with this ID already exists.\n";
            return;
        }
    }

    string name = readText("Enter Service Name: ");
    double cost = readNonNegativeDouble("Enter Service Cost: ");

    services[serviceCount] = Service(id, name, cost);
    serviceCount++;

    cout << "Service added successfully.\n";
    saveAll();
}

// ==================== ADD BOOKING ====================

void EventManager::addBooking()
{
    if (bookingCount >= MAX_RECORDS)
    {
        cout << "Booking storage is full.\n";
        return;
    }

    if (clientCount == 0)
    {
        cout << "Please add a client before creating a booking.\n";
        return;
    }

    if (venueCount == 0)
    {
        cout << "Please add a venue before creating a booking.\n";
        return;
    }

    cout << "\n========== ADD BOOKING ==========\n";

    int bookingId = readPositiveInt("Enter Booking ID: ");

    for (int i = 0; i < bookingCount; i++)
    {
        if (bookings[i].getBookingId() == bookingId)
        {
            cout << "A booking with this ID already exists.\n";
            return;
        }
    }

    int clientId = readPositiveInt("Enter Client ID: ");

    if (!clientExists(clientId))
    {
        cout << "Client not found. Please add the client first.\n";
        return;
    }

    int venueId = readPositiveInt("Enter Venue ID: ");

    if (!venueExists(venueId))
    {
        cout << "Venue not found. Please add the venue first.\n";
        return;
    }

    int venueIndex = -1;

    for (int i = 0; i < venueCount; i++)
    {
        if (venues[i].getVenueId() == venueId)
        {
            venueIndex = i;
            break;
        }
    }

    if (venueIndex == -1)
    {
        cout << "Venue not found.\n";
        return;
    }

    if (!venues[venueIndex].isAvailable())
    {
        cout << "This venue is currently unavailable.\n";
        return;
    }

    string eventDate = readText("Enter Event Date (DD-MM-YYYY): ");

    double totalAmount = venues[venueIndex].getRent();

    cout << "\n========== BILL CALCULATION ==========\n";
    cout << "Venue: " << venues[venueIndex].getVenueName() << '\n';
    cout << "Venue Rent: " << venues[venueIndex].getRent() << '\n';

    if (serviceCount > 0)
    {
        cout << "\nAvailable Services:\n";

        for (int i = 0; i < serviceCount; i++)
        {
            cout << "ID: " << services[i].getServiceId()
                 << " | Name: " << services[i].getServiceName()
                 << " | Cost: " << services[i].getCost()
                 << '\n';
        }
    }
    else
    {
        cout << "\nNo additional services are available.\n";
    }

    int numberOfServices = 0;

    while (true)
    {
        numberOfServices = readInt(
            "\nHow many services do you want to add? ");

        if (numberOfServices >= 0 &&
            numberOfServices <= serviceCount)
        {
            break;
        }

        cout << "Enter a number between 0 and "
             << serviceCount << ".\n";
    }

    bool selected[MAX_RECORDS] = {};
    int selectedCount = 0;

    while (selectedCount < numberOfServices)
    {
        int serviceId = readPositiveInt(
            "Enter the Service ID you want to add: ");

        int serviceIndex = -1;

        for (int i = 0; i < serviceCount; i++)
        {
            if (services[i].getServiceId() == serviceId)
            {
                serviceIndex = i;
                break;
            }
        }

        if (serviceIndex == -1)
        {
            cout << "Service not found. Try again.\n";
            continue;
        }

        if (selected[serviceIndex])
        {
            cout << "This service is already selected. "
                 << "Choose another service.\n";
            continue;
        }

        selected[serviceIndex] = true;
        selectedCount++;

        totalAmount += services[serviceIndex].getCost();

        cout << services[serviceIndex].getServiceName()
             << " added: "
             << services[serviceIndex].getCost()
             << '\n';
    }

    bookings[bookingCount] = Booking(
        bookingId, clientId, venueId, eventDate, totalAmount
    );

    bookingCount++;

    cout << "\n========== FINAL BILL ==========\n";
    cout << "Venue Rent: " << venues[venueIndex].getRent() << '\n';
    cout << "Additional Services: "
         << totalAmount - venues[venueIndex].getRent() << '\n';
    cout << "--------------------------------\n";
    cout << "Total Booking Amount: " << totalAmount << '\n';
    cout << "================================\n";

    cout << "Booking added successfully.\n";
    saveAll();
}

// ==================== DISPLAY CLIENTS ====================


void EventManager::displayClients()
{
    cout << "\n========== CLIENTS ==========\n";

    if (clientCount == 0)
    {
        cout << "No clients available.\n";
        return;
    }

    for (int i = 0; i < clientCount; i++)
    {
        Person* person = &clients[i];
        person->display();

        cout << "-----------------------------\n";
    }
}


// ==================== DISPLAY VENUES ====================

void EventManager::displayVenues()
{
    cout << "\n========== VENUES ==========\n";

    if (venueCount == 0)
    {
        cout << "No venues available.\n";
        return;
    }

    for (int i = 0; i < venueCount; i++)
    {
        venues[i].display();
        cout << "----------------------------\n";
    }
}

// ==================== DISPLAY SERVICES ====================

void EventManager::displayServices()
{
    cout << "\n========== SERVICES ==========\n";

    if (serviceCount == 0)
    {
        cout << "No services available.\n";
        return;
    }

    for (int i = 0; i < serviceCount; i++)
    {
        services[i].display();
        cout << "------------------------------\n";
    }
}

// ==================== DISPLAY BOOKINGS ====================

void EventManager::displayBookings()
{
    cout << "\n========== BOOKINGS ==========\n";

    if (bookingCount == 0)
    {
        cout << "No bookings available.\n";
        return;
    }

    for (int i = 0; i < bookingCount; i++)
    {
        bookings[i].display();
        cout << "------------------------------\n";
    }
}

// ==================== DISPLAY ALL ====================

void EventManager::displayAll()
{
    displayClients();
    displayVenues();
    displayServices();
    displayBookings();
}

// ==================== SEARCH RECORD ====================

void EventManager::searchRecord()
{
    cout << "\n========== SEARCH RECORD ==========\n";
    cout << "1. Search Client\n";
    cout << "2. Search Venue\n";
    cout << "3. Search Service\n";
    cout << "4. Search Booking\n";

    int type = readInt("Choose record type: ");
    int id = readPositiveInt("Enter record ID: ");

    bool found = false;

    switch (type)
    {
        case 1:
            for (int i = 0; i < clientCount; i++)
            {
                if (clients[i].getId() == id)
                {
                    clients[i].display();
                    found = true;
                    break;
                }
            }
            break;

        case 2:
            for (int i = 0; i < venueCount; i++)
            {
                if (venues[i].getVenueId() == id)
                {
                    venues[i].display();
                    found = true;
                    break;
                }
            }
            break;

        case 3:
            for (int i = 0; i < serviceCount; i++)
            {
                if (services[i].getServiceId() == id)
                {
                    services[i].display();
                    found = true;
                    break;
                }
            }
            break;

        case 4:
            for (int i = 0; i < bookingCount; i++)
            {
                if (bookings[i].getBookingId() == id)
                {
                    bookings[i].display();
                    found = true;
                    break;
                }
            }
            break;

        default:
            cout << "Invalid record type.\n";
            return;
    }

    if (!found)
        cout << "Record not found.\n";
}

// ==================== UPDATE RECORD ====================

void EventManager::updateRecord()
{
    cout << "\n========== UPDATE RECORD ==========\n";
    cout << "1. Update Client\n";
    cout << "2. Update Venue\n";
    cout << "3. Update Service\n";
    cout << "4. Update Booking\n";

    int type = readInt("Choose record type: ");
    int id = readPositiveInt("Enter record ID to update: ");

    bool updated = false;

    switch (type)
    {
        case 1:
        {
            for (int i = 0; i < clientCount; i++)
            {
                if (clients[i].getId() == id)
                {
                    string name = readText("Enter new client name: ");
                    string phone = readText("Enter new phone number: ");

                    clients[i] = Client(id, name, phone);
                    updated = true;
                    break;
                }
            }
            break;
        }

        case 2:
        {
            for (int i = 0; i < venueCount; i++)
            {
                if (venues[i].getVenueId() == id)
                {
                    string name = readText("Enter new venue name: ");
                    int capacity = readPositiveInt("Enter new capacity: ");
                    double rent = readNonNegativeDouble("Enter new rent: ");

                    venues[i].setVenueName(name);
                    venues[i].setCapacity(capacity);
                    venues[i].setRent(rent);

                    updated = true;
                    break;
                }
            }
            break;
        }

        case 3:
        {
            for (int i = 0; i < serviceCount; i++)
            {
                if (services[i].getServiceId() == id)
                {
                    string name = readText("Enter new service name: ");
                    double cost = readNonNegativeDouble(
                        "Enter new service cost: ");

                    services[i].setServiceName(name);
                    services[i].setCost(cost);

                    updated = true;
                    break;
                }
            }
            break;
        }

        case 4:
        {
            for (int i = 0; i < bookingCount; i++)
            {
                if (bookings[i].getBookingId() == id)
                {
                    string date = readText(
                        "Enter new event date (DD-MM-YYYY): ");

                    double amount = readNonNegativeDouble(
                        "Enter new total amount: ");

                    bookings[i].setEventDate(date);
                    bookings[i].setTotalAmount(amount);

                    updated = true;
                    break;
                }
            }
            break;
        }

        default:
            cout << "Invalid record type.\n";
            return;
    }

    if (updated)
    {
        cout << "Record updated successfully.\n";
        saveAll();
    }
    else
    {
        cout << "Record not found.\n";
    }
}

// ==================== DELETE RECORD ====================

void EventManager::deleteRecord()
{
    cout << "\n========== DELETE RECORD ==========\n";
    cout << "1. Delete Client\n";
    cout << "2. Delete Venue\n";
    cout << "3. Delete Service\n";
    cout << "4. Delete Booking\n";

    int type = readInt("Choose record type: ");
    int id = readPositiveInt("Enter record ID to delete: ");

    int index = -1;

    switch (type)
    {
        case 1:
        {
            for (int i = 0; i < clientCount; i++)
            {
                if (clients[i].getId() == id)
                {
                    for (int j = 0; j < bookingCount; j++)
                    {
                        if (bookings[j].getClientId() == id)
                        {
                            cout << "Cannot delete this client because "
                                 << "a booking uses it.\n";
                            return;
                        }
                    }

                    index = i;

                    for (int j = index; j < clientCount - 1; j++)
                    {
                        clients[j] = clients[j + 1];
                    }

                    clientCount--;
                    break;
                }
            }
            break;
        }

        case 2:
        {
            for (int i = 0; i < venueCount; i++)
            {
                if (venues[i].getVenueId() == id)
                {
                    for (int j = 0; j < bookingCount; j++)
                    {
                        if (bookings[j].getVenueId() == id)
                        {
                            cout << "Cannot delete this venue because "
                                 << "a booking uses it.\n";
                            return;
                        }
                    }

                    index = i;

                    for (int j = index; j < venueCount - 1; j++)
                    {
                        venues[j] = venues[j + 1];
                    }

                    venueCount--;
                    break;
                }
            }
            break;
        }

        case 3:
        {
            for (int i = 0; i < serviceCount; i++)
            {
                if (services[i].getServiceId() == id)
                {
                    index = i;

                    for (int j = index; j < serviceCount - 1; j++)
                    {
                        services[j] = services[j + 1];
                    }

                    serviceCount--;
                    break;
                }
            }
            break;
        }

        case 4:
        {
            for (int i = 0; i < bookingCount; i++)
            {
                if (bookings[i].getBookingId() == id)
                {
                    index = i;

                    for (int j = index; j < bookingCount - 1; j++)
                    {
                        bookings[j] = bookings[j + 1];
                    }

                    bookingCount--;
                    break;
                }
            }
            break;
        }

        default:
            cout << "Invalid record type.\n";
            return;
    }

    if (index == -1)
    {
        cout << "Record not found.\n";
        return;
    }

    cout << "Record deleted successfully.\n";
    saveAll();
}

// ==================== MAIN MENU ====================

void EventManager::menu()
{
    int choice;

    do
    {
        cout << "\n========================================\n";
        cout << "     WEDDING EVENT MANAGEMENT SYSTEM\n";
        cout << "========================================\n";
        cout << "1. Add Client\n";
        cout << "2. Add Venue\n";
        cout << "3. Add Service\n";
        cout << "4. Add Booking\n";
        cout << "5. Display All Records\n";
        cout << "6. Search Record\n";
        cout << "7. Update Record\n";
        cout << "8. Delete Record\n";
        cout << "0. Exit\n";
        cout << "========================================\n";

        choice = readInt("Enter your choice: ");

        switch (choice)
        {
            case 1:
                addClient();
                break;

            case 2:
                addVenue();
                break;

            case 3:
                addService();
                break;

            case 4:
                addBooking();
                break;

            case 5:
                displayAll();
                break;

            case 6:
                searchRecord();
                break;

            case 7:
                updateRecord();
                break;

            case 8:
                deleteRecord();
                break;

            case 0:
                saveAll();
                cout << "Thank you for using the system!\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 0);
}