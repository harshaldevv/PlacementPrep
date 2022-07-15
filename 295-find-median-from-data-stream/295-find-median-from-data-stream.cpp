class MedianFinder {
public:
    priority_queue<double> maxHeap; 
    // stores the first half of the array
    
    priority_queue<double, vector<double>, greater<double> > minHeap; 
    // stores the second half of the array
    
    int size = 0;
    int count = 0;
    
    MedianFinder() {
        maxHeap = priority_queue<double>();
        minHeap = priority_queue<double, vector<double>, greater<double> >();
        size = 0;
        count = 0;
        
    }
    
    void addNum(int num) {
        
        maxHeap.push(num);
        
        // now transfer the maximum element from the maxheap to the minheap
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        
        if(minHeap.size() > maxHeap.size()){
            // unbalanced
            // transfer minimum element from minheap to maxHeap
            int minElem = minHeap.top();
            minHeap.pop();
            
            maxHeap.push(minElem);
        }
    }
    
    double findMedian() {
        
        if(maxHeap.size() == minHeap.size()){
            //even size
            return (maxHeap.top() + minHeap.top() )/2;
        }
        else{
            return maxHeap.top();
        }
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */