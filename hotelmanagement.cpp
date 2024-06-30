#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Room {
public:
    int roomNumber;
    bool isOccupied;
    string guestName;

    Room(int number) : roomNumber(number), isOccupied(false), guestName("") {}

    void checkIn(const string& name) {
        if (!isOccupied) {
            guestName = name;
            isOccupied = true;
            cout << "Guest " << guestName << " has checked into room " << roomNumber << endl;
        } else {
            cout << "Room " << roomNumber << " is already occupied." << endl;
        }
    }

    void checkOut() {
        if (isOccupied) {
            cout << "Guest " << guestName << " has checked out of room " << roomNumber << endl;
            guestName = "";
            isOccupied = false;
        } else {
            cout << "Room " << roomNumber << " is already vacant." << endl;
        }
    }

    void displayStatus() const {
        cout << "Room " << roomNumber << ": " << (isOccupied ? "Occupied by " + guestName : "Vacant") << endl;
    }
};

class Hotel {
private:
    vector<Room> rooms;

public:
    Hotel(int numberOfRooms) {
        for (int i = 1; i <= numberOfRooms; ++i) {
            rooms.push_back(Room(i));
        }
    }

    void checkIn(int roomNumber, const string& guestName) {
        if (roomNumber > 0 && roomNumber <= rooms.size()) {
            rooms[roomNumber - 1].checkIn(guestName);
        } else {
            cout << "Invalid room number." << endl;
        }
    }

    void checkOut(int roomNumber) {
        if (roomNumber > 0 && roomNumber <= rooms.size()) {
            rooms[roomNumber - 1].checkOut();
        } else {
            cout << "Invalid room number." << endl;
        }
    }

    void displayStatus() const {
        for (const auto& room : rooms) {
            room.displayStatus();
        }
    }
};

int main() {
    Hotel hotel(10);  // Create a hotel with 10 rooms

    int choice;
    int roomNumber;
    string guestName;

    while (true) {
        cout << "\nHotel Management System\n";
        cout << "1. Check In\n";
        cout << "2. Check Out\n";
        cout << "3. Display Room Status\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter room number to check in: ";
            cin >> roomNumber;
            cout << "Enter guest name: ";
            cin.ignore();
            getline(cin, guestName);
            hotel.checkIn(roomNumber, guestName);
            break;

        case 2:
            cout << "Enter room number to check out: ";
            cin >> roomNumber;
            hotel.checkOut(roomNumber);
            break;

        case 3:
            hotel.displayStatus();
            break;

        case 4:
            cout << "Exiting..." << endl;
            return 0;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
