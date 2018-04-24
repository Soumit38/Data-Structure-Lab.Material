/* sample input from shahani's books page number 218 Figure 4.6 graph:

number of nodes: 7
number of edges: 9

node1 - node2 <-> weight
~~~~~   ~~~~~     ~~~~~~
  1       2         28
  1       6         10
  2       3         16
  2       7         14
  3       4         12
  4       5         22
  4       7         18
  5       6         25
  5       7         24


Sample output:

minimum cost spanning tree: 99
 */

#include<iostream>

using namespace std;

int main()
{


    int node,edge,i,j;

    cout << "Enter Number of Node and edge: ";
    cin >> node >>  edge;

    int nodeEdge[node][node];

    for(i=0; i<node; i++)
        for(j=0; j<node; j++)
            nodeEdge[i][j]=0;

    int node1,node2,weight;

    for(i=0; i<edge; i++)
    {
        cout << "\nEnter two node and it's weight(negative to break) : ";
        cin >> node1  >> node2 >> weight;

            nodeEdge[node1-1][node2-1] = weight;
            nodeEdge[node2-1][node1-1] =  weight;

    }

    int arr[node],count=0,p=0,small=-1,tmp,index1,index2,path=0,freq=0;
    arr[count]=0;


int mn=0;
    while(1)
    {
        p=0;

        for(j=0; j<=count; j++)
        {
            for(i=0; i<node; i++)
            {
                if(nodeEdge[arr[j]][i]>0 && p==0)
                {
                    small=nodeEdge[arr[j]][i];
                    p=1;
                    index1=arr[j];
                        index2=i;
                }
                else if(p==1)
                {
                    if(small>nodeEdge[arr[j]][i] && nodeEdge[arr[j]][i]>0)
                    {
                        small=nodeEdge[arr[j]][i];
                        index1=arr[j];
                        index2=i;
                    }

                }

            }


        }
        if(small>0)
        {
            nodeEdge[index2][index1]=-1;
            nodeEdge[index1][index2]=-1;
            //arr[0]=0;
            arr[++count]=index2;

            for(i=0; i<node; i++)
                nodeEdge[i][index2]=-1;

            path = path + small;
            small=-1;
            freq++;
        }


        if(freq==node-1)
        {
            cout << "\n minimum cost spanning tree: = " << path << "\n\n";
            break;
        }

    }

}

