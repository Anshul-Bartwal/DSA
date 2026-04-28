#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node* left;
    struct node* right;
    int height;
} *Node;
Node rightRotation(Node node);
Node leftRotation(Node node);
Node leftRightRotation(Node node);
Node rightLeftRotation(Node node);
Node newNode(int val){
    Node new=(Node)malloc(sizeof(struct node));
    new->data=val;
    new->left=new->right=NULL;
    new->height=0;
    // im taking h=-1 for null
    // and h=0 for leaf
    return new;
}
int maxi(int a,int b){

    return a>b?a:b;
}
int getHeight(Node node){
    
    if(node ==NULL){
        return -1;
    }
    
    return node->height;
    // return (1+ maxi(getHeight(node->left),getHeight(node->right)));
}
int getBalanceFactor(Node node){
    if(node == NULL) return 0;
    return getHeight(node->left) - getHeight(node->right);

}

Node insertNode(Node root,int val){
    if (root==NULL){
        Node new=newNode(val);
        return new;
    }
    else if (val<root->data){
        root->left=insertNode(root->left,val);
    }else if(val>root->data){
        root->right=insertNode(root->right,val);
    }
    root->height=(1+ maxi(getHeight(root->left),getHeight(root->right)));
    int bf=getBalanceFactor(root);

    if (getBalanceFactor(root)>1 && getBalanceFactor(root->left)>=0){ // LL imbalance
        root=rightRotation(root);
    }
    else if(getBalanceFactor(root)<-1 && getBalanceFactor(root->right)<=0){ // rr 
        root=leftRotation(root);
    }
    else if (getBalanceFactor(root)>1 && getBalanceFactor(root->left)<0){ // lr : main node is left imb and its left node is right heavy
        root=leftRightRotation(root);
    }
    else if (getBalanceFactor(root)<1 && getBalanceFactor(root->right)>0){
        root=rightLeftRotation(root);
    }
    root->height=(1+ maxi(getHeight(root->left),getHeight(root->right)));

    return root;
}

Node rightRotation(Node node){
    Node y=node->left;
    Node temp=y->right;

    //swapping
    y->right=node;
    node->left=temp;

    y->height=(1+maxi(getHeight(y->left),getHeight(y->right)));
    node->height=(1+maxi(getHeight(node->left),getHeight(node->right)));
    return y;


}

Node leftRotation(Node node){
    Node y=node->right;
    Node temp=y->left;
    
    //swapping
    y->left=node;
    node->right=temp;

    y->height=1+maxi(getHeight(y->left),getHeight(y->right));
    node->height=1+maxi(getHeight(node->left),getHeight(node->right));
    return y;


}

Node leftRightRotation(Node node){
    node->left=leftRotation(node->left);
    return rightRotation(node);

}

Node rightLeftRotation(Node node){
    node->right=rightRotation(node->right);
    return leftRotation(node);
}
void inorder(Node node){
    if(node==NULL){
        return;
    }
    inorder(node->left);
    printf("%d ",node->data);
    inorder(node->right);

}
int main(){
    printf("gi");
    Node head=newNode(10);

    for (int i=0;i<10;i++){
        int val;
        scanf("%d",&val);
        head=insertNode(head,val);
    }

    printf("%d",getHeight(head));
    printf("\n");
    inorder(head);
    return 0;
}