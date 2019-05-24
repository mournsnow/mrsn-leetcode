#include "leetcode_structs.h"

#include <iostream>
#include <stack>
#include <vector>
#include <deque>
#include <queue>
#include <limits>
#include <cassert>
#include <utility>
#include <unordered_map>
#include <algorithm>
#include <set>

using std::string;
using std::to_string;

/* data sturctures */
using std::unordered_map;
using std::stack;
using std::deque;
using std::queue;
using std::vector;
using std::set;
using std::make_pair;

using std::fill;
using std::fill_n;

/* limits */
using std::numeric_limits;

/* algorithm */
using std::find;
using std::remove;
using std::remove_if;
using std::reverse;

using std::max;
using std::min;

using std::swap;

namespace cpp_util
{
    string toString(const vector<vector<char>> &charVector2);
    string toString(const vector<char> &charVector);

    string toString(const int *intArray, const int &size);
    string toString(const vector<int> &intVector);
    string toString(const vector<vector<int>> &intMatrix);

    string toString(ListNode *start);
    string toString(TreeNode *start);

    int randomBetween(const int &start, const int &end);
};

