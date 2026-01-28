/*	Exercise 2 - Product of Two Numbers

Start
	Declare A, B, Product as integers
	Display("Enter first number: ")
	Read(A)

	Display("Enter second number: ")
	Read(B)

	Product <-- A * B

	Display("The product is: ", Product)

End
*/
#include <stdio.h>
int main() {
	int A, B, Product;
	printf("Enter first number: ");
	scanf("%d", &A);
	printf("Enter second number: ");
	scanf("%d", &B);

	Product = A * B;

	printf("The Product is: %d", Product);

	return 0;
}