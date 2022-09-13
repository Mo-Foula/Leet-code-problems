class Solution {
public:
    bool validUtf8(vector<int>& data) {
        bool valid = true;
        auto it = data.begin();
        
        vector<int> possibleNumbers ={0,  128+64, 128+64+32,128+64+32+16, 128+64+32+16+8, 256};
        //                            v        v        v           v       n
        int indexFound,M;
        
        while(it != data.end() && valid){
            
            // 0  128+64  128+64+32  128+64+32+16
            indexFound= upper_bound(possibleNumbers.begin(), possibleNumbers.end(), *it) - possibleNumbers.begin() -1;
            if((indexFound == 0 && *it >= 128 ) || indexFound == 4){
                valid = false; break;
            }
            while(indexFound--){
                it++;
                
                if(it == data.end() || !(*it >= 128 && *it <128+64 )){
                    // problem
                    valid = false;
                    break;
                }
            }
            it++;
            
            
        }
        
        return valid;

        
    }
};