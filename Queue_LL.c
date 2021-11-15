#include <stdio.h>
#include <stdlib.h>

struct n{
    int data;
    struct n *next;
};
typedef struct n node;

node *root=NULL;
node *son=NULL;

void ekle(int veri){
    if(root==NULL){
        root = (node *)malloc(sizeof(node));
        root->data=veri;
        root->next=NULL;
        son = root;
    } else {
        son->next= (node *)malloc(sizeof(node));
        son->next->data=veri;
        son = son->next;
        son->next=NULL;

    }
}

int cikart(){
    if(root==NULL){
        printf("Sira zaten bos!");
        return 0;
    }
    int rvalue=root->data;
    node *temp = root;
    root = root->next;
    free(temp);
    return rvalue;
}

int main(){
    int i;
    for(i=0;i<=20;i++){
        ekle(i*10);
    }

    for (i=0;i<=10;i++){
        printf("%d ",cikart());
    }
    return 0;
}