#ifndef _disjSet_H

#define numset 10

typedef int DisjSet[numset + 1];
typedef int SetType;
typedef int ElementType;

void Init(DisjSet s);
void Union(DisjSet s, SetType root1, SetType root2);
SetType Find(ElementType x, DisjSet s);

#endif