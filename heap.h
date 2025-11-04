//
// Created by Manju Muralidharan on 10/19/25.
//

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <algorithm>
using namespace std;

struct MinHeap {
    int data[64]; // stores guide of nodes 
    int size; // number of elements within heap 

    MinHeap() { size = 0; }


void upheap(int pos, int weightArr[]) { 
            while ( pos > 0 ) { 
                int parent = ( pos - 1 ) / 2; // parent index 
            if (weightArr[data[pos]] < weightArr[data[parent]]) {
                swap (data[pos], data[parent]);
                    pos = parent;
           } else break; // stops if heap property is restored 
     }
}

    void downheap(int pos, int weightArr[]) {
      while (true) {
          int left = 2 * pos + 1; // left child index 
          int right = 2 * pos +2; // right child index 
          int smallest = pos; // assumes current is smallest

    if (left < size && weightArr[data[left]] < weightArr[data[smallest]])
        smallest = left; 

    if (right < size && weightArr[data[right]] < weightArr[data[smallest]])
        smallest = right;

    if (smallest !=pos) {
        swap (data[pos], data[smallest]);
        pos = smallest;
            } else break; 
        }
    }

 void push(int idx, int weightArr[]) { 
     data[size] = idx; 
     upheap ( size , weightArr ) // fix position 
         size++; // increase heap size 
       }

    int pop(int weightArr[]) {
        if ( size == 0 ) {
            cerr << "heap is empty!\n"
                return -1;
    }
        int root = data[0]; // smallest index 
        data[0] = data[size - 1]; // move last element to root 
        size--; // reduce size 
    if ( size > 0 ) 
        downheap ( 0, weightArr); // restore heap property 
    return root; // return smallest index 
    }
};


#endif
