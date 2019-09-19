#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>

int main(int argc, char * argv[])
{
	unsigned short myOrder = 0x0001;
	unsigned short networkOrder = htons(0x0001);		// big endian일때 테스트

	unsigned char * p;

	if(argc == 1){
		p = (unsigned char*)&myOrder; 
	}
	else if(argc != 1 && !strcmp(argv[1],"big")){
		p =(unsigned char *)&networkOrder;				// big endian일때 테스트
	}
	else{
		printf("error\n");
		return 1;
	}
	
	// little vs big
	if( *p == 1 ) printf("little endian\n");
	else printf("big endian\n");

	// 32bit vs 64bit
	if( sizeof(p)  == 4 ) printf("32bit\n");
	else if(sizeof(p) == 8) printf("64bit\n");
	else printf("I don't know\n");

	return 0;
}
