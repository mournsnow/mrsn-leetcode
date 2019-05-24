#include "cpp_util.h"

class Solution
{
public:
    string stripExtraSpace(const string &s)
    {
        string stripped;

        /* Stip head spaces and tail spaces */
        auto headStrip = s.begin();
        auto tailStrip = s.end();

        while ((s.end() != headStrip) && (' ' == *headStrip))
        {
            ++headStrip;
        }

        while ((s.begin() != tailStrip) && (' ' == *(tailStrip - 1)))
        {
            --tailStrip;
        }

        stripped = s.substr(headStrip - s.begin(), tailStrip - headStrip);

        /* Change multiple spaces in to one space */
        for (auto middleStrip = stripped.begin(); middleStrip != stripped.end(); ++middleStrip)
        {
            if ((' ' == *middleStrip) && (' ' == *(middleStrip + 1)))
            {
                stripped.erase(middleStrip);
                --middleStrip;
            }
        }

        return stripped;
    }

    /* Time: O(n), Space: O(n) */
    /* Time: O(n), Space: O(1), if do inplace strip */
    string reverseWords(string s)
    {
        string target = stripExtraSpace(s);

        //printf("Stripped string = [%s]\n", target.c_str());

        reverse(target.begin(), target.end());

        //printf("Full reverse string = [%s]\n", target.c_str());

        auto wordStart = target.begin();
        auto wordEnd = wordStart;

        while (wordStart != target.end())
        {
            wordEnd = wordStart;

            while ((target.end() != wordEnd) && (' ' != *wordEnd))
            {
                ++wordEnd;
            }

            reverse(wordStart, wordEnd);

            //printf("Word reverse = [%s]\n", target.c_str());

            wordStart = wordEnd;

            while((target.end() != wordStart) && (' ' == *wordStart))
            {
                ++wordStart;
            }
        }

        //printf("Result = [%s]\n", target.c_str());

        return target;
    }
};

int main()
{
    Solution solution;

    /* pen a is This */
    //string original = "This is a pen";

    /* pen a is This */
    //string original = " This is a pen ";

    /* pen a is This */
    //string original = " This is a  pen ";

    /* example good a */
    string original = "a good   example";

    printf("Original string = [%s]\n", original.c_str());

    string reversed = solution.reverseWords(original);

    printf("Reversed string = [%s]\n", reversed.c_str());

    return 0;
}

