#include "cpp_util.h"

class Solution
{
public:
    void mergeItem(vector<int> &mergedArray, const vector<int> &inputArray, int &index)
    {
        mergedArray.push_back(inputArray[index]);
        ++index;
    }

    double solution1(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> mergedArray;
        int index1 = 0;
        int index2 = 0;

        while ((index1 < (int)nums1.size()) || (index2 < (int)nums2.size()))
        {
            //printf("Index 1 = [%d], index 2 = [%d]\n", index1, index2);

            if ((int)nums1.size() <= index1)
            {
                mergeItem(mergedArray, nums2, index2);
                continue;
            }

            if ((int)nums2.size() <= index2)
            {
                mergeItem(mergedArray, nums1, index1);
                continue;
            }

            if (nums1[index1] <= nums2[index2])
            {
                mergeItem(mergedArray, nums1, index1);
            }
            else
            {
                mergeItem(mergedArray, nums2, index2);
            }
        }

        const int &mergedSize = mergedArray.size();

        //printf("Merged size = [%d]\n", mergedSize);

        assert(mergedSize == (int)nums1.size() + (int)nums2.size());

        double median = 0;

        if (0 == mergedSize)
        {
            return median;
        }

        if (0 == mergedSize % 2)
        {
            median = (double(mergedArray[mergedSize/2 - 1]) + double(mergedArray[mergedSize/2])) / 2;
        }
        else
        {
            median = mergedArray[mergedSize/2];
        }

        return median;
    }

    double solution2(vector<int>& nums1, vector<int>& nums2)
    {
        int start = 0;
        int end = nums1.size();
        int matchResult = -1;
        int partitionIndex = (start + end) / 2;
        double median = 0.0;

        matchResult = testPartition(nums1, nums2, partitionIndex, median);

        while (0 != matchResult)
        {
            if (matchResult > 0)
            {
                /* Partition right part */
                start = partitionIndex + 1;
                partitionIndex = (start + end) / 2;
            }
            else
            {
                /* Partition left part */
                end = partitionIndex;
                partitionIndex = (start + end) / 2;
            }

            matchResult = testPartition(nums1, nums2, partitionIndex, median);
        }

        return median;
    }

    int getPartitionIndex2(const int &size1, const int &size2, const int &partitionIndex1)
    {
        /* +1 to make odd number get more left values than right values */
        int parititonIndex2 = (size1 + size2 + 1) / 2 - partitionIndex1;

        //printf("Size 1 = [%d], size 2 = [%d], parittion 1 = [%d], parititon 2 = [%d]\n", size1, size2, partitionIndex1, parititonIndex2);

        return parititonIndex2;
    }

    int testPartition(const vector<int> &nums1, const vector<int> &nums2, const int &partitionIndex1, double &median)
    {
        int result = 0;

        const int left1Index = partitionIndex1 - 1;
        const int right1Index = partitionIndex1;
        const int right2Index = getPartitionIndex2(nums1.size(), nums2.size(), partitionIndex1);
        const int left2Index = right2Index - 1;


        const int left1Value = ((0 > left1Index) || (left1Index >= (int)nums1.size())) ? numeric_limits<int>::min() : nums1[left1Index];
        const int right1Value = ((int)nums1.size() <= right1Index) ? numeric_limits<int>::max() : nums1[right1Index];
        const int right2Value = ((int)nums2.size() <= right2Index) ? numeric_limits<int>::max() : nums2[right2Index];
        const int left2Value = ((0 > left2Index) || (left2Index >= (int)nums2.size())) ? numeric_limits<int>::min() : nums2[left2Index];

        const bool left1right2 = (left1Value <= right2Value);
        const bool left2right1 = (left2Value <= right1Value);

        //printf("Index (left1, right1) = [%d, %d], (left2, right2) = [%d, %d]\n", left1Index, right1Index, left2Index, right2Index);
        //printf("Value (left1, right1) = [%d, %d], (left2, right2) = [%d, %d]\n", left1Value, right1Value, left2Value, right2Value);

        if ((true == left1right2) && (true == left2right1))
        {
            /* Found, calculate median */
            const int totalSize = nums1.size() + nums2.size();

            if (1 == totalSize % 2)
            {
                median = (double)(max(left1Value, left2Value));
            }
            else
            {
                median = ((double)(max(left1Value, left2Value)) + (double)(min(right1Value, right2Value))) / 2.0;
            }
        }
        else if ((true == left1right2) && (false == left2right1))
        {
            /* Partition rightward */
            result = 1;
        }
        else if ((false == left1right2) && (true == left2right1))
        {
            /* Partition leftward */
            result = -1;
        }
        else
        {
            assert(false);
        }

        return result;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        //return solution1(nums1, nums2);
        return (nums1.size() > nums2.size()) ? solution2(nums2, nums1) : solution2(nums1, nums2);
    }

};

int main()
{
    Solution solution;

    /* 2 */
    //vector<int> nums1 = {1, 3};
    //vector<int> nums2 = {2};

    /* 2.5 */
    //vector<int> nums1 = {1, 2};
    //vector<int> nums2 = {3, 4};

    /* 2 */
    //vector<int> nums1 = {2};
    //vector<int> nums2 = {};

    /* 1 */
    vector<int> nums1 = {1};
    vector<int> nums2 = {1};

    printf("Vector 1 = [%s]\n", cpp_util::toString(nums1).c_str());
    printf("Vector 2 = [%s]\n", cpp_util::toString(nums2).c_str());

    double median = solution.findMedianSortedArrays(nums1, nums2);

    printf("Median = [%lf]\n", median);

    return 0;
}

