/*
https://leetcode.com/problems/find-median-from-data-stream/

Let maxheap and minheap dicide where to put numbers
If number is greater than maxheap then it goes to minheap,
if it overflows : minheap gives the minimum number to push to maxheap

If number is smaller than maxheap, then it goes to the maxheap
if it overflows : maxheap gives the max number, it goes to minheap
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
        if (num > maxh.top()){
            minh.push(num);
            if (minh.size()>maxh.size()){
                maxh.push(minh.top());
                minh.pop();
            }
        }
        else {
            maxh.push(num);
            if (maxh.size()>minh.size()+1){
                minh.push(maxh.top());
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
