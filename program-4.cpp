# include<iostream>
using namespace std;

int Getlevel(int low,int mid,int high)
{
    if(high >= 60)
        return 3;
    if(mid >= 60)
        return 2;
    if(low >= 60)
        return 1;
    return 0;
}

int main()
{
    int t,n,low,mid,high,i = 0;
    int gl = 0,gm = 0,gh = 0;

    cin>>t;
    if(t >= 1 && t <= 100)
    {
        while(t--)
        {
            cin>>n;
            low = 0,mid = 0,high = 0;
            if(n >= 1 && n <=1000)
            {                
                while (n--)
                {
                    cin>>gl>>gm>>gh;
                    switch(Getlevel(gl,gm,gh))
                    {
                        case 3: high++;
                        case 2: mid++;
                        case 1: low++;
                    }
                }
            }
            cout<<"Case #"<<++i<<": "<<low<<" "<<mid<<" "<<high<<endl;
        }
    }
    return 0;
}
