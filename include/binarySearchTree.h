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
};// !class BST


#endif // !__BINARYSEARCHTREE_H__
