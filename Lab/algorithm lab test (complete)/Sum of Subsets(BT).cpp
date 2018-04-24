/* code taken from saif's upload */
#include <iostream>
using namespace std;
int x[100], m=35;
int w[]= {5,7,10,12,15,18,20};
void Subset(int s, int k, int r)
{
    x[k] = 1;
    if((s + w[k]) == m)
    {
        for(int i=0; i<=k; i++)
            cout << x[i] << " ";
        cout << endl;
    }

    else if((s + w[k] + w[k+1]) <= m)
        Subset( s + w[k], k+1, r - w[k] );
    if(((s + r - w[k]) >= m) && ((s + w[k+1])<=m))
    {
        x[k] = 0;
        Subset(s, k+1, r-w[k]);
    }
}
int main()
{
    Subset(0, 0, 87);
    return 0;
}
