#include <iostream>
#include "binarySearchTree.h"

int main()
{
    BST bsTree;
    std::pair<bool, BSTnode*> rt;
    bsTree.insert(9);
    bsTree.insert(3);
    bsTree.insert(12);
    bsTree.insert(10);
    bsTree.insert(8);
    bsTree.insert(15);
    bsTree.insert(5);
    rt = bsTree.insert(11);
    if (rt.first)
    {
        std::cout << "insert " << rt.second->val << " success!" << std::endl;
    }
    bsTree.printLDR();
    return 0;
}
