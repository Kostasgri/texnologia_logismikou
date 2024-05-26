#include <iostream>
#include <string>
#include <vector>

// Forward declaration of User class
class User;

// Review class
class Review {
public:
    // Constructor
    Review(const User& user, int rating, const std::string& comment)
        : user(user), rating(rating), comment(comment) {}

    // Make a review
    void makeReview(const std::string& review) {
        this->comment = review;
        std::cout << "Review submitted: " << review << std::endl;
    }

    // Display the review
    void displayReview() const {
        std::cout << "User: " << user.getName() << std::endl;
        std::cout << "Rating: " << rating << std::endl;
        std::cout << "Comment: " << comment << std::endl;
    }

private:
    const User& user;
    int rating;
    std::string comment;
};

// User class
class User {
public:
    // Constructor
    User(const std::string& name) : name(name) {}

    // Get user name
    std::string getName() const {
        return name;
    }

private:
    std::string name;
};

// Example usage
int main() {
    // Create a user
    User user("John Doe");

    // Create a review
    Review review(user, 5, "Amazing experience!");

    // Make a review
    review.makeReview("Had a great time at the concert!");

    // Display the review
    review.displayReview();

    return 0;
}
