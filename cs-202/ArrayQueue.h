#ifndef ARRAYQUEUE_H_
#define ARRAYQUEUE_H_
#include "DataType.h"
using namespace std;

const size_t ARRAY_MAX = 1000;

class ArrayQueue{
    friend ostream &operator<<(ostream &os, const ArrayQueue &arrayQueue);

    public:
        ArrayQueue();
        ArrayQueue(size_t count, const DataType &value);
        ArrayQueue(const ArrayQueue &other);
        ~ArrayQueue();
        ArrayQueue &operator=(const ArrayQueue &rhs);
        DataType &front();
        const DataType &front() const;
        DataType &back();
        const DataType &back() const;
        void push(const DataType &value);
        void pop();
        size_t size() const;
        bool empty() const;
        bool full() const;
        void clear();
        void serialize(ostream &os) const;
    
    private:
        DataType m_array[ARRAY_MAX];
        size_t m_front;
        size_t m_back;
        size_t m_size;
};

#endif