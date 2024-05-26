
#include <iostream>
#include <map>
#include <string>
#include <vector>

class Accommodation {
public:
    // Constructor
    Accommodation(const std::string& name, const std::string& location)
        : name(name), location(location) {}

    // Book a room
    void bookRoom(const std::string& roomType, const std::string& guestType) {
        if (availableRooms[roomType] > 0) {
            availableRooms[roomType]--;
            std::cout << "Room of type " << roomType << " booked for " << guestType << "." << std::endl;
        } else {
            std::cout << "No available rooms of type " << roomType << "." << std::endl;
        }
    }

    // Get available rooms
    std::vector<std::string> getAvailableRooms() const {
        std::vector<std::string> available;
        for (const auto& room : availableRooms) {
            if (room.second > 0) {
                available.push_back(room.first + ": " + std::to_string(room.second) + " available");
            }
        }
        return available;
    }

    // Add rooms for demonstration purposes
    void addRoomType(const std::string& roomType, int count) {
        availableRooms[roomType] = count;
    }

private:
    std::string name;
    std::string location;
    std::map<std::string, int> availableRooms;
};

// Example usage
int main() {
    // Create an accommodation
    Accommodation hotel("Grand Hotel", "New York");

    // Add room types and availability for demonstration purposes
    hotel.addRoomType("Single", 5);
    hotel.addRoomType("Double", 3);
    hotel.addRoomType("Suite", 2);

    // Get available rooms
    std::vector<std::string> availableRooms = hotel.getAvailableRooms();
    std::cout << "Available Rooms:" << std::endl;
    for (const auto& room : availableRooms) {
        std::cout << room << std::endl;
    }

    // Book a room
    hotel.bookRoom("Double", "Business Traveler");

    // Get available rooms after booking
    availableRooms = hotel.getAvailableRooms();
    std::cout << "Available Rooms after booking:" << std::endl;
    for (const auto& room : availableRooms) {
        std::cout << room << std::endl;
    }

    return 0;
}
