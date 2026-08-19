class Solution {
public:
    bool dfs(int node,int currentColor,vector<vector<int>>& graph,vector<int>& color){
	color[node]=currentColor;
	
	    for(auto neighbour:graph[node]){
		    if(color[neighbour]==-1){
			    if(!dfs(neighbour,1-currentColor,graph,color)){
			    return false;
                }
		    }
	        else if(color[neighbour]==color[node]){
		        return false;
		    }
	}
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph){
	    int n=graph.size();
	    vector<int> color(n,-1);
	
	    for(int i=0;i<n;i++){   
		    if(color[i]==-1){
			    if(!dfs(i,0,graph,color)){
			    return false;
                }
			
		    }
        } 
	
	    return true;
    }

};   