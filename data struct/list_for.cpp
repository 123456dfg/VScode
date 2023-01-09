#include<iostream>
#include<string>
#include<vector>
using namespace std;
typedef char elemtype;
typedef struct LIST_FOR
{
    elemtype *data;
    int front;
    int rear;
}list;
class list_for{
    public:
    void init();
    void push(elemtype &x);
    void pop(elemtype &x);
    int getlength();
    const int MAX_SIZE=100;
    list_for(){init();}
    private:
    list L;
};
void list_for::pop(elemtype &x){
    if(L.rear==L.front){
        cout<<"The list is empty"<<endl;
        return;
    }
    x=L.data[L.front];
    L.front=(L.front+1)%MAX_SIZE;

}
void list_for::push(elemtype &x){
    if ((L.rear+1)%MAX_SIZE==L.front)
    {
        cout<<"list is full"<<endl;
        return;
    }
    L.data[L.rear]=x;
    L.rear=(L.rear+1)%MAX_SIZE;
    return ;
}
void list_for::init(){
    try
        {
            L.data=new elemtype[100];
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        L.front=L.rear=0;
}
int list_for::getlength(){
    if((L.rear+1)%MAX_SIZE==L.front)//ÅÐ¶ÏÊÇ·ñÎªÂú
    return MAX_SIZE;
    else if(L.rear==L.front)
    return 0;
    else return (L.rear-L.front+MAX_SIZE)%MAX_SIZE;
}
int main(){
    list_for L;
    elemtype x;
    scanf("%c",&x);
    while(x!=10){
        L.push(x);
        scanf("%c",&x);
    }
    while(L.getlength()){
        L.pop(x);
        cout<<x;
    }
}