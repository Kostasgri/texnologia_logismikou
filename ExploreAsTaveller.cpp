#include <iostream>
#include <vector>
#include <string>
#include <map>

class ExploreAsTraveller {
public:
    // Constructor
    ExploreAsTraveller(const std::string& city, const std::string& date, const std::vector<std::string>& interests)
        : city(city), date(date), interests(interests) {}

    // Select destination
    void selectDirection() const {
        std::map<std::string, std::vector<std::string>> touristDestinations = {
            {"Paris", {"Eiffel Tower", "Louvre Museum", "Notre-Dame Cathedral"}},
            {"Rome", {"Colosseum", "Vatican Museums", "Trevi Fountain"}},
            {"Tokyo", {"Shibuya Crossing", "Tokyo Tower", "Meiji Shrine"}},
            {"New York", {"Statue of Liberty", "Central Park", "Times Square"}}
        };

        if (touristDestinations.find(city) != touristDestinations.end()) {
            std::cout << "Popular destinations in " << city << ":" << std::endl;
            for (const auto& destination : touristDestinations[city]) {
                std::cout << "- " << destination << std::endl;
            }
        } else {
            std::cout << "No destinations found for city: " << city << std::endl;
        }
    }

    // Select activity based on interests
    void selectActivity() const {
        std::map<std::string, std::vector<std::string>> touristActivities = {
            {"Music", {"Live concert", "Music festival"}},
            {"Technology", {"Tech conference", "Gadget expo"}},
            {"Art", {"Art exhibition", "Museum tour"}},
            {"Food", {"Gourmet food tour", "Wine tasting"}}
        };

        std::cout << "Activities available in " << city << " on " << date << " based on your interests:" << std::endl;
        for (const auto& interest : interests) {
            if (touristActivities.find(interest) != touristActivities.end()) {
                std::cout << interest << ":" << std::endl;
                for (const auto& activity : touristActivities[interest]) {
                    std::cout << "- " << activity << std::endl;
                }
            } else {
                std::cout << "No activities found for interest: " << interest << std::endl;
            }
        }
    }

private:
    std::string city;
    std::string date;
    std::vector<std::string> interests;
};

// Example usage
int main() {
    // Information about the trip
    std::string city = "Rome";
    std::string date = "2023-08-15";
    std::vector<std::string> interests = {"Art", "Food"};

    // Create an instance of ExploreAsTraveller
    ExploreAsTraveller explore(city, date, interests);

    // Select destination
    explore.selectDirection();

    // Select activity based on interests
    explore.selectActivity();

    return 0;
}
