#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX_NAME = 256 ;
const int TABLE_SIZE = 10 ;

typedef struct {
	char name[MAX_NAME];
	int age;
} person ;



unsigned int hash(char *name) {
	unsigned int hash_value = 0 ;
	int length = strlen(name);
	for (int i = 0 ; i < length ; i++)
		hash_value += name[i] ;
	return hash_value;
}

int main() {
	int n ;
	scanf("%d\n" , &n);
	for (int i = 0 ; i < n;  i++) {
		char s[MAX_NAME] ;
		gets(s);
		printf("%s => %u\n" , &s , hash(s));
	}
	return 0 ;
}