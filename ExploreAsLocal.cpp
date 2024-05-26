#include <iostream>
#include <vector>
#include <string>
#include <map>

class ExploreAsLocal {
public:
    // Constructor
    ExploreAsLocal(const std::string& city, const std::string& date, const std::vector<std::string>& interests)
        : city(city), date(date), interests(interests) {}

    // Select activity based on interests
    void selectActivity() const {
        std::map<std::string, std::vector<std::string>> localActivities = {
            {"Music", {"Concert at Central Park", "Jazz night at Blue Note"}},
            {"Technology", {"Tech meetup at WeWork", "Coding bootcamp"}},
            {"Art", {"Gallery opening at MoMA", "Street art tour"}},
            {"Food", {"Food festival at Union Square", "Cooking class at Sur La Table"}}
        };

        std::cout << "Activities available in " << city << " on " << date << " based on your interests:" << std::endl;
        for (const auto& interest : interests) {
            if (localActivities.find(interest) != localActivities.end()) {
                std::cout << interest << ":" << std::endl;
                for (const auto& activity : localActivities[interest]) {
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
    // User's local information
    std::string city = "New York";
    std::string date = "2023-08-15";
    std::vector<std::string> interests = {"Music", "Food"};

    // Create an instance of ExploreAsLocal
    ExploreAsLocal explore(city, date, interests);

    // Select activity based on interests
    explore.selectActivity();

    return 0;
}
