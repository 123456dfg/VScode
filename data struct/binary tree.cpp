#include <iostream>
using namespace std;
template <class DataType>
struct BiNode{
    DataType data;
    BiNode<DataType> *lchild,*rchild;
};
template <class DataType>
class Bitree{
public:
    Bitree(){root= Create(root);};
    ~Bitree(){Release(root);}
    void PreOrder(){PreOrder(root);};// 前序遍历
    void Inorder(){Inorder(root);};// 中序遍历
    void PostOrder(){ PoseOrder(root);};//后序遍历
private:
    BiNode<DataType> *root;
    BiNode<DataType> *Create(BiNode<DataType> *bt);
    void Release(BiNode<DataType>* bt);
    void PreOrder(BiNode<DataType> *bt);
    void InOrder(BiNode<DataType> *bt);
    void PoseOrder(BiNode<DataType> *bt);
};
template <class DataType>
BiNode<DataType> *Bitree<DataType>::Create(BiNode<DataType> *bt) {
    DataType ch;
    cin>>ch;
    if(ch=='#')
        bt=NULL;
    else{
        bt=new BiNode<DataType>;
        bt->data=ch;
        bt->lchild= Create(bt->lchild);
        bt->rchild= Create(bt->rchild);
    }
    return bt;
}
template <class DataType>
void Bitree<DataType>::PreOrder(BiNode<DataType> *bt) {
    if(bt==NULL)return;
    else {
        cout<<bt->data<<' ';
        PreOrder(bt->lchild);
        PreOrder(bt->rchild);
    }
}
template <class DataType>
void Bitree<DataType>::InOrder(BiNode<DataType> *bt) {
    if(bt==NULL)return;
    else {
        InOrder(bt->lchild);
        cout<<bt->data<<' ';
        InOrder(bt->rchild);
    }
}
template <class DataType>
void Bitree<DataType>::PoseOrder(BiNode<DataType> *bt) {
    if(bt==NULL)return ;
    else {
        PoseOrder(bt->lchild);
        PoseOrder(bt->rchild);
        cout<<bt->data<<' ';
    }
}
template <class DataType>
void Bitree<DataType>::Release(BiNode<DataType> *bt) {
    if(bt!= NULL){
        Release(bt->lchild);
        Release(bt->rchild);
        delete bt;
    }
}
int main(){
    Bitree<char> bt;
    bt.PreOrder();
    return 0;
}