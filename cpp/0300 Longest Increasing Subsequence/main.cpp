#include "cpp_util.h"

class Solution
{
public:
    int linearSearch(vector<int> &intArray, const int &previousValue, const int &index)
    {
        if ((int)(intArray.size()) == index)
        {
            return 0;
        }

        if (previousValue < intArray[index])
        {
            /* current value is larger then previous, can take current index into path or not */

            /* taken */
            int takenLength = 1 + linearSearch(intArray, intArray[index], index + 1);
            /* untaken */
            int untakenLength = linearSearch(intArray, previousValue, index + 1);

            return max(takenLength, untakenLength);
        }
        else
        {
            /* current value is not larger then previous, try next index with already taken path */

            return linearSearch(intArray, previousValue, index + 1);
        }
    }

    /* Brute force, time O(2^n), space (O^2) */
    int solution1(vector<int> &nums)
    {
        return linearSearch(nums, numeric_limits<int>::min(), 0);
    }

    int **mCachedLength;

    int linearSearchCached(vector<int> &intArray, const int &previousIndex, const int &index)
    {
        if ((int)(intArray.size()) == index)
        {
            return 0;
        }

        int takenLength = 0;
        int untakenLength = 0;

        if (0 <= mCachedLength[previousIndex + 1][index])
        {
            return mCachedLength[previousIndex + 1][index];
        }

        /* current value is larger then previous, can take current index into path or not */
        if ((0 > previousIndex) || (intArray[previousIndex] < intArray[index]))
        {
            /* taken */
            takenLength = 1 + linearSearchCached(intArray, index, index + 1);
        }

        /* untaken */
        untakenLength = linearSearchCached(intArray, previousIndex, index + 1);

        int maxLength = max(takenLength, untakenLength);

        mCachedLength[previousIndex + 1][index] = maxLength;

        return maxLength;
    }

    int solution2(vector<int> &nums)
    {
        const int &arraySize = nums.size();

        mCachedLength = new int*[arraySize];

        for (int i = 0; i < arraySize; ++i)
        {
            mCachedLength[i] = new int[arraySize];

            fill_n(mCachedLength[i], arraySize, (int)-1);
        }

        return linearSearchCached(nums, -1, 0);
    }

    int *mCachedMaxLength;

    int solution3(vector<int> &nums)
    {
        const int &arraySize = nums.size();

        if (0 == arraySize)
        {
            return 0;
        }

        mCachedMaxLength = new int[arraySize];
        int maxLength = 0;

        fill_n(mCachedMaxLength, arraySize, 1);

        for (int walkIndex = 0; walkIndex < arraySize; ++walkIndex)
        {
            for (int checkIndex = 0; checkIndex < walkIndex; ++checkIndex)
            {
                if (nums[checkIndex] < nums[walkIndex])
                {
                    mCachedMaxLength[walkIndex] = max(mCachedMaxLength[walkIndex], mCachedMaxLength[checkIndex] + 1);
                }
            }

            //printf("Walk index = [%d], cached length = [%s]\n", walkIndex, cpp_util::toString(mCachedMaxLength, arraySize).c_str());

            maxLength = max(maxLength, mCachedMaxLength[walkIndex]);
        }


        return maxLength;
    }

    vector<int> mLastIndexForLisLength;
    int *mReverseSearchList;

    int binarySearch(const vector<int> &lastIndexForLisLength, const int &arraySize, const vector<int> &intArray, const int &walkIndex)
    {
        const int &currentValue = intArray[walkIndex];
        int lower = 0;
        int upper = lastIndexForLisLength.size();

        return binarySearchRecurse(intArray, lastIndexForLisLength, lower, upper, currentValue);
    }

    int binarySearchRecurse(const vector<int> &intArray, const vector<int> &indexArray, int &lower, int &upper, const int &currentValue)
    {
        if (lower + 1 == upper)
        {
            return upper;
        }

        int current = (lower + upper) / 2;

        if (intArray[indexArray[current]] < currentValue)
        {
            lower = current;

            return binarySearchRecurse(intArray, indexArray, lower, upper, currentValue);
        }
        else
        {
            upper = current;

            return binarySearchRecurse(intArray, indexArray, lower, upper, currentValue);
        }
    }

    int solution4(vector<int> &nums)
    {
        const int &arraySize = nums.size();

        if (0 == arraySize)
        {
            return 0;
        }

        mReverseSearchList = new int[arraySize];

        fill_n(mReverseSearchList, arraySize, -1);

        for (int walkIndex = 0; walkIndex < arraySize; ++walkIndex)
        {
            if (0 == mLastIndexForLisLength.size())
            {
                //printf("First\n");

                mLastIndexForLisLength.push_back(walkIndex);
                continue;
            }

            if (nums[mLastIndexForLisLength[mLastIndexForLisLength.size() - 1]] < nums[walkIndex])
            {
                //printf("Append, max value = [%d], current value = [%d]\n", nums[mLastIndexForLisLength[mLastIndexForLisLength.size() - 1]], nums[walkIndex]);

                /* if lis path appendable */
                mLastIndexForLisLength.push_back(walkIndex);
                mReverseSearchList[walkIndex] = mLastIndexForLisLength[mLastIndexForLisLength.size() - 2];
            }
            else if (nums[mLastIndexForLisLength[0]] >= nums[walkIndex])
            {
                //printf("New Start\n");

                /* if new starting point found */
                mLastIndexForLisLength[0] = walkIndex;
            }
            else
            {
                int replaceIndex = binarySearch(mLastIndexForLisLength, arraySize, nums, walkIndex);

                //printf("Replace with index = [%d]\n", replaceIndex);

                mLastIndexForLisLength[replaceIndex] = walkIndex;
                mReverseSearchList[walkIndex] = mLastIndexForLisLength[replaceIndex - 1];
            }

            //printf("Walk index = [%d], reverse list = [%s], last index list = [%s]\n", walkIndex,
            //       cpp_util::toString(mReverseSearchList, arraySize).c_str(), cpp_util::toString(mLastIndexForLisLength).c_str());
        }

        return mLastIndexForLisLength.size();
    }

    int lengthOfLIS(vector<int> &nums)
    {
        //return solution1(nums);
        //return solution2(nums);
        //return solution3(nums);
        return solution4(nums);
    }
};

int main()
{
    Solution solution;

    vector<int> intArray = {10, 9, 2, 5, 3, 7, 101, 18};
    //vector<int> intArray = {1, 3, 6, 7, 9, 4, 10, 5, 6};
    //vector<int> intArray = {10, 9, 2, 5, 3, 7, 101, 18, 20, 21, 2, 23, 24, 25};
    //vector<int> intArray = {1, 3, 2, 4, 6, 5, 8, 7, 9, 13, 11, 12, 10, 14, 20, 16, 17, 25, 19, 15,
    //                        21, 22, 23, 24, 18, 26, 27, 28, 29, 30};
    //vector<int> intArray = {3, 4, -1, 5, 8, 2, 3, 12, 7, 9, 10};

    int lisLength = solution.lengthOfLIS(intArray);

    printf("Lis length of array = [%d]\n", lisLength);

    return 0;
}

