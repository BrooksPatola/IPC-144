
#include <stdio.h>
#include <stdlib.h>

void clear(void){
        char input = 0;
        while(input!='\n'){
        input=getchar();
        }
}


void getDailyData( float* high, float* low, char * conditions);

int main (void)
{
float x, y;
char z;

getDailyData(&x, &y, &z);

return 0;

}

void getDailyData( float* high, float* low, char * condition)
{

 	float dailyhigh, dailylow;
	char conditions;
	int keeptrying = 1;

 	*high = dailyhigh;
        *low = dailylow;
	*condition = conditions;    
 	
	do{
	
	printf("data: ");
	int rval = scanf("%f, %f, %c", &dailyhigh, &dailylow, &conditions);
        
        if (rval != 3) {
		printf("error\n");
		clear();
	    }
	else if (dailyhigh < dailylow) {
		printf("error\n");
		clear();
            }
	else if (conditions != 'p' && conditions != 'c' && conditions != 's') {
		printf("error\n");
		clear();
	    }
	else 
		keeptrying = 0;
        

	} while (keeptrying == 1);
 

}
