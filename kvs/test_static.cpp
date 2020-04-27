#include "kvs.h"

int main(int argc, char* argv[])
{
	if(argc < 4 ){
		cout << argv[0] << " put.txt get.txt result_static" << endl;
		exit(1);
	}

	vector<string> fileName;

	for(int i = 0 ; i< 3; i++){
		fileName.push_back(argv[i+1]);
	}

	KVS kvs(fileName);

	kvs.put();
	kvs.get();
	kvs.generateResultFile(fileName);	


	return 0;
}

