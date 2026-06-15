#include <iostream>
#include <fstream>
#include <string>

/**
 * @file main.cpp
 * @brief CodeAlpha C++ Programming Internship - TASK 2: Login & Registration System
 * @details Manages user accounts by writing/reading credentials permanently to a database file.
 */

const std::string DB_FILE = "user_database.txt";

// Function Prototypes
void registerUser();
bool loginUser();
bool isUsernameTaken(const std::string& username);

int main() {
    int choice;

    std::cout << "=========================================\n";
    std::cout << "      CODEALPHA SECURITY GATEWAYWAY      \n";
    std::cout << "=========================================\n";

    while (true) {
        std::cout << "\n--- System Authentication ---\n";
        std::cout << "1. Register New Account\n";
        std::cout << "2. Account Login\n";
        std::cout << "3. Terminate Session\n";
        std::cout << "Enter system choice (1-3): ";
        std::cout.flush();
        std::cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                if (loginUser()) {
                    std::cout << "\n[ACCESS GRANTED] Welcome back to the dashboard!\n";
                } else {
                    std::cout << "\n[ACCESS DENIED] Invalid credentials provided.\n";
                }
                break;
            case 3:
                std::cout << "\nSession terminated securely. Goodbye!\n";
                return 0;
            default:
                std::cout << "\nError: Invalid selection. Try again.\n";
        }
    }
    return 0;
}

// 1. Check if a username already exists in the file database
bool isUsernameTaken(const std::string& username) {
    std::ifstream file(DB_FILE);
    if (!file.is_open()) return false; // File doesn't exist yet, username can't be taken

    std::string u, p;
    while (file >> u >> p) {
        if (u == username) {
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}

// 2. Feature: Handle New User Registration
void registerUser() {
    std::string username, password;

    std::cout << "\n--- Registration Portal ---\n";
    std::cout << "Enter a unique username (No spaces): ";
    std::cin >> username;

    // Validation step for duplicate registration records
    if (isUsernameTaken(username)) {
        std::cout << "\nRegistration Failed: Username '" << username << "' already exists!\n";
        return;
    }

    std::cout << "Enter a secure password (No spaces): ";
    std::cin >> password;

    // Append new credentials securely to file database
    std::ofstream file(DB_FILE, std::ios::app);
    if (file.is_open()) {
        file << username << " " << password << "\n";
        file.close();
        std::cout << "\nAccount successfully created! You can now log in.\n";
    } else {
        std::cout << "\nFatal Error: Unable to open database for writing.\n";
    }
}

// 3. Feature: Handle User Authentication Verification
bool loginUser() {
    std::string username, password;
    std::string fileUsername, filePassword;

    std::cout << "\n--- Login Portal ---\n";
    std::cout << "Enter Username: ";
    std::cin >> username;
    std::cout << "Enter Password: ";
    std::cin >> password;

    std::ifstream file(DB_FILE);
    if (!file.is_open()) {
        std::cout << "\nSystem Note: No user records found. Please register an account first.\n";
        return false;
    }

    // Scan flat-file lines for matching record pairs
    while (file >> fileUsername >> filePassword) {
        if (fileUsername == username && filePassword == password) {
            file.close();
            return true; // Match found
        }
    }

    file.close();
    return false; // No record matched
}