#include <vector>
#include <iostream>
using namespace std;
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);
vector<int>& merge2Arrays(vector<int>& nums1, vector<int>& nums2);
double findMedian(vector<int> arr);

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        return findMedian(merge2Arrays(nums1,nums2));
    }

    vector<int>& merge2Arrays(vector<int>& nums1, vector<int>& nums2){
        int m = nums1.size();
        int n = nums2.size();
        int t = n+m;
        vector<int> arr;
        arr.resize(t);
        int p1 = 0;
        int p2 = 0;
        for(int i = 0; i<t; i++){
            if(nums1[p1]< nums2[p2]){
                arr.push_back(nums1[p1]);
                p1++;
            }
            else if(nums1[p1]==nums2[p2]){
                arr.push_back(nums1[p1]);
                arr.push_back(nums2[p2]);
                p1++,p2++;
            }
            else if(nums1[p1]>nums2[p2]){
                arr.push_back(nums2[p2]);
                p2++;
            }
            if(p1 == m-1){
                while(p2<n){
                    arr.push_back(nums2[p2]);
                }
                break;
            }
            if(p2 == n-1){
                 while(p1<m){
                    arr.push_back(nums1[p1]);
                }
                break;
            }
        }
        return arr;
    }

    double findMedian(vector<int> arr){
        int s = arr.size();
        if(s%2 ==0){
            return ((arr[s/2-1]+arr[s/2])/2);
        }
        else{
            return arr[s/2];
        }
    }

    int main(){
        vector<int> n1;
        n1.push_back(1);
        n1.push_back(3);
        vector<int> n2;
        n2.push_back(2);
        cout<< findMedianSortedArrays(n1,n2)<<endl;
}