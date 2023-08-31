class Solution
{
    public:

        static bool compare(pair<int, int> a, pair<int, int> b)
        {
            if (a.first == b.first)
                return a.second > b.second;
            return a.first < b.first;
        }

    int minTaps(int n, vector<int> &ranges)
    {

       	//         start end
        vector<pair<int, int>> intervals;

        for (int i = 0; i < ranges.size(); ++i)
        {
            if (ranges[i] > 0)
                intervals.push_back({ max(i - ranges[i], 0),
                    min(i + ranges[i], n) });
        }
       	//[3,4,1,1,0,0]
       	// (0,3) (0,5) (1,3) (2,4) (4,4) (5,5)
       	// After sorting: (0,5) (0,3) (1,3) (2,4) (4,4) (5,5)

       	//[0,       5,0,3,3,3,   1,4,0,4]
       	// (0,0) (0, 6) (0,0) (0,6) (1,7) (2,8) (5,7) (3, 11) (0,0) (5, 13)
       	// sorted: (0,6) (0,6) (0,0) (0,0) (0,0) (1,7) (2,8) (3, 11) (5,13) (5,7) | (10, 12)

       	// search: (start <= 7, end as big as possible)

        sort(intervals.begin(), intervals.end(), compare);

        int indexToBeCovered = 0, usedTaps = 0;
        auto it = intervals.begin();

        int bestEnd = 0;

        while (it != intervals.end() && indexToBeCovered <= n)
        {
            if (it->first > bestEnd) return -1;

            if (it->first > indexToBeCovered)
            {
                ++usedTaps;
                indexToBeCovered = bestEnd;
            }

            bestEnd = max(bestEnd, it->second);
            ++it;
        }

        if (indexToBeCovered < bestEnd)
        {
            ++usedTaps;
            indexToBeCovered = bestEnd;
        }

        if (indexToBeCovered < n)
        {
            return -1;
        }
        return usedTaps;
    }
};