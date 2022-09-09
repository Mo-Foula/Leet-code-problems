   
bool compNumberOfWeakCharacters(vector<int>& a, vector<int>& b){
   
    if(a[0] == b[0]){
        return a[1] < b[1];
    }
    return a[0] < b[0];
}
class Solution {
    
public:
    


int numberOfWeakCharacters(vector<vector<int>>& properties) {

    vector<int> maxDefenses(1e5+1,-1);
    
    for(auto agent : properties){
        maxDefenses[agent[0]] = max(maxDefenses[agent[0]],      agent[1]);
    }

    sort(properties.begin(),properties.end(), compNumberOfWeakCharacters);

    int index = properties.size()-1;
    int maxAttack = properties[index][0];


//    int maxDef = properties[properties.size()-1][1];
    int maxDef = maxDefenses[maxAttack];
    int weakNumbers = 0 ;


    // preparing maximum defense in my attack or bigger attacks
    for (int i = maxAttack-1; i > 0 ; --i) {
        maxDef = max(maxDefenses[i], maxDef);
        maxDefenses[i] = maxDef;
    }


    // start of looping on characters
    while(index > 0 && properties[index][0] == maxAttack){
        index--;
    }

    for (; index >= 0 ; --index) {
        if(properties[index][1] < maxDefenses[properties[index][0] + 1]){
            weakNumbers++;
        }
    }

    return weakNumbers;

}
};