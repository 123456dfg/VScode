#include<iostream>
long long count=0;
void move(int num,char x,char y,char z){
    if(1==num)
    count++;
    //std::cout<<x<<"-->"<<z<<std::endl;
    else 
    {
        move(num-1,x,z,y);
        //std::cout<<x<<"-->"<<z<<std::endl;
        count++;
        move(num-1,y,x,z);
    }
}
int main(){
    move(64,'x','y','z');
    std::cout<<count;
    return 0;
}