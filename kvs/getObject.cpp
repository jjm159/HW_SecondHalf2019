#include "kvs.h"

extern "C" KVS* getObject(vector<string>& fileName){
    return new KVS(fileName);
}