#include<cstdio>
#include<cstring>
#include<cmath>
typedef long long LL;
const int MAXN=20;
LL cnt[MAXN]={0};
char ans[MAXN];
LL mypow(LL x,LL p)
{
	long long res=1;
	while(p--) res*=x;
	return res;
}
int main()
{
    int t , n;

    for(int i=1;i<MAXN;i++)
	{
		LL p=(i+1)/2-1;
		cnt[i]=cnt[i-1]+9*mypow(10,p);
	}

    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int k,num;
        for(int i=1;i<MAXN;i++){
            if(n <= cnt[i]){
                k=n-cnt[i-1];//还需要的个数
                num=i;  //位数
                break;
            }
        }
        int len=num;
        num=(num+1)/2;
        LL x=mypow(10,num-1)+k-1;

        printf("%lld",x);
        if(len %2!=0) x/=10;
        while(x){
            printf("%lld",x%10);
            x/=10;
        }
        printf("\n");
    }
	return 0;
}