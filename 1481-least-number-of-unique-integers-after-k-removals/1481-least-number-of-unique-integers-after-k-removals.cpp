class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
         map<int,    int> count;
        // number, count

        for(int number : arr){
            count[number]++;
        }
        priority_queue<int, vector<int>, greater<int> > pq;
        // sort by smaller
        for(map<int,int>::iterator it = count.begin(); it != count.end(); it++){
            pq.push((*it).second);
        }
        while(!pq.empty() && k>=pq.top()){
            k-=pq.top();
            pq.pop();
        }
        return pq.size();
    }
};