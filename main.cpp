#include <iostream>
#include "binarySearchTree.h"

int main()
{
    BST bsTree;
    bsTree.insert(9);
    bsTree.insert(3);
    bsTree.insert(12);
    bsTree.insert(10);
    bsTree.insert(8);
    bsTree.insert(15);
    bsTree.insert(5);
    bsTree.printLDR();
    return 0;
}
