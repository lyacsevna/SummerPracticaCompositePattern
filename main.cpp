#include "pattern.h"
#include "Windows.h"

#include<String>

using namespace std;


void menu() {

    cout << "             *** Меню ***" << endl << endl;
    cout << "1. Создать новый контакт;" << endl;
    cout << "2. Просмотреть список контактов;" << endl;
    cout << "3. Выход;" << endl << endl;
    cout << "Выберите пункт меню для дальнейшей работы: " << endl;
}


int main() {

    setlocale(0, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    ContactGroup* allContacts = new ContactGroup(" ***  Все контакты  ***");
    ContactGroup* groupFamily = new ContactGroup("Семья");
    ContactGroup* groupStudy = new ContactGroup("Учеба");
    ContactGroup* groupWork = new ContactGroup("Работа");
    ContactGroup* groupFriends = new ContactGroup("Друзья");

    int num;

    menu();

    cin >> num;

    while (num) {

        switch (num) {

        case 1:

            system("cls");
            while (true)
            {
                system("cls");

                cout << "                    *** Новый контакт ***" << endl << endl;
                string name, phone, email;
                cout << "Введите имя контакта: " << endl;
                cin >> name;
                cout << "Введите номер телефона: " << endl;
                cin >> phone;
                cout << "Введите адрес электронной почты: " << endl;
                cin >> email;
                Contact* newContact = new Contact(name, phone, email);

                int group;
                char choise;

                cout << "В какую группу добавить контакт? (Выберите цифру) " << endl;
                cout << "1 - семья,  2- учеба, 3 - работа, 4 - друзья, 5 - не отсортировывать" << endl;

                cin >> group;

                if (group == 1) {
                    allContacts->addContact(groupFamily);
                    groupFamily->addContact(newContact);
                }
                else if (group == 2) {
                    allContacts->addContact(groupStudy);
                    groupStudy->addContact(newContact);
                }
                else if (group == 3) {
                    allContacts->addContact(groupWork);
                    groupWork->addContact(newContact);

                }
                else if (group == 4) {
                    allContacts->addContact(groupFriends);
                    groupFriends->addContact(newContact);

                }
                else if (group == 5) {
                    allContacts->addContact(newContact);
                }
                else {
                    cout << "ERROR! Неверный выбор!";
                }
                while (true)
                {
                    cout << "Продолжить ввод? Введите д - если да, н - если нет" << endl;
                    cin >> choise;
                    if (choise == 'д' || choise == 'н') break;
                }
                if (choise == 'н') break;
            }
            system("cls");
            menu();
            cin >> num;

        case 2:

            system("cls");
            allContacts->display();

            system("pause");
            system("cls");
            menu();
            cin >> num;
            break;

        case 3:
            return 0;
        }

    }
}