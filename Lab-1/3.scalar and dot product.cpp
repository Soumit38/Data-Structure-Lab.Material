#include <iostream>

using namespace std;

int main()
{
    int a[10], b[10], c[10];
    int n, m, x, y;
    int sum1=0, sum2=0;
    cout << "Enter 1st array element number: ";
    cin >> m;
    cout << "Enter 1st array element: ";
    for(int i=0; i<m; i++){
        cin >> a[i];
    }
    cout << "Enter 2nd array element number: ";
    cin >> n;
    cout << "Enter 2nd array element: ";
    for(int i=0; i<n; i++){
        cin >> b[i];
    }
    cout << "Enter x and y: ";
    cin >> x >> y;
    for(int i=0; i<m; i++){
        sum2=sum2+(a[i]*b[i]);
        sum1=sum1+(a[i]*x+b[i]*y);
    }
    cout << "scaler= " << sum1 <<endl;
    cout << "dot= " << sum2 << endl;

    return 0;
}
