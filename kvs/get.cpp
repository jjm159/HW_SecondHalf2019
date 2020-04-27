#include "kvs.h"

void KVS::get(){
		map<string,string>::iterator iter;
		int keyCount = getString.size();
		for(int i = 0; i<keyCount; i++){
			iter = kvsMapContainer.find(getString[i]);
			if(iter == kvsMapContainer.end()){
				cout << "Can't find " << getString[i] << "key" << endl;
			}
			else{
				resultString.push_back(iter->second);
			}
		}
	}