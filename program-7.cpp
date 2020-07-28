#include <stdio.h>
#include<vector>
using namespace std;

int main()
{
    int t = 0,n = 0,q = 0,left = 0,right = 0,index = 0,temp = 0;
    long long sum = 0;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        vector<long long> s1(n+1,0);
        vector<long long> s2(n+1,0);
        for(int i = 1;i <= n;i++){
            scanf("%d",&temp);
            s1[i] = s1[i - 1] + temp;
            s2[i] = s2[i - 1] + temp * i;
        }
        scanf("%d",&q);
        printf("Case #%d: \n",++index);  
        for(int i = 0;i < q;i++){
            scanf("%d %d",&left,&right);
            sum = s2[right] - s2[left - 1] - (s1[right] - s1[left - 1]) * (left - 1);
            printf("%lld\n", sum);
        }
    }
    return 0;
}