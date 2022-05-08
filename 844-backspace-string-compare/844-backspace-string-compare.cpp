class Solution {
public:
    
bool backspaceCompare(string s, string t) {
    stack<char> s1,s2;
    for(auto x : s){
        if(x == '#'){
            if(!s1.empty())
                s1.pop();
        }else{
            s1.push(x);
        }
    }
    for(auto x : t){
        if(x == '#'){
            if(!s2.empty())
                s2.pop();
        }else{
            s2.push(x);
        }
    }
    while(!s1.empty() && !s2.empty()){
        if(s1.top() != s2.top())
            return false;
        s1.pop();s2.pop();
    }
    return s1.empty() && s2.empty();
}
};