#include<iostream>
#include<string>
using namespace std;
typedef struct Linklist 
    {
        int data;
        string name;
        Linklist *next;
    }*linklist;
class LINKLIST{
    public:
    void tailcreate();
    void allmembers();//
    void getlength();//
    void menu(linklist);//
    linklist L=new Linklist;
    private:
    int length;
}LINKLIST;
void LINKLIST::allmembers(){
    linklist p=L;
    do
    {
        cout<<p->data<<' ';
        p=p->next;
    } while (p!=L);
}

void LINKLIST::tailcreate(){
    linklist tail,r;
    r=L;
    getlength();
    for (int i = 0; i < length; i++)
    {
        linklist p=new Linklist;
        p->name="this is me";
        p->data=i+1;
        r->next=p;
        r=p;
    }
    r->next=L->next;
    tail=L;
    L=L->next;
    delete tail;
}


void LINKLIST::getlength(){
    cout<<"please enter your numbers that you want to create the linklist"<<endl;
    cin>>length;
}
int main(){
    LINKLIST.tailcreate();
    LINKLIST.allmembers();
    return 0;
}