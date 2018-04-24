#include <bits/stdc++.h>

using namespace std;

class myqueue
{
    int ara[1000];
    int frnt, rear;
public:
    myqueue()
    {
        frnt=0,rear=0;
    }
    void pushh(int n)
    {
        ara[rear++]=n;
    }
    void popp()
    {
        frnt++;
    }
    int frontt()
    {
        return ara[frnt];
    }
    bool emptyy()
    {
        if(frnt>rear) return 1;
        else return 0;
    }
};

bool graph[500][500];
int par[500];
bool visited[500];
int level[500];
int node,edge,data;

int bfs(int src, int dst)
{
    myqueue Q;
    memset(par,-1,sizeof par);
    visited[src]=1;
    level[src]=0;
    Q.pushh(src);
    while(!Q.emptyy())
    {
       int u=Q.frontt();
        Q.popp();
        if(u==dst) return level[dst];
        for(int i=1;i<=node;i++)
        {
            if(graph[u][i] && !visited[i])
            {
                Q.pushh(i);
                visited[i]=1;
                par[i]=u;
                level[i]=level[u]+1;
            }
        }
    }
    return level[dst];
}

int path[500];

int main()
{

    cout<<"Input Number of Node:\n";
    cin>>node;
//    char s,d;
int s,d;
    for(int i=1;i<=node;i++)
    {
        cout<<"Input root :\n";
        cin>>s;
        cout<<"Number of adjacent:\n";
        cin>>edge;
        for(int j=1;j<=edge;j++)
        {
            cout<<"Enter adjacent element: ";
            cin>>data;
//                cin>>d;
            graph[s][data]=1;
//            graph[s-'A'+1][d-'A'+1]=1;
        }
    }

    int src,dst;
    cout << "Enter source and destination: ";
    cin>>src>>dst;
    cout<<"Distance from source to destination is : ";
    cout<<bfs(src,dst)<<endl;
    cout<<"The shortest path is : ";
    int ab=dst,k=0;
    path[k]=dst;
    k++;
    while(par[dst]!=-1)
    {
        path[k++]=par[dst];
        dst=par[dst];
    }

    for(int i=k-1;i>=0;i--)
    cout<<path[i]<<" ";
    return 0;
}

