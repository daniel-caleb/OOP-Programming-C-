#include <iostream>
#include <string>
using namespace std;

// User class represents a user of the system
class User {
private:
    string username;
    string password;
public:
    User(string username, string password) {
        this->username = username;
        this->password = password;
    }

    string get_username() {
        return username;
    }

    bool check_password(string password) {
        return this->password == password;
    }
};

// Login class manages the login and logout process
class Login {
private:
    User* user;
    int attempts_left;
public:
    Login(User* user) {
        this->user = user;
        attempts_left = 3;
    }

    bool login(string username, string password) {
        if (user->get_username() == username && user->check_password(password)) {
            cout << "Login successful!\n";
            attempts_left = 3;
            return true;
        } else {
            attempts_left--;
            cout << "Login failed. Attempts left: " << attempts_left << endl;
            return false;
        }
    }

    bool logout() {
        cout << "Logged out.\n";
        return true;
    }

    int get_attempts_left() {
        return attempts_left;
    }
};

// Billing class represents the user's water bill
class Billing {
private:
    int prev_reading;
    int curr_reading;
    double unit_cost = 5.50;
    double fixed_charge = 300.00;
    double vat_rate = 0.05;
public:
    Billing(int prev_reading, int curr_reading) {
        this->prev_reading = prev_reading;
        this->curr_reading = curr_reading;
    }

    double calculate() {
        if (curr_reading <= prev_reading) {
            cout << "Error: Current reading must be greater than previous reading.\n";
            return 0.0;
        }
        int units_consumed = curr_reading - prev_reading;
        double total_cost = fixed_charge + units_consumed * unit_cost;
        double vat = total_cost * vat_rate;
        return total_cost + vat;
    }
};

int main() {
    // Create a user with username "user1" and password "pass1"
    User user("user1", "pass1");
    // Create a Login object with the user
    Login login(&user);
    // Attempt to log in with correct credentials
    if (login.login("user1", "pass1")) {
        // If login is successful, provide the three options
        cout << "Choose an option:\n";
        cout << "0: Check current bill\n";
        cout << "1: Make payment\n";
        cout << "2: Enter meter readings\n";
        int option;
        cin >> option;
        switch (option) {
            case 0: {
                // If user chooses option 0, calculate the current bill and display it
                Billing billing(100, 150); // Example meter readings
                double bill = billing.calculate();
                cout << "Current bill: " << bill << endl;
                break;
            }
            case 1: {
                // If user chooses option 1, make a payment
                cout << "Payment made.\n";
                break;
            }
            case 2: {
                // If user chooses option 2, enter meter readings
                int prev_reading, curr_reading;
                cout << "Enter previous reading: ";
                cin >> prev_reading;
                cout << "Enter current reading: ";
                cin >> curr_reading;
                Billing billing(prev_reading, curr_reading);
                double bill = billing.calculate();

