class Solution {
public:
    static int comp( const vector<int>& u, const vector<int>& v ){ 
        return u[1] > v[1]; 
};
int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        // boxTypes[i] = [numberOfBoxesi, numberOfUnitsPerBoxi];
    int max_N = 0;
    sort(boxTypes.begin(), boxTypes.end(), comp );
    for(int i = 0; i < boxTypes.size() && truckSize>0; i++){
        while( boxTypes[i][0] && truckSize-->0){
            max_N += boxTypes[i][1];
            boxTypes[i][0]--;
        }
    }
    return max_N;
}
};