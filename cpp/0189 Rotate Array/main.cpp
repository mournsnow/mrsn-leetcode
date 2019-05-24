#include "cpp_util.h"

class Solution
{
public:
    /* Time: O(n), space: O(1) */
    void solution1(vector<int>& nums, int k)
    {
        const int &rotateCount = k % nums.size();

        reverse(nums.begin(), nums.end());

        auto middle = nums.begin() + rotateCount;

        reverse(nums.begin(), middle);
        reverse(middle, nums.end());
    }

    /* Time: O(n), space: O(1) */
    void solution2(vector<int>& nums, int k)
    {
        const int &rotateCount = k % nums.size();

        int count = nums.size();
        int startIndex = nums.size() - 1;

        int index = startIndex;
        int temp = 0;

        while (count > 0)
        {
            if (startIndex == index)
            {
                temp = nums[startIndex];
            }

            int assignerIndex = ((index - rotateCount) >= 0) ? index - rotateCount : index - rotateCount + nums.size();

            //printf("Index = [%d], assigner = [%d]\n", index, assignerIndex);
            //printf("Rotate count = [%d], size = [%d]\n", rotateCount, (int)nums.size());

            /* Loopback */
            if (startIndex == assignerIndex)
            {
                nums[index] = temp;
                --startIndex;
                index = startIndex;
            }
            else
            {
                nums[index] = nums[assignerIndex];
                index = assignerIndex;
            }

            --count;
        }
    }

    void rotate(vector<int>& nums, int k)
    {
        //return solution1(nums, k);
        return solution2(nums, k);
    }
};

int main()
{
    Solution solution;

    /* {5, 6, 7, 1, 2, 3, 4} */
    vector<int> array = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    ///* {-1} */
    //vector<int> array = {-1};
    //int k = 2;

    ///* {5, 6, 7, 1, 2, 3, 4} */
    //vector<int> array = {1, 2, 3, 4, 5, 6};
    //int k = 2;

    printf("Input Array = [%s]\n", cpp_util::toString(array).c_str());

    solution.rotate(array, k);

    printf("Output Array = [%s]\n", cpp_util::toString(array).c_str());

    return 0;
}

