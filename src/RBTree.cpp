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
    if (root == nullptr)
    {
        root = new Node(key);
        root->color = Color::black;
        return std::make_pair(true, root);
    }
    else
    {
        //HACK: 临时只有一个父节点
        Node* x = new Node(key);
        Node* curNode  = root;
        while (true)
        {
            if (key < curNode->key)
            {
                Node* curLeft = curNode->left;
                if (curNode->left == nullptr)
                {
                    //插入到左链接
                    curNode->left = x;
                    x->parent = curNode;
                    return std::make_pair(true, x);
                }
                else
                {
                    curNode = curLeft;
                }
            }
            else if (key > curNode->key)
            {
                Node* curRight = curNode->right;
                if (curNode->right == nullptr)
                {
                    //插入到右链接
                    Node* tmp = curNode->parent;
                    curNode->right = x;
                    x->parent = curNode;
                    
                    if (tmp == nullptr)
                    {
                        root = rotateLeft(x);
                        root->parent = nullptr;
                        return std::make_pair(true, x);
                    }
                    else if (tmp->left == curNode)
                    {
                        tmp->left = rotateLeft(x);
                        x->parent = tmp;
                        return std::make_pair(true, x);
                    }
                    else
                    {
                        tmp->right = rotateLeft(x);
                        x->parent = tmp;
                        return std::make_pair(true, x);
                    }
                }
                else
                {
                    curNode = curRight;
                }
            }
            else
            {
                return std::make_pair(false, nullptr);
            }
        }
    }

}

Node* RBTree::rotateLeft(Node* x)
{
    Node* x_parent = x->parent;
    x_parent->right = x->left;
    x->left = x_parent;
    x->color = x_parent->color;
    x_parent->color = Color::red;
    return x;
}

Node* RBTree::rotateRight(Node* x)
{
    Node* x_parent = x->parent;
    x_parent->left = x->right;
    x->right = x_parent;
    x->color = x_parent->color;
    x_parent->color = Color::red;
    return x;
}
