#include "kvs.h"
    
    // put
	void KVS::put(){
		int valueCount = putString.size();
		for(int i = 0 ; i< valueCount ; i = i+2)
		{	
			kvsMapContainer.erase(putString[i]);
			kvsMapContainer.insert(make_pair(putString[i], putString[i+1]));
		}
	}