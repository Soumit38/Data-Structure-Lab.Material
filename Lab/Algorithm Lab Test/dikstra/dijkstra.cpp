#include <iostream>
#include<cstdio>
#include <queue>
#include <vector>
#include <map>
#include<string>
using namespace std;
class node
{
public:
	int source,destin, d;
	bool operator()(node n1 ,node n2)
	{
		return n1.d > n2.d;
	}
};
vector<node> v[100];
int dijkstra(int source, int destin)
{
	priority_queue < node, vector<node>, node> pq;
	int d[100];
	for (int i = 0; i < 100; i++) d[i] = 9999999;
	node start;
	start.source = source; start.destin = source; start.d = 0;
	d[source] = 0;
	pq.push(start);
	while (!pq.empty())
	{
		node p = pq.top();

		if (p.source == destin)
			break;
		pq.pop();
		for (int i = 0; i < v[p.destin].size(); i++)
		{
			node c = v[p.destin][i];
			int parent = c.source;
			int child = c.destin;
			if (d[parent] + c.d < d[child])
			{
				d[child] = d[parent] + c.d;
				pq.push(c);
			}
		}

	}
	return d[destin];
}
int main()
{
	vector <int> nodes;
	map <int, int> m;
	cout << " Inter source,destination,dnce(negative to terminate )" << endl;
	int source, destin, d;
	freopen("input.txt","r",stdin);//Read from input.txt file
	while (cin >> source)
	{
		if (source <0) break;
		cin >> destin >> d;
		node a;
		a.source = source; a.destin = destin; a.d = d;
		v[source].push_back(a);
		if (!m[destin])
		{
			nodes.push_back(destin);
			m[destin] = 1;
		}
		if (!m[source])
		{
			nodes.push_back(source);
			m[source] = 1;
		}
	}
	cout << "Enter Source:" << endl;
	cin >> source;
	priority_queue <node, vector <node> , node> v1;
	for (int i = 0; i < nodes.size(); i++)
	{
		int d = dijkstra(source, nodes[i]);
		node n; n.source = source; n.destin = nodes[i]; n.d = d;
		v1.push(n);
	}
	vector <int> path;
     cout<<"The dnce from 5 node :"<<endl;
	while (!v1.empty())
	{
		path.push_back(v1.top().destin);
		for (int i = 0; i < path.size() - 1; i++)
		{
			cout << path[i] << ",";
		}
		cout << path[path.size() - 1] << " ";
		cout << v1.top().d << endl;
		v1.pop();
	}
}
