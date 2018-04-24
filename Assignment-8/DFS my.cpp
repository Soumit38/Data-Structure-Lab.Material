#include <bits/stdc++.h>

using namespace std;

vector<char>V[50];

void DFS(int node, char start){
    stack<char>S;
    bool visited[node+1];

    S.push(start);
    visited[start]=true;

    cout << "Depth first Search starting from vertex ";
    cout << start << " : " << endl;

    while(!S.empty()){
        char k=S.top();
        S.pop();

        cout << k << " ";

        for(int i=0; i<V[k].size(); i++){
            char p=V[k][i];
            if(!visited[p]){
                S.push(p);
                visited[p]=true;
            }
        }
    }
}

int main(){
    int node, edge;
    char starting;

    cout << "Enter node and edge: ";
    cin >> node >> edge;

    for(int i=0; i<edge; i++){
        char x, y;
        cout << "Enter two adjacent node of the edge: ";
        cin >> x >> y;
        V[x].push_back(y);
    }

    cout << "Enter starting node: ";
    cin >> starting;

    DFS(node, starting);

    return 0;
}
