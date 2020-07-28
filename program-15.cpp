#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

// bool Getlocation(vector<long>& a,int& x,int& y,long q,int n){
//     int idx;
//     auto it = find(a.begin(),a.end(),q);
//     if(it != a.end()){
//         idx = distance(a.begin(),it);
//         x = (idx / n) + 1; y = idx % n +1;
//         for(auto it2 = a.begin() + x*n -1; it2 != it; it2--){
//             if(*it2 == q){
//                 idx = distance(a.begin(),it2);
//                 y = idx % n +1;
//             }
//         }
//         return true;
//     }
//     return false;
// }

int main(){
    int n,t,qn,x,y,q;

    cin >> t;
    while (t--)
    {
        cin >> n;
        int a[n][n];
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                cin >> a[i][j];
            }
        }
        cin >> qn;
        for(int j = 0;j < qn;j++){
            cin >> q;
            bool flag = true;
            int l ,m ,r;
            for(int j = 0;j < n; j++){
                if(q >= a[j][0] && q <= a[j][n-1]) {
                    x = j + 1;
                    l = 0;r = n -1 ;
                    while (l <= r)
                    {
                        m = (l + r) / 2;
                        if(q >= a[j][m] && x <= a[j][r]){
                            if(q == a[j][r]){
                                y = r + 1;
                                flag = false; break;
                            }else if(q == a[j][m]){
                                y = m + 1;
                                flag = false;
                            }
                            l = m + 1;
                        }else
                            r = m - 1;
                    }
                }
                if(!flag) break; 
            }
            if(flag) cout << "-1" << endl;
            else cout << x << " " << y << endl;
        }
    }
}

