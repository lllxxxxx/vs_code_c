#include"queue.h"

struct QueueRecord{
    int Capacity;
    int Front;
    int Rear;
    int Size;
    ElementType *Array;
};

int IsEmpty(Queue q){
    return q->Size == 0;
}

void MakeEmpty(Queue q){
    q->Size = 0;
    q->Front = 1;
    q->Rear = 0;
}

static int Succ(int Value,Queue q){
    if(++Value==q->Capacity){
        Value = 0;
    }
    return Value;
}

void Enqueue(ElementType x,Queue q){
    if(IsFull(q)){

    }else{
        q->Size++;
        q->Rear = Succ(q->Rear, q);
        q->Array[q->Rear] = x;
    }
}
