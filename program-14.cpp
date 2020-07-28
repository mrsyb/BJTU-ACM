#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
const string h1 = "happy";
const string h2 = "unhappy";

int main(){
    int w,n,t,temp;
    cin >> t;
    while (t--)
    {
        cin >> w >> n;
        vector<int> a;
        for(int i = 0;i < n;i++){
            cin >> temp;
            a.push_back(temp);
        }
        if(find(a.begin(),a.end(),w) != a.end() )
        cout << h2 << endl;
        else cout << h1 << endl;
    }
    return 0;
}