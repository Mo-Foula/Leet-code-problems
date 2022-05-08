class Solution {
public:

map<string,bool> visitedCalcEquation;
map<string,vector<pair<string,double>>> wg;//char , weighted graph: char, cost
//  char orig           char  weight


pair<bool,double> dfsCalcEquation(string here,string target,double value){
    if(visitedCalcEquation[here]) return {false,0};
    visitedCalcEquation[here] = true;
    if(here == target)
        return {true,value};
    for(const auto& connection : wg[here]){
        auto res = dfsCalcEquation(connection.first,target,value*connection.second);
        if(res.first) 
            return res;
    }
    return {false,-1};
}

vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {

    for(int i = 0; i < equations.size(); i++){
        auto val = values[i];
        wg[equations[i][0]].emplace_back(equations[i][1],val);
        wg[equations[i][1]].emplace_back(equations[i][0],1.0/val);
    }
    vector<double> answer;
    for(auto query: queries){
        if(wg.find(query[0]) == wg.end() || wg.find(query[1]) == wg.end()){

            answer.push_back(-1);
        }else if(query[0] == query[1]){
            answer.push_back(1);
        }
        else{
            answer.push_back(dfsCalcEquation(query[0],query[1],1).second);
            visitedCalcEquation.clear();
        }
    }
    return answer;
}

};