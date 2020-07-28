#include <stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

template <typename T>
inline void PRINT_ELEMENTS (const T& coll)
{
    for(auto it = coll.begin();it != coll.end() - 1 ;it++)
    {
        cout << *it <<" ";
    }
    cout << *(coll.end() - 1) << endl;  
}

int main()
{
    int t = 0,n = 0,index = 0,temp = 0;;
    vector<int> p;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        p.clear();
        for(int i = 0;i < n;i++){
            scanf("%d",&temp);
            p.push_back(temp);
        }
        auto it_max = max_element(p.begin(),p.end());
        auto it_min = min_element(p.begin(),p.end());

        if(it_min == p.begin() && it_max == p.end() - 1)
        {
            iter_swap(it_max,it_min);
        }else if(it_min == p.end() - 1 && it_max == p.begin()){}
        else if(it_min == p.begin() && it_max != p.end() - 1){
            iter_swap(it_min,it_max);
            iter_swap(it_max,p.end() - 1);
        }else if(it_min != p.begin() && it_max == p.end() - 1){
            iter_swap(it_min,it_max);
            iter_swap(it_min,p.begin());
        }else{
            iter_swap(it_min,p.end() - 1);
            iter_swap(it_max,p.begin());
        }
        printf("Case #%d: ",++index);
        PRINT_ELEMENTS(p);
    }
    return 0;
}