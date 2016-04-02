#include <stdio.h>
#include <ctype.h>

int wordcount(char str[]) {

	int i =0;
	int words = 0;
	
	while(str[i] != '\0') {
		if(isspace(str[i]) == 0 && (isspace(str[i+1]) || str[i+1] == '\0')){
			words++;
		}
	i++;
	
	}

return words;

}



int main(void) {

	char input[101];
	
	printf("Word Counter\n");
	printf("==============\n");
	
	printf("Text to be analyzed: ");
	scanf("%100[^\n]", input);
	
	wordcount(input);
	
	printf("Word Count: %d\n", wordcount(input));
	



}
