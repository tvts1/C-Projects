#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void hangman(int life) {
    // Function to print the hangman based on the number of lives left
    switch(life) {
        case 6:
            printf("\n---------");
            printf("\n|");
            printf("\n|");
            printf("\n|");
            printf("\n|");
            printf("\n-");
            break;
        case 5: 
            printf("\n---------");
            printf("\n|       0");
            printf("\n|");
            printf("\n|");
            printf("\n|");
            printf("\n-");
            break;
        case 4:
            printf("\n---------");
            printf("\n|       0");
            printf("\n|       |");
            printf("\n|");
            printf("\n-");
            break;
        case 3: 
            printf("\n---------");
            printf("\n|       0");
            printf("\n|      -|");
            printf("\n|");
            printf("\n|");
            printf("\n-");
            break;
        case 2: 
            printf("\n---------");
            printf("\n|       0");
            printf("\n|      -|-");
            printf("\n|");
            printf("\n|");
            printf("\n-");
            break;
        case 1: 
            printf("\n---------");
            printf("\n|       0");
            printf("\n|      -|-");
            printf("\n|      /");
            printf("\n|");
            printf("\n-");
            break;
        case 0: 
            printf("\n---------");
            printf("\n|       0");
            printf("\n|      -|-");
            printf("\n|      / \\");
            printf("\n|");
            printf("\n-");
            break;
    }
} 

int main() {
    int life = 6;
    char word[50], secret_word[50], try;

    puts("Secret word: ");
    fgets(word, 50, stdin);

    //The secret_word is initially filled with asterisks
    for (int i = 0; i < strlen(word)-1; i++) {
        secret_word[i] = '*';
    }

    secret_word[strlen(word) - 1] = '\0';
    
    system("clear");
    puts("Welcome to the hangman"); 
    printf("The secret word is %s\n", secret_word);

    do {
        // check is used to see if the player's guess is in the word
        // allLetters is used to check if the player has guessed all the letters
        int check = 0, allLetters = 1; 
        hangman(life);
        printf("\nEnter with a character: ");
        scanf(" %c", &try);
        
        // The program checks if the player's guess is in the word
        for (int i = 0; i < strlen(word)-1; i++) {
            if (try == word[i]) {
                secret_word[i] = try;
                check = 1;
            }
        }

        if (check == 0) {
            life--;
        } 

        // The program checks if the player has guessed all the letters
        for (int i = 0; i < strlen(secret_word); i++) {
            if (secret_word[i] == '*') {
                allLetters = 0;
                break;
            }
        }
        printf("%s", secret_word);
        system("clear");

        if (allLetters) {
            printf("\nYou Win");
            break;
        }
 
        if (life == 0) {
            puts("\nYou Lose");
        }

    } while (life != 0);
    hangman(life);
    printf("\nThe secret word was %s", word);    
}
