class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        // int n = edges.size();
        vector< int > indegree(n);
        for( vector< int > & edge: edges )
        {
            int u = edge[0];
            int v = edge[1];

            indegree[v]++;
        }

        int count = 0;
        int champ = -1;

        for( int i = 0; i < n; i++ )
        {
            if( indegree[i] == 0 )
            {
                champ = i;
                count++;

                if( count > 1 )
                {
                    return -1;
                }
            }
        }

        return champ;
    }
};