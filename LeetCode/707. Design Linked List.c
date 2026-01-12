typedef struct Node{
    int val;
    struct Node *prev;
    struct Node *next;
}Node;


typedef struct LinkedList{
    int size;
    Node *head;
    Node *tail;
} MyLinkedList;


MyLinkedList* myLinkedListCreate() {
    // 初始化Linklist
    MyLinkedList *obj = (MyLinkedList *)malloc(sizeof(MyLinkedList));
    // 建立head與tail兩個Node
    obj->head = (Node *)malloc(sizeof(Node));
    obj->tail = (Node *)malloc(sizeof(Node));
    // 初始化head
    obj->head->next = obj->tail;
    obj->head->prev = NULL;
    obj->head->val = -1;
    // 初始化tail
    obj->tail->prev = obj->head;
    obj->tail->next = NULL;
    obj->tail->val = -1;
    // 初始化Linklist的size
    obj->size = 0;
    return obj;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    // 不為邊界內範圍就返回-1
    if(!(index >= 0 && index < obj->size)){
        return -1;
    }
    Node *p = obj->head->next;
    for(int i = 0; i < index; i++){
        p = p->next;
    }
    int val = p->val;
    return val;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    Node *p = obj->head->next;
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = p;
    newNode->prev = obj->head;
    p->prev->next = newNode;
    p->prev = newNode;
    obj->size++;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    Node *p = obj->tail->prev;
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->val = val;
    newNode->prev = p;
    newNode->next = obj->tail;
    p->next->prev = newNode;
    p->next = newNode;
    obj->size++;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    // 不為邊界內範圍就返回
    if(!(index >= 0 && index <= obj->size)){
        return;
    }
    Node *p = obj->head->next;
    for(int i = 0; i < index; i++){
        p = p->next;
    }
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = p;
    newNode->prev = p->prev;
    p->prev->next = newNode;
    p->prev = newNode;
    obj->size++;
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    // 不為邊界內範圍就返回
    if(!(index >= 0 && index < obj->size)){
        return;
    }
    Node *p = obj->head->next;
    for(int i = 0; i < index; i++){
        p = p->next;
    }
    p->next->prev = p->prev;
    p->prev->next = p->next;
    obj->size--;
    free(p);
}

void myLinkedListFree(MyLinkedList* obj) {
    free(obj);
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/