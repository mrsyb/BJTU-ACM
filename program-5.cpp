#include<iostream>
#include<sstream>
#include<string>
using namespace std;

const int BASENUMBER = 2333;
const string STRBASENUMBER = "2333";
const int BLEN = 4;

string BigNumAdd(string a,string b){
	if(a.length()<b.length()){
		string temp=a;
		a=b;
		b=temp;
	}
	int i,j,sum,flag=0;
	for(int l1 = a.length(),l2 = b.length();l1 > 0;l1--,l2--){
		i = a.at(l1-1) - '0';
		if(l2>0) 
            j=b.at(l2-1) - '0';
		else 
            j=0;
		sum=i+j+flag;
		if(sum>=10){
			a.at(l1-1) = '0' + sum%10;
			flag=1;
		}else{
			a.at(l1-1) = '0' + sum;
			flag=0;
		}
	}
	if(1==flag)
		a="1"+a;
	return a;
}

string GetNumber(string p)
{
    int len = p.length(),p_int = 0,temp = 0,temp_len = 0;
    string::size_type index;

    stringstream stream;
    string substr,str_temp;

    if(len < 4)
        return STRBASENUMBER;
    if(len == 4){
        stream << p;
        stream >> p_int;
        if(p_int < BASENUMBER) return STRBASENUMBER;
        return "1"+STRBASENUMBER;
    }

    // temp_len = len;
    // index = p.find("2333");
    // while(index != string::npos){
    //     ++temp;
    //     substr = p.substr(index + BLEN,temp_len - BLEN - index);
    //     index = substr.find("2333");
    //     temp_len = substr.length();
    // }
    // if(temp > 1)//has >1 "2333"
    //     return BigNumAdd(p,"1");
    // if(temp == 1 && substr != "" ){//has a "2333" and have not carry
    //     if(BigNumAdd(substr,"1").length() == substr.length()){
    //         p.at(len -1) += 1;
    //         return p;
    //     }
    // }
    // //have not "2333"   
    // substr = p.substr(len - BLEN,BLEN);
    // stream.clear();
    // stream << substr;
    // stream >> temp; 
    // if(temp < BASENUMBER)
    //     return p.substr(0,len - BLEN) + STRBASENUMBER;

    for(str_temp = BigNumAdd(p,"1"); str_temp.find(STRBASENUMBER) == string::npos; str_temp = BigNumAdd(str_temp,"1")){}
    return str_temp;
}

int main()
{
    int t = 0,i = 0;
    string p;
    cin>>t;
    while(t--){
        cin>>p;
        cout<<"Case #"<<++i<<": "<<GetNumber(p)<<endl;    
    }
    return 0;
}