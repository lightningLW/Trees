/***********************************************************************************************************************
* @file: binarySearchTrss.h
* @brief: 二叉查找树模块
* @date: 2026-10-30
* @update:
* @author: lightningLW
* @note: 
***********************************************************************************************************************/
#ifndef __BINARYSEARCHTREE_H__
#define __BINARYSEARCHTREE_H__

#include <utility>
#include <functional>
#include <iostream>

//二叉查找树节点node
struct BSTnode {
    int val;
    BSTnode* leftTree;
    BSTnode* rightTree;
    BSTnode(int _val) : val(_val), leftTree(nullptr), rightTree(nullptr) {}
}; //!struct BSTnode

class BST {
private:
    BSTnode* root;

    /*
     * @brief: 插入value值到BST中
     * @param value: 插入的值
     * @return: first: 是否插入成功; second: 新插入的节点地址
    */
    std::pair<bool, BSTnode*> insertNode(int value);

    /*
     * @brief: 中序遍历树
     * @param root: 遍历的树的根节点
    */
    void printLDR_traverse(const BSTnode* root) const;

    /*
     * @brief: 根据键值key, 查找节点 递归实现
     * @param root: 以此为根节点向下查找
     * @param key: 所查找的键值
     * @return: 成功, 返回节点的地址; 否则, 返回nullptr.
    */
    const BSTnode* _find_recursive(const BSTnode* root, int key) const;

    /*
     * @brief: 删除节点
     * @param root: 开始查找的根节点
     * @param key: 所要删除的节点的键值
     * @return: 删除节点的父节点
    */
    BSTnode* deleteNode(BSTnode* root, int key);

    /*
     * @brief: 遍历树 左子树-->右子树-->根
     * @param root: 遍历的根节点
     * @param func: 对节点所做的操作
    */
    void LRD_traverse(BSTnode* root, std::function<void (BSTnode*)> func);
public:
    BST() : root(nullptr) {}
    ~BST();

    /*
     * @brief:往二叉查找树插入 @value值
     * @param value: 插入到树中的值
     * @return: first: 插入是否成功; second: 若插入成功, 返回插入节点的地址;否则, 返回nullptr.
    */
    std::pair<bool, BSTnode*> insert(int value)
    {
        return insertNode(value);
    }
    /*
     * @brief: 中序遍历树
    */
    void printLDR() const
    {
        printLDR_traverse(root);
    }

    /*
     * @brief: 根据键值key, 查找节点 迭代实现
     * @param key: 所查找的键值
     * @return: 成功, 返回节点的地址; 否则, 返回nullptr.
    */
    const BSTnode* find_iterate(int key) const;

    /*
     * @brief: 根据键值key, 查找节点 递归实现
     * @param key: 所查找的键值
     * @return: 成功, 返回节点的地址; 否则, 返回nullptr.
    */
    const BSTnode* find_recursive(int key) const
    {
        return _find_recursive(root, key);
    }

    /*
     * @brief: 查找中序前驱节点
     * @param root: 以该节点为根
     * @return: 成功, 返回节点的地址; 否则, 返回nullptr.
    */
    BSTnode* findMax(const BSTnode* root) const;

    /*
     * @brief: 查找中序后继节点
     * @param root: 以该节点为根
     * @return: 成功, 返回节点的地址; 否则, 返回nullptr.
    */
    BSTnode* findMin(const BSTnode* root) const;

    /*
     * @brief: 根据key值删除节点
     * @param key: 键值
    */
    void remove(int key)
    {
        deleteNode(root, key);
    }

    /*
     * @brief: 后根遍历树
     * @param func: 对节点所执行的操作
     * @return: void
    */
    void LRD_dosomething(std::function<void (BSTnode*)> func = [](BSTnode* node) { std::cout << node->val << "\t";})
    {
        LRD_traverse(root, func);
    }
};// !class BST


#endif // !__BINARYSEARCHTREE_H__
