class MyLinkedList {
    struct Node{
        int val;
        Node *prev;
        Node *next;
        Node(int val):val(val),prev(NULL),next(NULL){}
    };

    Node *head;
    Node *tail;
    int size;

public:
    MyLinkedList() {
        head = new Node(-1);
        tail = new Node(-1);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    
    int get(int index) {
        if(!(index >= 0 && index < size)){
            return -1;
        }
        Node *p = head->next;
        for(int i = 0; i < index; i++){
            p = p->next;
        }
        return p->val;
    }
    
    void addAtHead(int val) {
        Node *p = new Node(val);
        p->next = head->next;
        p->prev = head;
        head->next->prev = p;
        head->next = p;
        size++;
    }
    
    void addAtTail(int val) {
        Node *p = new Node(val);
        p->next = tail;
        p->prev = tail->prev;
        tail->prev->next = p;
        tail->prev = p;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        // 邊界檢查
        if(!(index >= 0 && index <= size)){
            return;
        }
        Node *p = head->next;
        for(int i = 0; i < index ;i++){
            p = p->next;
        }
        Node *tmp = new Node(val);
        tmp->prev = p->prev;
        tmp->next = p;
        p->prev->next = tmp;
        p->prev = tmp;
        size++;
    }
    
    // 邊界檢查
    void deleteAtIndex(int index) {
        if(!(index >= 0 && index < size)){
            return;
        }
        Node *p = head->next;
        for(int i = 0; i < index; i++){
            p = p->next;
        }
        p->prev->next = p->next;
        p->next->prev = p->prev;
        p->next = NULL;
        p->prev = NULL;
        delete p;
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */