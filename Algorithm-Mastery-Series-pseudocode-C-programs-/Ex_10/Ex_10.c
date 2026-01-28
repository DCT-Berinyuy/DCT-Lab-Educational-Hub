/*	Exercise 10 - Discount Plus VAT

Start
	Declare price, discountedPrice, finalTotal as Real
	Display("Enter the price before tax: ")
	Read(price)

	If(price > 200) Then
		discountedPrce <-- price - (0.15 * price)
		Else
			discountedPrce <-- price
	EndIf

	totalPrice <-- discountedPrice + (0.20 * discountedPrice)
	Display("The discount plus VAT is: ", totalPrice)
End
*/
#include <stdio.h>
int main() {
	float price, discountedPrice, finalTotal;
	printf("Enter price before tax: ");
	scanf("%f", &price);

	if (price > 200) {
		discountedPrice = price - (0.15f * price);//15% discount
	}else {
		discountedPrice = price; //No discount
	}

	finalTotal = discountedPrice + (0.20f * discountedPrice);
	printf("The discount plus VAT is: %.2f", finalTotal);
	return 0;
}