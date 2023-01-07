#include<iostream>
#include<string>
using namespace std;
#define elemtype char
typedef struct QNode
{
    elemtype data;
    struct QNode *next;
}Qnode,*QueuePtr;
typedef struct 
{
    Qnode *front,*rear;
}Linkqueue;
void InitQueue(Linkqueue &q);
void push(Linkqueue &q,elemtype &x);
void pop(Linkqueue &q,elemtype &e);
void InitQueue(Linkqueue &q){
    try
    {
        q.front=q.rear=new QNode;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    } 
    q.front->next=nullptr;
}
void push(Linkqueue &q,elemtype &x){
    Qnode *p;
    try
    {
        p=new Qnode;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    p->data=x;
    p->next=nullptr;
    q.rear->next=p;
    q.rear=p;
}
void pop(Linkqueue &q,elemtype &e){
    Qnode *p;
    if(q.front==q.rear)
    return;
    p=q.front->next;
    e=p->data;
    q.front->next=p->next;
    if(q.rear==p){
        q.rear=q.front;
    }
    delete p;
    return;
}
int main(){
    elemtype x;
    Linkqueue q;
    InitQueue(q);
    scanf("%c",&x);
    while(x!='\n'){
        push(q,x);
        scanf("%c",&x);
    }
    while (q.rear!=q.front)
    {   
        pop(q,x);
        cout<<x;
    }
}
