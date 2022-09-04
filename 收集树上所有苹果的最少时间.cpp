class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        int i, ret = 0;
        for (i = edges.size() - 1; i >= 0; i--) 
            if (hasApple[edges[i][1]] == true) 
                hasApple[edges[i][0]] = true;    
        for (i = 0; i < edges.size(); i++) 
            if (hasApple[edges[i][1]] == true)
                ret += 2;
        return ret;
    }
};
