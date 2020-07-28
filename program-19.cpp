#include<cstdio>
#include<algorithm>
// #include<map>
// #include<vector>
// #include<cmath>
using namespace std;

// int main()
// {
//     int t,n,p,ids;
//     //vector<int> k;
//     map<int,int> m;//ids:rate
//     map<int,int> idx;//ids:studentId

//     scanf("%d",&t);
//     while(t--){
//         scanf("%d %d",&n,&p);
//         for(int i=1;i<=n*5;i++){
//             scanf("%d",&ids);
//             //if(k.size() >= 3) break;
//             if(find(idx.begin(),idx.end(),ids) == idx.end()){
//                 m[ids] += 1;
//                 if(m[ids] >= ceil(n*p*0.01)){
//                 //k.push_back(ids);
//                 idx[i/5] = ids;
//             }
//         }


        
//         if(k.size() >= 3)
//         printf("yes\n");
//         else  printf("no\n");
//     }
// 	return 0;
// }
#define LEN 61
int main() {
    int t, n, p;
    scanf("%d", &t);
    int rate,ids[5],sets[LEN][LEN][LEN];
    for (int i = 0; i < t; i++) {
        int flag = 0;
        scanf("%d %d", &n, &p);
        rate = n * p * 0.01;
        for (int j = 0; j < n; j++) {
            for (int classnum = 0;classnum<5;classnum++){scanf("%d", &ids[classnum]);}
            sort(ids,ids+5);
            if (flag) continue;
            for (int k = 0; k < 3; k++) {
                for (int l = k + 1; l < 4; l++) {
                    for (int m = l + 1; m < 5; m++) {
                        sets[ids[k]][ids[l]][ids[m]]++;
                        if (sets[ids[k]][ids[l]][ids[m]] >= rate) {
                            flag = 1;
                            break;
                        }
                    }
                    if (flag) break;
                }
                if (flag) break;
            }
        }
        if (flag) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}