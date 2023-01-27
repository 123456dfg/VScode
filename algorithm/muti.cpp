#include<iostream>
#include<assert.h>
using namespace std;
int muit(int);
int muit(int num){
    if (num==1)
    {
        return 1;
    }
    else 
    return num*muit(num-1);
}
auto main()->int{
    int num=0;
    cin>>num;
    assert(("数据过大,请输入不大于100的数",num<=100));
    cout<<muit(num)<<endl;
}