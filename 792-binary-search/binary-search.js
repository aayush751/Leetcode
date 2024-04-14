/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var search = function(nums, target) {
    let start = 0, end = nums.length - 1;

    let mid = Math.floor((start + end) / 2);

    while( start <= end )
    {
        if( nums[mid] > target )
        {
            end = mid - 1;
        }
        else if( nums[mid] == target )
        {
            return mid;
        }
        else
        {
            start = mid + 1;
        }

        mid = Math.floor((start + end) / 2);
    }

    return -1;
};