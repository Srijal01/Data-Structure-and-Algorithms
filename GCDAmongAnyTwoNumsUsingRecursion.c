//Program in C to find the greatest common divisor (GCD) of any two numbers using recursion.
#include<stdio.h>
int GCD(int, int);
int main()
{
	int a, b, gcd;
	printf("Enter any two numbers: ");
	scanf("%d%d",&a,&b);
	gcd = GCD(a,b);
	printf("The greatest common divisor of given two numbers is %d",gcd);
	return 0;
}
int GCD(int x, int y)
{
	if(y==0)
		return x;
	else 
		return (GCD(y,x%y));
}
