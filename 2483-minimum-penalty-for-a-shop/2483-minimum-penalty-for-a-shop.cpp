class Solution {
public:
    int bestClosingTime(string customers) {
        int size = customers.size();
        
        vector<int> closedBefore(size + 1);
        vector<int> openAfter(size + 2);
        
        closedBefore[0] = 0;
        openAfter[size + 1] = 0;
        
        for (int i = 1; i <= size; ++i){
            closedBefore[i] = closedBefore[i-1] + (customers[i-1] == 'N');
        }
        
        for (int i = size; i >= 0; --i){
            openAfter[i] = openAfter[i+1] + (customers[i] == 'Y');
        }
        
        int mn = size + 1;
        int mnIndex = 0;
        
        int temp;
        
        for(int i = 0; i <= size; ++i){
            temp = openAfter[i] + closedBefore[i];
            if (mn > temp){
                mn = temp;
                mnIndex = i;
            }
        }
        
        return mnIndex;
    }
};