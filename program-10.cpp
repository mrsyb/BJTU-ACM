#include<iostream>
using namespace std;

int main()
{
    int t = 0,n = 0,i = 0;
    long max,p[3];
    cin >> t;
    while(t--){
        max = 0;
        for(int j = 0;j < 3;j++){
            cin >> p[j];
        }
        max = p[0]*p[1];
	    if (p[1]*p[2] > max) max = p[1]*p[2];
	    if (p[0]*p[2] > max) max = p[0]*p[2];
        cout << "Case #"<<++i<<": "<<max<<endl;
    }
    return 0;
}