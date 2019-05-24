#include "cpp_util.h"

namespace cpp_util
{
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

    string toString(const int *intArray, const int &size)
    {
        string intArrayString = "";

        for (int index = 0; index < size; ++index)
        {
            intArrayString += to_string(intArray[index]);
            if (size - 1 != index)
            {
                intArrayString += " ";
            }
        }

        return intArrayString;
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

    string toString(const vector<vector<int>> &intMatrix)
    {
        string intMatrixString = "\n";

        for (const vector<int> &vector : intMatrix)
        {
            intMatrixString += "    [";
            intMatrixString += toString(vector);
            intMatrixString += "]\n";
        }

        return intMatrixString;
    }

    string toString(ListNode *start)
    {
        ListNode *walkNode = start;
        string listString = "";
        bool first = true;

        while (nullptr != walkNode)
        {
            if (true == first)
            {
                first = false;
            }
            else
            {
                listString += " ";
            }

            listString += to_string(walkNode->val);

            walkNode = walkNode->next;
        }

        return listString;
    }

    string toString(TreeNode *start)
    {
        TreeNode *walk = nullptr;
        string listString = "";
        bool first = true;
        queue<TreeNode*> walkQueue;

        walkQueue.push(start);

        while (false == walkQueue.empty())
        {
            walk = walkQueue.front();
            walkQueue.pop();

            if (true == first)
            {
                listString += to_string(walk->val);
                first = false;
            }
            else
            {
                listString += " ";
                listString += to_string(walk->val);
            }

            if (nullptr != walk->left)
            {
                walkQueue.push(walk->left);
            }
            if (nullptr != walk->right)
            {
                walkQueue.push(walk->right);
            }
        }

        return listString;
    }

    int randomBetween(const int &start, const int &end)
    {
        /* Including end */
        int diff = end - start + 1;

        if (0 == diff)
        {
            return start;
        }

        srand(time(nullptr));

        return rand() % diff + start;
    }
}

