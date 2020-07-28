#include <iostream>
using namespace std;

int main(){
    int n,m,t;
    int *a,*ans,*f;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        a = new int[n];
        ans = new int[n];
        f = new int[n];
        for(int i = 0;i < n;i++)
            cin >> a[i];
        f[0] = a[0];
        for(int j = 1;j < n;j++)
            f[j] = ((2 * f[j-1]) % m + (a[j]) % m) % m;
        ans[0] = 2 * a[0] - 1;
        for(int k = 1;k < n;k++){
            if(a[k] == 1)
                ans[k] = ((2 * f[k-1]) % m+1) % m;
            else
                ans[k] = ((2 * f[k-1]) % m + (2 * a[k]) % m + ans[k-1]) % m;
        }
        cout << ans[n-1] << endl;
        delete[] a;
        delete[] f;
        delete[] ans;
    }
    return 0;
}

// #include <iostream>
// #include <stdio.h>
// using namespace std;
// int f[15001], ans[15001], arr[15001];
// int main() {
//     int T, n, m;
//     scanf("%d", &T);
//     for (int i=1;i<=T;i++) {
//         scanf("%d %d", &n, &m);
//         for (int j=1;j<=n;j++) {
//             scanf("%d", &arr[j]);
//         }
//         f[1] = arr[1];
//         for (int j=2;j<=n;j++) {
//             f[j] = ((2*f[j-1])%m+arr[j])%m;
//         }
//         ans[1] = 2*arr[1]-1;
//         for (int j=2;j<=n;j++) {
//             if (arr[j]==1) {
//                 ans[j] = ((2*f[j-1])%m+1)%m;
//             }else{
//                 ans[j] = ((2*f[j-1])%m+2*arr[j]+ans[j-1])%m;
//             }
//         }
//         printf("%d\n", ans[n]);
//     }
//     return 0;
// }