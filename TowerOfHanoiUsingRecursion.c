//Program in C of Tower of Hanoi using recursion.
#include<stdio.h>
#include<conio.h>
void TOH(int, char, char, char);
void main()
{
	int n;
	printf("Enter number of disks: ");
	scanf("%d",&n);
	TOH(n,'P','U','S');
	getch();
}
void TOH(int n, char A, char B, char C)
{
	if(n>0)
	{
		TOH(n-1,A,C,B);
		printf("Move disk %d from %c to %c\n",n,A,B);
		TOH(n-1,C,B,A);
	}
}
