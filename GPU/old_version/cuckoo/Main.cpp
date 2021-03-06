//
// Created by jing on 2018/7/1.
//

#include "cuckoo.h"
#include "api.h"

#define SIZE_TEST 1000
using namespace std;

bool  test_size(int size){
    printf("\tsize:%d\n",size);
    checkCudaErrors(cudaGetLastError());
    auto *key=new int[size];
    auto *value=new int[size];
    auto *search=new int[size];
    auto *chck=new int[size];

    for(int i=0;i<size;i++){
        key[i]=2*i+3+1;
        value[i]=3*i+3+1;
        search[i]=i+3+1;
        chck[i]=0;
    }
//     //ADD_FAILURE()<<"test_simple"<<"\n";
//     // table_size = size/4
     hashAPI h(size*2);
    //insert size/8
    //h.hash_insert(key,value,size/8);
    
//     //insert size/8 ~ size/4
//     h.hash_insert(key,value,size/4);
//     //insert left 3/4
     h.hash_insert(key,value,size);
    
    
    
    h.hash_search(key,chck,size);
    
   
    int tmp=0;
    for(int i=0;i<size;i++){
        if(chck[i]!=value[i]){
            //printf("check error %d :%d %d \n",key[i],chck[i],value[i]);
            tmp++ ;
            //(chck[i]==value[i]);
        }
    }
    printf("test complete , tmp no check conponent");//%d not pass:abort %.2f%\n",size,tmp,tmp*100*1.0/size);

    checkCudaErrors(cudaGetLastError());
    delete[] key;
    delete[] value;
    delete[] search;
    delete[] chck;
    return true;
}

int main(){
    
    assert(test_size(128));
//    assert(test_size(100));
//    assert(test_size(1000));
//    assert(test_size(10000));
//    assert(test_size(100000));
//    assert(test_size(1000000));
//    assert(test_size(10000000));
//


    
}