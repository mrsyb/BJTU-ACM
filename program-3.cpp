# include<iostream>
using namespace std;

inline int Sum(int a1,int n)
{
    return n * a1 + (n * (n - 1))/2;
}

int GetCount(int n)
{
    int maxlen,count = 0,sum = 0,min = 0;
    maxlen = (n + 1)/2;

    for(int i = 2;i <= maxlen;i++)
    {
        min = n/i-(i-1)/2;

        if(min < 1)
            break;

        sum = Sum(min,i);

        if(sum == n)
        {
            count++;
        }
    }
    return count;
}


int main()
{
   int t,n,i = 0;

    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<"Case #"<<++i<<": "<<GetCount(n)<<endl;
    }
    return 0;
}
