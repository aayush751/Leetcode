class Solution {
public:
    
    // int maxRow( vector<vector<int>>& arr, int k, int row )
    // {
        
    //     return rowMax;
    // }
    
    vector<vector<int>> sortTheStudents(vector<vector<int>>& arr, int k) {

       vector<vector<int>> ans;
       int size = arr.size();
       int row = -1;
       unordered_map< int, bool > mp;
       bool flag = false; 

       while( size-- )
       {
            int score = INT_MIN;
            int rowMax = -1;
            vector< int > temp;

            for(int i = 0; i < arr.size(); i++ )
            {
                if( flag == false or mp[i] != true )
                {
                    flag = true;
                    for(int j = 0; j < arr[0].size(); j++ )
                    {
                        if( j == k )
                        {
                            if( arr[i][j] > score )
                            {
                                score = arr[i][j];
                                rowMax = i;
                            }
                        }
                    }
                }
            }

            int idx = rowMax;
            mp[idx] = true;

            for(int i = 0; i < arr[0].size(); i++ )
            {
                temp.push_back( arr[idx][i] );
            }
            ans.push_back( temp );
        }

       return ans;
    }
};