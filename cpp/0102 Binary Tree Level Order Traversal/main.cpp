#include <iostream>
#include <stack>
#include <vector>
#include <deque>
#include <limits.h>
#include <cassert>

using std::string;
using std::to_string;
using std::stack;
using std::deque;
using std::vector;

class Solution {
public:
    string toString(const vector<vector<char>> &charVector2)
    {
        string charVector2String = "";

        for (int index = 0; index < (int)charVector2.size(); ++index)
        {
            charVector2String += toString(charVector2[index]);
            charVector2String += "\n";
        }

        return charVector2String;
    }

    string toString(const vector<char> &charVector)
    {
        bool first = true;
        string charVectorString = "";

        for (int index = 0; index < (int)charVector.size(); ++index)
        {
            if (true == first)
            {
                charVectorString += charVector[index];
                first = false;
            }
            else
            {
                charVectorString += " ";
                charVectorString += charVector[index];
            }
        }

        return charVectorString;
    }

    string toString(const vector<int> &intVector)
    {
        bool first = true;
        string intVectorString = "";

        for (int index = 0; index < (int)intVector.size(); ++index)
        {
            if (true == first)
            {
                intVectorString += to_string(intVector[index]);
                first = false;
            }
            else
            {
                intVectorString += " ";
                intVectorString += to_string(intVector[index]);
            }
        }

        return intVectorString;
    }

    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> levelArray;
        int level = 0;
        vector<vector<TreeNode*>> walkArray;

        if (nullptr != root)
        {
            vector<TreeNode*> rootLayer;

            rootLayer.push_back(root);
            walkArray.push_back(rootLayer);
        }

        while (level < walkArray.size())
        {
            vector<TreeNode*> currentLayer = walkArray[level];

            for (TreeNode *layerNode : currentLayer)
            {
                bfsRecursive(levelArray, layerNode, level, walkArray);
            }

            ++level;
        }

        return levelArray;
    }

    void bfsRecursive(vector<vector<int>> &levelArray, const TreeNode *currentNode, const int &level, vector<vector<TreeNode*>> &walkArray)
    {
        //printf("Bfs, level = [%d], curent = [%d]\n", level, currentNode->val);

        if (nullptr == currentNode)
        {
            return;
        }

        checkAssign(levelArray, level, currentNode->val);

        checkPush(walkArray, level + 1, currentNode->left);
        checkPush(walkArray, level + 1, currentNode->right);
    }

    void checkAssign(vector<vector<int>> &levelArray, const int &level, const int &value)
    {
        while(level >= levelArray.size())
        {
            vector<int> layerArray;

            levelArray.push_back(layerArray);
        }

        levelArray[level].push_back(value);
    }

    void checkPush(vector<vector<TreeNode*>> &walkArray, const int &level, TreeNode* node)
    {
        if (nullptr == node)
        {
            return;
        }

        while(level >= walkArray.size())
        {
            vector<TreeNode*> layerArray;

            walkArray.push_back(layerArray);
        }

        //printf("Check push, level = [%d], node = [%d]\n", level, node->val);

        walkArray[level].push_back(node);
    }
};

int main()
{
    return 0;
}

