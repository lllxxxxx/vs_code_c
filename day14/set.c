#include"set.h"



void Init(DisjSet s){
    int i;
    for (i = numset; i > 0;i--)
        s[i] = 0;
}

/*Union-by-Height*/
void Union(DisjSet s, SetType root1, SetType root2){
    if(s[root2]<s[root1])
        s[root1] = root2;
    else{
        if(s[root1]==s[root2])
            s[root1]--;
        s[root2] = root1;
    }
}

/*Union-by-Size*/
// void Union( DisjSet S,SetType Root1, SetType Root2)
// { 
//     if ( S[Root2] < S[Root1] ) { /* 如果集合2比较大 */
//         S[Root2] += S[Root1];     /* 集合1并入集合2  */
//         S[Root1] = Root2;
//     }
//     else {                         /* 如果集合1比较大 */
//         S[Root1] += S[Root2];     /* 集合2并入集合1  */
//         S[Root2] = Root1;
//     }
// }

/*路径压缩*/
// SetType Find(ElementType x, DisjSet s){
//     if(s[x]<=0)
//         return x;
//     else
//         return s[x] = Find(s[x], s);
// }

SetType Find(ElementType x, DisjSet s){
    if(s[x]<=0)
        return x;
    else
        return Find(s[x], s);
}

