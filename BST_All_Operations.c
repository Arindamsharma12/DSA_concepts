#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node * left;
    struct Node * right;
}Node;

Node * create(int val){
    Node * n = (Node *)malloc(sizeof(Node));
    n->data = val;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void inOrder(Node * root){
    if(root != NULL){
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}

int isBST(Node * root){
    static Node * prev = NULL;
    if(root != NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev != NULL && root->data <= prev->data){
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else{
        return 1;
    }
}

Node * search(Node * root, int key){
    if(root == NULL) return NULL;
    if(root->data == key) return root;
    else if(root->data < key) return search(root->right,key);
    else return search(root->left,key);
}

void insert(Node * root, int key){
    Node * prev = NULL;
    while(root != NULL){
        prev = root;
        if(root->data > key) root = root->left;
        else if(root->data < key) root = root->right;
        else printf("Not possible to insert");
    }
    Node * n = create(key);
    if(key > prev->data){
        prev->right = n;
    }
    else{
        prev->left = n;
    }
}

Node * inOrderSucc(Node * root){
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}

Node* delete_node(Node * root,int val){
    if(root == NULL) return NULL;
    if(root->data > val) root->left = delete_node(root->left,val);
    else if(root->data < val) root->right = delete_node(root->right,val);
    else{
        if(root->left == NULL){
            Node * temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            Node * temp = root->left;
            free(root);
            return temp;
        }
        
        Node * temp = inOrderSucc(root->right);
        root->data = temp->data;
        root->right = delete_node(root->right,temp->data);
    }
    return root;
}

int main(){
    Node * root = create(5);
    Node * p1 = create(3);
    Node * p2 = create(1);
    Node * p3 = create(4);
    Node * p4 = create(7);
    Node * p5 = create(6);
    Node * p6 = create(15);

    root->left = p1;
    root->right = p4;
    p1->left = p2;
    p1->right = p3;
    p4->left = p5;
    p4->right = p6;

    inOrder(root);
    printf("\n");
    if(isBST(root)){
        printf("BST");
    }
    else{
        printf("Not BST");
    }
    printf("\n");
    int key = 5;
    if(search(root,key) != NULL){
        printf("%d is found in BST",search(root,key)->data);
    }
    else{
        printf("Not found");
    }

    insert(root,8);
    inOrder(root);
    delete_node(root,3);
    printf("\n");
    inOrder(root);
    return 0;
}
