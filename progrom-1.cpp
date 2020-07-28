# include<iostream>
using namespace std;

int GetBallNum(int n,int m)
{
    if(n <= 0 || m <= 0)
        return 0;

    int num = 1,index = 1;
    bool *flags = new bool[n+1]();
    flags[1] = true;

    while(!flags[(index+m)%n])
    {
        index = (index+m)%n;
        flags[index] = true;
        num++;
    }
    delete [] flags;
    return num;
}


int main()
{
    int n,m,count,index=1;

    cin>>count;

    while(count--)
    {
        cin>>n>>m;
        cout<<"Case #"<<index++<<": "<<GetBallNum(n,m)<<endl;
    }
    return 0;
}
