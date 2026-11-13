/***********************************************************************************************************************
* @file: RBTree.cpp
* @brief: 红黑查找树实现模块
* @date: 2026-11-06
* @update:
* @author: lightningLW
* @note: 
***********************************************************************************************************************/
#include "RBTree.h"


void RBTree::_LDR_traverse(const Node* root, std::function<void (const Node*)> func) const
{
    const Node* left = root->left;
    const Node* right = root->right;
    if (root == nullptr)
    {
        return;
    }
    if (left == nullptr && right == nullptr)
    {
        // std::cout << root->val << "\t";
        func(root);
        return;
    }
    if (left != nullptr)
    {
        _LDR_traverse(left, func);
        // std::cout << root->val << "\t";
        func(root);
    }
    else
    {
        func(root);
    }
    if (right != nullptr)
    {
        _LDR_traverse(right, func);
    }

}

std::pair<bool, Node*> RBTree::_insert(int key)
{

}
