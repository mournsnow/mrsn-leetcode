#include "cpp_util.h"

class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<vector<int>> totalResult = combRecursive(candidates, target);

        return totalResult;
    }

    vector<vector<int>> combRecursive(const vector<int> &candidates, const int &target)
    {
        /* Terminate condition */
        if (isCached(target))
        {
            return getCachedResult(target);
        }

        vector<vector<int>> result;

        for (const int &candidate: candidates)
        {
            if (candidate == target)
            {
                /* answer with itself */
                vector<int> singleResult;

                singleResult.push_back(target);
                result.push_back(singleResult);

                if ((1 <= candidate) && (3 >= candidate))
                {
                    /* for 1 ~ 3, only single result is enough */
                    cacheResult(candidate, result);

                    return result;
                } else {
                    /* for others, continue to integrate other results */
                    continue;
                }
            }

            if (candidate > target)
            {
                /* no answer */
                continue;
            }

            /* candidate < target */
            /* divide and conqure */
            vector<vector<int>> leftResult = combRecursive(candidates, candidate);
            vector<vector<int>> rightResult = combRecursive(candidates, target - candidate);
            vector<vector<int>> partialResult = crossJoin(leftResult, rightResult);

            //printf("For taget [%d], from candidate [%d] result [%s]\n", target, candidate, toString(partialResult).c_str());
            //fflush(stdout);

            /* Add to total result */
            for (const vector<int> combination : partialResult)
            {
                result.push_back(combination);
            }
        }

        deduplicate(result);
        cacheResult(target, result);

        return result;
    }

    vector<vector<int>> crossJoin(vector<vector<int>> &left, vector<vector<int>> &right)
    {
        vector<vector<int>> joinedResult;
        vector<int> tempJoined;

        /* If one of the result to join is empty, the result is empty */
        if ((0 == left.size()) || (0 == right.size()))
        {
            return joinedResult;
        }

        for (const vector<int> leftComb : left)
        {
            for (const vector<int> rightComb : right)
            {
                tempJoined.clear();

                for (const int & leftValue : leftComb)
                {
                    tempJoined.push_back(leftValue);
                }

                for (const int &rightValue : rightComb)
                {
                    tempJoined.push_back(rightValue);
                }

                joinedResult.push_back(tempJoined);
            }
        }

        deduplicate(joinedResult);

        return joinedResult;
    }

    void deduplicate(vector<vector<int>> &result)
    {
        vector<vector<int>> deduplicated;

        for (vector<int> combination : result)
        {
            sort(combination.begin(), combination.end());

            if (deduplicated.end() == find(deduplicated.begin(), deduplicated.end(), combination))
            {
                deduplicated.push_back(combination);
            }
        }

        swap(result, deduplicated);
    }

    bool isCached(const int &target)
    {
        return (mSavedAnswer.end() != mSavedAnswer.find(target));
    }

    vector<vector<int>> getCachedResult(const int &target)
    {
        return mSavedAnswer[target];
    }

    void cacheResult(const int &target, const vector<vector<int>> &result)
    {
        //printf("Cache result, target = [%d], result = [%s]\n", target, toString(result).c_str());
        //fflush(stdout);

        mSavedAnswer[target] = result;
    }

    string toString(const vector<vector<int>> &result)
    {
        string resultString = "[ ";

        for (const vector<int> &combination : result)
        {
            resultString += toString(combination);
            resultString += " ";
        }

        resultString += " ]";

        return resultString;
    }

    string toString(const vector<int> &combination)
    {
        string combString = "[";
        bool first = true;

        for (const int &value : combination)
        {
            if (true == first)
            {
                first = false;
            }
            else
            {
                combString += " ";
            }
            combString += to_string(value);
        }

        combString += "]";

        return combString;
    }

public:
    unordered_map<int, vector<vector<int>>> mSavedAnswer;
};

int main()
{
    return 0;
}

