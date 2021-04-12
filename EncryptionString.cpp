#include <iostream>
#include <string>
#include <memory>
#include <fstream>  
#include <streambuf>  
using namespace std;

int key = 0x1AA4A;

void encode(const char* rawData, char*& encodedData)
{
	for (int i = 0; i < strlen(rawData); i++) {
		encodedData[i] = rawData[i] + key;
	}
}

void decode(const char* encodeData, char*& decodedData)
{
	for (int i = 0; i < strlen(encodeData); i++) {
		decodedData[i] = encodeData[i] - key;
	}
}


void produceEncodeFile(string source, string dest)
{
	std::ifstream sourceStream(source);
	std::string sourceStr((std::istreambuf_iterator<char>(sourceStream)),
		std::istreambuf_iterator<char>());

	ofstream encodeFile;
	encodeFile.open(dest, ios::out);
	if (!encodeFile)
		exit(1);

	char* encodedData = (char*)malloc(sizeof(char) * strlen(sourceStr.c_str()) + 1);
	if (encodedData == nullptr)
		exit(1);

	memset(encodedData, 0, sizeof(char) * strlen(sourceStr.c_str()) + 1);
	encode(sourceStr.c_str(), encodedData);


	encodeFile << encodedData;
	encodeFile.close();
	free(encodedData);
}
void formEncodeFileProduceDecodeFile(string source, string dest)
{

	std::ifstream sourceStream(source);
	std::string encodeSourceStr((std::istreambuf_iterator<char>(sourceStream)),
		std::istreambuf_iterator<char>());

	ofstream decodeFile;
	decodeFile.open(dest, ios::out);
	if (!decodeFile)
		exit(1);

	char* decodedData = (char*)malloc(sizeof(char) * strlen(encodeSourceStr.c_str()) + 1);
	if (decodedData == nullptr)
		exit(1);

	memset(decodedData, 0, sizeof(char) * strlen(encodeSourceStr.c_str()) + 1);
	decode(encodeSourceStr.c_str(), decodedData);

	decodeFile << decodedData;
	decodeFile.close();
	free(decodedData);

}
int main() 
{
	produceEncodeFile("C:\\Users\\Method.Jiao-WTG\\Desktop\\rsa\\Debug\\MepConfig.xml", "C:\\Users\\Method.Jiao-WTG\\Desktop\\rsa\\Debug\\MepConfig1.xml");

	formEncodeFileProduceDecodeFile("C:\\Users\\Method.Jiao-WTG\\Desktop\\rsa\\Debug\\MepConfig1.xml", "C:\\Users\\Method.Jiao-WTG\\Desktop\\rsa\\Debug\\MepConfig2.xml");
}