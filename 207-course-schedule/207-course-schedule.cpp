class Solution {
public:
    
    //detct the cycle in graph 
    bool iscycle(vector<int> adj[], vector<int>&visit,int node){
        if(visit[node]==1){
            return true; 
        }
        
        if(visit[node]==0){
            visit[node]= 1;
            for(auto x: adj[node]){
                if(iscycle(adj,visit,x)){
                    return true;
                }
            }
        }
        
        visit[node]=2;
        return false;
        
    }
    
    
    bool canFinish(int numc, vector<vector<int>>& pqt) {
       // unordered_map<int,vector<int>>adj;
        //graph is ready 
        vector<int>adj[numc];
        
        for(auto x: pqt){
             adj[x[1]].push_back(x[0]);
        }
        
        //visit vector
        vector<int>visit(numc,0);
        
        for(int i =0; i<numc; i++){
            if(iscycle(adj,visit,i)){
                return false;
            }
        }
        return true;
    }
};