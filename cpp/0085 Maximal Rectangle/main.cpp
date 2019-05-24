#include <iostream>
#include <stack>
#include <vector>

using std::string;
using std::to_string;
using std::stack;
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

    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int maximalSize = 0;

        const int &rowCount = matrix.size();

        if (0 == rowCount)
        {
            return maximalSize;
        }

        const int &columnCount = matrix[0].size();

        if (0 == columnCount)
        {
            return maximalSize;
        }

        for (int rowIndex = 0; rowIndex < rowCount; ++rowIndex)
        {
            //printf("Row = [%d], get heights\n", rowIndex);
            //fflush(stdout);

            vector<int> heights;
            int height = 0;

            for (int columnIndex = 0; columnIndex < columnCount; ++columnIndex)
            {
                height = 0;

                for (int heightIndex = 0; heightIndex <= rowIndex; ++heightIndex)
                {
                    if ('1' == matrix[heightIndex][columnIndex])
                    {
                        ++height;
                    }
                    else
                    {
                        height = 0;
                    }
                }

                heights.push_back(height);
            }

            //printf("Row = [%d], heights = [%s]\n", rowIndex, toString(heights).c_str());
            //fflush(stdout);

            int rectArea = largestRectangleArea(heights);

            maximalSize = (maximalSize < rectArea) ? rectArea : maximalSize;
        }

        //printf("Maximal size = [%d]\n", maximalSize);
        //fflush(stdout);

        return maximalSize;
    }

    int largestRectangleArea(vector<int> &heights)
    {
        //printf("Start\n");
        //fflush(stdout);

        int maximum = 0;
        stack<int> increasingStack;

        for (int index = 0; index < (int)heights.size(); ++index)
        {
            //printf("Index = [%d] stack size = [%d]\n", index, increasingStack.size());
            //fflush(stdout);

            if (0 == index)
            {
                increasingStack.push(heights[index]);
                continue;
            }

            if (increasingStack.top() < heights[index])
            {
                increasingStack.push(heights[index]);
                continue;
            }
            else
            {
                int count = 1;

                while((false == increasingStack.empty()) && (increasingStack.top() > heights[index]))
                {
                    int stackTop = increasingStack.top();
                    increasingStack.pop();

                    maximum = (maximum > stackTop * count) ? maximum : stackTop * count;

                    ++count;
                }

                for (int pushIndex = 0; pushIndex < count; ++pushIndex)
                {
                    increasingStack.push(heights[index]);
                }
            }
        }

        int count = 1;
        int value = 0;

        //printf("While loop\n");
        //fflush(stdout);

        while(false == increasingStack.empty())
        {
            //printf("Count = [%d], value = [%d], maximum = [%d]\n", count, value, maximum);
            //fflush(stdout);

            value = increasingStack.top();
            increasingStack.pop();

            if (true == increasingStack.empty())
            {
                maximum = (maximum > value * count) ? maximum : value * count;
                break;
            }

            if (increasingStack.top() != value)
            {
                maximum = (maximum > value * count) ? maximum : value * count;

                value = increasingStack.top();
            }

            ++count;
        }

        //printf("%d\n", maximum);
        //fflush(stdout);

        return maximum;
    }
};

int main()
{
    int rowCount = 0;
    int columnCount = 0;

    vector<vector<char>> charMap;
    char value = 0;

    scanf("%d", &rowCount);
    scanf("%d", &columnCount);

    /* new line */
    scanf("%c", &value);
    for (int rowIndex = 0; rowIndex < rowCount; ++rowIndex)
    {
        vector<char> charRow;
        charMap.push_back(charRow);

        for (int columnIndex = 0; columnIndex < columnCount; ++columnIndex)
        {
            scanf("%c", &value);
            charMap[rowIndex].push_back(value);
        }

        /* new line */
        scanf("%c", &value);
    }

    Solution solution;

    //printf("Char map: (%d, %d)\n%s", (int)charMap.size(), (int)charMap[0].size(), solution.toString(charMap).c_str());
    //fflush(stdout);

    solution.maximalRectangle(charMap);

    return 0;
}

