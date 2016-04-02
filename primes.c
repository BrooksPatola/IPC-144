#include <stdio.h>

 int check_prime(int a)
{
   int c;
 
   for ( c = 2 ; c <= a - 1 ; c++ )
   { 
      if ( a%c == 0 )
	 return 0;
   }
   if ( c == a )

      return 1;
}

int main (void){

	int num;

	printf("num: ");
	scanf("%d", &num);

	printf("%d", check_prime(num));


return 0;
	


		
}
