#include <iostream>
#include <ctime>
#include <climits>
#include <cmath>
#include "heapsort.h"
using namespace std;

int main(int argc, const char * argv[]) {
    int n=10;
    heap H(n);
    
    srand(static_cast<unsigned int>(time(nullptr)));
    for(int i=0; i<n; i++){
        H.S[i]=rand();
    }
    
    cout<<"pre-sorted"<<endl;
    for(int i=0; i<n; i++){
        cout<<H.S[i]<<endl;
    }
    
    cout<<"commence heapsort"<<endl;
    heapsort(n, H);
    
    cout<<"post sort"<<endl;
    for(int i=0; i<n; i++){
        cout<<H.S[i]<<endl;
    }
    cout<<"compare count: "<<H.cnt<<endl;
    cout<<"function call count: "<<H.fcnt<<endl;
    
    return 0;
}
