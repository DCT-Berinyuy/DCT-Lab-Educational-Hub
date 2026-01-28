/*	Exercise 8 - Absolute value

Start
	Declare N, AbsValue as Integer
	Display("Enter integer value: ")
	Read(N)
	
	If (N < 0) Then
		AbsValue <-- -N
		Else
			AbsValue <-- N
	EndIf

	Display("The absolute value is: ", AbsValue)
End
*/
#include <stdio.h>
int main() {
	int N, AbsValue;
	printf("Enter inter value: ");
	scanf("%d", &N);

	if (N < 0) {
		AbsValue = -N;
	}else {
		AbsValue = N;
	}
	printf("The absolute value is: %d", AbsValue);
	return 0;
}