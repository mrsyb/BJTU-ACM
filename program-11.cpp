// #include<iostream>
// #include<algorithm>
// #include<map>
// #include<cmath>
// using namespace std;

// struct point
// {
//    point():x(0),y(0){}
//    point(int x1,int y1):x(x1),y(y1){}
//    int x,y;
// };


// int GetPathLength(point a,point b)
// {
//     int x1 = a.x,x2 = b.x,y1 = a.y,y2 = b.y;
//     return abs(x1 - x2) + abs(y1 - y2);
// }

// void FindShorst(map<char,point>& m,map<int,char>& path)
// {
//     for(map<char,point>::iterator it = m.begin(); it != m.end();it++){
//         if(it->first >='a' && it->first <= 'z'){
//            if(m.find(it->first - ('a' - 'A')) != m.end()){
//                int len = GetPathLength(it->second,m.find(it->first - ('a' - 'A'))->second);
//                path.insert(make_pair(len,it->first));
//            }
//         }
//     }
// }

// int main()
// {
//     int t = 0,r = 0,c = 0,d = 0;
//     char temp;
//     map<char,point> m;
//     map<int,char> path;

//     cin>>t;
//     while(t--){
//         cin>>r>>c>>d;
//         m.clear();
//         path.clear();
//         for(int i = 0;i < r;i++)
//             for(int j = 0;j < c;j++){
//                 cin >> temp;
//                 if((temp >='a' && temp <= 'z') || (temp >='A' && temp <= 'Z'))
//                 m[temp] = point(i,j);
//             }
//         FindShorst(m,path);
//         cout<<min_element(path.begin(),path.end())->second<<endl;    
//     }
//     return 0;
// }


#include <iostream>
#include <algorithm>
using namespace std;

int GetNum(int m,int num[],int len)
{
    int sum = 0,j = 0, value = 0;
    for(int i = 0 ; i < len; i++){
        while(j < len){
            if(value <= m){
                value += num[j];
                j++;
            }
            else break;
        }
        sum += j - i;
        value -= num[i];
     }
    return sum;
 }

int main()
{
    int t;
    cin>>t;
    for(int i = 0; i < t; i++)
    {
        int n,k;
        cin >> n >> k;
        int p[n], Nnum[n];
        for(int j = 0; j < n; j++){
            cin>>p[j];
            if(j > 0 && p[j] == p[j-1]){
                Nnum[j-1] = 1;
            }
            else if(j > 0){
                Nnum[j-1] = 0;
            }
        }
        int left = 0,right = n - 1;
        while(left < right){
            int mid = (left+right)/2;
            if(GetNum(mid, Nnum, n) >= k)
                right = mid;
            else
                left = mid + 1;
        }
        cout<<left<<endl;   
    }
    return 0;
}