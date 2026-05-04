#include<iostream>
#include<cstring>
#include<limits>
using namespace std;

typedef struct keyword{
    char key[20];
    char meaning[100];
}WORD;

typedef struct node {
    struct node *LC;
    WORD data;
    int height;
    struct node *RC;
}NODE;

class AVL {
    NODE *root;

public:
    AVL() {
        root = NULL;
    }

    NODE* getroot() {
        return root;
    }

    int height(NODE *T) {
        if(T == NULL) return 0;
        int lh = height(T->LC);
        int rh = height(T->RC);
        return (lh > rh ? lh : rh) + 1;
    }

    int difference(NODE* T) {
        if(T == NULL) return 0;
        return height(T->LC) - height(T->RC);
    }

    NODE* rr_rotate(NODE* P) {
        NODE* A = P->RC;
        P->RC = A->LC;
        A->LC = P;
        cout<<"\nRR Rotation";
        return A;
    }

    NODE* ll_rotate(NODE* P) {
        NODE* A = P->LC;
        P->LC = A->RC;
        A->RC = P;
        cout<<"\nLL Rotation";
        return A;
    }

    NODE* lr_rotate(NODE* P) {
        P->LC = rr_rotate(P->LC);
        cout<<"\nLR Rotation";
        return ll_rotate(P);
    }

    NODE* rl_rotate(NODE* P) {
        P->RC = ll_rotate(P->RC);
        cout<<"\nRL Rotation";
        return rr_rotate(P);
    }

    NODE* balance(NODE* T) {
        int bf = difference(T);

        if(bf > 1) {
            if(difference(T->LC) > 0)
                T = ll_rotate(T);
            else
                T = lr_rotate(T);
        }
        else if(bf < -1) {
            if(difference(T->RC) > 0)
                T = rl_rotate(T);
            else
                T = rr_rotate(T);
        }
        return T;
    }

    NODE* insert(NODE* T, WORD w) {
        if(T == NULL) {
            T = new NODE;
            T->data = w;
            T->LC = T->RC = NULL;
            root = T;
            return T;
        }

        if(strcmp(w.key, T->data.key) < 0) {
            T->LC = insert(T->LC, w);
            T = balance(T);
        }
        else if(strcmp(w.key, T->data.key) > 0) {
            T->RC = insert(T->RC, w);
            T = balance(T);
        }

        root = T;
        return T;
    }

    void displayIN(NODE *T) {
        if(T) {
            displayIN(T->LC);
            cout<<T->data.key<<" : "<<T->data.meaning<<endl;
            displayIN(T->RC);
        }
    }
};

int main() {
    AVL B;
    int choice;
    WORD w;

    while(true) {
        cout<<"\n***** AVL Dictionary *****";
        cout<<"\n1. Insert Word";
        cout<<"\n2. Display Dictionary";
        cout<<"\n3. Exit";
        cout<<"\nEnter choice: ";

        cin >> choice;

        // 🔥 FIX: handle invalid input
        if(cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"Invalid choice!";
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch(choice) {
            case 1:
                cout<<"Enter keyword: ";
                cin.getline(w.key, 20);

                cout<<"Enter meaning: ";
                cin.getline(w.meaning, 100);

                B.insert(B.getroot(), w);
                break;

            case 2:
                B.displayIN(B.getroot());
                break;

            case 3:
                cout<<"\nProgram Exits!!";
                return 0;

            default:
                cout<<"Invalid choice!";
        }
    }
}