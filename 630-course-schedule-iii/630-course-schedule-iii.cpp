class Solution {
public:
    
    static bool com_fun(vector<int>& a,vector<int>& b){
	    return a[1]<b[1];
    }

    
    int scheduleCourse(vector<vector<int>>& courses) {
        priority_queue<int> pq;
        //          duration;
        int time = 0,counter = 0;
        // sort on last
        sort(courses.begin(),courses.end(),com_fun);
        
        int duration,last;
        for(auto course : courses){
            duration = course[0];
            last = course[1];
            if(duration + time <= last){
                // insert normally
                pq.push(duration);
                time += duration;
                counter++;
            }else if(!pq.empty() && pq.top() > duration){
                time -= pq.top();
                pq.pop();
                pq.push(duration);
                time += duration;
            }
        }
        return counter;
    }
};