//
// Created by bryan on 2017/11/19.
//

#ifndef DEMO_HEAP_H
#define DEMO_HEAP_H

/**
  *使用最大堆实现优先队列
  * 使用数组实现最大堆，并没有使用普通的树定义的方法，因为最大堆自己本身的特点。
**/

#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

template <typename Item>
class MaxHeap{

private:
    Item* data;     //成员变量设置为指针，长度不用提前限制.
    int count;
    int capacity;

    void shiftUp(int k){
        while( k > 1 && data[k/2] < data[k] ){
            swap(data[k/2],data[k]);
            k = k/2;
        }
    }

    void shiftDown(int k){
        while( 2*k <= count ){
            int j = 2*k;
            if( j+1 <= count && data[j+1] > data[j] )
                j++;
            //data[j]是data[2*k]与data[2*k+1]中的最大值
            if( data[k] >= data[j] ) break;
            swap(data[k],data[j]);
            k = j;
        }
    }

public:
    MaxHeap(int capacity){
        data = new Item[capacity];
        count = 0;
        this->capacity = capacity;
    }

    ~MaxHeap(){
        delete[] data;
    }

    int size(){
        return count;
    }

    bool isEmpty(){
        return count == 0;
    }
    //向树中插入节点。采用shiftUp的方法
    void insert(Item item){
        assert(count + 1 <= capacity);
        data[count+1] = item;
        count++;
        shiftUp(count);
    }

    Item extractMax(){
        assert( count > 0 );
        Item ret = data[1];

        swap(data[1],data[count]);
        count --;
        shiftDown(1);
        return ret;
    }

    Item getMax(){
        assert( count > 0 );
        return data[1];
    }
};
#endif //DEMO_HEAP_H
