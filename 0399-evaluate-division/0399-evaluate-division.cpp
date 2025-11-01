class Solution {
public:
    unordered_map<string,unordered_map<string,double>> map;
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        vector<double> result;
        for(int i = 0; i < equations.size(); i++){
            string numerator = equations[i][0];
            string denaminator = equations[i][1];
            double value = values[i];
            map[numerator][denaminator] = value;
            map[denaminator][numerator] = 1/value;
        }

        for(auto& q : queries){
            result.push_back(helper(q[0], q[1], unordered_set<string>{}));
        }
        return result;
    }
    double helper(string numerator, string denaminator, unordered_set<string> set){
        if(map.find(numerator) == map.end() || map.find(denaminator) == map.end()) return -1.0;
        if(numerator == denaminator){
            return 1.0;
        }
        for(auto& [neighbor, val] : map[numerator]){
            if(set.count(neighbor)) continue;
            set.insert(neighbor);
            double result = helper(neighbor, denaminator,set);
            if(result != -1.0){
                return result * val;
            }
        }
        return -1.0;
    }
};