class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int score = 0;
        int maxScore = 0;
        
        if(tokens.size() == 0) return 0;
        
        sort(tokens.begin(),tokens.end());
        
        auto it = tokens.begin();
        auto it2 = tokens.end()-1;
        
        while(it <= it2){
            if(*it <= power){
                power -= *it;
                it++;
                score++;
                maxScore = max(maxScore,score);
            }
            else if(score){
                // consume token and add power
                score--;
                power += *it2;
                it2--;
            }
            else break;
        }
        return maxScore;
    }
};