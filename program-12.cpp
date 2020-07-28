#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int Getvalue( vector<long> q)
{
    int value = 0;
    vector<long>::iterator i,j;
    if(q.size() == 1){   
        value = 0;
    }else{
        i = q.begin();
        j = q.begin() + 1;
        while (j != q.end())
        {
            if(*i == *j){
                value++; j++;
            }else{
                i++; j++;
            }
        }
    }
    return value;
}
void DivideAndGetValue(vector<int>& value,vector<long> p)
{
    int len = p.size(),i = 0;
    while (i < len)
    {
        i++;
        for(auto it1 = p.begin();it1 != p.end();it1++){
            vector<long> q;
            for(auto it2 = it1; it2 != it1 + i/*sqrt(2*i+1/4.0)-0.5*/ && it2 != p.end() ; it2++)
            {
                q.push_back(*it2);
            }
            if(q.size() == i)
                value.push_back(Getvalue(q));
            else if(q.size() == 0) break;
        }
    }
}

int main()
{
    int t = 0,n = 0,k = 0;
    long temp;
    vector<long> p;
    vector<int> value;
    cin>>t;
    while(t--){
        cin>>n>>k;
        value.clear();
        p.clear();
        for(int i = 0;i < n;i++){
                cin >> temp;
                p.push_back(temp);
            }
        DivideAndGetValue(value,p);
        sort(value.begin(),value.end());
        cout<<value[k-1]<<endl;    
    }
    return 0;
}