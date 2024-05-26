#include <iostream>
#include <string>
#include <vector>

class User {
public:
    // Constructor
    User(const std::string& username, const std::string& email, const std::string& password,
         int age, const std::string& city, const std::vector<std::string>& occupation,
         const std::vector<std::string>& interests, const std::string& bio)
        : username(username), email(email), password(password), age(age), city(city),
          occupation(occupation), interests(interests), bio(bio), loggedIn(false) {}

    // Sign up
    void signUp() {
        std::cout << "Signed up successfully!" << std::endl;
    }

    // Log in
    void login() {
        loggedIn = true;
        std::cout << "Logged in successfully!" << std::endl;
    }

    // Make profile details
    void makeProfileDetails() {
        // Implementation logic to make profile details
        std::cout << "Profile details made." << std::endl;
    }

    // Save profile
    void saveProfile() {
        // Implementation logic to save profile
        std::cout << "Profile saved." << std::endl;
    }

    // Explore choices
    void exploreChoices() {
        // Implementation logic to explore choices
        std::cout << "Choices explored." << std::endl;
    }

    // Pick choices
    void pickChoices() {
        // Implementation logic to pick choices
        std::cout << "Choices picked." << std::endl;
    }

    // Make a review
    void makeReview() {
        // Implementation logic to make a review
        std::cout << "Review made." << std::endl;
    }

    // Make a reservation
    void makeReservation() {
        // Implementation logic to make a reservation
        std::cout << "Reservation made." << std::endl;
    }

    // Book a room
    void bookRoom() {
        // Implementation logic to book a room
        std::cout << "Room booked." << std::endl;
    }

private:
    std::string username;
    std::string email;
    std::string password;
    int age;
    std::string city;
    std::vector<std::string> occupation;
    std::vector<std::string> interests;
    std::string bio;
    bool loggedIn;
};

// Example usage
int main() {
    // Create a user
    User user("john_doe", "john@example.com", "password123", 30, "New York",
              {"Software Engineer"}, {"Travel", "Music", "Technology"},
              "I love traveling and exploring new technologies.");

    // Sign up
    user.signUp();

    // Log in
    user.login();

    // Make profile details
    user.makeProfileDetails();

    // Save profile
    user.saveProfile();

    // Explore choices
    user.exploreChoices();

    // Pick choices
    user.pickChoices();

    // Make a review
    user.makeReview();

    // Make a reservation
    user.makeReservation();

    // Book a room
    user.bookRoom();

    return 0;
}
