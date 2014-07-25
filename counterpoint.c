#include <stdlib.h>

typedef struct note note;
struct note {
    int pitch;
    int interval;
};

typedef struct node node;
struct node {
    note values;
    node *children;
    unsigned int numChildren;
    struct node *parent;
};

void newNode(node *new, node *parent){
    new = malloc(sizeof(node));
    new->values.pitch = 0;
    new->values.interval = 0;
    new->children = NULL;
    new->numChildren = 0;
    new->parent = parent;
}

//void copyNode(node final, node *source){
//    final.values = source->values;
//    final.children = source->children;
//    final.numChildren = source->numChildren;
//    final.parent = source->parent;
//}

// do not pass in an unallocated node
void addNode(node *parent, node *newNode){
    if(parent->numChildren){
        // backup CHILDREN into temp array
        node backupChildren[parent->numChildren];
        for(int i = 0; i < parent->numChildren; i++)
            backupChildren[i] = parent->children[i];
        // delete CHILDREN
        free(parent->children);
        // re-allocate + 1
        parent->numChildren = parent->numChildren + 1;
        parent->children = malloc( sizeof(node)*(parent->numChildren) );
        // fill again
        for(int i = 0; i < parent->numChildren; i++)
            parent->children[i] = backupChildren[i];
        parent->children[parent->numChildren-1] = newNode[0];
//        copyNode(tree->children[tree->numChildren-1], newNode);
//        tree->children[tree->numChildren-1] = newNode;
    }
}

void counterpoint(int *cantusFirmus, int count, node *cp, int startingInterval){
    newNode(cp, NULL);
    
    for(int i = 0; i < count; i++){
        
    }
}