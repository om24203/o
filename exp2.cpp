#include<iostream>
#include<cstring>
using namespace std;

#define MAX 20

// Node structure
struct Node {
    Node *left;
    char data;
    Node *right;
};

// Stack class
class Stack {
    Node* arr[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(Node* x) {
        if (top == MAX - 1)
            cout << "\nStack Overflow";
        else
            arr[++top] = x;
    }

    Node* pop() {
        if (top == -1) {
            cout << "\nStack Underflow";
            return NULL;
        }
        return arr[top--];
    }

    bool isEmpty() {
        return top == -1;
    }
};

// Expression Tree class
class ExpTree {
    char prefix[20];
    Node* root;

public:
    ExpTree() {
        root = NULL;
    }

    void readExp() {
        cout << "\nEnter Prefix Expression: ";
        cin >> prefix;
    }

    void showExp() {
        cout << "\nEntered Expression: " << prefix;
    }

    bool isOperator(char ch) {
        return (ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^');
    }

    bool isOperand(char ch) {
        return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
    }

    void buildTree() {
        Stack st;
        Node *temp;

        for (int i = strlen(prefix) - 1; i >= 0; i--) {
            temp = new Node;
            temp->data = prefix[i];
            temp->left = temp->right = NULL;

            if (isOperand(prefix[i])) {
                st.push(temp);
            } else {
                temp->left = st.pop();
                temp->right = st.pop();
                st.push(temp);
            }
        }

        root = st.pop();
        cout << "\nTree Created Successfully!";
    }

    void inorder(Node* t) {
        if (t) {
            inorder(t->left);
            cout << t->data << " ";
            inorder(t->right);
        }
    }

    Node* getRoot() {
        return root;
    }

    void postorderNonRecursive(Node* root) {
        if (root == NULL) return;

        Stack s1, s2;
        Node* temp;

        s1.push(root);

        while (!s1.isEmpty()) {
            temp = s1.pop();
            s2.push(temp);

            if (temp->left)
                s1.push(temp->left);
            if (temp->right)
                s1.push(temp->right);
        }

        cout << "\nPostorder: ";
        while (!s2.isEmpty()) {
            cout << s2.pop()->data << " ";
        }
    }
};

// Main function
int main() {
    ExpTree obj;
    int choice;

    do {
        cout << "\n\n===== Expression Tree Menu =====";
        cout << "\n1. Enter Expression";
        cout << "\n2. Show Expression";
        cout << "\n3. Build Tree";
        cout << "\n4. Inorder Traversal";
        cout << "\n5. Postorder (Non-Recursive)";
        cout << "\n6. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: obj.readExp(); break;
            case 2: obj.showExp(); break;
            case 3: obj.buildTree(); break;
            case 4:
                cout << "\nInorder: ";
                obj.inorder(obj.getRoot());
                break;
            case 5:
                obj.postorderNonRecursive(obj.getRoot());
                break;
            case 6:
                cout << "\nProgram Ended!";
                break;
            default:
                cout << "\nInvalid Choice!";
        }
    } while (choice != 6);

    return 0;
}