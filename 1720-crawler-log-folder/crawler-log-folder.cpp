class Solution {
public:
    int minOperations(vector<string>& logs) {
        int depth = 0;

        for(auto log: logs )
        {
            if( log != "../" and log != "./")
            {
                depth++;
            }
            else if( log == "../" )
            {
                if( depth != 0 )
                {
                    depth--;
                }
            }
        }

        return depth;
    }
};