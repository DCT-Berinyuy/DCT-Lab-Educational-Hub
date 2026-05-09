/*
 * 0795-SWR-Mock-2026 — SECTION B: Programming
 * Caesar Cipher — Encryption in C
 * GCE A-Level Computer Science
 *
 * Covers: Task 3 (tables), Task 4 (pseudocode), Task 5 (full C implementation)
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

/* ── Task 5(i): Global ALPHABET array (2 marks) ──
 * Declared globally, immediately initialized with uppercase English alphabet.
 */
char ALPHABET[26] = {
    'A','B','C','D','E','F','G','H','I','J','K','L','M',
    'N','O','P','Q','R','S','T','U','V','W','X','Y','Z'
};

/* ── Task 5(ii): encryptChar function (6 marks) ──
 * Converted directly from the pseudocode in Task 4.
 * Accepts a character and key, returns the encrypted character.
 */
char encryptChar(char chr, int key) {
    int isLower = 0;
    char upperChar;
    int position = -1;
    int newPosition;
    char cipherChar;

    /* Step 1: If chr is not alphabetic, return chr unchanged */
    if (!isalpha(chr))
        return chr;

    /* Step 2: Convert to uppercase, remember if originally lowercase */
    if (islower(chr)) {
        isLower = 1;
        upperChar = toupper(chr);
    } else {
        isLower = 0;
        upperChar = chr;
    }

    /* Step 3: Find position of character in ALPHABET array */
    for (int i = 0; i <= 25; i++) {
        if (ALPHABET[i] == upperChar)
            position = i;
    }

    /* Step 4: Calculate new position with wrap-around (Task 3ii(b))
     * newPosition = (position + key) % 26
     */
    newPosition = (position + key) % 26;

    /* Step 5: Return encrypted character, preserving case */
    if (isLower == 1)
        cipherChar = tolower(ALPHABET[newPosition]);
    else
        cipherChar = ALPHABET[newPosition];

    return cipherChar;
}

/* ── Task 5(iii): encryptMessage procedure (3 marks) ──
 * Loops through every character in plaintext,
 * calls encryptChar and prints each result immediately.
 */
void encryptMessage(char plaintext[], int key) {
    int len = strlen(plaintext);
    for (int i = 0; i < len; i++) {
        printf("%c", encryptChar(plaintext[i], key));
    }
    printf("\n");
}

/* ── Task 5(iv): Main program (3 marks) ── */
int main() {
    char message[200];
    int key;

    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0';   /* remove trailing newline */

    printf("Enter key value: ");
    scanf("%d", &key);

    printf("Encrypted message: ");
    encryptMessage(message, key);

    return 0;
}

/*
 * ─────────────────────────────────────────────────────────────────
 *  TASK 3 ANSWERS (manual / theory section)
 * ─────────────────────────────────────────────────────────────────
 *
 *  Task 3i(a) — Calculated index BEFORE wrap, key = 3:
 *
 *    Plaintext | Index in ALPHABET | Calculated Index (index + 3)
 *    A         |  0                |  3
 *    D         |  3                |  6
 *    X         | 23                | 26  ← out of bounds!
 *    Z         | 25                | 28  ← out of bounds!
 *
 *  Task 3i(b) — Problem with X and Z:
 *    X gives index 26 and Z gives index 28.
 *    The ALPHABET array only has valid indices 0–25.
 *    Accessing index 26, 27, or 28 goes beyond the array boundary,
 *    causing undefined behaviour / wrong characters.
 *
 *  Task 3i(c) — Wrap-around table, key = 3:
 *
 *    Calculated Index | Valid Index (% 26) | Letter
 *    26               |  0                 |  A
 *    27               |  1                 |  B
 *    28               |  2                 |  C
 *
 *  Task 3ii(a) — Expression BEFORE wrap:
 *    newPosition = position + key
 *
 *  Task 3ii(b) — Expression WITH wrap (mod operator):
 *    newPosition = (position + key) % 26
 *
 * ─────────────────────────────────────────────────────────────────
 *  TASK 4 PSEUDOCODE ANSWERS
 * ─────────────────────────────────────────────────────────────────
 *
 *  Task 4(i) — Step 1 pseudocode (check if alphabetic, 2 marks):
 *
 *    IF chr < 'A' OR (chr > 'Z' AND chr < 'a') OR chr > 'z' THEN
 *      RETURN chr
 *    ENDIF
 *
 *  Task 4(ii) — encryptMessage pseudocode (4 marks):
 *
 *    PROCEDURE encryptMessage(plaintext, key)
 *      FOR i ← 0 TO LENGTH(plaintext) - 1 DO
 *        encryptedChar ← encryptChar(plaintext[i], key)
 *        PRINT encryptedChar
 *      ENDFOR
 *    ENDPROCEDURE
 *
 * ─────────────────────────────────────────────────────────────────
 *  TASK 5(v) — Required output
 *  Message: "Computer Science gives insight"
 *  Key: 3
 *  Output: Frpsxwhu Vflhqfh jlyhv lqvljkw
 * ─────────────────────────────────────────────────────────────────
 */