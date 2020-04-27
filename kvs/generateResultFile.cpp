#include "kvs.h"

// generateResultFile
	void KVS::generateResultFile(vector<string>& fileName){
		ofstream fileManager;

		fileManager.open(fileName[2]);
		if(!fileManager){
			cout << fileName[2] << " open is falied" << endl;
			exit(1);
		}

		int keyCount = getString.size();	

		for(int i = 0; i< keyCount; i++)
		{
			fileManager << resultString[i] << endl;	
		}

		fileManager.close();
	}
