#include <stdio.h>

int cantusFirmus[10] = {1, 3, 2, 4, 3, 5, 4, 3, 2, 1};

typedef struct node node;
struct node {
    node *children;
    unsigned int numChildren;
    struct node *parent;
};

// do not pass in an unallocated node
void addNode(node *n){
    if(n->numChildren){
        node newList[n->numChildren];
        for(int i = 0; i < n->numChildren; i++)
            newList[i] = n->nodes[i];
        free(n->nodes);
        n->nodes = malloc( sizeof(node)*(n->numChildren+1) );
        for(int i = 0; i < n->numChildren; i++)
            n->nodes[i] = newList[i];
    }
}

void counterpoint(int *cf, node *cp, int beginning, int count){
    node *intervals = malloc(sizeof(node));
    cp = malloc(sizeof(node));
    
    for(int i = 0; i < count; i++){
        
    }
}