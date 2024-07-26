class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dis(n,vector<int>(n,1e7));

        for(int i=0;i<n;i++)
        {
            dis[i][i]=0;
        }

        for(auto e:edges)
        {
            dis[e[0]][e[1]] = e[2]; //[from][to] = dist
            dis[e[1]][e[0]] = e[2]; //[to][from] = dist
        }

        // we will find the distance between each node to every other nodes 

        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
                }
            }
        }

        //we will find the count of cities
        int mn=INT_MAX, ans_node = n+1;
        for(int i=0;i<n;i++)
        {
            int count=0;
            for(int j=0;j<n;j++)
            {
                if(i!=j && dis[i][j]<=distanceThreshold)
                {
                    count++;
                }
            }
            if(count<=mn)
            {
                mn=count;
                ans_node= i;
            }
        }

        return ans_node;

    }
};

// find out the city number -> from this city number , we can reach to the smallest number of cities through any path within the threshold distance 

// weight. -> dist between the nodes which is connected

// 0 -> 1,2
// 1 -> 2,0,3
// 2 -> 3,1,0
// 3 -> 1,2

// 0,3 -> 
// ans = 3

// basically, we need to find the distance from each node to every other node 

// Floyd Warshall Algorithm -> 

// we need to find the minimum distance 
//         intermediate node
// i                k               j

// 0<=k<n
// (dis[i][k] + dis[k][j]) -> we can simply know the distance betwee dis[i][j]

// 3           0

// INT_MAX
// [3][0]+[0][0 
// [3][1] + [1][0]
// [3][2] +[2][1]
// [3][3] + [3][2]

// among these the value which will be minimum gives me the dis[i][j] -> dis[3][0]

// dis-> 2D matrix -> we need to check for each and every node by taking that node as intermediate

// we will find the distance between each node to every other nodes 

// we will again from each to every other node and check that min dist we have find between the pair of nodes <= th_dis
// we will just count it 

// and the node which has minimum count would be the answer and the nodes whose value is greater then that will be our answer 