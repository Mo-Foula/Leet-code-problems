class Solution {
public:

int totalFruit(vector<int>& fruits) {
    vector<pair<int,     int> > grouped_fruits;
    //         counter,  fruit
    int prev_char = -1;
    for(int x : fruits){
        if(x != prev_char){
            prev_char = x;
            grouped_fruits.emplace_back(1,x);
        }else{
            grouped_fruits.back().first++;
        }
    }

    if(grouped_fruits.empty()) return 0;
    int trees = grouped_fruits[0].first;
    if(grouped_fruits.size() > 1) {
        trees = 2;
        int trees_counter = grouped_fruits[0].first + grouped_fruits[1].first;
        int first_fruit = grouped_fruits[0].second, second_fruit = grouped_fruits[1].second;
        for (auto itr = grouped_fruits.begin()+2; itr != grouped_fruits.end(); itr++) {
            if ((*itr).second == first_fruit || (*itr).second == second_fruit) {
                trees_counter+= (*itr).first;
            } else {
                trees = max(trees,trees_counter);
                trees_counter = (*(itr-1)).first + (*(itr)).first;
                first_fruit = (*(itr-1)).second;
                second_fruit = (*itr).second;
            }
        }
        trees = max(trees,trees_counter);
    }
    return trees;
}

};