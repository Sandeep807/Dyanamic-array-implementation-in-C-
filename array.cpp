#include "array.h"

void DyaArray ::doubleArray()
{
    int *temp;
    temp = new int[capacity * 2];
    for (int i = 0; i <= lastIndex; i++)
    {
        temp[i] = ptr[i];
    }
    delete[] ptr;
    ptr = temp;
    capacity *= 2;
}

void DyaArray::halfArray()
{
    int *temp;
    temp = new int[capacity / 2];
    for (int i = 0; i <= lastIndex; i++)
        temp[i] = ptr[i];
    delete[] ptr;
    ptr = temp;
    capacity /= 2;
}

DyaArray ::DyaArray(const DyaArray &obj)
{
    capacity = obj.capacity;
    lastIndex = obj.lastIndex;
    ptr = new int[capacity];
    for (int i = 0; i <= lastIndex; i++)
    {
        ptr[i] = obj.ptr[i];
    }
}

DyaArray &DyaArray ::operator=(const DyaArray &obj)
{
    if (this != &obj)
    {
        if (ptr == nullptr)
            delete[] ptr;
        capacity = obj.capacity;
        lastIndex = obj.lastIndex;
        ptr = new int[capacity];
        for (int i = 0; i <= lastIndex; i++)
        {
            ptr[i] = obj.ptr[i];
        }
    }
    return *this;
}

bool DyaArray ::isEmpty()
{
    return lastIndex == -1;
}

bool DyaArray ::isFull()
{
    return lastIndex == capacity - 1;
}
void DyaArray ::append(int data)
{
    if (isFull())
    {
        doubleArray();
    }
    ptr[++lastIndex] = data;
}

void DyaArray ::insert(int index, int data)
{
    if (index < 0 || index > lastIndex + 1)
    {
        cout << "Index invalid" << endl;
    }
    else if (isFull())
    {
        cout << "Array full" << endl;
    }
    else
    {
        for (int i = lastIndex; i >= index; i--)
        {
            ptr[i + 1] = ptr[i];
        }
        ptr[index] = data;
        lastIndex++;
    }
}

void DyaArray ::edit(int index, int data)
{
    if (index < 0 || index > lastIndex)
    {
        cout << "Invalid index" << endl;
    }
    else
    {
        ptr[index] = data;
    }
}

void DyaArray ::del(int index)
{
    if (index < 0 || index > lastIndex)
    {
        cout << "Invalid index" << endl;
    }
    else
    {
        for (int i = index; i < lastIndex; i++)
            ptr[i] = ptr[i + 1];
        lastIndex--;
        if (capacity > 1 && lastIndex + 1 <= capacity / 2)
            halfArray();
    }
}

int DyaArray ::getItem(int index)
{
    if (index < 0 || index > lastIndex)
    {
        cout << "Invalid index" << endl;
        throw new exception();
    }
    else
    {
        return ptr[index];
    }
}

int DyaArray ::count()
{
    return lastIndex + 1;
}

DyaArray ::~DyaArray()
{
    delete[] ptr;
}

int DyaArray ::find(int data)
{
    for (int i = 0; i <= lastIndex; i++)
    {
        if (ptr[i] == data)
        {
            return i;
        }
    }
    return -1;
}

int DyaArray :: getCapacity()
{
    return capacity;
}
