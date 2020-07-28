#include<iostream>
using namespace std;

int main()
{
    int t = 0,n = 0,index = 0,temp = 0;;
    char p[5][5]  = {{'A','B','C','D','E'},
                     {'F','G','H','I','K'},  
                     {'L','M','N','O','P'}, 
                     {'Q','R','S','T','U'},   
                     {'V','W','X','Y','Z'},
    };
    cin >> t;
    while(t--){
        cin >> n;
        cout << "Case #"<<++index<<": ";
        for(int i = 0;i < n;i++){
            scanf("%d",&temp);
            cout << p[temp/10 - 1][temp % 10 -1];
        }
        cout << endl;
    }
    return 0;
}