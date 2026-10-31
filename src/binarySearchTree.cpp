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
