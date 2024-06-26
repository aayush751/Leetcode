class Solution {
public:

    void reverse( vector< int > & arr )
    {
        int i = 0, j = arr.size() - 1;
        while( i < j )
        {
            swap( arr[i], arr[j] );
            i++;
            j--;
        }
    }
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {


        for(int i = 0; i < image.size(); i++ )
        {
            reverse( image[i] );
        }

        for(int i = 0; i < image.size(); i++ )
        {
            for(int j = 0; j < image[0].size(); j++ )
            {
                if( image[i][j] == 0 )
                {
                    image[i][j] = 1;
                }
                else
                {
                    image[i][j] = 0;
                }
            }
        }

        return image;
    }
};