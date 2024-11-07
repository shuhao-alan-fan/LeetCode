class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> s;
        int max_area = INT_MIN;
        
        for(int i = 0; i< n; i++){
            
            while(!s.empty() && heights[s.top()] > heights[i]){
                cout<<"hello"<<endl;
                int a = s.top();
                s.pop();
                int prev_smaller = s.empty()? -1 : s.top();
                max_area = max(max_area, heights[a] * (i - prev_smaller - 1)); //why - 1
            }
            s.push(i);

        }
        while(!s.empty()){
            int b = s.top();
            s.pop();
            int prev_smaller = s.empty()? -1 : s.top();
            int width = n - prev_smaller - 1; // why - 1?
            max_area = max(max_area, width*heights[b]);
        }
        return max_area;
    }
};