#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <stdio.h>
#include <string.h>
#include <iostream>



bool ReadData(char* fileName, char* header, char* data) {

	FILE* file = fopen(fileName, "rt");

	if (!file) return false;


	char str[100];

	while (fgets(str, 100, file)) {

		char* Head = strstr(str, header);

		if (Head) {
			sscanf(str, "%*[^:]:%[^\n]", data);

			fclose(file);
			return true;
		}
	}
}


int main() {

	char fileName[100];
	char header[100];
	printf("Enter file name (for example Email.0.eml) = "); scanf("%s", fileName);
	printf("\nEnter header name (for example: Return-path) = "); scanf("%s", header);

	char data[100];

	bool result = ReadData(fileName, header, data);

	if (result) {

		printf("%s:%s", header, data);
	}
	else {
		printf("Header not found");
	}


}