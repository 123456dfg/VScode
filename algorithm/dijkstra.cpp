#include<iostream>
#include<queue>
#include<map>
#include "vector"
#include "queue"
#include "stack"
const int INF=2500;
class travel
{
private:

public:
    int map[9][9];
    int dist[550];
    bool visited[550]={false};
    bool visitedlink[9][9];//邻接矩阵
    void dijkstra(int,int);
    void searchPoint();
    void init(int,int);
    void pointSearch(int ,int );
    int prev[9];
};


int main(){
    travel trl;
    int start=2,end=7;
    trl.init(start,end);
    trl.dijkstra(start,end);
    //trl.searchPoint();
    int pre=end;
    std::stack<int>st;
    while(1){
        if(pre==start){
            st.push(pre);
            break;
        }
        st.push(pre);
        pre=trl.prev[pre];
    }
    while (!st.empty()){
        std::cout<<st.top()<<"->";
        st.pop();
    }
    return 0;
}
void travel::dijkstra(int start,int end){
    for (int i = 0; i < 9; i++)
    {
        int index=-1;
        dist[start]=0;
        for (int j = 0; j < 9; j++)
        {
            if(!visited[j]&&(index==-1||dist[j]<dist[index])){
                index=j;

            }
        }
        visited[index]=true;
        for (int j = 0; j < 9; j++)
        {
            if(visited[j]== false&&dist[index]+map[index][j]<dist[j]){
                dist[j]=dist[index]+map[index][j];
                prev[j]=index;
            }

        }

    }
    std::cout<<dist[end]<<std::endl;

    if (dist[end]==INF)
    {
        //std::cout<<-1;
        return;
    }


}

void travel::init(int start,int end){
    for (int i = 0; i < 9; ++i) {
        prev[i]=-1;
    }
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if(i==j) {
                visitedlink[i][j] = true;
                continue;
            }
            visitedlink[i][j]= false;
        }
    }

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if(i==j)map[i][j]=0;
            else map[i][j]=INF;
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
        dist[i]=INF;
    }

}


