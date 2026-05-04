#include<iostream>
using namespace std;

#define SIZE 5

class HashTable {
    int phone[SIZE];
    string name[SIZE];

public:
    HashTable() {
        for(int i = 0; i < SIZE; i++) {
            phone[i] = -1;
            name[i] = "";
        }
    }

    int hashFunc(int key) {
        return key % SIZE;
    }

    void insert() {
        int key;
        string nm;

        cout << "Enter client No.:";
        cin >> key;
        cout << "Enter client name:";
        cin >> nm;

        int index = hashFunc(key);

        int i = 0;
        while(phone[(index + i) % SIZE] != -1 && i < SIZE) {
            i++;
        }

        if(i == SIZE) {
            cout << "Hash Table is Full\n";
            return;
        }

        phone[(index + i) % SIZE] = key;
        name[(index + i) % SIZE] = nm;
    }

    void display() {
        cout << "\nTelephone No.\tName\n";
        for(int i = 0; i < SIZE; i++) {
            if(phone[i] != -1)
                cout << phone[i] << "\t\t" << name[i] << endl;
            else
                cout << "-1\n";
        }
    }

    void search() {
        int key;
        cout << "Enter telephone number to search:";
        cin >> key;

        int index = hashFunc(key);

        int i = 0;
        while(i < SIZE && phone[(index + i) % SIZE] != key) {
            i++;
        }

        if(i == SIZE) {
            cout << "Record not found\n";
        } else {
            cout << "Found: " << name[(index + i) % SIZE] << endl;
        }
    }

    void update() {
        int key;
        cout << "Enter telephone number to update:";
        cin >> key;

        int index = hashFunc(key);

        int i = 0;
        while(i < SIZE && phone[(index + i) % SIZE] != key) {
            i++;
        }

        if(i == SIZE) {
            cout << "Record not found\n";
        } else {
            cout << "Enter new name:";
            cin >> name[(index + i) % SIZE];
        }
    }

    void deleteRecord() {
        int key;
        cout << "Enter telephone number to delete:";
        cin >> key;

        int index = hashFunc(key);

        int i = 0;
        while(i < SIZE && phone[(index + i) % SIZE] != key) {
            i++;
        }

        if(i == SIZE) {
            cout << "Record not found\n";
        } else {
            phone[(index + i) % SIZE] = -1;
            name[(index + i) % SIZE] = "";
            cout << "Record deleted\n";
        }
    }
};

int main() {
    HashTable h;
    int choice;

    do {
        cout << "\n******** HASH TABLE - LINEAR PROBING ********\n";
        cout << "1.INSERT RECORD\n";
        cout << "2.DISPLAY ALL RECORD\n";
        cout << "3.SEARCH RECORD\n";
        cout << "4.UPDATE RECORD\n";
        cout << "5.DELETE RECORD\n";
        cout << "6.EXIT\n";

        cout << "What operations:";
        cin >> choice;

        switch(choice) {
            case 1: h.insert(); break;
            case 2: h.display(); break;
            case 3: h.search(); break;
            case 4: h.update(); break;
            case 5: h.deleteRecord(); break;
            case 6: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice\n";
        }

    } while(choice != 6);

    return 0;
}