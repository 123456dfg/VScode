#include<map>
#include<cctype>
#include<iostream>
using namespace std;



size_t duplicateCount(const std::string& in); // helper for tests

size_t duplicateCount(const char* in)
{
    string str;
str=in;
  map<char,int>mv;
  int count=0;
  for(auto i:str){
    i=tolower(i);
    mv[i]++;
  }   
    for(int i=0;i<mv.size();i++){
        if(mv[i]>1){
            count++;
        }
    }
    return count;
}