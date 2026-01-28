/*	Exercise 6 - Evaluate Grade

Start
	Declare Grade as Integer
	Display("Enter grade: ")
	Read(Grade)

	If (Grade > 10) Then
		Display("Passed: ")
		Else
			Display("Faild")
	EndIf
End
*/
#include <stdio.h>
int main() {
	int Grade;
	printf("Enter your grade: ");
	scanf("%d", &Grade);

	if (Grade > 10) {
		printf("Passed\n");
	}else{
		printf("Failed\n");
	}
	return 0;
}