/*
Parth Patel
CS 288 2017F Section 101
HW 01
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int length;

char *itoa(int v, char*s, int b){
	sprintf(s,(b==16)?"%x":"%d",v);
	return s;
}

char* concat(const char *s1, const char *s2)
{
    char *result = malloc(strlen(s1)+strlen(s2)+1);
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

void printDashedLine() {
	printf("%75s", "+------+------+------+------+------+------+------+------+\n");
}

void printLeftHex(int s) {
	printf("%016X", s);
	printf(" |");
}

void printCells(char *s) {
    int length;
    char * a = "0";
    for(length = 16 - strlen(s); length > 0; length--) {
    	 s = concat(a, s);
    }
    int i = 0;
    for(int j = 0; j < 8; j++) {  	
    	printf("%3c", s[i]);
    	i++;
    	printf("%c", s[i]);
    	printf("  |");
    	i++;
    }
    
}

void printEmptyCell() {
	printf("      |");
}


int main(int argc, char *argv[]) {
	int i;

	char *temp;	
	printf("0000000000000000 +------+------+------+------+------+------+------+------+\n");
	printDashedLine();
	printDashedLine();

	//PRINT ARGC 
	printLeftHex(argc);
	char a = (char ) argc;
	printCells(&a);
	printf("  argc\n");
	printDashedLine();

	//PRINT ARGV
	printLeftHex(*((int *) argv));
	temp = itoa(*((int *) argv), *argv, 16);
	printCells(temp);
	printf(" argv\n");
	printDashedLine();

	//PRINT VALUES IN ARGV
	for (i = 0; i < argc; ++i) {

		printLeftHex(*argv[i]);
		itoa(*((int *) argv[i]), temp, 16);
		printCells(temp);
		printf(" argv+");
		printf("%i\n", i);	
		printDashedLine();
	}

	//PRINT CHARACTERS
	int j = 0;
	for (i = 0; i < argc; ++i) {
		// if(!argv[i]) {
		// 	continue;
		// }
		while(1) {
			if(((j-1)%8 == 0) && (j>0)) {
				printLeftHex((int)argv[i][j]);
			}
			if(!argv[i][j]) {
				while((j%8)){
					printEmptyCell();
					j++;
				}
				// printf("%c",'\n');
			}
	
			printf("%3c", argv[i][j]);
			printf("   |");
			if((j%8 == 0)) {
				printf("%s", "\n");
				printDashedLine();
			}
			j++;
			if(!argv[i][j]) break;
		}
		j=0;
		
		
	}

	printDashedLine();
	printDashedLine();

	
	return 0;
}