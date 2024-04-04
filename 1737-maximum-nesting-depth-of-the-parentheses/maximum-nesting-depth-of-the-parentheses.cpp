class Solution {
public:
    int maxDepth(string s) {
        int depth = 0;
        int maxi_depth = 0;
        for(int i = 0; i < s.size(); i++ )
        {
            if( s[i] == '(' )
            {
                depth++;
            }
            else if( s[i] == ')' )
            {
                depth--;
            }

            maxi_depth = max( maxi_depth, depth );
        }

        return maxi_depth;
    }
};