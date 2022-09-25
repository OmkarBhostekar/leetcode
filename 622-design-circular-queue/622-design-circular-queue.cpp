class MyCircularQueue {
public:
    int front=0,rear=-1,size;
    vector<int> v;
    MyCircularQueue(int k) {
        v.resize(k);
        size = k;
    }
    bool enQueue(int val) {
        if (isFull()) return false;
        rear = (rear + 1) % size;
        v[rear] = val;
        return true;
    }
    bool deQueue() {
        if (isEmpty()) return false;
        if (front == rear) front = 0, rear = -1;
        else front = (front + 1) % size;
        return true;
    }
    int Front() {
        return isEmpty() ? -1 : v[front];
    }
    int Rear() {
        return isEmpty() ? -1 : v[rear];
    }
    bool isEmpty() {
        return rear == -1;
    }
    bool isFull() {
        return !isEmpty() && (rear + 1) % size == front;
    }
};

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