#include <iostream>
#include<cmath>
using namespace std;

int GetDigits(int a,int b)  
{  
    int p = pow(a,b),num = 0;
    while(p > 0){p/=10;num++;}
    return num;  
}  

int main(){
    int t,a,b;
    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        cout << GetDigits(a,b) <<endl;
    }
    return 0;
}

