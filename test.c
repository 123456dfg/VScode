#include<stdio.h>
#include<string.h>
typedef struct 
{
    int a;
}test;

void change(test test1){
    test1.a=55;
    while(test1.a--){
        printf("%d ",test1.a);
    }
}

int main(){
    test test1={
        .a=5,
    };
    change(test1);
    printf("%d",test1.a);
}