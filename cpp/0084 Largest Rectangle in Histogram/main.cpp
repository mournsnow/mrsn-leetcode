#include <iostream>
#include <stack>
#include <vector>

using std::stack;
using std::vector;

class Solution {
public:
    int largestRectangleArea(vector<int> &heights)
    {
        //printf("Start\n");
        //fflush(stdout);

        int maximum = 0;
        stack<int> increasingStack;

        for (int index = 0; index < heights.size(); ++index)
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

        printf("%d\n", maximum);

        return maximum;
    }
};

int main()
{
    vector<int> inputVector;
    int value = 0;

    while(0 < scanf("%d", &value))
    {
        inputVector.push_back(value);
    }

    Solution solution;

    solution.largestRectangleArea(inputVector);

    return 0;
}

