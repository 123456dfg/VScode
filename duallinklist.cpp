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

}duallinklist;
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
    for (int i = 0; i < 26; i++)
    {
        cout<<p->data;
        p=p->next;
    }
}
int main(){
    linklist L;
    duallinklist.initlinklist(&L);
    duallinklist.printabcd(&L,cin.get()-'0');
}
