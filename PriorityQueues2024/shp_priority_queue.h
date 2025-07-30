
#ifndef PRIORITYQUEUES_SHP_PRIORITY_QUEUE_H
#define PRIORITYQUEUES_SHP_PRIORITY_QUEUE_H

#include <string>
#include <vector>
using namespace std;

class shp_priority_queue {
public:
    shp_priority_queue();
    ~shp_priority_queue();
    void pop();
    void push(string str);
    string top() const;
    int size() const;
    bool empty() const;
private:
    vector<string> heap;
    void heapifyUp(int index);
    void heapifyDown(int index);
};


#endif //PRIORITYQUEUES_SHP_PRIORITY_QUEUE_H
