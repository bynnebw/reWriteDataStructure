//
// Created by bryan on 2017/11/19.
//
#include <iostream>
#include <algorithm>
#include "Heap.h"
#include "sortTestHelper.h"

using namespace std;

//创建堆，将数组中的元素依次加入进堆中，然后再依次取出元素
//创建堆的过程与取出元素的过程时间复杂度都是nlog(n)
template <typename T>
void heapSort1(T arr[],int n){
    MaxHeap<T> maxheap = MaxHeap<T>(n);

    for( int i = 0; i < n; i ++ )
        maxheap.insert(arr[i]);

    for( int i = 0; i < n; i ++ )
        arr[i] = maxheap.extractMax();
}

template <typename T>
void heapSort2(T arr[],int n){
    return;
}


int main(){
    int n = 100;
    cout<<"Test for Random array"<<endl;
    int* arr1 = SortTestHelper::generateRandomArray(n,0,n);

    SortTestHelper::testSort("Heap Sort1",heapSort1,arr1,n);

    return 0;
}