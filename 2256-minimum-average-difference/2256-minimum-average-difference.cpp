class Solution
{
    public:
        vector < long long > prefixSumZeroBased(vector<int> &nums)
        {
            vector < long long > prefix(nums.size());
            long long sum = 0;
            for (int i = 0; i < nums.size(); ++i)
            {
                sum += nums[i];
                prefix[i] = sum;
            }
            return prefix;
        }

    vector < long long > suffixSumZeroBased(vector<int> &nums)
    {
        vector < long long > suffix(nums.size());
        long long sum = 0;
        for (int i = nums.size() - 1; i >= 0; --i)
        {
            sum += nums[i];
            suffix[i] = sum;
        }
        return suffix;
    }

    int minimumAverageDifference(vector<int> &nums)
    {
        vector < long long > prefix = prefixSumZeroBased(nums);
        vector < long long > suffix = suffixSumZeroBased(nums);

        long long minimum = LONG_LONG_MAX;
        int index = -1, n = nums.size();

        long long firstHalf, secondHalf, calculated;

        for (int i = 0; i < nums.size() - 1; ++i)
        {
            firstHalf = floor(prefix[i] / (i + 1.0));
            secondHalf = floor(suffix[i + 1] / (n - i - 1.0));

            calculated = abs(firstHalf - secondHalf);
            if (calculated < minimum)
            {
                minimum = calculated;
                index = i;
            }
        }
       	// Handle last element
        calculated = floor(prefix[n - 1] / (n));
        if (calculated < minimum)
        {
            minimum = calculated;
            index = n - 1;
        }

        return index;
    }
};