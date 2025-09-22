#include<stdio.h>

void readFile(const char *filePath);

int main() {
	readFile("test.txt");
	return 0;
}

void readFile(const char *filePath) {
	FILE *fptr;
	fptr = fopen(filePath, "r");

	char myString[100];

	if(fptr != NULL) {
		while(fgets(myString, sizeof(myString), fptr)) {
			printf("%s", myString);
		}
		fclose(fptr);
	} else {
		printf("Not able to find this file");
	}
}