class Solution {
    public void setZeroes(int[][] matrix) {
         int row = matrix.length;
        int col = matrix[0].length;

        int r = 1;
        int c = 1;

        for(int i=0; i<row; i++){
            if(matrix[i][0] == 0){
                c = 0;
            }
        }

        for(int i=0; i<col; i++){
            if(matrix[0][i] == 0){
                r = 0;
            }
        }

        for(int i=0; i<row; i++){
            for(int j =0; j<col; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for(int i=1; i<col; i++){
            if(matrix[0][i]== 0){
                for(int j=0; j<row; j++){
                    matrix[j][i] = 0;
                }
            }
        }

        for(int i=1; i<row; i++){
            if(matrix[i][0]== 0){
                for(int j=0; j<col; j++){
                    matrix[i][j] = 0;
                }
            }
        }

        if(c == 0){
            for(int i=0; i<row; i++){
                matrix[i][0] = 0;
            }
        }

        if(c == 0){
            for(int i=0; i<row; i++){
                matrix[i][0] = 0;
            }
        }

        if(r == 0){
            for(int i=0; i<col; i++){
                matrix[0][i] = 0;
            }
        }
    }
}