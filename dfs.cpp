#include<iostream>
using namespace std;

#define MAX 10

class GraphDFS{
    int G[MAX][MAX], visited[MAX], n;
    string Landmark[4] = {"Admin","Canteen","Sports","Workshop"};

public:
    GraphDFS(){
        for(int i=0;i<MAX;i++){
            visited[i]=0;
            for(int j=0;j<MAX;j++)
                G[i][j]=0;
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

            G[s][d]=1;

            cout<<"More edges? (1/0): ";
            cin>>more;
        }
    }

    void displayMatrix(){
        cout<<"\nAdjacency Matrix:\n";
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)
                cout<<G[i][j]<<" ";
            cout<<endl;
        }
    }

    void DFS(int v){
        visited[v]=1;
        cout<<Landmark[v-1]<<" -> ";

        for(int i=1;i<=n;i++){
            if(G[v][i]==1 && visited[i]==0)
                DFS(i);
        }
    }

    void reset(){
        for(int i=0;i<MAX;i++) visited[i]=0;
    }
};

int main(){
    GraphDFS g;
    int ch,start;

    do{
        cout<<"\n1.Create\n2.Matrix\n3.DFS\n4.Exit\n";
        cout<<"Enter choice: ";
        cin>>ch;

        switch(ch){
            case 1: g.createGraph(); break;
            case 2: g.displayMatrix(); break;
            case 3:
                cout<<"Start node: ";
                cin>>start;
                g.reset();
                g.DFS(start);
                break;
        }

    }while(ch!=4);

    return 0;
}