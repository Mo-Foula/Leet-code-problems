class Solution {
public:
    int strStr(string haystack, string needle) {
        int found = -1;
        for (int i = 0; i < haystack.size() && found == -1; ++i){
            if (haystack[i] == needle[0]){
                int k = i + 1, j = 1;
                for (; j < needle.size() && k < haystack.size(); ++j){
                    if (haystack[k++] != needle[j]){
                        break;
                    }
                }
                if (j == needle.size())
                    found = i;
            }
        }
        return found;
    }
};