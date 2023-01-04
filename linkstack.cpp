#include<iostream>
#include<string>
#define elemtype char
#define initsize 100
using namespace std;
typedef struct Linkstack
{
    elemtype data;
    struct Linkstack *next;
}*linkstack;

class stack{
    public:
    void init(linkstack &s);
    bool empty(linkstack &s);
    void push(linkstack &s,elemtype &x);
    void pop(linkstack &s,elemtype &x);
};
void stack::init(linkstack &s){
    s=nullptr;
}

bool stack::empty(linkstack &s){
    if(s->next==nullptr)return true;
    else return false;
}
void stack::push(linkstack &s,elemtype &x){
    linkstack p;
    try
    {
        p=new Linkstack;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    p->data=x;
    p->next=s;
    s=p;
}
void stack::pop(linkstack &s,elemtype &x){
    x=s->data;
    linkstack p=s;
    s=s->next;
    delete p;
}

int main(){
    stack Stack;
    elemtype x;
    linkstack s;
    Stack.init(s);
    scanf("%c",&x);
    while (x!='#')
    {
        Stack.push(s,x);
        scanf("%c",&x);
    }
    getchar();
    while(s!=nullptr){
        Stack.pop(s,x);
        cout<<x;
    }
    return 0;
}