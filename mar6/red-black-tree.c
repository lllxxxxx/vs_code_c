#include<stdio.h>
#include<math.h>
#include<stdlib.h>

//1代表red  0代表black

typedef struct node Node;
typedef Node *PtrToNode;

struct node{
    int val;
    int color;
    PtrToNode par;
    PtrToNode left;
    PtrToNode right;
};


PtrToNode newNode(int val,PtrToNode par){
    PtrToNode c = (PtrToNode)malloc(sizeof(Node));
    c->val = val;
    c->par = par;
    c->left = c->right = NULL;
    c->color = 1;
    return c;
}

int inLeaf(PtrToNode p){
    if(p->left==NULL&&p->right)
        return 1;
    return 0;
}

PtrToNode leftRotate(PtrToNode node){
    PtrToNode parent = node->par;
    PtrToNode grand = parent->par;

    parent->right = node->left;
    if(node->left!=NULL){
        node->left->par = parent;
    }
    node->par = grand;
    parent->par = node;
    node->left = parent;
    if(grand!=NULL){
        if(grand->right==parent)
            grand->right = node;
        else
            grand->left = node;
    
    }
    return node;
}

PtrToNode rightRotate(PtrToNode node){
    PtrToNode parent = node->par;
    PtrToNode grand = parent->par;

    parent->left = node->right;
    if(node->right!=NULL){
        node->right->par = parent;
    }
    node->par = grand;
    node->right = parent;
    parent->par = node;
    if(grand!=NULL){
        if(grand->left==parent)
            grand->left = node;
        else
            grand->right = node;
    }
    return node;
}

void checkNode(PtrToNode node){
    if(node==NULL||node->par==NULL){
        return;
    }
    PtrToNode child = node;
    if(node->color==0||(node->par)->color==0){
        return;
    }

    PtrToNode parent = node->par;
    PtrToNode grand = parent->par;

    if(grand==NULL){
        parent->color = 0;
        return;
    }

    if(grand->right!=NULL&&(grand->right)->color==1&&
        grand->left!=NULL&&(grand->left)->color==1){
        (grand->right)->color = 0;
        (grand->left)->color = 0;
        grand->color = 1;
        return;
        }
    else{
        PtrToNode greate = grand->par;
        if(parent->right==parent){
            if(parent->right==node){
                grand->right = parent->left;
                if(parent->left!=NULL){
                    (parent->left)->par = grand;
                }
                parent->left = grand;
                grand->par = parent;

                parent->par = greate;
                if(greate!=NULL){
                    if(greate->left!=NULL&&greate->left==grand){
                        greate->left = parent;
                    }
                    else{
                        greate->right = parent;
                    }
                }
                parent->color = 0;
                grand->color = 1;
            }
            else{
                parent->left = child->right;
                if(child->right!=NULL){
                    (child->right)->par = parent;
                }
                child->right = parent;
                parent->par = child;

                grand->right = child->left;
                if(child->left!=NULL){
                    (child->left)->par = grand;
                }
                child->left = grand;
                grand->par = child;

                child->par = greate;
                if(greate!=NULL){
                    if(greate->left!=NULL&&greate->left==grand){
                        greate->left == child;
                    }
                    else{
                        greate->right = child;
                    }
                }
                child->color = 0;
                grand->color = 1;
            }
        }
        else{
            if(parent->left==node){
                grand->left = parent->right;
                if(parent->right!=NULL){
                    (parent->right)->par = grand;
                }
                parent->right = grand;
                grand->par = parent;

                parent->par = greate;
                if(greate!=NULL){
                    if(greate->left!=NULL&&greate->left==grand){
                        greate->left = parent;
                    }
                    else{
                        greate->right = parent;
                    }
                }
                parent->color = 0;
                grand->color = 1;
            }
            else{
                parent->right = child->left;
                if(child->left!=NULL){
                    (child->left)->par = parent;
                }
                child->left = parent;
                parent->par = child;

                grand->left = child->right;
                if(child->right!=NULL){
                    (child->right)->par = grand;
                }
                child->right = grand;
                grand->par = child;

                child->par = greate;
                if(greate!=NULL){
                    if(greate->left!=NULL&&greate->left==grand){
                        greate->left = child;
                    }
                    else{
                        greate->right = child;
                    }
                }
                child->color = 0;
                grand->color = 1;
            }
        }
    }
}

void insert(int val,PtrToNode *root){
    PtrToNode buffRoot = *root;
    while(buffRoot){
        if(buffRoot->val>val){
            if(buffRoot->left!=NULL){
                buffRoot = buffRoot->left;
            }
            else{
                PtrToNode toInsert = newNode(val, buffRoot);
                buffRoot->left = toInsert;
                buffRoot = toInsert;
                break;
            }
        }
        else{
            if(buffRoot->right!=NULL){
                buffRoot = buffRoot->right;
            }
            else{
                PtrToNode toInsert = newNode(val, buffRoot);
                buffRoot->right = toInsert;
                buffRoot = toInsert;
                break;
            }
        }
    }
    while(buffRoot!=*root){
        checkNode(buffRoot);
        if(buffRoot->par==NULL){
            *root = buffRoot;
            break;
        }
        buffRoot = buffRoot->par;
        if(buffRoot==*root){
            buffRoot->color = 0;
        }
    }
}

void checkForCase2(PtrToNode toDelete,int delete,int fromDirection,PtrToNode *root){
    if(toDelete==(*root)){
        return;
    }

    if(!delete&&toDelete->color==1){
        if(!fromDirection){
            if(toDelete->right!=NULL){
                toDelete->right->color = 1;
            }
        }
        else{
            if(toDelete->left!=NULL){
                toDelete->left->color = 1;
            }
        }
        toDelete->color = 0;
        return;
    }

    PtrToNode sibling;
    PtrToNode parent = toDelete->par;
    int locateChild = 0;
    if(parent->right==toDelete){
        sibling = parent->left;
        locateChild = 1;
    }
    else{
        sibling = parent->right;
    }
    if((sibling->right!=NULL&&sibling->right->color==1)||
    (sibling->left!=NULL&&sibling->left->color==1)){
        if(sibling->right!=NULL&&sibling->right->color==1){
            if(locateChild==1){
                int parColor = parent->color;
                sibling = leftRotate(sibling-> right);
                parent = rightRoate(sibling);
                if(parent->par==NULL){
                    *root = parent;
                }
                parent->color = parColor;
                parent->left->color = 0;
                parent->right->color = 0;
                if(delete){
                    if(toDelete){
                        if(toDelete->left!=NULL){
                            toDelete->left->par = parent->right;
                        }
                        parent->right->right = toDelete->left;
                        free(toDelete);
                    }
                }
                else{
                    int parColor = parent->color;
                    parent = leftRotate(sibling);
                    if(parent->par==NULL){
                        *root = parent;
                    }
                    parent->color = parColor;
                    parent->left->color = 0;
                    parent->right->color = 0;
                    if(delete){
                        if(toDelete->right!=NULL){
                            toDelete->right->par = parent->left;
                        }
                        parent->left->left = toDelete->left;
                        free(toDelete);
                    }
                }
            }
            else{
                int parColor = parent->color;
                parent = rightRotate(sibling);
                if(parent->par==NULL){
                    *root = parent;
                }
                parent->color = parColor;
                parent->left->color = 0;
                parent->right->color = 0;
                if(delete){
                    if(toDelete->left!=NULL){
                        toDelete->left->par = parent->right;
                    }
                    parent->right->right = toDelete->left;
                    free(toDelete);
                }
            }
        }
    }
    else if(sibling->color==0){
         if (locateChild == 0)
            {
                int parColor = parent->color;

                // Step 1: Right rotate sibling
                sibling = rightRotate(sibling->left);

                // printf("%d - reached\n", sibling->val);
                // return;

                // Step 2: Left rotate updated sibling
                parent = leftRotate(sibling);

                // Check if the root is rotated
                if (parent->par == NULL)
                {
                    *root = parent;
                }

                // Step 3: Update the colors
                parent->color = parColor;
                parent->left->color = 0;
                parent->right->color = 0;

                // Delete the node (present at parent->left->left)
                if (delete)
                {
                    if (toDelete->right != NULL)
                    {
                        toDelete->right->par = parent->left;
                    }
                    parent->left->left = toDelete->right;
                    free(toDelete);
                }
            }
            else
            {  // Sibling is left and child is also left. i.e. RIGHT RIGHT
               // ROTATION

                int parColor = parent->color;

                // Right Rotate the sibling
                parent = rightRotate(sibling);

                // Check if the root is rotated
                if (parent->par == NULL)
                {
                    *root = parent;
                }

                // Update Colors
                parent->color = parColor;
                parent->left->color = 0;
                parent->right->color = 0;

                // Delete the node (present at parent->right->right)
                if (delete)
                {
                    if (toDelete->left != NULL)
                    {
                        toDelete->left->par = parent->right;
                    }
                    parent->right->right = toDelete->left;
                    free(toDelete);
                }
            }
        }
    
    else if (sibling->color == 0)
    {  // Make the sibling red and recur for its parent

        // Recolor the sibling
        sibling->color = 1;

        // Delete if necessary
        if (delete)
        {
            if (locateChild)
            {
                toDelete->par->right = toDelete->left;
                if (toDelete->left != NULL)
                {
                    toDelete->left->par = toDelete->par;
                }
            }
            else
            {
                toDelete->par->left = toDelete->right;
                if (toDelete->right != NULL)
                {
                    toDelete->right->par = toDelete->par;
                }
            }
        }

        checkForCase2(parent, 0, locateChild, root);
    }
    else
    {  // Bring the sibling on top and apply 2.1 or 2.2 accordingly
        if (locateChild)
        {  // Right Rotate

            toDelete->par->right = toDelete->left;
            if (toDelete->left != NULL)
            {
                toDelete->left->par = toDelete->par;
            }

            parent = rightRotate(sibling);

            // Check if the root is rotated
            if (parent->par == NULL)
            {
                *root = parent;
            }

            parent->color = 0;
            parent->right->color = 1;
            checkForCase2(parent->right, 0, 1, root);
        }
        else
        {  // Left Rotate

            toDelete->par->left = toDelete->right;
            if (toDelete->right != NULL)
            {
                toDelete->right->par = toDelete->par;
            }
            parent = leftRotate(sibling);

            // Check if the root is rotated
            if (parent->par == NULL)
            {
                *root = parent;
            }

            printf("\nroot - %d - %d\n", parent->val, parent->left->val);

            parent->color = 0;
            parent->left->color = 1;
            checkForCase2(parent->left, 0, 0, root);
        }
    }
}
    
void deleteNode(int val,PtrToNode *root){
    PtrToNode buffRoot = *root;
    while (1) {
        if (val == buffRoot->val){
            break;
        }
        if(val>buffRoot->val){
            if(buffRoot->right!=NULL){
                buffRoot = buffRoot->right;
            }
            else{
                printf("error");
                return;
            }
        }
        else{
            if(buffRoot->left!=NULL){
                buffRoot = buffRoot->left;
            }
            else{
                printf("error");
                return;
            }
        }
    }
    PtrToNode toDelete = buffRoot;

    if(toDelete->left!=NULL){
        toDelete = toDelete->left;
        while(toDelete->right!=NULL){
            toDelete = toDelete->right;
        }
    }
    else if(toDelete->right!=NULL){
        toDelete = toDelete->right;
        while(toDelete->left!=NULL){
            toDelete = toDelete->left;
        }
    }
    if(toDelete==*root){
        *root = NULL;
        return;
    }
    buffRoot->val = toDelete->val;
    toDelete->val = val;
    if(toDelete->color==1||
        (toDelete->left!=NULL&&toDelete->left->color==1)||
        (toDelete->right!=NULL&&toDelete->right->color==1)){
            if(toDelete->left==NULL&&toDelete->right==NULL){
                if(toDelete->par->left==toDelete){
                    toDelete->par->left = NULL;
                }
                else{
                    toDelete->par->right = NULL;
                }
            }
            else{
                    if (toDelete->left != NULL)
                {
                    // The node should be right to its parent
                    toDelete->par->right = toDelete->left;
                    toDelete->left->par = toDelete->par;
                    toDelete->left->color = 1;
                }
                else
                {  // else the right node should be red
                    toDelete->par->left = toDelete->right;
                    toDelete->right->par = toDelete->par;
                    toDelete->right->color = 1;
                }
            }
            free(toDelete);
        }
        else{
            checkForCase2(toDelete, 1,((toDelete->par->right == toDelete)), root);
        }
}