#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstring>
using namespace std;

class Employee {
    int id;
    char name[20];
    char post[20];
    float salary;

public:
    void accept() {
        cout << "\nEnter ID: ";
        cin >> id;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Designation: ";
        cin >> post;
        cout << "Enter Salary: ";
        cin >> salary;
    }

    void display() {
        cout << "\n" << id << setw(15) << name << setw(15) << post << setw(10) << salary;
    }

    int getID() { return id; }
    char* getName() { return name; }
};

class File {
public:

    void add() {
        Employee e;
        ofstream fout("emp.dat", ios::binary | ios::app);
        e.accept();
        fout.write((char*)&e, sizeof(e));
        fout.close();
        cout << "\nRecord Added!";
    }

    void display() {
        Employee e;
        ifstream fin("emp.dat", ios::binary);

        while (fin.read((char*)&e, sizeof(e))) {
            e.display();
        }
        fin.close();
    }

    void search() {
        Employee e;
        char name[20];
        int flag = 0;

        cout << "\nEnter name to search: ";
        cin >> name;

        ifstream fin("emp.dat", ios::binary);

        while (fin.read((char*)&e, sizeof(e))) {
            if (strcmp(e.getName(), name) == 0) {
                cout << "\nRecord Found:";
                e.display();
                flag = 1;
                break;
            }
        }

        if (!flag)
            cout << "\nRecord Not Found";

        fin.close();
    }

    void update() {
        Employee e;
        char name[20];
        int flag = 0;

        cout << "\nEnter name to update: ";
        cin >> name;

        fstream file("emp.dat", ios::binary | ios::in | ios::out);

        while (file.read((char*)&e, sizeof(e))) {
            if (strcmp(e.getName(), name) == 0) {
                cout << "\nOld Record:";
                e.display();

                cout << "\nEnter New Data:";
                e.accept();

                int pos = -1 * sizeof(e);
                file.seekp(pos, ios::cur);
                file.write((char*)&e, sizeof(e));

                cout << "\nRecord Updated!";
                flag = 1;
                break;
            }
        }

        if (!flag)
            cout << "\nRecord Not Found";

        file.close();
    }

    void removeRecord() {
        Employee e;
        char name[20];
        int flag = 0;

        cout << "\nEnter name to delete: ";
        cin >> name;

        ifstream fin("emp.dat", ios::binary);
        ofstream fout("temp.dat", ios::binary);

        while (fin.read((char*)&e, sizeof(e))) {
            if (strcmp(e.getName(), name) != 0) {
                fout.write((char*)&e, sizeof(e));
            } else {
                flag = 1;
            }
        }

        fin.close();
        fout.close();

        remove("emp.dat");
        rename("temp.dat", "emp.dat");

        if (flag)
            cout << "\nRecord Deleted!";
        else
            cout << "\nRecord Not Found";
    }
};

int main() {
    File f;
    int ch;

    do {
        cout << "\n\n--- Employee File System ---";
        cout << "\n1. Add Record";
        cout << "\n2. Display Records";
        cout << "\n3. Search Record";
        cout << "\n4. Update Record";
        cout << "\n5. Delete Record";
        cout << "\n6. Exit";
        cout << "\nEnter choice: ";
        cin >> ch;

        switch (ch) {
            case 1: f.add(); break;
            case 2: f.display(); break;
            case 3: f.search(); break;
            case 4: f.update(); break;
            case 5: f.removeRecord(); break;
        }

    } while (ch != 6);

    return 0;
}