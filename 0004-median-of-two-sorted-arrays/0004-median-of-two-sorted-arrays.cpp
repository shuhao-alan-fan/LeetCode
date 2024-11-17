class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int n1 = nums1.size(), n2 = nums2.size();
        int sum = n1+n2;
        //brute force O(n) memory & time
            // vector<int> sorted;
            // int i = 0, j = 0;
            // while(i<n1 && j<n2){
            //     if(nums1[i] <= nums2[j]) sorted.push_back(nums1[i]);
            //     else{sorted.push_back(nums2[j]);}
            // }
        
        //brute force O(1) space + O(nlogn) time
            // for(auto i : nums2){
            //     nums1.push_back(i);
            // }
            // sort(nums1.begin(),nums1.end());
            // if(sum % 2 == 0) return (nums1[sum / 2] + nums1[(sum - 1) / 2]) / 2.0;
            // else{
            //     return nums1[sum / 2];
            // }
        //Optimized using binary search O(log(min(m,n)))
        if(n1 > n2) return findMedianSortedArrays(nums2,nums1);
        int low = 0, high = n1;
        while(low <= high){
            int p1 = low + (high - low)/2;
            int p2 = ((sum+1) / 2) - p1;
            int Aleft = (p1 <= 0) ? INT_MIN : nums1[p1 - 1];
            int Aright = (p1 > n1 - 1) ? INT_MAX : nums1[p1];
            int Bleft = (p2 <= 0) ? INT_MIN : nums2[p2 - 1];
            int Bright = (p2 > n2 - 1) ? INT_MAX : nums2[p2];
            
            if(Bleft <= Aright && Aleft <=  Bright){
                if(sum % 2 == 0) return (max(Aleft,Bleft) + min(Aright, Bright)) / 2.0;
                else return (max(Aleft,Bleft));
                    
            }
            else if(Aleft > Bright) high = p1 - 1;
            else low = p1 + 1;
        }
        return 0.0;
    }
};