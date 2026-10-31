/***********************************************************************************************************************
* @file: binarySearchTrss.h
* @brife: 二叉查找树模块
* @date: 2026-10-30
* @update:
* @author: lightningLW
* @note: 
***********************************************************************************************************************/
#ifndef __BINARYSEARCHTREE_H__
#define __BINARYSEARCHTREE_H__

#include <utility>

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
     * @brife: 插入value值到BST中
     * @param value: 插入的值
     * @return: first: 是否插入成功; second: 新插入的节点地址
    */
    std::pair<bool, BSTnode*> insertNode(int value);

    /*
     * @brife: 中序遍历树
     * @param root: 遍历的树的根节点
    */
    void printLDR_traverse(const BSTnode* root) const;

    /*
     * @brife: 根据键值key, 查找节点 递归实现
     * @param root: 以此为根节点向下查找
     * @param key: 所查找的键值
     * @return: 成功, 返回节点的地址; 否则, 返回nullptr.
    */
    const BSTnode* _find_recursive(const BSTnode* root, int key) const;

    /*
     * @brife: 删除节点
     * @param root: 开始查找的根节点
     * @param key: 所要删除的节点的键值
     * @return:
    */
    BSTnode* deleteNode(BSTnode* root, int key);
public:
    BST() : root(nullptr) {}
    //TODO: ~BST()

    /*
     * @brife:往二叉查找树插入 @value值
     * @param value: 插入到树中的值
     * @return: first: 插入是否成功; second: 若插入成功, 返回插入节点的地址;否则, 返回nullptr.
    */
    std::pair<bool, BSTnode*> insert(int value)
    {
        return insertNode(value);
    }
    /*
     * @brife: 中序遍历树
    */
    void printLDR() const
    {
        printLDR_traverse(root);
    }

    /*
     * @brife: 根据键值key, 查找节点 迭代实现
     * @param key: 所查找的键值
     * @return: 成功, 返回节点的地址; 否则, 返回nullptr.
    */
    const BSTnode* find_iterate(int key) const;

    /*
     * @brife: 根据键值key, 查找节点 递归实现
     * @param key: 所查找的键值
     * @return: 成功, 返回节点的地址; 否则, 返回nullptr.
    */
    const BSTnode* find_recursive(int key) const
    {
        return _find_recursive(root, key);
    }

    /*
     * @brife: 查找中序前驱节点
     * @param root: 以该节点为根
     * @return: 成功, 返回节点的地址; 否则, 返回nullptr.
    */
    BSTnode* findMax(const BSTnode* root) const;

    /*
     * @brife: 查找中序后继节点
     * @param root: 以该节点为根
     * @return: 成功, 返回节点的地址; 否则, 返回nullptr.
    */
    BSTnode* findMin(const BSTnode* root) const;

    /*
     * @brife: 根据key值删除节点
     * @param key: 键值
     * @return: 删除是否成功
    */
    bool remove(int key)
    {
        BSTnode* node = deleteNode(root, key);
        if (node == nullptr)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};// !class BST


#endif // !__BINARYSEARCHTREE_H__
