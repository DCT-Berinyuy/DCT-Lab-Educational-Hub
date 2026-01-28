/*	Exercise 5 - Largest of Three Numbers

Start
	Declare A, B, C, Largest as integers
	Display("Enter three values: ")
	Read(A, B, C)
	If (A > B) AND (A > C) Then
		Largest <-- A
		ElseIf (B > A) AND (B > C) Then
			Largest <-- B
			Else 
				Larg4est <-- C
	EndIF
	Display("The largest number is: ", Largest)
End
*/
#include <stdio.h>
int main() {
	int A, B, C, Largest;
	printf("Enter three values: \n");
	scanf("%d %d %d", &A, &B, &C);
	if(A > B && A > C) {
		Largest = A;
	}else if (B > A && B > C) {
		Largest = B;
	}else{
		Largest = C;
	}

	printf("The Largest number is %d\n", Largest);
	return 0;
}