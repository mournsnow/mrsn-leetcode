#include <vector>
#include <queue>

using std::vector;
using std::queue;

class ListNode
{
public:
    ListNode(int x);
    ~ListNode();

public:
    static ListNode* createList(const vector<int> &valueArray);

public:
    int val;
    ListNode *next;
};

class TreeNode
{
public:
    TreeNode(int x);
    ~TreeNode();

public:
    static TreeNode* createTree(const vector<int> &valueArray);

public:
    int val;
    TreeNode *left;
    TreeNode *right;
};

