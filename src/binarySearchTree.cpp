/***********************************************************************************************************************
* @file: binarySearchTrss.h
* @brife: 二叉查找树模块
* @date: 2026-10-30
* @update:
* @author: lightningLW
* @note: 
***********************************************************************************************************************/

#include "binarySearchTree.h"
#include <iostream>

std::pair<bool, BSTnode*> BST::insertNode(int value)
{
    std::pair<bool, BSTnode*> res = std::make_pair(false, nullptr);
    BSTnode* curNode = root;
    if (curNode == nullptr)
    {
        root = new BSTnode(value);
        res = std::make_pair(true, root);
    }
    else 
    {
        while (curNode != nullptr)
        {
            if (value > curNode->val)
            {
                if (curNode->rightTree == nullptr)
                {
                    curNode->rightTree = new BSTnode(value);
                    res = std::make_pair(true, curNode->rightTree);
                    break;
                }
                curNode = curNode->rightTree;
            }
            else if (value < curNode->val)
            {
                if (curNode->leftTree == nullptr)
                {
                    curNode->leftTree = new BSTnode(value);
                    res = std::make_pair(true, curNode->leftTree);
                    break;
                }
                curNode = curNode->leftTree;
            }
            else
            {
                res.first = false; 
                res.second = nullptr;
                break;
            }
        }
    }
    return res;
}

void BST::printLDR_traverse(const BSTnode* root) const
{
    const BSTnode* left = root->leftTree;
    const BSTnode* right = root->rightTree;
    if (root == nullptr)
    {
        return;
    }
    if (left == nullptr && right == nullptr)
    {
        std::cout << root->val << "\t";
        return;
    }
    if (left != nullptr)
    {
        printLDR_traverse(left);
        std::cout << root->val << "\t";
    }
    else
    {
        std::cout << root->val << "\t";
    }
    if (right != nullptr)
    {
        printLDR_traverse(right);
    }
}

const BSTnode* BST::find_iterate(int key) const
{
    const BSTnode* curNode = root;
    while (curNode != nullptr)
    {
        if (key > curNode->val)
        {
            //到右子树继续查找
            curNode = curNode->rightTree;
        }
        else if (key < curNode->val)
        {
            //到左子树继续查找
            curNode = curNode->leftTree;
        }
        else
        {
            //找到
            break;
        }
    }
    return curNode;
}

const BSTnode* BST::_find_recursive(const BSTnode* root, int key) const
{
    if (root == nullptr)
    {
        return root;
    }
    if (key > root->val)
    {
       return _find_recursive(root->rightTree, key);
    }
    else if (key < root->val)
    {
       return _find_recursive(root->leftTree, key);
    }
    else
    {
        return root;
    }
}

BSTnode* BST::findMax(const BSTnode *root) const
{
    if (root == nullptr)
    {
        return nullptr;
    }
    BSTnode* curNode = root->leftTree;
    while (curNode != nullptr && curNode->rightTree != nullptr)
    {
        curNode = curNode->rightTree;
    }
    return curNode;
}

BSTnode* BST::findMin(const BSTnode *root) const
{
    if (root == nullptr)
    {
        return nullptr;
    }
    BSTnode* curNode = root->rightTree;
    while (curNode != nullptr && curNode->leftTree != nullptr)
    {
        curNode = curNode->leftTree;
    }
    return curNode;
}
