/*	Exercise 9 - Average of Three Numbers

Start
	Declare A, B, C as Integers
	Declare Avg as Real
	Display("Enter three values: ")
	Read(A, B, C)

	Avg <--- (A + B + C) / 3.0

	Display("The average is: ", Avg)
End
*/
#include <stdio.h>
int main() {
	int A, B, C;
	float Avg;
	printf("Enter three values: ");
	scanf("%d %d %d", &A, &B, &C);

	Avg = (A + B + C) / 3.0; //3.0 is to ensure floating point values

	printf("The average is: %.2f\n", Avg);
	return 0;
}