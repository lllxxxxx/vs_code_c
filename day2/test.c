#include"stack1.h"

int main(void){
    Stack s = CreteStack();
    int a = IsEmpty(s);
    Push(1, s);
    Push(2, s);
    Push(3, s);
    PrintAll(s);
}