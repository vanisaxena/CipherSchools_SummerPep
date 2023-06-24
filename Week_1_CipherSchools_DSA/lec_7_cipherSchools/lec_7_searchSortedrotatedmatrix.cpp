int findPivotIndex(vector<int>& arr, int n){
        int ans = 0;
        int low = 0, high = n-1;
        int mid;
        while(low < high) {
            mid = low + (high-low)/2;
            if(arr[mid] >= arr[0])
                low = mid+1;
            else 
                high = mid;
        }
        return high;
    }   
    int findIndex(vector<int> &arr, int target, int low, int high) {
        while(low <= high) {
            int mid = low + (high-low)/2;
            if(arr[mid] == target)
                return mid;
            else if(arr[mid] > target) 
                high = mid-1;
            else 
                low = mid+1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int pivot = findPivotIndex(nums, nums.size());
        cout<<pivot<<endl;
        int l = nums.size()-1;

        if(target >= nums[pivot] && target<=nums[l])
            return findIndex(nums, target, pivot, nums.size()-1);
        return findIndex(nums, target, 0, pivot-1);
    }
