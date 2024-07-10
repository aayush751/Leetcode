class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        
        vector<int> ans;

        for(int i = 0; i < nums.size(); i++ )
        {
            string temp = to_string( nums[i] );
            for( auto ch: temp )
            {
                ans.push_back( ch - '0' );
            }
        }

        return ans;
    }
};