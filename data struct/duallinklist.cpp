#include<iostream>
#include<string>
using namespace std;
typedef char eletype;
typedef struct Linklist
{
    struct Linklist *next;
    struct Linklist *prior;
    eletype data;
}node,*linklist;

class duallinklist{
    public:
    void initlinklist(linklist *);
    void printabcd(linklist*,int);
    void listinsert(linklist*,int);
    void getlistlength(linklist*);
    void multlistinsert(linklist*,int);
    private:
    int length=0;
}duallinklist;
void duallinklist::multlistinsert(linklist*L,int n){
    static int countplus=0;
    if(n==0)return;
    node *p=*L;
    node *q;
    try
    {
        q=new Linklist;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    q->data='a';
    if(n==1){
       q->next=p;
       q->prior=p->prior;
       p->prior->next=q;
       p->prior=q;
       (*L)=q;
    }
    else if(n>0&&n!=1){
    while(--n-1+countplus){
        p=p->next;
    }
    q->prior=p;
    q->next=p->next;
    p->next->prior=q;
    p->next=q;
    }
    ++countplus;
}
void duallinklist::getlistlength(linklist *L){
    node *p;
    p=(*L);
    do
    {

        length++;
        p=p->next;
    } while (p!=(*L));
    return;
}

void duallinklist::initlinklist(linklist *L){
    try{
    (*L)=new Linklist;
    }
    catch (bad_alloc &e){
        cout<<e.what()<<endl;
    }

    node *p;
    node *q;
    int i;
    (*L)->next=(*L)->prior=nullptr;
    p=(*L);
    for(i=0;i<26;i++){
        try
        {
            q=new Linklist;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        q->data='A'+i;
        q->prior=p;
        q->next=p->next;
        p->next=q;

        p=q;
    }
    p->next=(*L)->next;
    (*L)->next->prior=p;
    linklist dele=(*L);
    (*L)=(*L)->next;
    delete dele;
}


void duallinklist::printabcd(linklist *L,int n){
    linklist p=(*L);
    if(n>0)
    do
    {
        p=p->next;
    } while (--n);
    else if(n<0)
        do
    {
        p=p->prior;
    } while (!++n&&n!=0);
    for (int i = 0; i < length; i++)
    {
        cout<<p->data;
        p=p->next;
    }
}
void duallinklist::listinsert(linklist *L,int n){
    if(n==0)return;
    node *p=*L;
    node *q;
    try
    {
        q=new Linklist;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    q->data='a';
    if(n==1){
       q->next=p;
       q->prior=p->prior;
       p->prior->next=q;
       p->prior=q;
       (*L)=q;
    }
    else if(n>0&&n!=1){
    while(--n-1){
        p=p->next;
    }
    q->prior=p;
    q->next=p->next;
    p->next->prior=q;
    p->next=q;
    }
}
int main(){
    linklist L;
    duallinklist.initlinklist(&L);
    for (int i = 0; i < 10; i++)
    {
        duallinklist.listinsert(&L,i);
    }
    duallinklist.getlistlength(&L);
    duallinklist.printabcd(&L,0);
}
