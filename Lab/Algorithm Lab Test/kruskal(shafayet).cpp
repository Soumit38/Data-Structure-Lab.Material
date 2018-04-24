/*

here adjacent list is used


*/



#include<iostreatm>
#include<vector>

using namespace std;

#define MAX 1000;
vector<int>edges[MAX];
vector<int>cost[MAX];

int node,edg,value;
int pr[MAX];

void create_graph();
int find_par(int r);
int mst(int n);
void sort_grpah();

int main()
{
    create_graph();

}

void create_graph()
{

    cout<<"Enter number of nodes: ";
    cin>>node;
    cout<<"Enter number of edges: ";
    cin>edg;

    cout<<"Enter edges and cost: ";
    for(int i=1; i<=edg; i++)
    {
        int x,y;
        cin>>x>>y;
        cin>>value;
        edges[x].push_back(y);
        cost[x].push_back(value);

    }
}

int find_par(int r)
{

    return (pr[r]==r) ? r: find_par(pr[r]);
}

int mst(int n)
{

}

