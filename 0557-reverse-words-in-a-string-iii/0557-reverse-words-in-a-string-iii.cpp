class Solution {
public:

    void reverseString(string& s, int start, int end){
        int j = end - 1;
        char temp;
        for(int i = start; i < j; ++i, --j){
            temp = s[i];
            s[i] = s[j];
            s[j] = temp;
        }
    }

    string reverseWords(string s) {
        auto prevIt = 0;
        auto it = s.find(' ');

        while(it != s.npos){
            reverseString(s, prevIt, it);
            prevIt = it+1;
            it = s.find(' ', it + 1);
        }
        reverseString(s, prevIt, s.size());
        return s;
    }
};