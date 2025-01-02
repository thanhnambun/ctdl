#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(int data){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
Node *insert(Node *root, int data){
    if (root->data == NULL)
    {
        return createNode(data);
    }
    if (root->data < data)
    {
        root->right = insert(root->right, data);
    }else if (root->data > data)
    {
        root->left = insert(root->left, data);
    }
    return root;
}
void preOder(Node *root){
    if (root->data == NULL)
    {
        return;
    }
    printf("%d", root->data);
    preOder(root->left);
    preOder(root->right);
}
void inOder(Node *root)
{
    if (root->data == NULL)
    {
        return;
    }
    preOder(root->left);
    printf("%d", root->data);
    preOder(root->right);
}
void postOder(Node *root)
{
    if (root->data == NULL)
    {
        return;
    }
    preOder(root->left);
    preOder(root->right);
    printf("%d", root->data);
}
int main(){
    Node *root = NULL;
    int n, data, i;
    printf("Nh?p s? lu?ng ph?n t? mu?n chèn vào cây: ");
    scanf("%d", &n);
    printf("Nh?p các giá tr?:\n");
    for (i = 0; i < n; i++)
    {
        printf("Ph?n t? %d: ", i + 1);
        scanf("%d", &data);
        root = insert(root, data);
    }
    preOder(root);
    inOder(root);
    postOder(root);
    return 0;
}
