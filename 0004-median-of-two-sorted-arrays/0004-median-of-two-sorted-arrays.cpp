class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //brute force O(n) memory & time
        int n1 = nums1.size(), n2 = nums2.size();
        int sum = n1+n2;
        // vector<int> sorted;
        // int i = 0, j = 0;
        // while(i<n1 && j<n2){
        //     if(nums1[i] <= nums2[j]) sorted.push_back(nums1[i]);
        //     else{sorted.push_back(nums2[j]);}
        // }
        
        //brute force O(1) space + O(nlogn) time
        for(auto i : nums2){
            nums1.push_back(i);
        }
        sort(nums1.begin(),nums1.end());
        if(sum % 2 == 0) return (nums1[sum / 2] + nums1[(sum - 1) / 2]) / 2.0;
        else{
            return nums1[sum / 2];
        }
    }
};