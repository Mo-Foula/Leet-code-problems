class Solution {
public:
    vector<int> result;
    void dfs(int n,int k, int curr){
        // cout<<curr<<endl;
        if(n == 1){
            result.push_back(curr);
            return;
        }
        int t = curr%10;
        int next= t - k;
        
            if(next >= 0) 
            dfs(n-1,k,curr*10+next);
        // while(true){
        //     next -= k;
        // }
        
        int tnext=  k + t;
        
            if(tnext != next && tnext <= 9 ) 
            dfs(n-1,k,curr*10+tnext);
        // while(true){
        //     next += k;
        // }
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        for(int i = 1; i <= 9; i++){
            dfs(n,k,i);
        }
        return result;
    }
};