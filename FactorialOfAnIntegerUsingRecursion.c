//Program in C to calculate the factorial of an integer number using recursive function.
#include<stdio.h>
#include<conio.h>
void main()
{
	int n;
	long int fact;
	long int factorial(int n);
	printf("Enter a number: ");
	scanf("%d",&n);
	fact = factorial(n);
	printf("%d! = %ld",n,fact);
	getch();
}
long int factorial(int n)
{
	if(n==0)
		return 1;
	else
		return n*factorial(n-1);
}
