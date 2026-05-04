#include<iostream>
using namespace std;

struct Node {
    string word, meaning;
    Node *left, *right;
};

class BST {
    Node *root;

public:
    BST() {
        root = NULL;
    }

    Node* insert(Node* root, string w, string m) {
        if(root == NULL) {
            Node* temp = new Node;
            temp->word = w;
            temp->meaning = m;
            temp->left = temp->right = NULL;
            return temp;
        }

        if(w < root->word)
            root->left = insert(root->left, w, m);
        else if(w > root->word)
            root->right = insert(root->right, w, m);
        else
            cout << "\nDuplicate node!!";

        return root;
    }

    void addNode(string w, string m) {
        root = insert(root, w, m);
    }

    void inorder(Node* root) {
        if(root) {
            inorder(root->left);
            cout << "[" << root->word << "|" << root->meaning << "]  ";
            inorder(root->right);
        }
    }

    void displayAsc() {
        if(root == NULL)
            cout << "\nTree Empty!";
        else
            inorder(root);
    }

    void displayDesc(Node* root) {
        if(root) {
            displayDesc(root->right);
            cout << "[" << root->word << "|" << root->meaning << "]  ";
            displayDesc(root->left);
        }
    }

    void searchNode(string key) {
        Node* temp = root;
        int count = 0;

        while(temp) {
            count++;
            if(key == temp->word) {
                cout << "\nWord found!";
                cout << "\nThe number of comparisons are::" << count;
                return;
            }
            else if(key < temp->word)
                temp = temp->left;
            else
                temp = temp->right;
        }
        cout << "\nNode not found";
    }

    void updateNode(string key) {
        Node* temp = root;
        while(temp) {
            if(key == temp->word) {
                cout << "\nEnter new meaning::";
                cin >> temp->meaning;
                return;
            }
            else if(key < temp->word)
                temp = temp->left;
            else
                temp = temp->right;
        }
        cout << "\nWord not found!";
    }

    Node* findMin(Node* root) {
        while(root->left)
            root = root->left;
        return root;
    }

    Node* deleteNode(Node* root, string key) {
        if(root == NULL) return root;

        if(key < root->word)
            root->left = deleteNode(root->left, key);
        else if(key > root->word)
            root->right = deleteNode(root->right, key);
        else {
            cout << "\n" << root->word << " : " << root->meaning << " will be deleted!";

            // no child
            if(root->left == NULL && root->right == NULL) {
                delete root;
                return NULL;
            }
            // one child
            else if(root->left == NULL) {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if(root->right == NULL) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            // two children
            Node* temp = findMin(root->right);
            root->word = temp->word;
            root->meaning = temp->meaning;
            root->right = deleteNode(root->right, temp->word);
        }
        return root;
    }

    void deleteKey(string key) {
        root = deleteNode(root, key);
    }

    void deleteTree(Node* root) {
        if(root) {
            deleteTree(root->left);
            deleteTree(root->right);
            delete root;
        }
    }

    Node* getRoot() {
        return root;
    }

    void clearTree() {
        deleteTree(root);
        root = NULL;
    }
};

int main() {
    BST P;
    int choice;
    string word, meaning;

    while(choice != 7) {
        cout << "\n****************BST Operations**************";
        cout << "\n1. Add Node";
        cout << "\n2. Display BST";
        cout << "\n3. Delete Node";
        cout << "\n4. Update Node";
        cout << "\n5. Search Node";
        cout << "\n6. Delete Tree";
        cout << "\n7. Exit";

        cout << "\n\nWhat operation you want::";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "\nEnter word::";
                cin >> word;
                cout << "\nEnter meaning::";
                cin >> meaning;
                P.addNode(word, meaning);
                break;

            case 2:
                cout << "\nPrint words in ascending:\n";
                P.displayAsc();

                cout << "\n\nPrint words in descending:\n";
                P.displayDesc(P.getRoot());
                break;

            case 3:
                cout << "\nEnter word to be deleted::";
                cin >> word;
                P.deleteKey(word);
                break;

            case 4:
                cout << "\nEnter word::";
                cin >> word;
                P.updateNode(word);
                break;

            case 5:
                cout << "\nEnter word to be searched::";
                cin >> word;
                P.searchNode(word);
                break;

            case 6:
                P.clearTree();
                cout << "\nTree Deleted!";
                break;

            case 7:
                cout << "\nThanks for using application!!";
                break;

            default:
                cout << "\nWrong Choice!!";
        }
    }

    return 0;
}