#include<iostream>
using namespace std;

#define MAX 10

struct Node{
    int val;
    Node* next;
};

class Queue{
    int q[MAX], front, rear;
public:
    Queue(){ front = rear = -1; }

    bool isEmpty(){ return front==-1; }

    void enqueue(int x){
        if(rear==MAX-1) return;
        if(front==-1) front=0;
        q[++rear]=x;
    }

    int dequeue(){
        if(isEmpty()) return -1;
        int x=q[front];
        if(front==rear) front=rear=-1;
        else front++;
        return x;
    }
};

class GraphBFS{
    Node* head[MAX];
    int visited[MAX], n;
    string Landmark[4] = {"Admin","Canteen","Sports","Workshop"};

public:
    GraphBFS(){
        for(int i=0;i<MAX;i++){
            head[i]=NULL;
            visited[i]=0;
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

            Node* temp = new Node;
            temp->val = d;
            temp->next = NULL;

            // insert at END
            if(head[s]==NULL){
                head[s]=temp;
            }else{
                Node* p=head[s];
                while(p->next!=NULL)
                    p=p->next;
                p->next=temp;
            }

            cout<<"More edges? (1/0): ";
            cin>>more;
        }
    }

    void displayList(){
        cout<<"\nAdjacency List:\n";
        for(int i=1;i<=n;i++){
            cout<<Landmark[i-1]<<" -> ";
            Node* temp=head[i];
            while(temp){
                cout<<Landmark[temp->val-1]<<" -> ";
                temp=temp->next;
            }
            cout<<"NULL\n";
        }
    }

    void BFS(int v){
        Queue q;
        q.enqueue(v);
        visited[v]=1;

        while(!q.isEmpty()){
            v=q.dequeue();
            cout<<Landmark[v-1]<<" -> ";

            Node* temp=head[v];
            while(temp){
                if(visited[temp->val]==0){
                    q.enqueue(temp->val);
                    visited[temp->val]=1;
                }
                temp=temp->next;
            }
        }
    }

    void reset(){
        for(int i=0;i<MAX;i++) visited[i]=0;
    }
};

int main(){
    GraphBFS g;
    int ch,start;

    do{
        cout<<"\n1.Create\n2.List\n3.BFS\n4.Exit\n";
        cout<<"Enter choice: ";
        cin>>ch;

        switch(ch){
            case 1: g.createGraph(); break;
            case 2: g.displayList(); break;
            case 3:
                cout<<"Start node: ";
                cin>>start;
                g.reset();
                g.BFS(start);
                break;
        }

    }while(ch!=4);

    return 0;
}