#include<iostream>
#include<string>
using namespace std;

string GetNumber(string& p)
{
    string str;
    if(p != ""){
        for(unsigned i = 0;i < p.size();i++){
            if(p[i] == 'A') str.append("U");
            if(p[i] == 'U') str.append("A");
            if(p[i] == 'C') str.append("G");
            if(p[i] == 'G') str.append("C");
        }
    }
    return str;
}

int main()
{
    int t = 0,i = 0;
    string p;
    cin>>t;
    while(t--){
        cin>>p;
        cout<<"Case #"<<++i<<": "<<GetNumber(p)<<endl;    
    }
    return 0;
}