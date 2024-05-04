class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort( begin(people), end( people) );

        int i = 0, j = people.size() - 1;

        int ans = 0;
        while( i <= j )
        {
            if( people[i] + people[j] <= limit )
            {
                ans++;
                i++;
                j--;
            }
            else
            {
                ans++;
                j--;
            }
        }

        return ans;
    }
};