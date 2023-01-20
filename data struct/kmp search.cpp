#include<iostream>
#include<string>
using namespace std;
void getnextval(string&,int[]);
void getnextval(string&t,int nextval[]){
    int k=-1,j=0;
    nextval[0]=-1;
    while (j<t.length())
    {
        if(k==-1||t[j]==t[k]){
            j++;k++;
            if (t[j]!=t[k])
            {
                nextval[j]=k;
            }
            else nextval[j]=nextval[k];
        }
        else  k=nextval[k];
    }
}
int KMP(string&,string&);
int KMP(string &s,string& t){
    int i=0,j=0;
    int nextval[t.length()];
    getnextval(t,nextval);
    while (i<static_cast<int>(s.length())&&j<static_cast<int>(t.length()))
    {
        if(j==-1||t[j]==s[i]){
            j++;i++;
        }
        else j=nextval[j];
    }
    if(j>=t.length())
    return (i-t.length());
    else return -1;
    
}
auto main()->int
{
    string s,t;
    cout<<"please input your string that you want to check"<<endl;
    cin>>s;
    cout<<"please input your checked string"<<endl;
    cin>>t;
    cout<<"子串位置在主串的第"<<KMP(s,t)<<"位开始"<<endl;
    return 0;
}