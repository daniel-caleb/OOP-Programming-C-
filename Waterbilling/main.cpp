#include <iostream>
#include <string>

class User {
private:
    std::string username;
    std::string password;

public:
    User(std::string _username, std::string _password) : username(_username), password(_password) {}

    std::string get_username() const {
        return username;
    }

    bool check_password(std::string _password) const {
        return _password == password;
    }
};

class Login {
private:
    int attempts_left;

public:
    Login() : attempts_left(3) {}

    bool login(const User& user, std::string password) {
        if (user.check_password(password)) {
            attempts_left = 3;
            return true;
        } else {
            attempts_left--;
            return false;
        }
    }

    bool logout() {
        attempts_left = 3;
        return true;
    }

    int get_attempts_left() const {
        return attempts_left;
    }
};

class Billing {
private:
    int prev_reading;
    int curr_reading;
    double unit_cost = 5.50;
    double fixed_charge = 300.00;

public:
    Billing(int _prev_reading, int _curr_reading) : prev_reading(_prev_reading), curr_reading(_curr_reading) {}

    double calculate() const {
        if (curr_reading <= prev_reading) {
            std::cout << "Error: current reading must be greater than previous reading" << std::endl;
            return -1;
        }

        int units_consumed = curr_reading - prev_reading;
        double consumption_cost = units_consumed * unit_cost;
        double total_cost = consumption_cost + fixed_charge;
        double vat = total_cost * 0.05;

        return total_cost + vat;
    }
};

int main() {
    User user("caleb2", "password");
    Login login;

    for (int i = 0; i < 4; i++) {
        std::string password;
        std::cout << "Enter password: ";
        std::cin >> password;

        if (login.login(user, password)) {
            std::cout << "Login successful" << std::endl;

            int option;
            std::cout << "Enter option (0 for current bill, 1 for payment, 2 for meter readings): ";
            std::cin >> option;

            switch (option) {
                case 0:
                    std::cout << "Current bill: " << Billing(1000, 1200).calculate() << std::endl;
                    break;
                case 1:
                    // Payment process
                    break;
                case 2:
                    int prev_reading, curr_reading;
                    std::cout << "Enter previous reading: ";
                    std::cin >> prev_reading;
                    std::cout << "Enter current reading: ";
                    std::cin >> curr_reading;
                    std::cout << "Total cost: " << Billing(prev_reading, curr_reading).calculate() << std::endl;
                    break;
                default:
                    std::cout << "Invalid option" << std::endl;
                    break;
            }

            login.logout();
            break;
        } else {
            std::cout << "Login failed. Attempts left: " << login.get_attempts_left() << std::endl;

            if (login.get_attempts_left() == 0) {
                std::cout << "Logging out" << std::endl;
                break;
            }
        }
    }

    return 0;
}
