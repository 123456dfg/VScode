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
    void tailcreate(linklist);//尾插法链表
    void allmembers(linklist L);//遍历链表
    void getlength();
    double getmidele(linklist L);//找中间值
    void linkinsert(linklist*);//插入元素
    void linkdelete(linklist*);//删除元素
    int linksearch(linklist);//查找元素返回索引
    void linkchange(linklist *L);//更改元素
    bool empty(linklist );//检查函数
    void menu(linklist);//菜单
    linklist L=new Linklist;
    private:
    int length;
}LINKLIST;

void LINKLIST::tailcreate(linklist L){//尾插法
    linklist r;
    r=L;
    getlength();
    for(int i=0;i<length;i++){
        linklist p=new Linklist;
        p->name="this is me";
        p->data=i+1;//数据域初始化为i+1
        r->next=p;
        r=p;
    }
    r->next=nullptr;
}
void LINKLIST::allmembers(linklist L){
    linklist p=L;
    while(p->next){
        p=p->next;
        cout<<p->name<<'-';
        cout<<p->data<<endl;
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
    while(search->next!=nullptr){
        if(search->next->next!=nullptr){
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
void LINKLIST::linkinsert(linklist *L){
    linklist p,r;
    r=(*L);
    p=new Linklist;
    int n;
    cout<<"please enter the inserted name"<<endl;cin>>p->name;
    cout<<"please enter the inserted number"<<endl;cin>>p->data;
    cout<<"please enter the number that you want to insert"<<endl;cin>>n;
    int i=0;
    while(i<n-1){
        r=r->next;
        i++;
    }
    p->next=r->next;
    r->next=p;
    length++;
}
void LINKLIST::linkdelete(linklist *L){
    linklist r,p;
    r=(*L);
    int n;
    cout<<"please enter the number that you want to delete"<<endl;cin>>n;
    int i=0;
    while (i<n-1)
    {
        r=r->next;
        i++;
    }
    p=r->next;
    r->next=r->next->next;
    delete p;
    
}
int LINKLIST::linksearch(linklist L){
    linklist p=L;
    int i=0;
    cout<<"please enter your find number"<<endl;
    cin>>i;
    int count=0;
    while(p->next!=nullptr){
        count++;
        p=p->next;
        if(p->data==i){
            return count;
        }
    }
    cout<<"not found"<<endl;
    return -999999;
}
void LINKLIST::linkchange(linklist *L){
    linklist p=*L;
    int i=0;
    int n=0;
    cout<<"please enter you want to change the undered number"<<endl;
    cin>>n;
    while(i<n){
        p=p->next;
        i++;
    }
    cout<<"please enter the data that you want to change"<<endl;
    cin>>p->data;
}
void LINKLIST::menu(linklist L){
    cout<<"1.初始化链表（尾插法）2.插入元素 3.删除元素 4. 查找元素 5.遍历元素 6.改元素 0.退出"<<endl;
    char i;
    cin>>i;
    switch (i)
    {
    case '1':tailcreate(L);break;
    case '2':if(!empty(L))linkinsert(&L);break;
    case '3':if(!empty(L))linkdelete(&L);break;
    case '4':if(!empty(L))cout<<linksearch(L);break;
    case '5':if(!empty(L))allmembers(L);break;
    case '6':if(!empty(L))linkchange(&L);break;
    case '0':exit(1);break;
    }
}
bool LINKLIST::empty(linklist L){
    if(L==nullptr){
        cout<<"请先创建一个链表";
        return true;
    }
    else return false;
}
int main(){
    while(true)LINKLIST.menu(LINKLIST.L);
}