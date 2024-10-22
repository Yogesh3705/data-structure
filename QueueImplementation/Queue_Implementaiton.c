typedef struct {
    int* stack1; 
    int* stack2; 
    int top1;   
    int top2;   
    int capacity; 
} MyQueue;

MyQueue* myQueueCreate() {
    MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));
    queue->capacity = 100; 
    queue->stack1 = (int*)malloc(queue->capacity * sizeof(int));
    queue->stack2 = (int*)malloc(queue->capacity * sizeof(int));
    queue->top1 = -1; 
    queue->top2 = -1;
    return queue;
}

void myQueuePush(MyQueue* queue, int x) {
    queue->stack1[++(queue->top1)] = x; 
}


int myQueuePop(MyQueue* queue) {
    if (queue->top2 == -1) { 
        while (queue->top1 != -1) {
            queue->stack2[++(queue->top2)] = queue->stack1[(queue->top1)--];
        }
    }
    return queue->stack2[(queue->top2)--];
}


int myQueuePeek(MyQueue* queue) {
    if (queue->top2 == -1) { 
        while (queue->top1 != -1) {
            queue->stack2[++(queue->top2)] = queue->stack1[(queue->top1)--];
        }
    }
    return queue->stack2[queue->top2]; 
}


bool myQueueEmpty(MyQueue* queue) {
    return queue->top1 == -1 && queue->top2 == -1; 
}


void myQueueFree(MyQueue* queue) {
    free(queue->stack1);
    free(queue->stack2);
    free(queue);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/
