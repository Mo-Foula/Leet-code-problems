class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
    map<char,int> m;
    if(ransomNote.size() > magazine.size()) return false;
    for(char c : magazine){
        m[c]++;
    }

    for(char c : ransomNote){
        if(!m[c]) return false;
        m[c]--;
    }
    return true;
    
}
};