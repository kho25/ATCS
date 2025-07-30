#include <string>
#include "shp_priority_queue.h"

shp_priority_queue::shp_priority_queue() {
}

shp_priority_queue::~shp_priority_queue() {
}

void shp_priority_queue::pop() {
    heap[0] = heap[heap.size()-1];
    heap.pop_back();
    heapifyDown(0)
}

void shp_priority_queue::push(string str) {
    heap.push_back(str);
    heapifyUp(heap.size()-1);
}

string shp_priority_queue::top() const {
    return heap[0];
}

int shp_priority_queue::size() const {
    return heap.size();
}

bool shp_priority_queue::empty() const {
    return heap.empty();
}

void shp_priority_queue::heapifyUp(int index) {
    if(index <= 0)
        return;
    int parentIndex = (index-1)/2;
    if(heap[index] > heap[parentIndex]) {
        string save = heap[index];
        heap[index] = heap[parentIndex];
        heap[parentIndex] = save;
        heapifyUp(parentIndex);
    }

}
void shp_priority_queue::heapifyDown(int index) {
    int leftChildIndex = index*2+1;
    int rightChildIndex = index*2+2;
    int champIndex = index;

    if(leftChildIndex < size() && heap[leftChildIndex] > heap[champIndex])
        champIndex = leftChildIndex;
    if(rightChildIndex < size() && heap[rightChildIndex] > heap[champIndex])
        champIndex = rightChildIndex;

    if(index != champIndex) {
        string save = heap[index];
        heap[index] = heap[champIndex];
        heap[champIndex] = save;
        heapifyDown(champIndex);
    }

}

