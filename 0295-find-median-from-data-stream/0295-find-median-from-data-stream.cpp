class MedianFinder {
public:
    
    priority_queue<int> maxHeap;//small heap
    priority_queue<int,vector<int>, greater<int>> minHeap;//big heap
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(maxHeap.empty()&& minHeap.empty()){
            maxHeap.push(num);
            return;
        }
        maxHeap.push(num);

        if(!minHeap.empty()){
            if(maxHeap.top() > minHeap.top()){
                maxHeap.pop();
                minHeap.push(num);
            }
        }
        if(static_cast<signed int>(maxHeap.size()) - static_cast<signed int>(minHeap.size()) >= 2){
            int temp = maxHeap.top();
            maxHeap.pop();
            minHeap.push(temp);
        }
        if(static_cast<signed int>(minHeap.size()) - static_cast<signed int>(maxHeap.size()) >= 2){
            int temp = minHeap.top();
            minHeap.pop();
            maxHeap.push(temp);
        }
        return;
    }
    
    double findMedian() {
        int n = maxHeap.size();
        int m = minHeap.size();
        
        if((n+m) %2 == 0){
            return double(maxHeap.top() +  minHeap.top()) / 2.0;
        }
        else if(n>m) return maxHeap.top();
        else{
            return minHeap.top();
        }
       
        
        return 0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */