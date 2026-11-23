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
    //TODO: destruction 函数
    ~RBTree() {}

    std::pair<bool, Node*> insert(Node x)
    {
        auto res = _insert(x);
        if (res.first == true)
        {
            _insertRepair(res.second);
        }
        return res;
    }

    void LDR(std::function<void (Node*)> func = [](Node* x) {
        std::cout << "Color: " << static_cast<int>(x->color) << " key: " << x->key << " value: " << x->value << std::endl;
    })
    {
        _LDR_traverse(root, func);
    }

    /*
     * @brief: 根据键值key, 查找节点
     * @param key: 键值
     * @return: 返回查找节点的指针
    */
    Node* find(const Key& key) const
    {
        return _find(root, key);
    }

    //TODO: 删除节点函数 20261121
    /*
     * @brief: 删除键值key的节点
     * @param key: 键值
     * @return: 是否删除成功
    */
    bool remove(const Key& key)
    {
        Node* rmNode = _find(root, key);
        if (rmNode == nullptr)
        {
            return false;
        }
        else
        {
            _remove(rmNode);
            return true;
        }
    }
private:
    Node* root;

    /*
     * @brief: 以x为轴进行左旋
     * @param x: 左旋的轴心;
    */
    void _leftRotate(Node* x);

    /*
     * @brief: 以x为轴进行右旋
     * @param x: 左旋的轴心;
    */
    void _rightRotate(Node* x);

    /*
     * @brief: 对节点x进行插入操作
     * @param x: 插入的节点
     * @return std::pair<bool, Node*>: first是否插入成功; second插入的节点的指针;
    */
    std::pair<bool, Node*> _insert(Node x);

    /*
     * @brief: 当出现连续红节点或者根节点为红色, 需要插入修复
     * @param x: 插入的节点
    */
    void _insertRepair(Node* x);

    /*
     * @brief: 判断一个节点是左孩子还是右孩子亦或没有父节点
     * @param x:所判断的节点
     * @return int: 0->无父节点; 1->左孩子; 2->右孩子
    */
    int _leftORright(const Node* x) const;

    /*
     * @brief: 中序遍历树
     * @param root: 遍历的根节点
     * @param func: 对当前节点所执行的操作
    */
    void _LDR_traverse(Node* root, std::function<void (Node*)> func = [](Node* x) {
        std::cout << "Color: " << static_cast<int>(x->color) << " key: " << x->key << " value: " << x->value << std::endl;
    });

    /*
     * @brief: 查找以x为根的中序后继节点
     * @param x: 查找树的根节点
     * @return : 以x为根的中序后继节点的指针
    */
    Node* _findMin(const Node* x) const;

    /*
     * @brief: 查找以x为根的中序前驱节点
     * @param x: 查找树的根节点
     * @return : 以x为根的中序前驱节点的指针
    */
    Node* _findMax(const Node* x) const;

    /*
     * @brief: 根据键值key, 查找节点
     * @param root: 查找树的根节点
     * @param key: 键值
     * @return: 返回查找的节点的指针
    */
    Node* _find(Node* root, const Key& key) const;

    /*
     * @brief: 按照BST,删除节点x 
     * param x: 待删除节点
     * return: 是否删除成功
    */
    bool _removeBST(Node* x);

    /*
     * @brief: 红黑树删除节点x
     * @param x: 待删除的原始节点
    */
    void _remove(Node* x, bool isRemove = true);
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

template <typename Key, typename Value>
void RBTree<Key, Value>::_rightRotate(Node* x)
{
    Node* y = x->left;
    x->left = y->right;
    if (x->left != nullptr)
    {
        x->left->parent = x;
    }
    y->right = x;
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

template<typename Key, typename Value>
std::pair<bool, typename RBTree<Key, Value>::Node*> RBTree<Key, Value>::_insert(Node x)
{
    Node* curNode = root;
    if (curNode == nullptr)
    {
        root = new Node(x.key, x.value);
        return std::make_pair(true, root);
    }
    else
    {
        Key key = x.key;
        Key curKey = curNode->key;
        while (true)
        {
            if (key < curKey)
            {
                if (curNode->left == nullptr)
                {
                    curNode->left = new Node(key, x.value);
                    curNode->left->parent = curNode;
                    return std::make_pair(true, curNode->left);
                }
                else
                {
                    curNode = curNode->left;
                    curKey = curNode->key;
                }
            }
            else if (key > curKey)
            {
                if (curNode->right == nullptr)
                {
                    curNode->right = new Node(key, x.value);
                    curNode->right->parent = curNode;
                    return std::make_pair(true, curNode->right);
                }
                else
                {
                    curNode = curNode->right;
                    curKey = curNode->key;
                }
            }
            else
            {
                return std::make_pair(false, nullptr);
            }
        }
    }
}

template <typename Key, typename Value>
int RBTree<Key, Value>::_leftORright(const Node* x) const
{
    const Node* parent = x->parent;
    if (parent == nullptr)
    {
        return 0;
    }
    else if (parent->left == x)
    {
        return 1;
    }
    else
    {
        return 2;
    }
}

template <typename Key, typename Value>
void RBTree<Key, Value>::_insertRepair(Node* x)
{
    Node* parent = x->parent;
    if (parent == nullptr)
    {
        x->color = Color::BLACK;
        root = x;
        return;
    }
    else
    {
        Node* grandfather = parent->parent;
        if (parent->color == Color::RED)                //连续红红的情况需要修复
        {
            if (_leftORright(parent) == 0)              //父节点是根节点(不会出现的状况)
            {
                return;
            }
            else if (_leftORright(parent) == 1)         //父节点是左孩子
            {
                Node* uncle = grandfather->right;
                if (uncle != nullptr && uncle->color == Color::RED)         //叔叔节点是红色
                {
                    uncle->color = Color::BLACK;
                    parent->color = Color::BLACK;
                    grandfather->color = Color::RED;
                    _insertRepair(grandfather);
                }
                else                                    //叔叔节点是黑色或nullptr
                {
                    if (_leftORright(x) == 1)           //当前节点是左孩子
                    {
                        parent->color = Color::BLACK;
                        grandfather->color = Color::RED;
                        _rightRotate(grandfather);
                        return;
                    }
                    else                                //当前节点是右孩子
                    {
                        _leftRotate(parent);
                        _insertRepair(parent);
                    }
                }
            }
            else                                        //父节点是右孩子
            {
                Node* uncle = grandfather->left;
                if (uncle != nullptr && uncle->color == Color::RED)         //叔叔节点是红色
                {
                    uncle->color = Color::BLACK;
                    parent->color = Color::BLACK;
                    grandfather->color = Color::RED;
                    _insertRepair(grandfather);
                }
                else                                    //叔叔节点是黑色或nullptr
                {
                    if (_leftORright(x) == 1)           //当前节点是左孩子
                    {
                        _rightRotate(parent);
                        _insertRepair(parent);
                    }
                    else                                //当前节点是右孩子
                    {
                        parent->color = Color::BLACK;
                        grandfather->color = Color::RED;
                        _leftRotate(grandfather);
                        return;
                    }
                }
            }
        }
    }
}

template <typename Key, typename Value>
void RBTree<Key, Value>::_LDR_traverse(Node* root, std::function<void (Node*)> func)
{
    if (root == nullptr)
    {
        return;
    }
    Node* left = root->left;
    Node* right = root->right;
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

template <typename Key, typename Value>
typename RBTree<Key, Value>::Node* RBTree<Key, Value>::_findMin(const Node* x) const
{
    if (x == nullptr)
    {
        return nullptr;
    }
    Node* curNode = x->right;
    while (curNode != nullptr && curNode->left != nullptr)
    {
        curNode = curNode->left;
    }
    return curNode;
}

template <typename Key, typename Value>
typename RBTree<Key, Value>::Node* RBTree<Key, Value>::_findMax(const Node* x) const
{
    if (x == nullptr)
    {
        return nullptr;
    }
    Node* curNode = x->left;
    while (curNode != nullptr && curNode->right != nullptr)
    {
        curNode = curNode->right;
    }
    return curNode;
}

template <typename Key, typename Value>
typename RBTree<Key, Value>::Node* RBTree<Key, Value>::_find(Node* root, const Key& key) const
{
    Node* curNode = root;
    Key curKey;
    while (curNode != nullptr)
    {
        curKey = curNode->key;
        if (key < curKey)
        {
            curNode = curNode->left;
        }
        else if (key > curKey)
        {
            curNode = curNode->right;
        }
        else
        {
            return curNode;
        }
    }
    return nullptr;
}

template <typename Key, typename Value>
bool RBTree<Key, Value>::_removeBST(Node* x)
{
    if (x == nullptr)
    {
        return false;
    }
    Node* left = x->left;
    Node* right = x->right;
    if (left == nullptr && right == nullptr)            //无左右孩子, 叶子节点直接删除释放即可
    {
        if (_leftORright(x) == 1)                       //x是左孩子
        {
            x->parent->left = nullptr;
        }
        else                                            //x是右孩子
        {
            x->parent->right = nullptr;
        }
        delete x;
        x = nullptr;
        return true;
    }
    else if (left != nullptr && right == nullptr)       //只有左孩子, 左孩子顶替x, 然后删除左孩子
    {
        x->key = left->key;
        x->value = left->value;
        x->color = left->color;
        x->left = nullptr;
        delete left;
        left = nullptr;
        return true;
    }
    else if (left == nullptr && right != nullptr)       //只有右孩子
    {
        x->key = right->key;
        x->value = right->value;
        x->color = right->color;
        x->right = nullptr;
        delete right;
        right = nullptr;
        return true;
    }
    else                                                //有左右孩子, 需要中序后继节点
    {
        Node* minNode = _findMin(x);
        x->key = minNode->key;
        x->value = minNode->value;
        x->color = minNode->color;
        return _remove(minNode);
    }
}

template <typename Key, typename Value>
void RBTree<Key, Value>::_remove(Node* x, bool isRemove)
{
    if (x == nullptr)
    {
        return;
    }
    Node* left = x->left;
    Node* right = x->right;
    Node* parent = x->parent;
    //1. 无孩子
    if (left == nullptr && right == nullptr)
    {
        //1. 删除节点x, 是红色🔴, 直接删除即可
        if (x->color == Color::RED)
        {
            if (_leftORright(x) == 1)                       //删除节点x是左孩子
            {
                if (isRemove == true)
                {
                    parent->left = nullptr;
                    delete x;
                    x = nullptr;
                }
            }
            else                                            //删除节点x是右孩子
            {
                if (isRemove == true)
                {
                    parent->right = nullptr;
                    delete x;
                    x = nullptr;
                }
            }
        }
        //TODO: 复杂重点
        //2. 删除节点x, 是黑色⚫
        else
        {
            if (_leftORright(x) == 0)                       //待删除节点是x是根节点
            {
                if (isRemove == true)
                {
                    delete x;
                    x = nullptr;
                    root = nullptr;
                }
            }
            else if (_leftORright(x) == 1)                  //待删除节点x是左孩子
            {
                Node* bro = parent->right;                  //肯定存在兄弟节点, 否则违背了黑路同原则
                Node* broSon_l = bro->left;
                Node* broSon_r = bro->right;
                if (bro->color == Color::BLACK)
                {
                    //1. 兄弟子节点至少有一个红色节点
                    if (broSon_l != nullptr && broSon_l->color == Color::RED)       //RL型
                    {
                        broSon_l->color = parent->color;
                        parent->color = Color::BLACK;
                        _rightRotate(bro);
                        _leftRotate(broSon_l);
                        if (isRemove == true)
                        {
                            parent->left = nullptr;
                            delete x;
                            x = nullptr;
                        }
                    }
                    else if (broSon_r != nullptr && broSon_r->color == Color::RED)  //RR型
                    {
                        broSon_r->color = bro->color;
                        bro->color = parent->color;
                        parent->color = Color::BLACK;
                        _leftRotate(bro);
                        if (isRemove == true)
                        {
                            parent->left = nullptr;
                            delete x;
                            x = nullptr;
                        }
                    }
                    //2. 孩子都是黑色
                    else
                    {
                        bro->color = Color::RED;
                        if (isRemove == true)
                        {
                            parent->left = nullptr;
                            delete x;
                            x = nullptr;
                        }
                        if (parent == root)
                        {
                            return;
                        }
                        else if (parent->color == Color::RED)
                        {
                            parent->color = Color::BLACK;
                        }
                        else
                        {
                            _remove(parent, false);
                        }
                    }
                }
                else                                        //兄弟节点是🔴
                {
                    bro->color = Color::BLACK;
                    parent->color = Color::RED;
                    _leftRotate(bro);
                    _remove(x);
                }

            }
            else                                            //待删除节点x是右孩子
            {
                Node* bro = parent->left;
                Node* broSon_l = bro->left;
                Node* broSon_r = bro->right;
                if (bro->color == Color::BLACK)
                {
                    //1. 兄弟子节点至少有一个红色节点
                    if (broSon_l != nullptr && broSon_l->color == Color::RED)       //LL型
                    {
                        broSon_l->color = bro->color;
                        bro->color = parent->color;
                        parent->color = Color::BLACK;
                        _rightRotate(bro);
                        if (isRemove == true)
                        {
                            parent->right = nullptr;
                            delete x;
                            x = nullptr;
                        }
                    }
                    else if (broSon_r != nullptr && broSon_r->color == Color::RED)  //LR型
                    {

                        broSon_r->color = parent->color;
                        parent->color = Color::BLACK;
                        _leftRotate(bro);
                        _rightRotate(broSon_r);
                        if (isRemove == true)
                        {
                            parent->right = nullptr;
                            delete x;
                            x = nullptr;
                        }
                    }
                    //2. 孩子都是黑色
                    else
                    {
                        bro->color = Color::RED;
                        if (isRemove == true)
                        {
                            parent->right = nullptr;
                            delete x;
                            x = nullptr;
                        }
                        if (parent == root)
                        {
                            return;
                        }
                        else if (parent->color == Color::RED)
                        {
                            parent->color = Color::BLACK;
                        }
                        else
                        {
                            _remove(parent, false);
                        }

                    }
                }
                else                                        //兄弟节点是🔴
                {
                    bro->color = Color::BLACK;
                    parent->color = Color::RED;
                    _rightRotate(bro);
                    _remove(x);
                }
            }
        }
    }
    //2. 只有左孩子或者只有右孩子.
    // 如果删除节点x是🔴, 存在单孩子只能是⚫, 但是那样就违背了黑路同性质
    // 因此, 删除节点x只能是⚫, 孩子只能是🔴, 转而删除孩子节点, 可以直接删除
    else if (left != nullptr && right == nullptr)           //只有左孩子
    {
        x->key = left->key;
        x->value = left->value;
        if (isRemove == true)
        {
            x->left = nullptr;
            delete left;
            left = nullptr;
        }
    }
    else if (left == nullptr && right != nullptr)           //只有右孩子
    {
        x->key = right->key;
        x->value = right->value;
        if (isRemove == true)
        {
            x->right = nullptr;
            delete right;
            right = nullptr;
        }
    }
    //3. 有两个孩子, 需要中序后继节点/中序前驱节点替换
    else
    {
        Node* minNode = _findMin(x);                        //中序后继节点
        x->key = minNode->key;
        x->value = minNode->value;
        _remove(minNode);
    }
}

#endif // !__RBTREE_HPP__ 
