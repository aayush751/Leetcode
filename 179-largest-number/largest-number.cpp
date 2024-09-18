class Solution {
public:

    string largestNumber(vector<int>& nums) {
        vector< string > numStr;

        for(int i = 0; i < nums.size(); i++ )
        {
            numStr.push_back( to_string( nums[i] ) );
        }

        sort( numStr.begin(), numStr.end(), []( string& a, string& b ) -> bool 
        {
            return a + b > b + a;
        });

        if( numStr[0] == "0" )
        {
            return "0";
        }

        string ans;

        for( string& i: numStr )
        {
            ans += i;
        }

        return ans;
    }
};