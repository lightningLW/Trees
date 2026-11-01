#include <iostream>
#include "binarySearchTree.h"

int main()
{
    BST bsTree;
    auto rt = bsTree.insert(9);
    bsTree.insert(3);
    bsTree.insert(12);
    bsTree.insert(10);
    bsTree.insert(8);
    bsTree.insert(15);
    bsTree.insert(5);

    // const BSTnode* node = bsTree.find_recursive(11);
    // if (node != nullptr)
    // {
    //     std::cout << "is find!" <<  node->val << std::endl;
    // }
    // else
    // {
    //     std::cout << "not find!" << std::endl;
    // }

    // BSTnode* node = bsTree.findMin(rt.second);
    // std::cout << node->val << std::endl;

    bsTree.remove(9);

    bsTree.printLDR();


    return 0;
}
