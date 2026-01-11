class MyCircularDeque {
    struct CircularDeque{
        vector<int> arr;
        int start;
        int end;
        int count;
        CircularDeque(int size):arr(size),start(0),end(0),count(0){}
    };

    CircularDeque *q;

public:
    MyCircularDeque(int k) {
       q = new CircularDeque(k);
    }
    
    bool insertFront(int value) {
        if(isFull()){
            return false;
        }
        q->start = (q->start - 1 + q->arr.size()) % q->arr.size();
        q->arr[q->start] = value;
        q->count++;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()){
            return false;
        }
        q->end = (q->end + 1 + q->arr.size()) % q->arr.size();
        q->arr[(q->end - 1 + q->arr.size()) % q->arr.size()] = value;
        q->count++;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()){
            return false;
        }
        q->start = (q->start + 1 + q->arr.size()) % q->arr.size();
        q->count--;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()){
            return false;
        }
        q->end = (q->end - 1 + q->arr.size()) % q->arr.size();
        q->count--;
        return true;
    }
    
    int getFront() {
        if(isEmpty()){
            return -1;
        }
        return q->arr[q->start];
    }
    
    int getRear() {
        if(isEmpty()){
            return -1;
        }
        return q->arr[(q->end - 1 + q->arr.size()) % q->arr.size()];
    }
    
    bool isEmpty() {
        return q->count == 0;
    }
    
    bool isFull() {
        return q->count == q->arr.size();
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */