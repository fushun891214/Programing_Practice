typedef struct CircularDeque{
    int arrSize;
    int *arr;
    int front;
    int rear;
    int count;
} MyCircularDeque;


MyCircularDeque* myCircularDequeCreate(int k) {
    MyCircularDeque *obj = (MyCircularDeque *)malloc(sizeof(MyCircularDeque));
    obj->arrSize = k;
    obj->arr = (int *)malloc(obj->arrSize * sizeof(int));
    obj->front = 0;
    obj->rear = 0;
    obj->count = 0;
    return obj;
}

bool myCircularDequeIsEmpty(MyCircularDeque* obj) {
    return obj->count == 0;
}

bool myCircularDequeIsFull(MyCircularDeque* obj) {
    return obj->count == obj->arrSize;
}

bool myCircularDequeInsertFront(MyCircularDeque* obj, int value) {
    if(myCircularDequeIsFull(obj)){
        return false;
    }
    obj->front = (obj->front - 1 + obj->arrSize) % obj->arrSize;
    obj->arr[obj->front] = value;
    obj->count++;
    return true;
}

bool myCircularDequeInsertLast(MyCircularDeque* obj, int value) {
    if(myCircularDequeIsFull(obj)){
        return false;
    }
    obj->arr[obj->rear] = value;
    obj->rear = (obj->rear + 1) % obj->arrSize;
    obj->count++;
    return true;
}

bool myCircularDequeDeleteFront(MyCircularDeque* obj) {
    if(myCircularDequeIsEmpty(obj)){
        return false;
    }
    obj->front = (obj->front + 1) % obj->arrSize;
    obj->count--;
    return true;
}

bool myCircularDequeDeleteLast(MyCircularDeque* obj) {
    if(myCircularDequeIsEmpty(obj)){
        return false;
    }
    obj->rear = (obj->rear - 1 + obj->arrSize) % obj->arrSize;
    obj->count--;
    return true;
}

int myCircularDequeGetFront(MyCircularDeque* obj) {
    if(myCircularDequeIsEmpty(obj)){
        return -1;
    }
    int val = obj->arr[obj->front];
    return val;
}

int myCircularDequeGetRear(MyCircularDeque* obj) {
    if(myCircularDequeIsEmpty(obj)){
        return -1;
    }
    int rearPos = (obj->rear - 1 + obj->arrSize) % obj->arrSize;
    int val = obj->arr[rearPos];
    return val;
}

void myCircularDequeFree(MyCircularDeque* obj) {
    free(obj);
}

/**
 * Your MyCircularDeque struct will be instantiated and called as such:
 * MyCircularDeque* obj = myCircularDequeCreate(k);
 * bool param_1 = myCircularDequeInsertFront(obj, value);
 
 * bool param_2 = myCircularDequeInsertLast(obj, value);
 
 * bool param_3 = myCircularDequeDeleteFront(obj);
 
 * bool param_4 = myCircularDequeDeleteLast(obj);
 
 * int param_5 = myCircularDequeGetFront(obj);
 
 * int param_6 = myCircularDequeGetRear(obj);
 
 * bool param_7 = myCircularDequeIsEmpty(obj);
 
 * bool param_8 = myCircularDequeIsFull(obj);
 
 * myCircularDequeFree(obj);
*/