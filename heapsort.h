#ifndef heapsort_h
#define heapsort_h
#include <cmath>
#include <climits>
using namespace std;

struct heap{
    int size=INT_MIN;
    int* S=nullptr;
    int cnt=0;
    int fcnt=0;
    
    heap(int newsize){
        size=newsize;
        S=new int[size];
    }
    
    ~heap(){
        delete[] S;
    }
};

void siftdown(heap& H, int i);
int root(heap& H);
void removekeys(int n, heap& H);
void makeheap(int n, heap& H);
void heapsort(int n, heap& H);

void siftdown(heap& H, int i){
    int parent=i;
    int largerchild;
    int siftkey=H.S[i];
    bool spotfound=false;
    
    while(2*parent+1<H.size && !spotfound){
        H.cnt+2;
        if(2*parent+1<H.size && H.S[2*parent+1]<H.S[2*parent+2]){
            H.cnt+2;
            largerchild=2*parent+2;
        } else largerchild=2*parent+1;
        
        if(siftkey<H.S[largerchild]){
            H.cnt++;
            H.S[parent]=H.S[largerchild];
            parent=largerchild;
        } else spotfound=true;
    }
    H.cnt++;
    H.S[parent]=siftkey;
}

int root(heap& H){
    int keyout;
    
    keyout=H.S[0];
    H.S[0]=H.S[H.size-1];
    H.size--;
    siftdown(H,0);
    H.fcnt++;
    
    return keyout;
}

void removekeys(int n, heap& H){
    for(int i=n-1; i>=0; i--){
        H.S[i]=root(H);
        H.fcnt++;
    }
}

void makeheap(int n, heap& H){
    H.size=n;
    for(int i=floor(n/2); i>=0; i--){
        siftdown(H,i);
        H.fcnt++;
    }
}

void heapsort(int n, heap& H){
    makeheap(n,H);
    removekeys(n,H);
    H.fcnt+=2;
}
#endif
