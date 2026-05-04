#include<iostream>
using namespace std;

#define SIZE 5

struct Record {
    long int phone;
    string person;
};

class Directory {
    Record linear[SIZE];
    Record quadratic[SIZE];
    Record temp;

public:
    Directory() {
        reset();
    }

    void reset() {
        for(int i=0;i<SIZE;i++) {
            linear[i].phone = -1;
            quadratic[i].phone = -1;
        }
    }

    void input() {
        cout << "\nEnter Phone: ";
        cin >> temp.phone;
        cout << "Enter Name: ";
        cin >> temp.person;
    }

    // 🔹 Linear Probing Insert
    void addLinear() {
        input();
        int index = temp.phone % SIZE;

        int i = 0;
        while(i < SIZE) {
            int pos = (index + i) % SIZE;

            if(linear[pos].phone == -1) {
                linear[pos] = temp;
                return;
            }
            i++;
        }

        cout << "\nTable Full!";
    }

    // 🔹 Display Linear
    void showLinear() {
        cout << "\n--- Linear Table ---\n";
        for(int i=0;i<SIZE;i++) {
            if(linear[i].phone != -1)
                cout << linear[i].phone << "\t" << linear[i].person << endl;
            else
                cout << "-\n";
        }
    }

    // 🔹 Search Linear
    void findLinear(long int key) {
        int index = key % SIZE;
        int count = 0;

        for(int i=0;i<SIZE;i++) {
            int pos = (index + i) % SIZE;
            count++;

            if(linear[pos].phone == key) {
                cout << "Found in " << count << " comparisons\n";
                return;
            }
        }

        cout << "Not Found\n";
    }

    // 🔹 Quadratic Probing Insert
    void addQuadratic() {
        input();
        int index = temp.phone % SIZE;

        int i = 0;
        while(i < SIZE) {
            int pos = (index + i*i) % SIZE;

            if(quadratic[pos].phone == -1) {
                quadratic[pos] = temp;
                return;
            }
            i++;
        }

        cout << "\nTable Full!";
    }

    // 🔹 Display Quadratic
    void showQuadratic() {
        cout << "\n--- Quadratic Table ---\n";
        for(int i=0;i<SIZE;i++) {
            if(quadratic[i].phone != -1)
                cout << quadratic[i].phone << "\t" << quadratic[i].person << endl;
            else
                cout << "-\n";
        }
    }

    // 🔹 Search Quadratic
    void findQuadratic(long int key) {
        int index = key % SIZE;
        int count = 0;

        for(int i=0;i<SIZE;i++) {
            int pos = (index + i*i) % SIZE;
            count++;

            if(quadratic[pos].phone == key) {
                cout << "Found in " << count << " comparisons\n";
                return;
            }
        }

        cout << "Not Found\n";
    }
};

int main() {
    Directory d;
    int choice, type;
    long int key;

    do {
        cout << "\n--- TELEPHONE DIRECTORY ---\n";
        cout << "1. Insert\n2. Display\n3. Search\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "1. Linear\n2. Quadratic\nChoice: ";
                cin >> type;
                if(type == 1)
                    d.addLinear();
                else
                    d.addQuadratic();
                break;

            case 2:
                cout << "1. Linear\n2. Quadratic\nChoice: ";
                cin >> type;
                if(type == 1)
                    d.showLinear();
                else
                    d.showQuadratic();
                break;

            case 3:
                cout << "Enter phone to search: ";
                cin >> key;
                cout << "1. Linear\n2. Quadratic\nChoice: ";
                cin >> type;
                if(type == 1)
                    d.findLinear(key);
                else
                    d.findQuadratic(key);
                break;

            case 4:
                cout << "Exit...\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while(choice != 4);

    return 0;
}