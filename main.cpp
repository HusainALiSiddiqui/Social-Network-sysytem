

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <vector>

#include "Person.h"

using namespace std;

void registerUser() {
    string name, placeOfBirth, password;
    int age;
    int numFriends;

    cin.ignore();
    cout << "Enter your name: ";
    getline(cin, name);

    cout << "Enter your age: ";
    cin >> age;

    cin.ignore();
    cout << "Enter your place of birth: ";
    getline(cin, placeOfBirth);

    cout << "Enter the number of friends you have: ";
    cin >> numFriends;

    cin.ignore();
    vector<string> friends;
    for (int i = 0; i < numFriends; i++) {
        string friendName;
        cout << "Enter friend's name " << i + 1 << ": ";
        getline(cin, friendName);
        friends.push_back(friendName);
    }

    cout << "Create a password: ";
    getline(cin, password);

    Person newUser(name, age, placeOfBirth, password, friends);

    ofstream outFile("users.txt", ios::app);
    if (outFile.is_open()) {
        outFile << newUser.getName() << endl;
        outFile << newUser.getAge() << endl;
        outFile << newUser.getPlaceOfBirth() << endl;
        outFile << newUser.getPassword() << endl;
        outFile << newUser.getFriends().size() << endl;

        const vector<string>& userFriends = newUser.getFriends();
        for (size_t i = 0; i < userFriends.size(); ++i) {
            outFile << userFriends[i] << endl;
        }
        outFile.close();

        cout << "User successfully registered!" << endl;
    } else {
        cout << "Unable to open the file, try again!" << endl;
    }
}

vector<Person> readFromFile() {
    vector<Person> users;

    ifstream inFile("users.txt");
    if (inFile.is_open()) {
        string name, placeOfBirth, password;
        int age, numFriends;

        while (getline(inFile, name)) {
            inFile >> age;
            inFile.ignore();
            getline(inFile, placeOfBirth);
            getline(inFile, password);
            inFile >> numFriends;
            inFile.ignore();

            vector<string> friends;
            for (int i = 0; i < numFriends; i++) {
                string friendName;
                getline(inFile, friendName);
                friends.push_back(friendName);
            }

            Person user(name, age, placeOfBirth, password, friends);
            users.push_back(user);
        }

        inFile.close();
    }

    return users;
}

void login() {
    string name;
    string password;

    cout << "Enter name: ";
    getline(cin, name);

    cout << "Enter password: ";
    getline(cin, password);

    vector<Person> users = readFromFile();
    bool authenticated = false;
    size_t authenticatedUserIndex = 0;

    for (size_t i = 0; i < users.size(); ++i) {
        const Person& user = users[i];
        if (user.getName() == name && user.authenticate(password)) {
            authenticated = true;
            authenticatedUserIndex = i;
            user.displayInfo();
            break;
        }
    }

    if (!authenticated) {
        cout << "Authentication failed. Invalid name or password." << endl;
    } else {
        ofstream outFile("user.txt");
        if (outFile.is_open()) {
            const Person& user = users[authenticatedUserIndex];
            outFile << "Welcome " << user.getName() << "!" << endl;
            outFile << "Your age is " << user.getAge() << "." << endl;
            outFile << "You were born in " << user.getPlaceOfBirth() << "." << endl;
            outFile << "You have " << user.getFriends().size() << " friends and they are:" << endl;
            
            const vector<string>& userFriends = user.getFriends();
             for (size_t i = 0; i < userFriends.size(); ++i) {
                outFile << "- " << userFriends[i] << endl;
            }

            outFile.close();
            cout << "User information saved to user.txt" << endl;
        } else {
            cout << "Unable to open the file to save user information." << endl;
        }
    }
}

int main(void) {
    int option;
    do {
        cout << "Select an option:" << endl;
        cout << "1. Login" << endl;
        cout << "2. Register" << endl;
        cout << "3. Exit" << endl;
        cout << "Option: ";
        cin >> option;
        cin.ignore();

        switch (option) {
            case 1:
                login();
                break;
            case 2:
                registerUser();
                break;
            case 3:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
                break;
        }
    } while (option != 3);

    return 0;
}

