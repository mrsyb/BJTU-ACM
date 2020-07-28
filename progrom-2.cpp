# include<iostream>
using namespace std;

bool GDC(int a,int b)
{
        int y = 1;
        while(y != 0)
        {
                y = a % b;
                a = b;
                b = y;
        }
        return a == 1;
}


int GetCount(int n)
{
    int count = 0,m = 2;
    if(n > 2)
    {
        if (n % 2 != 0){
            while (m < n){
                if(GDC(n,m))
                    count++;
                m += 2;
            }
        }
    }
    return count;
}


int main()
{
    int t,n,i = 0;

    cin>>t;
    if(t >= 1 && t <= 100)
    {
        while(t--)
        {
            cin>>n;
            if(n < 1 || n > 10000) 
                return 0;

            cout<<"Case #"<<++i<<": "<<GetCount(n)<<endl;
        }
    }
    return 0;
}
