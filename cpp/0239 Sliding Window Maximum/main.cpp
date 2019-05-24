#include "cpp_util.h"

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

    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        vector<int> answer;
        deque<int> window;
        int max = numeric_limits<int>::min();

        for (const int input : nums)
        {
            moveWindow(window, input, k, max);

            if (k == (int)window.size())
            {
                answer.push_back(max);
            }
        }

        return answer;
    }

    void moveWindow(deque<int> &window, const int &input, const int &k, int &max)
    {
        max = (max < input) ? input : max;

        window.push_back(input);

        if (k < (int)window.size())
        {
            int front = window.front();

            window.pop_front();

            if (max == front)
            {
                max = getMax(window);
            }
        }
    }

    int getMax(deque<int> &window)
    {
        int max = numeric_limits<int>::min();

        for (const int &value : window)
        {
            max = (max < value) ? value : max;
        }

        return max;
    }
};

int main()
{
    deque<int> intQueue = {5, 3, 2, 4, 1};

    for (const int &value : intQueue)
    {
        printf("%d ", value);
    }
    printf("\n");

    printf("Begin = [%d]\n", *(intQueue.begin()));
    //printf("End = [%d]\n", *(intQueue.end()));
    printf("Reverse Begin = [%d]\n", *(intQueue.rbegin()));
    //printf("Reverse End = [%d]\n", *(intQueue.rend()));
    printf("Front = [%d]\n", intQueue.front());
    printf("Back = [%d]\n", intQueue.back());

    printf("Size = [%d]\n", (int)intQueue.size());

    printf("Push back 100\n");
    intQueue.push_back(100);

    printf("Push front 101\n");
    intQueue.push_front(101);

    for (int index = 0; index < (int)intQueue.size(); ++index)
    {
        printf("%d ", intQueue[index]);
    }
    printf("\n");

    printf("Pop back\n");
    intQueue.pop_back();
    printf("Pop back\n");
    intQueue.pop_back();

    printf("Pop front\n");
    intQueue.pop_front();

    for (const int &value : intQueue)
    {
        printf("%d ", value);
    }
    printf("\n");

    return 0;
}

