#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Windows.h"


using namespace std;

class Component {
public:
    virtual void display() = 0;
    virtual ~Component() {}
    void setConsoleTextColor(int color) {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, color);
    }
};

// Контакт
class Contact : public Component {

private:

    string name;
    string phone;
    string email;

public:
    Contact(const string& name, const string& phone, const string& email) : name(name), phone(phone), email(email) {
    }


    void display() override {
        setConsoleTextColor(FOREGROUND_INTENSITY);
        cout << "- Контакт: " << name << " (" << phone << ", " << email << ")" << endl;
    }
};

// Группа контактов
class ContactGroup : public Component {
private:
    string name;
    vector<Component*> contacts;

public:
    ContactGroup(const string& name) : name(name) {
    }

    void addContact(Component* contact) {
        contacts.push_back(contact);
    }

    void display() override {
        setConsoleTextColor(FOREGROUND_GREEN);
        cout << endl << "               Группа контактов:" << name << endl << endl;

        for (Component* contact : contacts) {
            contact->display();
        }
    }

    ~ContactGroup() {
        for (Component* contact : contacts) {
            delete contact;
        }
    }
};