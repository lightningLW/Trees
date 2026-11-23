#include <iostream>
#include "binarySearchTree.h"
#include "LLRB.h"
#include "RBTree.hpp"

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

#if 0       //@左晴红黑树
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
    llrbTree.LDR_traverse([](const LLRB::Node* x) {
            std::cout << "key: " << static_cast<char>(x->key) << " color: " <<  static_cast<int>(x->color) << std::endl;
            // std::cout << "key: " << (x->key) << " color: " <<  static_cast<int>(x->color) << std::endl;
    });
#endif          //!@左晴红黑树

    RBTree<int, std::string> rbTree;
    using Node = RBTree<int, std::string>::Node;
    rbTree.insert(Node(15, "15"));
    rbTree.insert(Node(9, "9"));
    rbTree.insert(Node(18, "18"));
    rbTree.insert(Node(6, "6"));
    rbTree.insert(Node(13, "13"));
    rbTree.insert(Node(10, "10"));
    rbTree.insert(Node(17, "17"));
    rbTree.insert(Node(27, "27"));
    rbTree.insert(Node(23, "23"));
    rbTree.insert(Node(34, "34"));
    rbTree.insert(Node(37, "37"));
    rbTree.insert(Node(25, "25"));

    // rbTree.remove(18);
    // std::cout << "18" << std::endl;
    // rbTree.LDR();
    //
    // rbTree.remove(25);
    // std::cout << "25" << std::endl;
    // rbTree.LDR();
    //
    // rbTree.remove(15);
    // std::cout << "15" << std::endl;
    // rbTree.LDR();
    //
    // rbTree.remove(6);
    // std::cout << "6" << std::endl;
    // rbTree.LDR();
    //
    // rbTree.remove(13);
    // std::cout << "13" << std::endl;
    // rbTree.LDR();
    //
    // rbTree.remove(37);
    // std::cout << "37" << std::endl;
    // rbTree.LDR();
    //
    // rbTree.remove(27);
    // std::cout << "27" << std::endl;
    // rbTree.LDR();
    //
    // rbTree.remove(17);
    // std::cout << "17" << std::endl;
    // rbTree.LDR();
    //
    // rbTree.remove(34);
    // std::cout << "34" << std::endl;
    // rbTree.LDR();

    // rbTree.remove(9);
    // std::cout << "9" << std::endl;
    // rbTree.LDR();
    //
    // rbTree.remove(10);
    // std::cout << "10" << std::endl;
    // rbTree.LDR();
    //
    // rbTree.remove(23);
    // std::cout << "23" << std::endl;
    // rbTree.LDR();

    // rbTree.LDR();
    // rbTree.remove(8);
    // std::cout << "8" << std::endl;
    // rbTree.LDR();
    // std::cout << std::endl;
    // rbTree.remove(5);
    // std::cout << "5" << std::endl;
    // rbTree.LDR();
    // std::cout << std::endl;
    return 0;
}
