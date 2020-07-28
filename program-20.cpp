#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define TYPENUM  26
struct flower{
    flower(){}
    char specie;
    int num;
};
bool comp(flower pre,flower next){
        if(pre.num != next.num)
        return pre.num > next.num;
        else return pre.specie<next.specie;
}
int main() {
    int t, n, m;
    cin>>t;
    for (int i = 0; i < t; i++) {
        cin>>n>>m;
        char temp;
        vector<flower> flowers(TYPENUM,flower());
        int speciesNum = 0;
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                cin>>temp;
                flowers[temp-'A'].specie = temp;
                if(flowers[temp-'A'].num == 0)speciesNum++;
                flowers[temp-'A'].num++;
            }
        }
        sort(flowers.begin(),flowers.end(),comp);
        cout<<speciesNum<<endl;
        for (int i = 0; i < TYPENUM; i++) {
            if (flowers[i].num != 0) {
                cout<<flowers[i].num<<" "<<flowers[i].specie <<endl;
            } else break;
        }
    }
    return 0;
}