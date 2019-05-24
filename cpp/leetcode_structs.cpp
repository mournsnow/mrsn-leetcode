#include "leetcode_structs.h"

ListNode::ListNode(int x) :
    val(x),
    next(nullptr)
{
}

ListNode::~ListNode()
{
}

ListNode* ListNode::createList(const vector<int> &valueArray)
{
    ListNode *start = nullptr;
    ListNode *walk = nullptr;

    for (const int &value : valueArray)
    {
        ListNode *newNode = new ListNode(value);

        if (nullptr == start)
        {
            start = newNode;
            walk = newNode;
        }
        else
        {
            walk->next = newNode;
            walk = newNode;
        }
    }

    return start;
}

TreeNode::TreeNode(int x) :
    val(x),
    left(nullptr),
    right(nullptr)
{
}

TreeNode::~TreeNode()
{
}

TreeNode* TreeNode::createTree(const vector<int> &valueArray)
{
    TreeNode *start = nullptr;
    TreeNode *walk = nullptr;
    queue<TreeNode*> nextNodeQueue;

    for (const int &value : valueArray)
    {
        TreeNode *newNode = new TreeNode(value);

        if (nullptr == start)
        {
            start = newNode;
            walk = newNode;
        }
        else
        {
            if ((nullptr != walk->left) && (nullptr != walk->right))
            {
                walk = nextNodeQueue.front();
                nextNodeQueue.pop();
            }

            if (nullptr == walk->left)
            {
                walk->left = newNode;
                nextNodeQueue.push(newNode);
            }
            else if (nullptr == walk->right)
            {
                walk->right = newNode;
                nextNodeQueue.push(newNode);
            }
        }
    }

    return start;
}

