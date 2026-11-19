/***********************************************************************************************************************
* @file: RBTree.hpp
* @brief:标准红黑树模块 
* @date: 2026-11-19
* @update: 
* @author: lightningLW
* @note: 
***********************************************************************************************************************/
#ifndef __RBTREE_HPP__
#define  __RBTREE_HPP__

#include <iostream>

template <typename Key, typename Value>
class RBTree {
public:         //所需要的辅助类型
    enum class Color : uint8_t {
        RED,
        BLACK,
    }; //!enum class Color

    struct Node {
        Key key;
        Value value;
        Color color;
        Node* left;
        Node* right;
        Node* parent;
        Node(Key _key, Value _value) : key(_key), value(_value), color(Color::RED),left(nullptr), right(nullptr), parent(nullptr) {}
    }; //!struct Node

public:
    RBTree() { root = nullptr; }

private:
    Node* root;

    /*
     * @brief: 以x为轴进行左旋
     * @param x: 左旋的轴心;
    */
    void _leftRotate(Node* x);

}; //!class RBTree

template <typename Key, typename Value>
void RBTree<Key, Value>::_leftRotate(Node* x)
{
    Node* y = x->right;
    x->right = y->left;
    if (x->right != nullptr)
    {
        x->right->parent = x;
    }
    y->left = x;
    y->parent = x->parent;
    if (y->parent == nullptr)
    {
        root = y;
    }
    else if (y->parent->left == x)
    {
        y->parent->left = y; 
    }
    else if (y->parent->right == x)
    {
        y->parent->right = y;
    }
    x->parent = y;
    return;
}

#endif // !__RBTREE_HPP__ 

