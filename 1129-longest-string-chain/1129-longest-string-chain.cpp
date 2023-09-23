class Solution {
public:
    unordered_map<string, int> dp;
    int longestStrChain_R(unordered_set<string>& wordsSet, string word){
        if (wordsSet.find(word) == wordsSet.end())
            return 0;
        if (dp.find(word) != dp.end())
            return dp[word];

        int bestAns = 0;
        for (int i = 0; i < word.size(); ++i){
            string newWord = word.substr(0,i)+word.substr(i+1);
            bestAns = max(bestAns,longestStrChain_R(wordsSet, newWord));
        }

        return dp[word] = bestAns + 1;
    }
    int longestStrChain(vector<string>& words) {
        unordered_set<string> wordsSet;
        for(string w : words){
            wordsSet.insert(w);
        }
        int bestAns = 1;
        for(string w : words){
            bestAns = max(bestAns,longestStrChain_R(wordsSet, w));
        }
        return bestAns;
    }
};

/*
abcd
acd
ac
a
*/