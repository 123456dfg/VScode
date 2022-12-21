#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
    vector<string> strv;
    strv.push_back("test");
    strv.push_back("test again");
    for(auto str:strv)
    cout<<str<<endl;
}