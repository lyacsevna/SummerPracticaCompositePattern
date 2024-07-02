#include "pattern.h"
#include "Windows.h"


int main() {

    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Contact* contact1 = new Contact("Софья", "9158881811", "remnyovasofia@example.com");
    Contact* contact2 = new Contact("Александр", "9108556996", "alex@example.com");


    ContactGroup* group1 = new ContactGroup("Семья");
    group1->addContact(contact1);
    group1->addContact(contact2);

    Contact* contact3 = new Contact("Евгений", "9876543322", "zhenya@example.com");
    Contact* contact4 = new Contact("Денис", "9108555556", "Denis@example.com");

    ContactGroup* group2 = new ContactGroup("Учеба");
    group2->addContact(contact3);
    group1->addContact(contact4);

    ContactGroup* allContacts = new ContactGroup(" ***  Все контакты  ***");
    allContacts->addContact(group1);
    allContacts->addContact(group2);

    allContacts->display();
    system("pause");

    // Очистка памяти
    delete allContacts;

    return 0;
}