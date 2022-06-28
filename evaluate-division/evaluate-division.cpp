class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string,double>>> graph;
        
        for(int i = 0; i < equations.size(); i++){
            vector<string> equation = equations[i];
            string dividend = equation[0];
            string divisor = equation[1];
            double quotient = values[i];
            
            graph[dividend].push_back(make_pair(divisor,quotient));
            graph[divisor].push_back(make_pair(dividend,(double)1/quotient));
        }
        vector<double> result;
        for(int i = 0; i < queries.size(); i++){
            vector<string> query = queries[i];
            string dividend = query[0];
            string divisor = query[1];
            if(graph.find(dividend) == graph.end() || graph.find(divisor) == graph.end()){
                result.push_back(-1.0);
            }
            else if(dividend == divisor){
                result.push_back(1.0);
            }
            else{
                set<string> visited;
                result.push_back(backtrackEvaluate(graph,dividend,divisor,1,visited));
            }
        }
        return result;
    }
    double backtrackEvaluate(unordered_map<string,vector<pair<string,double>>> graph, string currnode, string targetnode, double accproduct, set<string>& visited){
        visited.insert(currnode);
        double ret = -1.0;
        
        vector<pair<string,double>> neighbors = graph[currnode];
        for(int i = 0; i < neighbors.size(); i++){
            if(neighbors[i].first == targetnode){
                ret = accproduct * neighbors[i].second;
                visited.erase(currnode);
                return ret;
            }
        }
        for(auto pair : neighbors){
            string nextnode = pair.first;
            if(visited.count(nextnode)){
                continue;
            }
            ret = backtrackEvaluate(graph,nextnode,targetnode,accproduct * pair.second,visited);
            if(ret != -1){
                break;
            }
        }
        visited.erase(currnode);
        return ret;
    }
};