// FOR REFERENCE ONLY

class Solution {
public:
    int candy(vector<int>& ratings) {
        int candies = ratings.size();
        int prevCandies = 0;
        vector<int> added = vector(ratings.size(), 0);

        for (int i = 1; i < ratings.size(); ++i){
            if (ratings[i] > ratings[i-1]){
                ++prevCandies;
                added[i] = prevCandies;
            } else {
                prevCandies = 0;
            }
        }
        for (int i = ratings.size() - 2; i >= 0; --i){
            if (ratings[i] > ratings[i+1]){
                ++prevCandies;
                added[i] = max(prevCandies,added[i]);
            } else {
                prevCandies = 0;
            }
        }
        for (int k : added){
            candies += k;
        }
        return candies;
    }
};

// 6 
// 1 2 3
// 1 2 | 4 3 2 1 

// 4 5 6 6 4 3 2 1
// 0 1 2 2 2 2 2 2
// 4 4 4 4 3 2 1 0