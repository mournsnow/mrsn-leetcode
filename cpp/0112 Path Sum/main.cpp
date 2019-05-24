#include "cpp_util.h"

class Solution
{
public:
    bool findRecursive(TreeNode* node, const int &value)
    {
        if ((nullptr == node->left) && (nullptr == node->right) && (value == node->val))
        {
            return true;
        }

        if ((nullptr != node->left) && (true == findRecursive(node->left, value - node->val)))
        {
            return true;
        }
        if ((nullptr != node->right) && (true == findRecursive(node->right, value - node->val)))
        {
            return true;
        }

        return false;
    }

    /* Time: O(n), space: O(1), stack size: O(ln(n)) */
    bool solution1(TreeNode* root, const int &sum)
    {
        if (nullptr == root)
        {
            return false;
        }

        return findRecursive(root, sum);
    }

    bool hasPathSum(TreeNode* root, int sum)
    {
        return solution1(root, sum);
    }
};

int main()
{
    Solution solution;

    vector<int> values = {2, 3, 5};
    TreeNode *input = TreeNode::createTree(values);

    printf("Original tree = [%s]\n", cpp_util::toString(input).c_str());

    bool hasPath = solution.hasPathSum(input, 5);

    printf("Has path = [%d]\n", hasPath);

    return 0;
}

