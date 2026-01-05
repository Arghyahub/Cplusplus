/*
https://leetcode.com/problems/find-median-from-data-stream/
*/
class MedianFinder {
    priority_queue<int> maxh;
    priority_queue<int,vector<int>,greater<int> > minh;
public:
    MedianFinder() {
        maxh.push(INT_MIN);
        minh.push(INT_MAX);
    }

    void addNum(int num) {
        // let maxheap decide maximum element to move to minheap
        // Insertion into maxheap: Minimum numbers to be inserted which are not present in max heap (To maintain order)
        // I.e : minimum of Current number and Minheap top
        //
        // but you only move a number from minheap if you have enough numbers to move (both sizes are same) becuz maxheapsize=minheapsize+(1|0)
        // Incase of minheap being small:
        // because numbers in minheap are already greatest, moving the addnum to minheap and taking the minheap top to maxheap
        // will not contain the element and maxheap with high size will send it back to minheap

        // If you don't check equal condition, pushing into maxheap might overflow, so you need to check again and push the overflowed part to minheap
        if (minh.size()==maxh.size() && minh.top()<num){
            maxh.push( minh.top() );
            minh.pop();
            minh.push(num);
        }
        else {
            maxh.push(num);
            if (maxh.size() > minh.size()+1){
                minh.push( maxh.top() );
                maxh.pop();
            }
        }
    }

    double findMedian() {
        double a = 0, b = 0;
        int M = maxh.size(), N = minh.size();
        if (!maxh.empty())
            a = maxh.top();
        if (!minh.empty())
            b = minh.top();

        if ((M+N)&1) return a;

        return (a+b)/2 ;
    }
};
