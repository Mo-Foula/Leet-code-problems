class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);

    int length = s.size();
    
    for (int i = 0; i < length ; ++i) {
        if(s[i] != s[length-1-i]) return false;
    }
    return true;
    }
};