#include <stdio.h>
#include <stdlib.h>

#define SIZE 3 //board size

void initialize_board(char board[SIZE][SIZE]) { //build a board
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      board[i][j] = ' ';
    }
  }
}

void display_board(char board[SIZE][SIZE]) { //show the board
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      printf(" %c ", board[i][j]);
      if (j == 2) {
        break;
      }
      printf("|");
    }
    printf("\n");
    if (i == 2) {
      break;
    }
    printf("---+---+---");
    printf("\n");
  }
}

int is_valid_moviment(int row, int col) { //check the validity of movements
  return row >= 0 && row < SIZE && col >= 0 && col < SIZE;
}

int check_win(char board_player[SIZE][SIZE], char player) { //checks if the player has won
  int i;
  for (i = 0; i < SIZE; i++) {
    if (board_player[i][0] == player && board_player[i][1] == player && board_player[i][2] == player) {
      return 1;
    } 
  
    if (board_player[0][i] == player && board_player[1][i] == player && board_player[2][i] == player) {
      return 1;
    }
  }
  if (board_player[0][0] == player && board_player[1][1] == player && board_player[2][2] == player) {
    return 1; 
  }
  if (board_player[0][2] == player && board_player[1][1] == player && board_player[2][0] == player) {
    return 1; 
  }
  return 0; 
}

int main(void) {
  char board_player[SIZE][SIZE], player = 'a';
  int row, col, rounds = 1;

  initialize_board(board_player);

  while (rounds < 10) {
    display_board(board_player);

    if (rounds % 2 == 1) {
      printf("Jogador 1 // X\n");
    } else {
      printf("Jogador 2 // O\n");
    }

    printf("Enter Row: ");
    scanf("%d", &row);
    printf("Enter Col: ");
    scanf("%d", &col);

    if (!is_valid_moviment(row - 1, col - 1) || board_player[row - 1][col - 1] != ' ') {
      printf("Invalid moviment. Try again. \n");
      continue;
    }

    if (rounds % 2 == 1) {
      board_player[row - 1][col - 1] = 'X';
      player = 'X';
    } else {
      board_player[row - 1][col - 1] = 'O';
      player = 'O';
    }

    if (check_win(board_player, player)) {
      system("clear");
      printf("Jogador %c venceu\n", player);
      display_board(board_player);
      break;
    };

    if (rounds == 9) {
      system("clear");
      puts("Empate");
      display_board(board_player);
      break;
    }

    system("clear");
    rounds++;
  }
}