class Solution {
public:
    int countPartitions(vector<int>& nums) {
       

        int left =0;
        int total =0;
        int count =0;

        for(int i: nums){
            total+=i;
        }
        for(int i: nums){
            left+=i;
            if(left==total){
                break;
            }

            if(abs(total-2*left)%2==0){
                count++;
            }
        }

        return count;
    }
};