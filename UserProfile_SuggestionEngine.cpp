#include <iostream>
#include <vector>
#include <map>
#include <string>

class UserProfile {
public:
    // Constructor
    UserProfile(int age, const std::string& city, const std::vector<std::string>& occupation,
                const std::vector<std::string>& interests, const std::string& bio,
                const std::map<std::string, std::string>& details,
                const std::map<std::string, std::string>& preferences)
        : age(age), city(city), occupation(occupation), interests(interests),
          bio(bio), details(details), preferences(preferences) {}

    // Save profile details
    void saveProfileDetails() {
        std::cout << "Profile details saved." << std::endl;
    }

    // Edit profile details
    void editProfileDetails(int age, const std::string& city,
                            const std::vector<std::string>& occupation,
                            const std::vector<std::string>& interests,
                            const std::string& bio) {
        this->age = age;
        this->city = city;
        this->occupation = occupation;
        this->interests = interests;
        this->bio = bio;
        std::cout << "Profile details updated." << std::endl;
    }

    // Get preferences based on interests
    std::map<std::string, std::string> getPreferences() const {
        std::map<std::string, std::string> personalized_preferences;
        for (const auto& interest : interests) {
            if (preferences.find(interest) != preferences.end()) {
                personalized_preferences[interest] = preferences.at(interest);
            }
        }
        return personalized_preferences;
    }

    // Print profile details (for demonstration purposes)
    void printProfileDetails() const {
        std::cout << "Age: " << age << std::endl;
        std::cout << "City: " << city << std::endl;
        std::cout << "Occupation: ";
        for (const auto& job : occupation) {
            std::cout << job << " ";
        }
        std::cout << std::endl;
        std::cout << "Interests: ";
        for (const auto& interest : interests) {
            std::cout << interest << " ";
        }
        std::cout << std::endl;
        std::cout << "Bio: " << bio << std::endl;
        std::cout << "Details: ";
        for (const auto& detail : details) {
            std::cout << detail.first << ": " << detail.second << " ";
        }
        std::cout << std::endl;
        std::cout << "Preferences: ";
        for (const auto& preference : preferences) {
            std::cout << preference.first << ": " << preference.second << " ";
        }
        std::cout << std::endl;
    }

protected:
    int age;
    std::string city;
    std::vector<std::string> occupation;
    std::vector<std::string> interests;
    std::string bio;
    std::map<std::string, std::string> details;
    std::map<std::string, std::string> preferences;
};

class SuggestionEngine : public UserProfile {
public:
    // Constructor
    SuggestionEngine(int age, const std::string& city, const std::vector<std::string>& occupation,
                     const std::vector<std::string>& interests, const std::string& bio,
                     const std::map<std::string, std::string>& details,
                     const std::map<std::string, std::string>& preferences)
        : UserProfile(age, city, occupation, interests, bio, details, preferences) {}

    // Suggest places based on user preferences
    std::vector<std::string> suggestPlaces(const std::map<std::string, std::string>& userPreferences) const {
        std::vector<std::string> suggested_places;
        for (const auto& preference : userPreferences) {
            if (preference.first == "Travel") {
                suggested_places.push_back("Paris");
                suggested_places.push_back("New York");
                suggested_places.push_back("Tokyo");
            }
        }
        return suggested_places;
    }

    // Suggest activities based on user preferences
    std::vector<std::string> suggestActivities(const std::map<std::string, std::string>& userPreferences) const {
        std::vector<std::string> suggested_activities;
        for (const auto& preference : userPreferences) {
            if (preference.first == "Music") {
                suggested_activities.push_back("Attend a concert");
                suggested_activities.push_back("Visit a music festival");
            } else if (preference.first == "Technology") {
                suggested_activities.push_back("Visit a tech expo");
                suggested_activities.push_back("Attend a coding workshop");
            }
        }
        return suggested_activities;
    }
};

// Example usage
int main() {
    std::vector<std::string> occupation = {"Engineer"};
    std::vector<std::string> interests = {"Technology", "Music"};
    std::map<std::string, std::string> details = {{"hobbies", "Guitar, Programming"}, {"languages", "English, Spanish"}};
    std::map<std::string, std::string> preferences = {{"Technology", "Latest gadgets"}, {"Music", "Concert tickets"}, {"Travel", "Discounted flights"}};

    SuggestionEngine suggestion_engine(30, "New York", occupation, interests, "A passionate engineer with a love for technology and music.", details, preferences);

    // Get preferences based on interests
    std::map<std::string, std::string> user_preferences = suggestion_engine.getPreferences();

    // Suggest places
    std::vector<std::string> places = suggestion_engine.suggestPlaces(user_preferences);
    std::cout << "Suggested Places:" << std::endl;
    for (const auto& place : places) {
        std::cout << place << std::endl;
    }

    // Suggest activities
    std::vector<std::string> activities = suggestion_engine.suggestActivities(user_preferences);
    std::cout << "Suggested Activities:" << std::endl;
    for (const auto& activity : activities) {
        std::cout << activity << std::endl;
    }

    return 0;
}
