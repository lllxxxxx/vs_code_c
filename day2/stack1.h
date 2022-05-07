#ifndef _Stack_h

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;
typedef int ElementType;

int IsEmpty(Stack s);
Stack CreteStack(void);
void DisposeStack(Stack s);
void MakeEmpty(Stack s);
void Push(ElementType x, Stack s);
ElementType Top(Stack s);
void Pop(Stack s);
void PrintAll(Stack s);

#endif
