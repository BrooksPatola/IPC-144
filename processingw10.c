#include <stdio.h>
#include <ctype.h>

int main (void) {

	FILE* input = NULL;
	FILE* output = NULL;
	char choice = 0, currentChar = 0;
	
	printf("Change Case\n");
	printf("============\n");	
	printf("Case(U for upper, L for lower\n): ");
	scanf(" %c", &choice);
	
	printf("Name of the original file: \n");
	printf("Name of the updated file: ");
	printf("Text has been updated and stored in updated.dat\n");
	
	input  = fopen("original.dat", "r");
	output = fopen("updated.dat", "w");
	
	   while(currentChar != EOF ) {
		currentChar = fgetc(input);
           if(currentChar != EOF) {
		if(choice == 'U') {
	          currentChar = toupper(currentChar); 
		}else {
		  currentChar = tolower(currentChar);
	        }
	   fputc(currentChar, output);
	}
	}
	fclose(input);
	fclose(output);	

}
