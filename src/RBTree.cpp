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
    Node* x = new Node(key);
    if (root == nullptr)
    {
        root = x;
        return std::make_pair(true, x);
    }
    else
    {
        Node* curNode = root;
        while (true)
        {
            if (key < curNode->key)
            {
                if (curNode->left == nullptr)
                {
                    curNode->left = x;
                    x->parent = curNode;
                    return std::make_pair(true, x);
                }
                else
                {
                    curNode = curNode->left;
                }
            }
            else if (key > curNode->key)
            {
                if (curNode->right == nullptr)
                {
                    curNode->right = x;
                    x->parent = curNode;
                    return std::make_pair(true, x);
                }
                else
                {
                    curNode = curNode->right;
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

void RBTree::transform2RBTree(Node* x)
{
    if (x == root)
    {
        x->color = Color::black;
    }
    else
    {
        if (x->parent->color == Color::red)
        {
        }
        else            //x->parent->color == black
        {
            if (leftORrightChild(x) == 0)
            {
                return;
            }
            else if (leftORrightChild(x) == 1)
            {
                return;
            }
            else
            {
                Node* tmp = x->parent->parent;
                if (leftORrightChild(x->parent) == 0)
                {
                    rotateLeft(x);
                    x->parent = nullptr;
                }
                else if (leftORrightChild(x->parent) == 1)
                {
                    tmp->left = rotateLeft(x);

                }
                else
                {}
            }
        }
    }
}

int RBTree::leftORrightChild(const Node* x) const
{
    const Node* x_parent = x->parent;
    if (x_parent == nullptr)
    {
        return 0;
    }
    else
    {
        if (x_parent->left == x)
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }
}
