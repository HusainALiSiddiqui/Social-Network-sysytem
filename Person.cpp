

#include <iostream>
#include <string>
#include <vector>

#include "Person.h"

using namespace std;

Person::Person(string n, int a, string pla, string p, vector<string> f) {
    name = n;
    age = a;
    placeOfBirth = pla;
    password = p;
    friends = f;
}

void Person::setName(string n) {
    name = n;
}

void Person::setAge(int a) {
    age = a;
}

void Person::setPlaceOfBirth(string pla) {
    placeOfBirth = pla;
}

void Person::setPassword(string p) {
    password = p;
}

void Person::setFriends(vector<string> f) {
    friends = f;
}

string Person::getName()const {
    return name;
}

int Person::getAge()const {
    return age;
}

string Person::getPlaceOfBirth() const {
    return placeOfBirth;
}

string Person::getPassword() const {
    return password;
}

vector<string> Person::getFriends() const {
    return friends;
}

bool Person::authenticate(const string& password) const {
    return password == this->password;
}

void Person::displayInfo() const {
    cout << "Welcome: " << name << endl;
    cout << "Your age is: " << age << endl;
    cout << "You were born in: " << placeOfBirth << endl;

    if (friends.empty()) {
        cout << "Friends: None" << endl;
    } else {
        cout << "You have " << friends.size() << " friends and they are:" << endl;
        for (size_t i = 0; i < friends.size(); ++i) {
            cout << "- " << friends[i] << endl;
        }
    }
}

