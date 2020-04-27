#ifndef _KVS_
#define _KVS_

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <string>
#include <vector>
#include <map>
using namespace std;

class KVS{
	vector<string> putString;
	vector<string> getString;
	vector<string> resultString;

	map<string, string> kvsMapContainer;
	
public:
//open 함수의 역할을 생성자가 한다.
	KVS(vector<string>& fileName){
		string stringBuffer;	
		ifstream fileManager;

		// put.txt 파일의 내용을 putString에 저장.
		fileManager.open(fileName[0]);
		if(!fileManager){
			cout << fileName[0] << " open is failed" << endl;
			exit(1);
		}
		while(fileManager){
			fileManager >> stringBuffer;
			// 문자열 크기 검사 루틴 추가하기. KeyMax 16B ValueMax 99B
			if(fileManager.eof()) break;
			putString.push_back(stringBuffer);
		}
		fileManager.close();

		// get.txt 파일의 내용을 getString에 저장.
		fileManager.open(fileName[1]);
		if(!fileManager){
			cout << fileName[1] << " open is failed" << endl;
			exit(1);
		}
		string str;	
		while(fileManager){
			fileManager >> stringBuffer;
			// 문자열 크기 검사 루틴 추가하기. maxSize 16Bytes
			if(fileManager.eof()) break;
			getString.push_back(stringBuffer);
		}
		fileManager.close();
	}

	void put();
	void get();
	void generateResultFile(vector<string>& fileName);
};


#ifdef _DLL
extern "C" KVS* getObject(vector<string>& fileName);
typedef KVS* funcType(vector<string>&);
#endif


#endif