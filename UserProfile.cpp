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

private:
    int age;
    std::string city;
    std::vector<std::string> occupation;
    std::vector<std::string> interests;
    std::string bio;
    std::map<std::string, std::string> details;
    std::map<std::string, std::string> preferences;
};

// Example usage
int main() {
    std::vector<std::string> occupation = {"Engineer"};
    std::vector<std::string> interests = {"Technology", "Music"};
    std::map<std::string, std::string> details = {{"hobbies", "Guitar, Programming"}, {"languages", "English, Spanish"}};
    std::map<std::string, std::string> preferences = {{"Technology", "Latest gadgets"}, {"Music", "Concert tickets"}, {"Travel", "Discounted flights"}};

    UserProfile user_profile(30, "New York", occupation, interests, "A passionate engineer with a love for technology and music.", details, preferences);

    // Save profile details
    user_profile.saveProfileDetails();

    // Edit profile details
    user_profile.editProfileDetails(31, "San Francisco", occupation, interests, "A passionate engineer who recently moved to San Francisco.");

    // Get preferences based on interests
    std::map<std::string, std::string> personalized_preferences = user_profile.getPreferences();
    std::cout << "Personalized Preferences:" << std::endl;
    for (const auto& preference : personalized_preferences) {
        std::cout << preference.first << ": " << preference.second << std::endl;
    }

    // Print profile details
    user_profile.printProfileDetails();

    return 0;
}
