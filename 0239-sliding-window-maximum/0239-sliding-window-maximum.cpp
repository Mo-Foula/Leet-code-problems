class Solution
{
    public:
        vector<int> maxSlidingWindow(vector<int> &nums, int k)
        {
            map<int, int> currentWindow;
            priority_queue<int> currentHighestForAllNumbers;
            vector<int> result(nums.size() - k + 1);
            vector<int>::iterator resultIndexIt = result.begin(), start, next;

            for (int i = 0; i < k; i++)
            {
                currentHighestForAllNumbers.push(nums[i]);
                currentWindow[nums[i]]++;
            }

            *resultIndexIt = (currentHighestForAllNumbers.top());
            resultIndexIt++;
            start = nums.begin();
            next = nums.begin() + k;

            while (next != nums.end())
            {
                currentWindow[*start]--;
                currentWindow[*next]++;
                currentHighestForAllNumbers.push(*next);

                while (!currentWindow[currentHighestForAllNumbers.top()])
                {
                    currentHighestForAllNumbers.pop();
                }
                *resultIndexIt = currentHighestForAllNumbers.top();

                resultIndexIt++;
                next++;
                start++;
            }

            return result;
        }
};