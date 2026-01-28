/*	Exercise 7 - Sign of Product

Start
	Declare m, n, product as Integer
	Display("Enter the values of m and n: ")
	Read(m, n)

	product <-- m * n

	If (product > 0) Then
		Display("The product is positive: ")
		ElseIf (product < 0) Then
			Display("The product is negative: ")
				Else
					Display("The product is Zero: ")
	EndIf
End
*/
#include <stdio.h>
int main() {
	int m, n, product;
	printf("Enter the values m and n: ");
	scanf("%d %d", &m, &n);

	product = m * n;

	if (product > 0) {
		printf("The product is positive:\n");
	}else if (product < 0) {
		printf("The product is negative:\n");
	}else {
		printf("The product is Zero\n");
	}

	return 0;
}