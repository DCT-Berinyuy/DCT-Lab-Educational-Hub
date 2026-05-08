/*
 * 0795NW_P3_2026 — SECTION A: Problem Solving
 * Labyrinth Minimum Energy Path (Dynamic Programming)
 * GCE A-Level Computer Science — Programming in C
 *
 * Covers: Q1a, Q1b (manual trace), Q2–Q9
 */

#include <stdio.h>

#define MAX 10

/* ── Q2: Global arrays ── */
int labyrinthGrid[MAX][MAX];
int energyGrid[MAX][MAX];
int path[MAX][MAX];
int rows, cols;

/* ── Q3: FillEnergy (4 marks) ── */
void FillEnergy() {
    /* Base case: top-left corner */
    energyGrid[0][0] = labyrinthGrid[0][0];

    /* Fill first row (can only come from the left) */
    for (int j = 1; j < cols; j++)
        energyGrid[0][j] = energyGrid[0][j-1] + labyrinthGrid[0][j];

    /* Fill first column (can only come from above) */
    for (int i = 1; i < rows; i++)
        energyGrid[i][0] = energyGrid[i-1][0] + labyrinthGrid[i][0];

    /* Fill remaining cells — choose minimum of top or left neighbour */
    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < cols; j++) {
            if (energyGrid[i-1][j] < energyGrid[i][j-1])
                energyGrid[i][j] = energyGrid[i-1][j] + labyrinthGrid[i][j];
            else
                energyGrid[i][j] = energyGrid[i][j-1] + labyrinthGrid[i][j];
        }
    }
}

/* ── Q4: optimalPath (4 marks) ── */
void optimalPath() {
    int i = rows - 1;
    int j = cols - 1;
    path[i][j] = 1;   /* mark treasure chamber */

    while (i > 0 || j > 0) {
        if (i == 0) {
            /* On top row — can only move left */
            j--;
        } else if (j == 0) {
            /* On left column — can only move up */
            i--;
        } else if (energyGrid[i-1][j] < energyGrid[i][j-1]) {
            /* Came from above */
            i--;
        } else {
            /* Came from the left */
            j--;
        }
        path[i][j] = 1;
    }
}

/* ── Q6: Display energyGrid and path arrays (4 marks) ── */
void Display() {
    printf("\nEnergy Grid:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            printf("%5d", energyGrid[i][j]);
        printf("\n");
    }

    printf("\nPath (1 = chosen path, 0 = not taken):\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            printf("%5d", path[i][j]);
        printf("\n");
    }
}

/* ── Q7 + Q8: Main program ── */
int main() {

    /* ── PART 1: Hardcoded Fig 1 grid (Q2) ──
     *  3  2  9
     *  1  6  2
     *  8  3  1
     */
    rows = 3; cols = 3;
    int fig1[3][3] = { {3, 2, 9}, {1, 6, 2}, {8, 3, 1} };

    /* Initialise labyrinthGrid and path */
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++) {
            labyrinthGrid[i][j] = fig1[i][j];
            path[i][j] = 0;
        }

    FillEnergy();
    optimalPath();

    /* Q5: Display minimum (maximum required) energy */
    printf("Minimum energy to reach the treasure: %d\n",
           energyGrid[rows-1][cols-1]);

    Display();  /* Q6 */

    /* ── PART 2: User-supplied grid (Q8) ── */
    printf("\n=== USER INPUT MODE ===\n");

    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    printf("Enter the energy values of the labyrinth:\n");
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            scanf("%d", &labyrinthGrid[i][j]);

    /* Reset path array */
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            path[i][j] = 0;

    FillEnergy();
    optimalPath();

    printf("\nMinimum energy to reach the treasure: %d\n",
           energyGrid[rows-1][cols-1]);
    Display();

    return 0;
}

/*
 * ─────────────────────────────────────────
 *  Q1a — energyGrid trace for Fig 1:
 *
 *   labyrinthGrid:      energyGrid (filled):
 *   3  2  9             3   5  14
 *   1  6  2             4  10  12
 *   8  3  1            12  13  13
 *
 * ─────────────────────────────────────────
 *  Q1b — path array (optimal path marked 1):
 *
 *   1  0  0
 *   1  1  1
 *   0  0  1
 *
 *  Path: (0,0)→(1,0)→(1,1)→(1,2)→(2,2)
 *  Cost:  3  + 1  + 6  + 2  + 1  = 13
 * ─────────────────────────────────────────
 *
 *  Q5 NOTE: The question asks for "maximum energy needed"
 *  which is energyGrid[rows-1][cols-1] — the accumulated
 *  minimum-cost to reach the bottom-right corner.
 *  This IS the minimum over all paths — misleading wording
 *  in the paper. Print: energyGrid[rows-1][cols-1]
 * ─────────────────────────────────────────
 */
