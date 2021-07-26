//
// Created by m0 on 2021/7/26.
//

#ifndef BINARYSEARCHTREE_BST_H
#define BINARYSEARCHTREE_BST_H

//本质现实的是一个查找表
template<typename Key,typename Value>
class BST{

private:
    //二分搜索树中，节点为私有的结构体，外界不需要二分搜索树节点的具体实现
    struct Node{
        Key key;
        Value value;
        Node *left;
        Node *right;

        Node(Key key,Value value){
            this->key=key;
            this-value=value;
            this->left= this->right=NULL;
        }
    };
    Node *root;//根节点
    int count;//节点个数
public:
    // 构造函数, 默认构造一棵空二分搜索树
    BST(){
        root = NULL;
        count = 0;
    }
    //析构函数
    ~BST(){
        //TODO:~BST()
    }
    // 返回二分搜索树的节点个数
    int size(){
        return count;
    }
    // 返回二分搜索树是否为空
    bool isEmpty(){
        return count==0;
    }
    // 向二分搜索树中插入一个新的(key, value)数据对
    void insert(Key key , Value value){
        //重写的重名递归函数
        root = insert(root,key,value);
    }
    // 查看二分搜索树中是否存在键key
    bool contain(Key key){
        return contain(root,key);
    }
    // 在二分搜索树中搜索键key所对应的值。如果这个值不存在, 则返回NULL
    Value* search(Key key){
        return search(root,key);
    }



private:
    // 向以node为根的二分搜索树中, 插入节点(key, value), 使用递归算法
    // 返回插入新节点后的二分搜索树的根
    Node* insert(Node *node,Key key,Value value){
        if(node == NULL){
            count++;
            return new Node(key,value);
        }
        if(key==node->key){
            node->value=value;
        } else if(key<node->key){
            node->left = insert(node->left,key,value);
        } else{ //key>node->key
            node->right = insert(node->right,key,value);
        }
        return node;
    }
    // 查看以node为根的二分搜索树中是否包含键值为key的节点, 使用递归算法
    bool contain(Node* node,Key key){

        if(node==NULL)
            return false;
        if(node->key==key){
            return true;
        } else if(node->key>key){
            return contain(node->left,key);
        } else{
            return contain(node->right,key);
        }
    }
    Value* search(Node* node, Key key){

        if(node==NULL){
            return NULL;
        }
        if(node->key == key){
            return &(node->value);
        }
        if(node->key>key){
            search(node->left,key);
        } else{//node->key<key
            search(node->right,key);
        }
    }


};
#endif //BINARYSEARCHTREE_BST_H
