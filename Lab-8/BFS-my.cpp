        // For integer //
#include <bits/stdc++.h>

using namespace std;

vector<int>V[50];
int level[50];
int parent[50];

void BFS(int src){
    queue<int>Q;
    int visited[50]={0};

    Q.push(src);
    visited[src]=1;
    level[src]=0;
    while(!Q.empty()){
        int u=Q.front();
        for(int i=0; i<V[u].size(); i++){
            int v=V[u][i];
            if(!visited[v]){
                level[v]=level[u]+1;
                parent[v]=u;
                visited[v]=1;
                Q.push(v);
            }
        }
        Q.pop();
    }
}

int main(){
    int node, edge, source, destination;

    cout << "Enter number of node and edge : ";
    cin >> node >> edge;

    for(int i=0; i<edge; i++){
        int a, b;
        cout << "Enter two node which is in the side of the edge: ";
        cin >> a >> b;
        V[a].push_back(b);
        V[b].push_back(a);
    }

    cout << "Enter source and destination : ";
    cin >> source >> destination;

    BFS(source);

    //cout << "Level : " << level[3] << endl;

    while(destination!=source){
        cout << destination << " ";
        destination=parent[destination];
    }
    cout << destination << endl;

    return 0;
}
