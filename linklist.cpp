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
    linklist tailcreate();
    void allmembers(linklist L);
    void getlength();
    double getmidele(linklist L);
    private:
    int length;
}LINKLIST;

linklist LINKLIST::tailcreate(){//尾插法
    linklist L=new Linklist;
    linklist r;
    r=L;
    for(int i=0;i<length;i++){
        linklist p=new Linklist;
        p->name="this is me";
        p->data=i+1;//数据域初始化为i+1
        r->next=p;
        r=p;
        r->next=NULL;
    }
    return L;
}
void LINKLIST::allmembers(linklist L){
    linklist p=L->next;
    while(p){
        cout<<p->name<<'-';
        cout<<p->data<<endl;
        p=p->next;
    }
    
}
void LINKLIST::getlength(){
    cout<<"please enter your numbers that you want to create the linklist"<<endl;
    cin>>length;
}
double LINKLIST::getmidele(linklist L){
    linklist search,mid;
    search=L->next;
    mid=L->next;
    while(search->next!=NULL){
        if(search->next->next!=NULL){
            search=search->next->next;
            mid=mid->next;
        }
        else {
            search=search->next;
            return (mid->data+mid->next->data)/2.0;
    }
    }
    return mid->data;
}
int main(){
    linklist L;
    LINKLIST.getlength();
    L=LINKLIST.tailcreate();
    LINKLIST.allmembers(L);
    cout<<LINKLIST.getmidele(L);
}