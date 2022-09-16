class Solution
{
    public:
        vector<int> findOriginalArray(vector<int> &changed)
        {
            sort(changed.begin(), changed.end());

            vector<int> frequencies(2e5 + 9);
            set<int> numbers;
           	//  number   

            for (int i = 0; i < changed.size(); i++)
            {
                numbers.insert(changed[i]);
                frequencies[changed[i]]++;
            }
    
            vector<int> answer;
            if(changed.size()%2 != 0) return answer;
            
            int twice;
            for (auto n : numbers)
            {
                if(frequencies[n] <= 0) continue;
                
                if(n == 0){
                    if(frequencies[0]%2 == 0){
                        // even
                        
                        for(int i = 1; i <= frequencies[0]/2 ; i++){
                            answer.push_back(0);
                        }
                    }
                    frequencies[0] = 0;
                    continue;
                }
                
                twice = n * 2;
                
                if (frequencies[twice] >= frequencies[n]){
                        frequencies[twice] -= frequencies[n] ;
                    for(int i = 0; i < frequencies[n] ; i++){
                        answer.push_back(n);
                    }
                        frequencies[n] = 0;
                        
                }else{
                    answer.clear();
                    break;
                }
            }
            return answer;
        }
};