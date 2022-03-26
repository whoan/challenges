// Good article: https://medium.com/swlh/binary-search-find-upper-and-lower-bound-3f07867d81fb
// In a nitshell, it depends on the context if we ant to do `left = mid+1` or right = mid-1`
// that's what std::lower_bound or std::upper_bound do

// lower bound example -> we need to find the minimum of the max values
int binary_search_template(vector<int>& nums) {
    int left = 0, right = nums.size()-1;
    while (left < right) {
        int mid = left + (right-left) / 2;
        if (nums[mid] < nums[mid+1]) { // ?
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}
