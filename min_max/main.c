#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


// Global variable
// Update the array nodes
int counter = 0;

// struct node
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;


// Create minimax game tree
node *createTree(int x,int D,int d) {
    node *p;

    // no expand
    if (x <= 0) {
        p = (node *)malloc(sizeof(node));
        p->data = x;
        p->left = NULL;
        p->right = NULL;
        return p;
    }

    // expand
    p = (node *) malloc(sizeof(node));
    p->data = x;
    p->left = createTree(x - d,D,d);
    p->right = createTree(x - D,D,d);

    return p;
}


// Get the level on tree from a specific node
int getLevelCount(node *node) {

    if (node->left == NULL && node->right== NULL) {
        return 0;
    }

    int leftMaxLevel = 1 + getLevelCount(node->left);
    int rightMaxLevel = 1 + getLevelCount(node->right);
    if (leftMaxLevel > rightMaxLevel) {
        return leftMaxLevel;
    } else {
        return rightMaxLevel;
    }

}


// Get the values of level k of tree ( assign to array nodes )
void printKDistant(struct node *root,int k,struct node *nodes) {
    if (root == NULL) // if node has not child, stop the recursion!!!
        return;
    if (k == 0) { // get the value of node , add to array nodes
        nodes[counter].data = root->data;
        nodes[counter].right = root->right;
        nodes[counter].left = root->left;
        counter++;
        return;
    }
    else {
        printKDistant(root->left, k - 1,nodes);
        printKDistant(root->right, k - 1,nodes);
    }
}


int main() {

    node *root;

    int A,D,d;

    // Read A,D,d
    printf("Please enter the distance(A) between of two players :");
    scanf(" %d", &A);

    printf("\nPlease enter the variable D: ");
    scanf(" %d", &D);

    printf("\nPlease enter the variable d: ");
    scanf(" %d", &d);

    // Create the mini max game tree
    root = createTree(A,D,d);

    //Get the level of tree
    int levels = getLevelCount(root);

    int player = 1;

    //Player1 is maximizer
    //Player2 is minimizer

    for (int i = levels-1; i >= 0; i--){

        if (i % 2 == 0) {
            printf("Level %d: Player 1 is playing\n", i);
            player = 1;
        }
        else if (i % 2 == 1) {
            printf("Level %d: Player 2 is playing\n", i);
            player = 2;
        }

        counter = 0;

        // initialize array nodes
        int size = pow(2,i);
        struct node nodes[size];
        memset(nodes,-1, sizeof(nodes));

        // get the values for (i+1)th level of tree
        printKDistant(root,i,nodes);

        for (int j = 0; j < size; j++) {

            if (nodes[j].data > 0) {
                printf("Node: %d , Distance: %d",j+1, nodes[j].data);

                if (player == 1) {
                    if (nodes[j].left->data > nodes[j].right->data) {
                        printf(" , optimal move : d\n");
                    } else {
                        printf(" , optimal move : D\n");
                    }
                }
                if (player == 2) {
                    if (nodes[j].left->data > nodes[j].right->data) {
                        printf(" , optimal move : D\n");
                    } else {
                        printf(" , optimal move : d\n");
                    }
                }

            }


        }
        printf("\n");
    }

    free(root);
    return 0;
}
