#include <iostream>
using namespace std;

int fac(int x)  
{  
    register int i,f=1; 
    for(i=1;i<=x;i++)  
        f*=i;  
    return f;  
}  

int main(){
    int t,n,sum;
    cin >> t;
    while (t--)
    {
        cin >> n;
        sum = 0;
        for(int i = 1;i <= n;i++){
            sum += fac(i);
        }
        cout << sum%1000000007 <<endl;
    }
    return 0;
}

