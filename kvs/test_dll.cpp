#define _DLL
#include "kvs.h"
#include <dlfcn.h>
#include <unistd.h>

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

	void *handle;
	char *error;
	funcType* getObject;

	handle = dlopen("./libkvs_dll.so", RTLD_LAZY);
	if(!handle){
		perror("falied to link SO");
		exit(1);
	}

	getObject = (funcType*)dlsym(handle, "getObject");
	if((error = dlerror()) != NULL){
		cout << "error : " << error << endl;
		exit(1);
	}

	KVS* kvs = getObject(fileName);

	kvs->put();
	kvs->get();
	kvs->generateResultFile(fileName);

	if(dlclose(handle)<0){
		cout << "close error";
		exit(1);
	}

	delete kvs;

	return 0;
}

