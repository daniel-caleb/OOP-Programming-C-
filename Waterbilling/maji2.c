#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Authentication {
private:
    string username;
    string password;
    int loginAttempts;

public:
    Authentication() {
        username = "username";
        password = "password";
        loginAttempts = 0;
    }

    bool login(string enteredUsername, string enteredPassword) {
        if (enteredUsername == username && enteredPassword == password) {
            loginAttempts = 0;
            return true;
        }
        else {
            loginAttempts++;
            if (loginAttempts >= 3) {
                cout << "Too many login attempts. Try again later." << endl;
                exit(0);
            }
            else {
                cout << "Incorrect username or password. Please try again." << endl;
                return false;
            }
        }
    }

    void logout() {
        cout << "You have been logged out." << endl;
        exit(0);
    }
};

class User {
private:
    string name;
    int userID;
    string phoneNo;
    string email;
    double balance;

public:
    User() {
        name = "John Doe";
        userID = 12345;
        phoneNo = "123-456-7890";
        email = "johndoe@example.com";
        balance = 0.0;
    }

    double getCurrentBill() {
        // Generate bill
        double unitsConsumed, cost, fixedCharge, vat;
        double prevReading, currReading;
        MeterReading mr;

        cout << "Enter previous meter reading: ";
        cin >> prevReading;
        mr.setPrevReading(prevReading);

        cout << "Enter current meter reading: ";
        cin >> currReading;
        mr.setCurrReading(currReading);

        while (!mr.validateReading()) {
            cout << "Invalid meter readings. Please try again." << endl;
            cout << "Enter previous meter reading: ";
            cin >> prevReading;
            mr.setPrevReading(prevReading);

            cout << "Enter current meter reading: ";
            cin >> currReading;
            mr.setCurrReading(currReading);
        }

        unitsConsumed = mr.calculate();
        cost = unitsConsumed * 5.50;
        fixedCharge = 300.00;
        vat = 0.05 * (cost + fixedCharge);

        cout << fixed << setprecision(2);
        cout << "Units consumed: " << unitsConsumed << endl;
        cout << "Cost: " << cost << endl;
        cout << "Fixed charge: " << fixedCharge << endl;
        cout << "VAT: " << vat << endl;

        return balance + cost + fixedCharge + vat;
    }

    void makePayment() {
        double amount;

        cout << "Enter payment amount: ";
        cin >> amount;

        balance -= amount;
        cout << "Payment of " << amount << " made. New balance: " << balance << endl;
    }

    void enterReadings() {
        // Enter meter readings
        double prevReading, currReading;
        MeterReading mr;

        cout << "Enter previous meter reading: ";
        cin >> prevReading;
        mr.setPrevReading(prevReading);

        cout << "Enter current meter reading: ";
        cin >> currReading;
        mr.setCurrReading(currReading);

        while (!mr.validateReading()) {
            cout << "Invalid meter readings. Please try again." << endl;
            cout << "Enter previous meter reading: ";
            cin >> prevReading;
            mr.setPrevReading(prevReading);

            cout << "Enter current meter reading: ";
            cin >> currReading;
            mr.setCurrReading(currReading
