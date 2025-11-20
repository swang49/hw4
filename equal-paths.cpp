#ifndef RECCHECK
//if you want to add any #includes like <iostream> you must do them here (before the next endif)

#endif

#include "equal-paths.h"
using namespace std;


// You may add any prototypes of helper functions here

// Returns the height if valid, or -1 if mismatch is found.
int checkHeight(Node* root)
{
    if (root == nullptr)
        return 0;

    int lh = checkHeight(root->left);
    int rh = checkHeight(root->right);

    if (lh == -1 || rh == -1)
        return -1;

    if (root->left != nullptr && root->right != nullptr && lh != rh)
        return -1;

    return 1 + (lh > rh ? lh : rh);
}

bool equalPaths(Node * root)
{
    return checkHeight(root) != -1;
}