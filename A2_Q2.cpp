#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <fstream>


using namespace std;

// Base class for Room
class Room {
protected:
    int roomNumber;
    bool isBooked;

public:
    Room(int roomNumber) : roomNumber(roomNumber), isBooked(false) {}

    int getRoomNumber() const { return roomNumber; }
    bool getIsBooked() const { return isBooked; }

    virtual string getRoomType() const = 0; // Pure virtual function

    void bookRoom() {
        if (isBooked) throw runtime_error("Room is already booked.");
        isBooked = true;
    }

    void cancelBooking() {
        if (!isBooked) throw runtime_error("Room is not booked yet.");
        isBooked = false;
    }
};

// Derived classes for different types of rooms
class SingleRoom : public Room {
public:
    SingleRoom(int roomNumber) : Room(roomNumber) {}

    string getRoomType() const override {
        return "Single Room";
    }
};

class DoubleRoom : public Room {
public:
    DoubleRoom(int roomNumber) : Room(roomNumber) {}

    string getRoomType() const override {
        return "Double Room";
    }
};

class SuiteRoom : public Room {
public:
    SuiteRoom(int roomNumber) : Room(roomNumber) {}

    string getRoomType() const override {
        return "Suite Room";
    }
};

// Customer class
class Customer {
    string id;
    string name;

public:
    Customer(const string& id, const string& name) : id(id), name(name) {}

    string getId() const { return id; }
    string getName() const { return name; }
};

// Booking class
class Booking {
    string bookingId;
    Customer customer;
    Room* room;

public:
    Booking(const string& bookingId, const Customer& customer, Room* room)
        : bookingId(bookingId), customer(customer), room(room) {}

    string getBookingId() const { return bookingId; }
    Customer getCustomer() const { return customer; }
    Room* getRoom() const { return room; }
};

// Hotel class
class Hotel {
    vector<Room*> rooms;
    vector<Booking> bookings;

public:
    Hotel() {
        loadRoomsFromFile();  // Load rooms from file when the Hotel object is created
    }

    ~Hotel() {
        saveRoomsToFile();  // Save rooms to file when the Hotel object is destroyed
        for (auto room : rooms) {
            delete room;  // Clean up dynamically allocated memory
        }
    }

    void addRoom(Room* room) {
        rooms.push_back(room);
    }

    Room* findRoom(int roomNumber) {
        for (auto room : rooms) {
            if (room->getRoomNumber() == roomNumber) {
                return room;
            }
        }
        throw runtime_error("Room not found.");
    }

    void bookRoom(int roomNumber, const Customer& customer, const string& bookingId) {
        Room* room = findRoom(roomNumber);
        room->bookRoom();
        bookings.push_back(Booking(bookingId, customer, room));
    }

    void cancelBooking(const string& bookingId) {
        for (auto it = bookings.begin(); it != bookings.end(); ++it) {
            if (it->getBookingId() == bookingId) {
                it->getRoom()->cancelBooking();
                bookings.erase(it);
                return;
            }
        }
        throw runtime_error("Booking not found.");
    }

    void checkAvailability() const {
        for (auto room : rooms) {
            cout << "Room " << room->getRoomNumber() << " (" << room->getRoomType() << "): "
                 << (room->getIsBooked() ? "Booked" : "Available") << endl;
        }
    }

    void saveRoomsToFile() const {
        ofstream file("rooms.txt");
        if (!file) {
            cerr << "Error: Could not open file for saving rooms." << endl;
            return;
        }

        for (auto room : rooms) {
            file << room->getRoomNumber() << " " << room->getRoomType() << " " << room->getIsBooked() << endl;
        }

        file.close();
    }

    void loadRoomsFromFile() {
        ifstream file("rooms.txt");
        if (!file) {
            cerr << "Error: Could not open file for loading rooms. Starting with empty hotel." << endl;
            return;
        }

        int roomNumber;
        string roomType;
        bool isBooked;

        while (file >> roomNumber >> roomType >> isBooked) {
            Room* room = nullptr;
            if (roomType == "Single") {
                room = new SingleRoom(roomNumber);
            } else if (roomType == "Double") {
                room = new DoubleRoom(roomNumber);
            } else if (roomType == "Suite") {
                room = new SuiteRoom(roomNumber);
            }

            if (room) {
                if (isBooked) {
                    room->bookRoom();  // Mark the room as booked if it was booked in the file
                }
                rooms.push_back(room);
            }
        }

        file.close();
    }
};

// Main Function
int main() {
    Hotel hotel;
    int choice;
    string customerId, customerName, bookingId;
    int roomNumber;

    do {
        cout << "\nHotel Booking System";
        cout << "\n1. Book Room";
        cout << "\n2. Cancel Booking";
        cout << "\n3. Check Room Availability";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "\nEnter Room Number to book: ";
                cin >> roomNumber;
                cout << "Enter Customer ID: ";
                cin >> customerId;
                cout << "Enter Customer Name: ";
                cin.ignore();
                getline(cin, customerName);
                cout << "Enter Booking ID: ";
                cin >> bookingId;

                try {
                    hotel.bookRoom(roomNumber, Customer(customerId, customerName), bookingId);
                    cout << "Room booked successfully." << endl;
                } catch (const exception& e) {
                    cerr << e.what() << endl;
                }
                break;
            }
            case 2: {
                cout << "\nEnter Booking ID to cancel: ";
                cin >> bookingId;

                try {
                    hotel.cancelBooking(bookingId);
                    cout << "Booking cancelled successfully." << endl;
                } catch (const exception& e) {
                    cerr << e.what() << endl;
                }
                break;
            }
            case 3: {
                hotel.checkAvailability();
                break;
            }
            case 4: {
                cout << "Exiting the system..." << endl;
                break;
            }
            default: {
                cout << "Invalid choice! Please choose again." << endl;
                break;
            }
        }
    } while (choice != 4);

    return 0;
}
