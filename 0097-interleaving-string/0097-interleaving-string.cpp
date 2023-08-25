class Solution
{
    public:
        map<pair<int, int>, bool> memo_isInterleaveRecursive;
    bool isInterleaveRecursive(string &s1, string &s2, string &s3, int i1, int i2, int n, int m)
    {
        if (i1 + i2 >= s3.size() && i1 == s1.size() && i2 == s2.size())
        {
            // if (!s1.empty() && !s2.empty())
            //     return abs(n - m) <= 1;
            return true;
        }

        if (memo_isInterleaveRecursive.find({ i1,
                i2 }) != memo_isInterleaveRecursive.end())
        {
            return memo_isInterleaveRecursive[
            {
                i1,
                i2
            }];
        }

        char c = s3[i1 + i2];

        bool secondString = false, firstString = false;
        
        if (i1 < s1.size())
            firstString = s1[i1] == c ? isInterleaveRecursive(s1, s2, s3, i1 + 1, i2, n + 1, m) : false;
        if (!firstString && i2 < s2.size())
            secondString = s2[i2] == c ? isInterleaveRecursive(s1, s2, s3, i1, i2 + 1, n, m + 1) : false;

        bool result = firstString || secondString;
        memo_isInterleaveRecursive[
        {
            i1,
            i2
        }] = result;

        return result;
    }

    bool isInterleave(string s1, string s2, string s3)
    {
       	// if (s1.empty() || s2.empty()) return false;
        return isInterleaveRecursive(s1, s2, s3, 0, 0, 0, 0);
    }
};