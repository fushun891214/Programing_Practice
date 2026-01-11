class MyCircularQueue {
    struct CircularQueue{
        vector<int> arr;
        int front;
        int rear;
        int count;
        CircularQueue(int size):arr(size),front(0),rear(0),count(0){}
    };

    CircularQueue *q;

public:
    MyCircularQueue(int k) {
        q = new CircularQueue(k);
    }
    
    bool enQueue(int value) {
        if(isFull()){
            return false;
        }
        q->arr[q->rear % q->arr.size()] = value;
        q->rear = (q->rear + 1) % q->arr.size();
        q->count++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()){
            return false;
        }
        q->front = (q->front + 1) % q->arr.size();
        q->count--;
        return true;
    }
    
    int Front() {
        if(isEmpty()){
            return -1;
        }
        return q->arr[q->front];
    }
    
    int Rear() {
        if(isEmpty()){
            return -1;
        }
        return q->arr[(q->rear - 1 + q->arr.size()) % q->arr.size()];
    }
    
    bool isEmpty() {
        return q->count == 0;
    }
    
    bool isFull() {
        return q->count == q->arr.size();
    }
};

// 另一種寫法，比較簡單
// class MyCircularQueue {
// private:
//     vector<int>arr;
//     int front;
//     int rear;
//     int count;

// public:
//     MyCircularQueue(int k) {
//         arr = vector<int>(k);
//         front = 0;
//         rear = 0;
//         count = 0;
//     }
    
//     bool enQueue(int value) {
//         if(isFull()){
//             return false;
//         }
//         arr[rear % arr.size()] = value;
//         rear = (rear + 1) % arr.size();
//         count++;
//         return true;
//     }
    
//     bool deQueue() {
//         if(isEmpty()){
//             return false;
//         }
//         front = (front + 1) % arr.size();
//         count--;
//         return true;
//     }
    
//     int Front() {
//         if(isEmpty()){
//             return -1;
//         }
//         return arr[front];
//     }
    
//     int Rear() {
//         if(isEmpty()){
//             return -1;
//         }
//         return arr[(rear - 1 + arr.size()) % arr.size()];
//     }
    
//     bool isEmpty() {
//         return count == 0;
//     }
    
//     bool isFull() {
//         return count == arr.size();
//     }
// };

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */