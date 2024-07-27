class Solution {
public:
    typedef long long ll;

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<ll>> dis(26,vector<ll>(26,1e12));

        for(int i=0;i<26;i++)
        {
            dis[i][i] = 0;
        }

        int m=original.size();
        for(int i=0;i<m;i++)
        {
            int from = original[i] -'a';
            int to = changed[i] -'a';

            dis[from][to] = min(dis[from][to], cost[i]*1ll);
        }

        for(int k=0;k<26;k++)
        {
            for(int i=0;i<26;i++)
            {
                for(int j=0;j<26;j++)
                {
                    dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
                }
            }
        }

        int n= source.size();
        ll ans=0;
        for(int i=0;i<n;i++)
        {
            int src = source[i]-'a';
            int des = target[i]-'a';

            if(dis[src][des]==1e12)
            {
                return -1;
            }
            ans+= dis[src][des] ;
        }

        return ans;

    }
};

// source -> target
// we need to convert this source to target by changing each and every char to the target 

// or[i] -> cha[i] -> cost[i] ->this cost should be minimum 

// 1) edge case
// // a -> b -> x
// // a-> b -> y

// 2) if we are not able to convert any char to target char then return -1;


// source = "abcd", target = "acbe", 
// original = ["a","b","c","c","e","d"], 
// changed =  ["b","c","b","e","b","e"], cost = [2,5,5,1,2,20]

// ans = 5+3+20= 28
// b -> c = 5
// c -> b = 5
// c->e->b = 1+2 = 3
// d->e = 20

// how will you convert any char to some other char in minimum cost 

// take cost analog to dist 

// can we think it like a graph ?
// nodes-> a to z
// edges -> org[i]  to change[i] with weight as cost[i]/dis[i]
// this needs to be change in minimum cost 

// yesterday for each and every node, we need to convert it ->

// total nodes -> 26

// any shortest algo which you can solve (Dikshtra, floyd warshall)


// Floyd warshall -> intermediate node as help to find the minimum dist/cost(here) between two pair of nodes(alphabets)
//     intermediate node
// 1 ....k..... 2

// 0<=k<n
// dis[1][2] = min(dis[1][k] + dis[k][2])

// i know all the minimum cost of converting any char to any char 

// return add all the minimum cost which needs to take the conversion from source to target and return the summation of all cost as our answer