class Solution {
public:
    int countSeniors(vector<string>& details) {
        
        int count = 0;
        
        for(int i = 0; i < details.size(); i++ )
        {
            int j = 2;
            int age = 0;
            int power = 0;
            int idx = 11;
            while( j-- )
            {
                age = age * pow(10, power++ ) + details[i][idx++] - '0';
            }

            if( age > 60 )
            {
                count++;
            }
        }
        return count;
    }
};