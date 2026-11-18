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
    // Node* x_parent_parent = x_parent->parent;
    Node* x_left = x->left;

    x_parent->parent = x;
    x_parent->right = x_left;

    // x_left->parent = x_parent;
    if (x_left != nullptr)
    {
        x_left->parent = x_parent;
    }

    x->left = x_parent;
    // x->parent = x_parent_parent;

    x->color = x_parent->color;
    x_parent->color = Color::red;

    return x;
}

Node* RBTree::rotateRight(Node* x)
{
    Node* xParent = x->parent;
    // Node* xParentP = xParent->parent;
    Node* xRight = x->right;

    xParent->parent = x;
    xParent->left = xRight;

    // xRight->parent = xParent;
    if (xRight != nullptr)
    {
        xRight->parent = xParent;
    }
    // x->parent = xParentP;
    x->right = xParent;

    x->color = xParent->color;
    xParent->color = Color::red;

    return x;
}

void RBTree::transform2RBTree(Node* x)
{
    // std::cout << static_cast<char>(x->key) << std::endl;
    if (x == root)
    {
        x->color = Color::black;
    }
    else
    {
        if (x->parent->color == Color::red)
        {
            if (leftORrightChild(x) == 0)
            {
                return;
            }
            else if (leftORrightChild(x) == 1)
            {
                int i = leftORrightChild(x->parent->parent);
                Node* tmp = x->parent->parent->parent;
                rotateRight(x->parent);
                if (i == 0)
                {
                    x->parent->left->color = Color::black;
                    x->parent->right->color = Color::black;
                    x->parent->parent = nullptr;
                    root = x->parent;
                    return;
                }
                else if (i == 1)
                {
                    tmp->left = x->parent;
                    x->parent->parent = tmp;
                    x->parent->color = Color::red;
                    x->parent->left->color = Color::black;
                    x->parent->right->color = Color::black;
                    transform2RBTree(x->parent);
                }
                else
                {
                    tmp->right = x->parent;
                    x->parent->parent = tmp;
                    x->parent->color = Color::red;
                    x->parent->left->color = Color::black;
                    x->parent->right->color = Color::black;
                    transform2RBTree(x->parent);
                }
            }
            else
            {
                int i = leftORrightChild(x->parent);
                Node* tmp = x->parent->parent;
                rotateLeft(x);
                if (i == 0)
                {
                    x->parent = nullptr;
                    x->color = Color::black;
                    root = x;
                    return;
                }
                else if (i == 1)
                {
                    tmp->left = x;
                    x->parent = tmp;
                    transform2RBTree(x->left);
                }
                else
                {
                    tmp->right = x;
                    x->parent = tmp;
                    std::cout << x->left->key << std::endl;
                    transform2RBTree(x->left);
                }

            }
        }
        else            //x->parent->color == black
        {
            int i = leftORrightChild(x);
            if (i == 0)
            {
                x->color = Color::black;
                return;
            }
            else if (i == 1)                            //第1种情况: 插入的节点是左孩子
            {
                return;
            }
            else
            {
                Node* x_parent = x->parent;
                Node* x_leftBro = x_parent->left;
                if (x_leftBro != nullptr && x_leftBro->color == Color::red)     //第2种情况: 插入的节点是右孩子, 且插入节点的左兄弟是红孩子
                {
                    x_leftBro->color = Color::black;
                    x->color = Color::black;
                    x_parent->color = Color::red;
                    transform2RBTree(x_parent);
                }
                else                                    //第3种情况: 插入的节点是右孩子, 且插入节点的左兄弟是黑孩子
                {
                    // std::cout << static_cast<char>(x->key) << std::endl;
                    int j = leftORrightChild(x_parent);
                    Node* x_parent_parent = x_parent->parent;
                    rotateLeft(x);
                    if (j == 0)
                    {
                        x->parent = x_parent_parent;
                        root = x;
                        return;
                    }
                    else if (j == 1)
                    {
                        x_parent_parent->left = x;
                        x->parent = x_parent_parent;
                        return;
                    }
                    else
                    {
                        x_parent_parent->right = x;
                        x->parent = x_parent_parent;
                        return;
                    }
                }
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
