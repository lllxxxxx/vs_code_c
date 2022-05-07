#ifndef _AVL_H

struct AvlNode;
typedef struct AvlNode *Position;
typedef struct AvlNode *AvlTree;
typedef int ElementType;

AvlTree MakeEmpty(AvlTree t);
Position Find(ElementType x, AvlTree t);
Position FindMin(AvlTree t);
Position FindMax(AvlTree t);
AvlTree Insert(ElementType x, AvlTree t);
AvlTree Delete(ElementType x, AvlTree t);
ElementType Retrieve(Position p);

#endif

