#include "bits/stdc++.h" // QioCas
using namespace std;

template<class T, T (*cmp)(T, T)> struct heap {
    int _size = 0;
    int heap[100005];
    int size() { return _size; }
    void push(T u) {
        int c = ++_size;
        for(int r; true;) {
            r = c >> 1;
            if(r == 0 or cmp(heap[r], u) >= 0) break;
            heap[c] = heap[r]; c = r;
        }
        heap[c] = u;
    }
    int pick(int result = 0) {
        if(size() == 0) return result;
        result = heap[1];
        int u = heap[_size--], r = 1;
        while(true) {
            int c = r << 1;
            if(c < _size and cmp(heap[c + 1], heap[c]) > 0) ++c;
            if(c > _size or cmp(u, heap[c]) >= 0) break;
            heap[r] = heap[c];
            r = c;
        }
        heap[r] = u;
        return result;
    }
};