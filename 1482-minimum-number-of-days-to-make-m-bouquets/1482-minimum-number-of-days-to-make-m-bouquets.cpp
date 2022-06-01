class Solution {
public:
    
bool calculateBouqets(vector<int>& bloomDay, int m,int k, int days){
    int calc = 0,innerCounter= 0;
    for(int i = 0; i < bloomDay.size();i++){
        if(bloomDay[i] <= days){
            innerCounter++;
        }else{
            innerCounter = 0;
        }
        if(innerCounter == k){
            innerCounter = 0;
            calc++;
        }
        if(calc == m)
            return true;
    }
    return false;
}
int first_true_mindays(vector<int>& bloomDay, int first, int last, int mm, int k){
    int ans = -1,mid;
    while(first <= last){
        mid = first + (last-first)/2;
        if(calculateBouqets(bloomDay, mm, k, mid)){
            last = mid-1;
            ans = mid;
        }else{
            first = mid+1;
        }
    }
    return ans;
}
int minDays(vector<int>& bloomDay, int m, int k) {
    int mn=bloomDay[0];
    int mx = mn;
    for(int i = 1; i < bloomDay.size();i++){
        mx = max(mx,bloomDay[i]);
        mn = min(mn,bloomDay[i]);
    }
    return first_true_mindays(bloomDay, mn,mx,m,k);
}

};