#include<iostream>

typedef struct Node{
    int val;
    struct Node *next;
}Node;

void initLinklist(Node *head,int n){
    Node *p = head;
    for(int i = 0; i < n; i++){
        Node *tmp = new Node();
        tmp->val = i;
        tmp->next = NULL;
        p->next = tmp;
        p = p->next;
    }
}

void printLinklist(Node *head){
    Node *p = head->next;
    while(p != NULL){
        std::cout << p->val << " ";
        p = p->next;
    }
    std::cout << std::endl;
}

void reverseLinklist(Node *head){
    Node *p = head->next;
    Node *q = p->next;
    p->next = NULL;
    while(q != NULL){
        Node *tmp = q->next;
        q->next = p;
        p = q;
        q = tmp;
    }
    head->next = p;
}

int main(){
    Node *dummy = new Node();
    dummy->val = -1;
    dummy->next = NULL;
    int n = 10;

    initLinklist(dummy,n);
    printLinklist(dummy);
    reverseLinklist(dummy);
    printLinklist(dummy);

    return 0;
}