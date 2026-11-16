/***********************************************************************************************************************
* @file: RBTree.h
* @brief: 红黑查找树模块
* @date: 2026-11-06
* @update:
* @author: lightningLW
* @note: 
***********************************************************************************************************************/
#ifndef __RBTREE_H__
#define __RBTREE_H__

#include <iostream>
#include <functional>

enum class Color {
    red,
    black
}; // !enum class Color

struct Node {
    int key;
    Color color;
    Node* left;
    Node* right;
    Node* parent;
    Node(int _key) : key(_key), color(Color::red), left(nullptr), right(nullptr), parent(nullptr) {}
}; //!struct Node

class RBTree {
private:
    Node* root;
    /*
     * @brief: 中序遍历树
     * @param root: 遍历的根节点
     * @param func: 对当前节点所执行的操作
     * @return: void
     */
    void _LDR_traverse(const Node* root, std::function<void (const Node*)> func = [](const Node* node) { std::cout << node->key << '\t';}) const;
    /*
     * @brief: 插入键值为key的节点
     * @param key: 键值
     * @return: std::pair<bool, Node*> first-->插入是否成功; second-->指向插入节点
     * @note: 只管插入节点, 不负责颜色和旋转等
    */
    std::pair<bool, Node*> _insert(int key);
    /*
     * @brief: 左旋转
     * @param x: 旋转的子节点
     * @return Node*: 旋转后的父节点
    */
    Node* rotateLeft(Node* x);
    /*
     * @brief: 右旋转
     * @param x: 旋转的子节点
     * @return Node*: 旋转后的父节点
    */
    Node* rotateRight(Node* x);
    /*
     * @brief: 对插入的节点进行旋转操作, 使其符合红黑树的性质
     * @param x: 新插入的节点
     * @return: void
    */
    void transform2RBTree(Node* x);
    /*
     * @brief:判断一个节点是左孩子还是右孩子
     * @param x: 待判定的节点
     * @return int: 0:表示无父节点; 1表示是左孩子; 2表示是右孩子
    */
    int leftORrightChild(const Node* x) const; 
public:
    RBTree() : root(nullptr) {}
    //TODO: : 析构函数 delete节点 
    ~RBTree() {}
    void LDR_traverse(std::function<void (const Node*)> func = [](const Node* node) { std::cout << node->key << '\t';}) const
    {
        _LDR_traverse(root, func);
    }
    std::pair<bool, Node*> insert(int key)
    {
        auto res = _insert(key);
        if (res.first)
        {
            transform2RBTree(res.second);
        }
        else
        {
            std::cout << "insert fail!" << std::endl;
        }
        return res;
    }
}; // !class RBTree

#endif // !__RBTREE_H__
