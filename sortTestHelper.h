//
// Created by bryan on 2017/11/19.
//

#ifndef REWRITEDATASTRUCTURE_SORTTESTHELPER_H
#define REWRITEDATASTRUCTURE_SORTTESTHELPER_H

//
// Created by bryan on 2017/11/19.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>
#include <cassert>

using namespace std;

namespace SortTestHelper{
    //利用随机种子生成固定大小的随机数组
    int* generateRandomArray(int n, int range_L, int range_R){

        int* arr = new int[n];

        srand(time(NULL));

        for( int i = 0; i < n; i ++ )
            arr[i] = rand() % (range_R - range_L + 1) + range_L;

        return arr;
    }

    //生成一个近乎有序的数组
    int* generateNearlyOrderedArray(int n, int swapTimes){

        int* arr = new int[n];
        for(int i = 0; i < n; i ++)
            arr[i] = i;
        srand(time(NULL));

        for( int i = 0; i < swapTimes; i ++ ){
            int posx = rand()%n;
            int posy = rand()%n;
            swap( arr[posx], arr[posy] );
        }
    }

    //将一个数组全部拷贝给另外一个数组
    int* copyIntArray(int a[],int n){

        int* arr = new int[n];
        copy(a,a+n,arr);
        return arr;
    }

    //打印arr数组的所有内容
    template <typename T>
    void printArray(T arr[], int n){
        for( int i = 0; i < n; i ++ )
            cout<<arr[i]<<" ";
        cout<<endl;
        return;
    }

    //判断arr数组是否有序
    template <typename T>
    bool isSorted(T arr[], int n){
        for( int i = 0; i < n; i ++ ){
            if(arr[i]>arr[i+1])
                return false;
        }
        return true;
    }

    //将算法的运行时间打印在控制台上
    template <typename T>
    void testSort(const string &sortName,void (*sort)(T [],int),T arr[],int n){
        clock_t startTime = clock();
        sort(arr, n);
        clock_t endTime = clock();
        cout<<sortName<<" : "<<double(endTime-startTime) / CLOCKS_PER_SEC<<" s"<<endl;

        assert(isSorted(arr,n));
        return;
    }
}

#endif //REWRITEDATASTRUCTURE_SORTTESTHELPER_H
