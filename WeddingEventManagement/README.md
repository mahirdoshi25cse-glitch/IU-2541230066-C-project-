# Wedding Event Management System

**Subject:** C++ Guided Project (CPP42)  
**Student:** Mahir P. Doshi  
**Enrollment No.:** IU2541230066  
**Semester:** 3

## 1. Project Overview

The Wedding Event Management System is a menu-driven C++ application designed to manage clients, wedding venues, services, and bookings. It allows the wedding event manager to add and display records, search for information, update or delete records, create bookings, calculate booking totals, and save data using text files.

## 2. Features

- Add and manage client records.
- Add and manage wedding venues.
- Add and manage wedding services and costs.
- Create bookings for clients and venues.
- Check venue availability during booking creation.
- Calculate the total booking amount.
- Display, search, update, and delete records.
- Save and load records using text files.
- Demonstrate object-oriented programming concepts in C++.

## 3. Technologies Used

- C++
- GCC/G++ compiler
- Visual Studio Code
- Text-file storage

## 4. Project Structure

| File | Description |
|---|---|
| `main.cpp` | Starts the application. |
| `Person.h` / `Person.cpp` | Base person class. |
| `Client.h` / `Client.cpp` | Client information management. |
| `Venue.h` / `Venue.cpp` | Venue information management. |
| `Service.h` / `Service.cpp` | Wedding service management. |
| `Booking.h` / `Booking.cpp` | Booking information. |
| `EventManager.h` / `EventManager.cpp` | Main menu and application operations. |
| `FileManager.h` / `FileManager.cpp` | File saving and loading. |
| `clients.txt` | Client records. |
| `venues.txt` | Venue records. |
| `services.txt` | Service records. |
| `bookings.txt` | Booking records. |
| `.vscode/tasks.json` | VS Code build-task configuration. |
| `output/main.exe` | Compiled Windows executable. |

## 5. Object-Oriented Programming Concepts

The project demonstrates classes and objects, encapsulation, inheritance, polymorphism, constructors, destructors, and dynamic memory allocation.

The `Client` class inherits from `Person`. The `EventManager` class coordinates application operations, while `FileManager` handles data persistence.

## 6. How to Compile

Install GCC/G++ and make sure it is available in your system PATH.

Open a terminal in the main project folder and run:

```powershell
g++ -Wall -Wextra -g3 main.cpp Person.cpp Client.cpp Venue.cpp Service.cpp Booking.cpp EventManager.cpp FileManager.cpp -o output\main.exe
```

The `output` folder must exist before compiling.

## 7. How to Run

From the main project folder, run:

```powershell
.\output\main.exe
```

Alternatively, open the project in Visual Studio Code and use your configured build/run workflow.

Run the application from the main project folder so the text files are read and written in the intended location.

## 8. Data Persistence

The system stores client, venue, service, and booking records in separate text files. Records are loaded into memory when the application starts and saved through the file-management functions when required.

## 9. Testing

The project can be tested using cases for adding records, duplicate IDs, booking total calculation, invalid IDs, searching, updating, deleting, input validation, and data persistence after restarting the application.

## 10. Limitations

- Console-based user interface.
- Maximum capacity of 100 records per collection.
- Local text-file storage rather than a database.
- No customer login or online payment system.
- No date-based conflict detection for overlapping bookings.

## 11. Future Enhancements

Possible improvements include database integration, a graphical interface, customer authentication, date-based availability checking, online payments, and automated notifications.

## Author

Mahir P. Doshi  
B.Tech Computer Science and Engineering  
Indus University