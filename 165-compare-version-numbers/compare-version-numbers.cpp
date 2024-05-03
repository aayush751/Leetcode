class Solution {
public:
    int compareVersion(string v1, string v2) {
        int n1 = v1.size(), n2 = v2.size();


        int i = 0, j = 0;

        while( i < n1 or j < n2 )
        {
            int var1 = 0, var2 = 0;
            while( i < n1 and v1[i] != '.' )
            {
                var1 = var1 * 10 + (v1[i] - '0');
                i++;
            }
            i++;

            while( j < n2 and v2[j] != '.' )
            {
                var2 = var2 * 10 + (v2[j] - '0');
                j++;
            }
            j++;

            if( var1 < var2 )
            {
                return -1;
            }
            else if( var1 > var2 )
            {
                return 1;
            }
        }

        return 0;
    }
};