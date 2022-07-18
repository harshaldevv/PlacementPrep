class MedianFinder {
public:
    // 2 priority queues --
    // maxheap to store the first half of the array
    // minheap to store the second half of the array
    
    priority_queue<double> maxheap;
    priority_queue<double, vector<double>, greater<double> > minheap;
    int size = 0;
    MedianFinder() {
        maxheap = priority_queue<double>();
        minheap = priority_queue<double, vector<double>, greater<double> >();
        size = 0;
    }
    
    void addNum(int num) {
        minheap.push(num);
        
       if(minheap.size() > maxheap.size()){
           //tranfer minheap top to maxheap 
           
           maxheap.push(minheap.top());
           minheap.pop();
       }
        
        if(minheap.top() < maxheap.top()){
            maxheap.push(minheap.top());
            minheap.pop();
            
            minheap.push(maxheap.top());
            maxheap.pop();
        }
        
        size++;
        
    }
    
    double findMedian() {
        if(size %2 != 0){
            // odd size length
            // return the first half last's element, aka maxheap's top element
            return maxheap.top();
        }
        else{
            return (minheap.top() + maxheap.top() ) /2;
        }
        
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */