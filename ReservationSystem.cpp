#include <iostream>
#include <map>
#include <string>

class ReservationSystem {
public:
    // Constructor
    ReservationSystem(const std::string& location, const std::string& date, const std::string& activity)
        : location(location), date(date), activity(activity) {}

    // Make a reservation
    void makeReservation(const std::map<std::string, std::string>& details) {
        this->details = details;
        std::cout << "Reservation made for the following details:" << std::endl;
        for (const auto& detail : details) {
            std::cout << detail.first << ": " << detail.second << std::endl;
        }
    }

    // Choose transport
    void chooseTransport(const std::string& type) {
        transportType = type;
        std::cout << "Transport chosen: " << transportType << std::endl;
    }

    // Take a ticket
    void takeTicket() {
        std::cout << "Ticket taken for " << activity << " on " << date << " at " << location << "." << std::endl;
        if (!transportType.empty()) {
            std::cout << "Transport type: " << transportType << std::endl;
        }
    }

private:
    std::string location;
    std::string date;
    std::string activity;
    std::map<std::string, std::string> details;
    std::string transportType;
};

// Example usage
int main() {
    // Create a reservation
    ReservationSystem reservation("New York", "2023-08-15", "Concert");

    // Make a reservation
    std::map<std::string, std::string> details = {{"Name", "John Doe"}, {"Seats", "2"}, {"Time", "7:00 PM"}};
    reservation.makeReservation(details);

    // Choose transport
    reservation.chooseTransport("Car");

    // Take a ticket
    reservation.takeTicket();

    return 0;
}
