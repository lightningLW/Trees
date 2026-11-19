#include <iostream>
#include "binarySearchTree.h"
#include "LLRB.h"

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

    LLRB llrbTree;
    // llrbTree.insert('s');
    llrbTree.insert('s');
    llrbTree.insert('e');
    llrbTree.insert('a');
    llrbTree.insert('r');
    llrbTree.insert('c');
    llrbTree.insert('h');
    llrbTree.insert('x');
    llrbTree.insert('m');
    llrbTree.insert('p');
    llrbTree.insert('l');
    LLRB* p_llrbTree = new LLRB;
    p_llrbTree->insert('a');
    p_llrbTree->insert('c');
    p_llrbTree->insert('e');
    p_llrbTree->insert('h');
    p_llrbTree->insert('l');
    p_llrbTree->insert('m');
    p_llrbTree->insert('p');
    p_llrbTree->insert('r');
    p_llrbTree->insert('s');
    p_llrbTree->insert('x');
    delete p_llrbTree;
    llrbTree.LDR_traverse([](const Node* x) {
            std::cout << "key: " << static_cast<char>(x->key) << " color: " <<  static_cast<int>(x->color) << std::endl;
            // std::cout << "key: " << (x->key) << " color: " <<  static_cast<int>(x->color) << std::endl;
    });

    return 0;
}
