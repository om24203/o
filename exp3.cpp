#include<iostream>
using namespace std;

#define MAX 10

// Node structure
struct Node{
    int val;
    Node* next;
};

// Queue for BFS
class Queue{
    int Q[MAX], front, rear;
public:
    Queue(){ front = rear = -1; }

    bool isEmpty(){ return front == -1; }

    void enqueue(int x){
        if(rear == MAX-1) return;
        if(front == -1) front = 0;
        Q[++rear] = x;
    }

    int dequeue(){
        if(isEmpty()) return -1;
        int x = Q[front];
        if(front == rear) front = rear = -1;
        else front++;
        return x;
    }
};

class GraphLandmarks{
    int GAM[MAX][MAX];     // adjacency matrix
    int VISITED[MAX];
    Node* HeaderGAL[MAX];  // adjacency list
    int n;

    string Landmark[4] = {"Admin","Canteen","Sports","Workshop"};

public:
    GraphLandmarks(){
        for(int i=0;i<MAX;i++){
            VISITED[i]=0;
            HeaderGAL[i]=NULL;
            for(int j=0;j<MAX;j++)
                GAM[i][j]=0;
        }
    }

    void createGraph(){
        int s,d;
        bool more = true;

        cout<<"Enter number of nodes: ";
        cin>>n;

        while(more){
            cout<<"Enter source: ";
            cin>>s;
            cout<<"Enter destination: ";
            cin>>d;

            // Matrix
            GAM[s][d] = 1;

            // List
            Node* temp = new Node;
            temp->val = d;
            temp->next = HeaderGAL[s];
            HeaderGAL[s] = temp;

            cout<<"More edges? (1/0): ";
            cin>>more;
        }
    }

    void displayGAM(){
        cout<<"\nAdjacency Matrix:\n";
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cout<<GAM[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    void displayGAL(){
        cout<<"\nAdjacency List:\n";
        for(int i=1;i<=n;i++){
            cout<<Landmark[i-1]<<" -> ";
            Node* temp = HeaderGAL[i];
            while(temp){
                cout<<Landmark[temp->val-1]<<" -> ";
                temp=temp->next;
            }
            cout<<"NULL\n";
        }
    }

    void resetVisited(){
        for(int i=0;i<MAX;i++)
            VISITED[i]=0;
    }

    // DFS
    void DFS(int v){
        VISITED[v]=1;
        cout<<Landmark[v-1]<<" -> ";

        for(int i=1;i<=n;i++){
            if(GAM[v][i]==1 && VISITED[i]==0)
                DFS(i);
        }
    }

    // BFS
    void BFS(int v){
        Queue q;
        q.enqueue(v);
        VISITED[v]=1;

        while(!q.isEmpty()){
            v = q.dequeue();
            cout<<Landmark[v-1]<<" -> ";

            Node* temp = HeaderGAL[v];
            while(temp){
                if(VISITED[temp->val]==0){
                    q.enqueue(temp->val);
                    VISITED[temp->val]=1;
                }
                temp=temp->next;
            }
        }
    }
};

int main(){
    GraphLandmarks g;
    int ch, start;

    do{
        cout<<"\n1.Create\n2.Matrix\n3.List\n4.DFS\n5.BFS\n6.Exit\n";
        cout<<"Enter choice: ";
        cin>>ch;

        switch(ch){
            case 1: g.createGraph(); break;
            case 2: g.displayGAM(); break;
            case 3: g.displayGAL(); break;
            case 4:
                cout<<"Start node: ";
                cin>>start;
                g.resetVisited();
                g.DFS(start);
                break;
            case 5:
                cout<<"Start node: ";
                cin>>start;
                g.resetVisited();
                g.BFS(start);
                break;
        }

    }while(ch!=6);

    return 0;
}