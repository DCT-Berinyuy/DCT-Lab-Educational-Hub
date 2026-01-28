/*	Exercise 3 - Swap Two Numbers

Start
	Declare A, B, Temp as integers
	Display("Enter value A: ")
	Read(A)

	Display("Enter value B: ")
	Read(B)
	A = 3
	B = 5

	Temp <-- A // Temp = 3
	A <-- B  // A = 5
	B <-- Temp  // B = 3

	Display("After swapping: ")
	Display(A)
	Display(B)
End
*/
#include <stdio.h>
int main() {
	int A, B, Temp;
	printf("Enter value of A: ");
	scanf("%d", &A);
	printf("Enter value of B: ");
	scanf("%d", &B);
	//Logic
	Temp = A;
	A = B;
	B = Temp;
	printf("After swapping: \n");
	printf("A = %d\n", A);
	printf("B = %d\n", B);

	return 0;
}