class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        

        if( hand.size() % groupSize != 0 )
        {
            return false;
        }

        map< int, int > mp;
        for(auto i: hand )
        {
            mp[i]++;
        }

        for(auto [value, freq] : mp )
        {
            if( freq == 0 )
            {
                continue;
            }

            while( freq-- )
            {
                for(int i = value; i < value + groupSize; i++ )
                {
                    if( mp[i] == 0 )
                    {
                        return false;
                    }

                    mp[i]--;
                }
            }
        }

        return true;
    }
};