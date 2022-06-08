class Solution {
public:
    int removePalindromeSub(string s) {
        string rev = s;
        reverse(rev.begin(),rev.end());
        if(s == rev)
            return 1;
        else if(s.find('a') != string::npos){
            if(s.find('b') != string::npos){
                return 2;
        }else{
            return 1;
        }
        }else{
            return 1;
        }
        return 0;
    }
};