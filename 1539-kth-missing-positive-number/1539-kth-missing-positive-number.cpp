class Solution
{
    public:
        int findKthPositive(vector<int> &arr, int k)
        {
            vector<int> missing;
            int current = 1;
            int index = 0;
            while (missing.size() < k)
            {
                if (index < arr.size() && arr[index] == current)
                    ++index;
                else
                    missing.push_back(current);
                ++current;
            }
            return missing[k - 1];
        }
};