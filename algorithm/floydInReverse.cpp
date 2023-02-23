#include <iostream>
#include "stack"
class floyd{
public:
    const int INF=0xffff;
    int map[9][9];
    int path[9][9];
    void init() ;
    void floydgo();
    void find();
    void print();
    std::stack<int>st;
    int start=2,end=8;
};
int main() {
    floyd f;
    f.init();
    f.floydgo();
    f.find();
    f.print();
    return 0;
}
void floyd::init() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (i == j)map[i][j] = 0;
            else map[i][j] = INF;
        }
    }
    map[0][1]=50;map[1][0]=50;
    map[1][2]=60;map[2][1]=60;
    map[2][3]=40;map[3][2]=40;
    map[3][4]=60;map[4][3]=60;
    map[2][5]=50;map[5][2]=50;
    map[5][4]=80;map[4][5]=80;
    map[4][6]=100;map[6][4]=100;
    map[6][7]=40;map[7][6]=40;
    map[6][8]=40;map[8][6]=40;
    map[5][6]=50;map[6][5]=50;
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if(map[i][j]!=INF&&i!=j) {
                path[i][j] = i;
            }
            else path[i][j]=-1;
        }
    }

}
void floyd::floydgo() {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            for (int k = 0; k < 9; ++k) {
                if(map[j][k]>map[j][i]+map[i][k]){
                    map[j][k]=map[j][i]+map[i][k];
                    path[j][k]=i;
                }
            }
        }
    }
}

void floyd::find() {
    int e=end;
    st.push(e);
    while (e!=start)
    {
        e=path[start][e];
        st.push(e);
    }
    
}
void floyd::print(){
    while(!st.empty()){
        std::cout<<st.top()<<' ';
        st.pop();
    }
}