#include <iostream>
#include <string>
#include <unordered_map>

class Authentication {
public:
    // Constructor
    Authentication() = default;

    // Sign up method
    bool signup(const std::string& email, const std::string& password) {
        if (users.find(email) != users.end()) {
            std::cout << "Email already registered." << std::endl;
            return false;
        }
        users[email] = password;
        std::cout << "Sign up successful." << std::endl;
        return true;
    }

    // Login method
    bool login(const std::string& email, const std::string& password) {
        if (authenticate(email, password)) {
            std::cout << "Login successful." << std::endl;
            return true;
        }
        std::cout << "Login failed. Incorrect email or password." << std::endl;
        return false;
    }

    // Set password method
    void set_code(const std::string& password) {
        this->password = password;
    }

    // Authenticate method
    bool authenticate(const std::string& email, const std::string& password) const {
        auto it = users.find(email);
        if (it != users.end() && it->second == password) {
            return true;
        }
        return false;
    }

private:
    std::unordered_map<std::string, std::string> users;
    std::string password;
};

// Example usage
int main() {
    Authentication auth;

    // Sign up new users
    auth.signup("user1@example.com", "password123");
    auth.signup("user2@example.com", "mypassword");

    // Try to sign up with an existing email
    auth.signup("user1@example.com", "newpassword");

    // Login with correct and incorrect credentials
    auth.login("user1@example.com", "password123"); // Should be successful
    auth.login("user1@example.com", "wrongpassword"); // Should fail

    return 0;
}
