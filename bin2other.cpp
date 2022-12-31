#include<iostream>
#include<cmath>
using namespace std;
#define elemtype char
#define initsize 100
#define createsize 10
typedef struct Stack
{
    elemtype *base;
    elemtype *top;
    int stacksize;
}sqstack;

class bin2other
{
    public:
    void initstack(sqstack *s);
    void push(sqstack *s,elemtype c);
    void pop(sqstack *s,elemtype *c);
    void bin2dec(sqstack *s,elemtype *c);
    void getstacklen(sqstack *s);
    void getdata(sqstack *s,elemtype*);
    private:
    int stacklen;
    char *copy;
};

void bin2other::initstack(sqstack *s){
    try
    {
        s->base=new elemtype[initsize];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    s->top=s->base;
    s->stacksize=initsize;
}

void bin2other::push(sqstack *s,elemtype c){
    if(s->top-s->base>=s->stacksize){
        try
        {
            s->base=new elemtype[createsize];
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    *(s->top)=c;
    s->top++;
    copy=s->top;
}

void bin2other::pop(sqstack *s,elemtype *c){
    if(s->top==s->base)
        return ;
    *c=*--(s->top);
}

void bin2other::getstacklen(sqstack *s){
    stacklen=s->top-s->base; 
}

void bin2other::bin2dec(sqstack *s,elemtype *c){
    s->top=copy;
    getstacklen(s);
    int sum=0;
    for (int i = 0; i < stacklen; i++)
    {
        pop(s,c);
        sum+=(*c-'0')*pow(2,i);
    }
    cout<<sum<<endl;
    
}
void bin2other::getdata(sqstack *s,elemtype *c){
    cout<<"please enter the binary number that you want to change and enter the # to end"<<endl;
    scanf("%c",c);
    while (*c!='#')
    {
        push(s,*c);
        scanf("%c",c);
    }
    getchar();
}
int main(){
    sqstack s;
    char c;
    bin2other solution;
    solution.initstack(&s);
    solution.getdata(&s,&c);
    solution.bin2dec(&s,&c);
}