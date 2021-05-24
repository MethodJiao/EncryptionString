#include <iostream>
#include <string>
#include <memory>
#include <fstream>  
#include <streambuf>  
using namespace std;

int key[] = {3,5,1,6,7,2,4,9,8,'a','$','&',3,'#'}
void encodeXOR(char* in char*out,size_t size)
{
	for(size_t i = 0; i < size; i++)
	{
		out[i] = in[i] ^ key[i%14];
	}
}

void decodeXOR(char* in,char* out,size_t size)
{
	encodeXOR(in,out,size);
}
