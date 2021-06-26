#include <stdio.h>
#include <stdlib.h>	// atoi()

int sum(a , b)
{
	return a + b;
}

int main(int argc, char **argv) 
{
	if (argc < 3) 
	{
		printf("usage: sum.exe num1 num2\n"
			   "example: sum.exe 2 4\n");
		return 1;
	}
		
	int a = atoi(argv[1]);
	int b = atoi(argv[2]);
	printf("%d + %d = %d\n", a, b, sum(a , b));
	return 0;
}
