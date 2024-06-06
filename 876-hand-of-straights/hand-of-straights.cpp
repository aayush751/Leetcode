class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int size) {
        // sort( begin(hand), end(hand) );

        if( hand.size() % size != 0)
        {
            return false;
        }

        map< int, int > mp;
        for(auto ele: hand )
        {
            mp[ele]++;
        }

        // int groupSizeCount = 0;
        // int value = hand[0];
        // int ans = 0;
        // while(1)
        // {
        //     if( groupSizeCount == size )
        //     {
        //         value = hand[0];
        //         groupSizeCount = 0;
        //         ans++;
        //     }

        //     if( mp.find( value ) != mp.end() )
        //     {
        //         mp[value]--;
        //         value++;
        //         groupSizeCount++;
        //     }
        //     else
        //     {
        //         value++;
        //     }

        //     if( ans == size )
        //     {
        //         break;
        //     }
        // }

        // return ans % size == 0;

        for(auto it = mp.begin(); it != mp.end(); it++ )
        {
            int currValue = it -> first;
            int count = it -> second;

            if( count > 0 )
            {
                for(int i = 0; i < size; i++ )
                {
                    if( mp[currValue + i] < count )
                    {
                        return false;
                    }

                    mp[currValue + i] -= count;
                }
            }
        }
        return true;
    }
};