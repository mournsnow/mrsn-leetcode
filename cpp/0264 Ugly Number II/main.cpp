#include "cpp_util.h"

class Solution
{
public:
    bool isUgly(const int &number)
    {
        if (1 == number)
        {
            return true;
        }

        int dividee = number;

        while ((0 == dividee % 2) || (0 == dividee % 3) || (0 == dividee % 5))
        {
            if (0 == dividee % 2)
            {
                dividee /= 2;
                continue;
            }
            else if (0 == dividee % 3)
            {
                dividee /= 3;
                continue;
            }
            else if (0 == dividee % 5)
            {
                dividee /= 5;
                continue;
            }

            break;
        }

        return (1 == dividee);
    }

    int solution1(const int &n)
    {
        int validCount = 0;
        int number = 0;

        while (validCount < n)
        {
            ++number;

            if (false == isUgly(number))
            {
                //printf("Number [%d] is not ugly\n", number);

                continue;
            }

            //printf("Number [%d] is ugly\n", number);

            ++validCount;

            if (n == validCount)
            {
                return number;
            }
        }

        return 0;
    }

    void checkAndAdd(vector<int> &destination, vector<int> &uglyVector, const int &genIndex, const int &multiplier)
    {
        if(numeric_limits<int>::max() / multiplier <= uglyVector[genIndex])
        {
            return;
        }

        destination.push_back(uglyVector[genIndex] * multiplier);
    }

    void sortMerge(vector<int> &merged, vector<int> &first, vector<int> &second, vector<int> &third)
    {
        vector<int> temp;

        temp.push_back(first[0]);
        temp.push_back(second[0]);
        temp.push_back(third[0]);

        sort(temp.begin(), temp.end());

        //printf("sort merge, min = [%d]\n", temp[0]);

        merged.push_back(temp[0]);

        first.erase(remove(first.begin(), first.end(), temp[0]), first.end());
        second.erase(remove(second.begin(), second.end(), temp[0]), second.end());
        third.erase(remove(third.begin(), third.end(), temp[0]), third.end());
    }

    int solution2(const int &n)
    {
        vector<int> uglyVector;
        vector<int> multiply2vector;
        vector<int> multiply3vector;
        vector<int> multiply5vector;
        int genIndex = 0;

        uglyVector.push_back(1);

        while (n > genIndex)
        {
            checkAndAdd(multiply2vector, uglyVector, genIndex, 2);
            checkAndAdd(multiply3vector, uglyVector, genIndex, 3);
            checkAndAdd(multiply5vector, uglyVector, genIndex, 5);

            sortMerge(uglyVector, multiply2vector, multiply3vector, multiply5vector);

            ++genIndex;
        }

        return uglyVector[n - 1];
    }

    int nthUglyNumber(int n)
    {
        //return solution1(n);
        return solution2(n);
    }
};

int main()
{
    Solution solution;

    int n = 1300;
    int nthUglyNum = solution.nthUglyNumber(n);

    printf("%dth ugly number = [%d]\n", n, nthUglyNum);

    return 0;
}

