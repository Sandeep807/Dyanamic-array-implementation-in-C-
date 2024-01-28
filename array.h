#include <iostream>
using namespace std;

class DyaArray
{
private:
    int capacity;
    int lastIndex;
    int *ptr;

public:
    DyaArray() = default;

    DyaArray(int size)
    {
        if(size>0){
        capacity=size;
        lastIndex=-1;
        ptr=new int[capacity];
    }
    else
        ptr=NULL;
    }
    void doubleArray();
    void halfArray();
    void append(int);
    bool isEmpty();
    bool isFull();
    void insert(int, int);
    int count();
    int getCapacity();
    void edit(int, int);
    void del(int);
    int getItem(int);
    ~DyaArray();
    int find(int);
    DyaArray(const DyaArray &);
    DyaArray& operator=(const DyaArray &);
};