#include <iostream>
#include "binarySearchTree.h"
#include "RBTree.h"

int main()
{
#if 0 // @二叉搜索树BST
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

    // bsTree.remove(9);

    // bsTree.printLDR();
    // std::cout << std::endl;
#endif  // !@二叉搜索树BST

    RBTree rbTree;
    rbTree.insert(10);
    rbTree.insert(8);
    rbTree.insert(9);
    rbTree.LDR_traverse([](const Node* x) {
            std::cout << "key: " << x->key << " color: " <<  static_cast<int>(x->color) << std::endl;
    });

    return 0;
}
