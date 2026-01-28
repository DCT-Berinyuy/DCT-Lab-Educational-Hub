/*
Program: JUNE 2025 Section B: Program Development
Author: Mr.DCT
Date: 6/21/2025
*/

#include <stdio.h>
#define RAND_SEED 7
#define Row 8
#define Col 8


// Global variables
	int RAND_x = RAND_SEED;	

// Function 1: row_line()
	void row_line() {
		printf("\n");
		for( int i = 0; i < Col; i++) {
			printf("-----");
		}
		printf("\n");
	}

// Function 2: Random Number Generator
	void Rand_init(int s) {
		if( s >= 0 && s < 16) {
			int Rand_x = s;
		}
	}
	
	int Rand_no() {
		int Rand_x = (5 * Rand_x + 3) % 16;
		return (Rand_x % 2);
	}

// Function 3: Gen_cells(A, row, col)
	void Gen_cells(int A[Row][Col], int row, int col) {
		for(int i = 0; i < row; i++) {
			for(int j = 0; j < col; j++) {
				A[i][j] = Rand_no();
			}
		}
	}

// Function 4: Count live neighbours
	int count_live_neighs(int A[Row][Col], int r, int c) {
		int count;
		count = 0;
		for(int i = r - 1; i <= r + 1; i++) {
			for(int j = c - 1; j <= c + 1; j++) {
				if((i >= 0 && i < Row) && (j >= 0 && j < Col)){
					if(!(i == r && j == c) && (A[i][j] == 1)) {
						count++;
					}
				}
			}
		}
		return count;
	}

// Function 5: Next_Gen(A, B)
	void Next_Gen(int A[Row][Col], int B[Row][Col]) {
		for(int i = 0; i < Row; i++) {
			for(int j = 0; j < Col; j++) {
				int n_live = count_live_neighs(A, i, j);
				if(A[i][j] == 1 && (n_live == 2 || n_live == 3)) {
					B[i][j] = 1;
				}
				else if(A[i][j] == 0 && n_live == 3) {
					B[i][j] = 1;
				}
				else{
					B[i][j] = 0;
				}
			}
		}

	}

// Function 7(a): Print Matrix
	void PrintMat(int A[Row][Col], int row, int col) {
		for(int i = 0; i < row; i++) {
			row_line();
		printf("\n");
		for(int j = 0; j < col; j++) {
			printf("|  %d ", A[i][j]);
		}
			printf("\n");
		}
		row_line();
	}

// Function 7(b): Print Next Generation
	void PrintNextGen(int B[Row][Col], int row, int col) {
		for(int i = 0; i < row; i++) {
			row_line();
		printf("\n");
		for(int j = 0; j < col; j++) {
			printf("|  %d ", B[i][j]);
		}
			printf("\n");
		}
		row_line();
	}

// Function 9: Main program
int main() {
    int A[Row][Col], B[Row][Col];
    int s;

    // Step 1: Seed the RNG
    printf("\nEnter the seed (0 - 15):\n");
    scanf("%d", &s);
    Rand_init(s);

    // Step 2: Generate initial board
    Gen_cells(A, Row, Col);

    // Step 3: Print initial generation
    printf("\nInitial Generation:\n");
    PrintMat(A, Row, Col);

    // Step 4: Compute next generation
    Next_Gen(A, B);

    // Step 5: Print next generation
    printf("\nNext Generation:\n");
    PrintNextGen(B, Row, Col);

    return 0;
}

