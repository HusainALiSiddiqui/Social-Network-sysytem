

#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <vector>

class Person {
private:
    std::string name;
    int age;
    std::string placeOfBirth;
    std::string password;
    std::vector<std::string> friends;

public:
    Person(std::string n, int a, std::string pla, std::string p, std::vector<std::string> f);

    void setName(std::string n);
    void setAge(int a);
    void setPlaceOfBirth(std::string pla);
    void setPassword(std::string p);
    void setFriends(std::vector<std::string> f);

    std::string getName()const;
    int getAge()const;

    std::string getPlaceOfBirth() const;
    std::string getPassword() const;
    std::vector<std::string> getFriends() const;

    bool authenticate(const std::string& password) const;
    void displayInfo() const;
};

#endif

