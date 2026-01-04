#include <iostream>
using namespace std;

class heap {
    public:
    int capacity;
    int idx;
    int *arr;

    heap(int capacity) {
        this->capacity = capacity;
        idx = 0;
        arr = new int[capacity+1];
        arr[0] = -1;
    }

    void insert(int num){
        if (idx > capacity){
            cout<<"Capacity exceeded\n";
            return;
        }
        idx++;

        int i = idx;
        arr[i] = num;
        while (i>1){
            int par = i/2;
            if (arr[par]<arr[i]){
                swap(arr[par],arr[i]);
                i=par;
            }
            else
                break;
        }
        this->print();
    }

    void print(){
        cout<<"Heap: [";
        for (int i=1; i<=idx; i++)
            cout<<arr[i]<<(i==idx ? "":",");
        cout<<"]\n";
    }

    int pop() {
        if (idx==0){
            cout<<"No items to remove\n";
            return -1;
        }
        int element = arr[1];
        arr[1] = arr[idx];
        idx--;

        int i=1;
        while (i*2 <= idx){
            int c1 = i*2, c2 = i*2 + 1;
            int newIdx = i;
            if (arr[c1] > arr[i]){
                i=c1;
            }
            if (c2<=idx && arr[c2]>arr[i]){
                i=c2;
            }
            if (i==newIdx) break;
            else swap(arr[newIdx],arr[i]);
        }

        cout<<"Removing : "<<element<<" => ";
        this->print();
        return element;
    }
};

int main() {
    heap h = heap(10);

    h.insert(4);
    h.insert(10);
    h.insert(1);
    h.insert(2);
    h.insert(67);
    h.insert(42);
    h.insert(90);
    h.insert(49);

    h.pop();
    h.pop();
    h.pop();
    h.pop();
    h.pop();
    h.pop();
    h.pop();
    h.pop();
    h.pop();

    return 0;
}
