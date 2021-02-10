/* 
 * Tic-Tac-Toe
 * by: James Mernin
 * February 10, 2021
 */

#include <iostream>

char square[10] = {'_', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

int checkWin() {
    if (square[1] == square[2] && square[2] == square[3]) return 1;
    else if (square[4] == square[5] && square[5] == square[6]) return 1;
    else if (square[7] == square[8] && square[8] == square[9]) return 1;
    else if (square[1] == square[4] && square[4] == square[7]) return 1;
    else if (square[2] == square[5] && square[5] == square[8]) return 1;
    else if (square[3] == square[6] && square[6] == square[9]) return 1;
    else if (square[1] == square[5] && square[5] == square[9]) return 1;
    else if (square[3] == square[5] && square[5] == square[7]) return 1;
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' && square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7] != '7' && square[8] != '8' && square[9] != '9') return 0;
    else return -1;
}

void board() {
    system("cls");
    std::cout << "\n\n\tTic Tac Toe\n\n";

    std::cout << "Player 1 (X)  -  Player 2 (O)" << std::endl  << std::endl ;
    std::cout << std::endl ;

    std::cout << "     |     |     " << std::endl ;
    std::cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << std::endl ;

    std::cout << "_____|_____|_____" << std::endl ;
    std::cout << "     |     |     " << std::endl ;

    std::cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << std::endl ;

    std::cout << "_____|_____|_____" << std::endl ;
    std::cout << "     |     |     " << std::endl ;

    std::cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << std::endl ;

    std::cout << "     |     |     " << std::endl  << std::endl ;
};

int main()
{
    int player = 1, i, choice;
    char mark;
    do {
        board();
        player = (player % 2) ? 1 : 2;
        std::cout << "Player " << player << ", enter a number: ";
        std::cin >> choice;
        std::cin.ignore();
        mark = (player == 1) ? 'X' : 'O';
        if (choice >= 1 && choice <= 9) {
            if (square[choice] != 'X' && square[choice] != 'O') {
                square[choice] = mark;
            } else {
                std::cout << "That square is already taken. Press Enter to try again.";
                player--;
                std::cin.clear();
                std::cin.ignore();
                std::cin.get();
            }
        } else {
            std::cout << "That is not a valid square. Press Enter to try again.";
            player--;
            std::cin.clear();
            std::cin.ignore();
            std::cin.get();
        }
        i = checkWin();
        player++;
    } while (i == -1);
    if (i == 1) {
        board();
        std::cout << "==> Player "<< --player << " wins!";
    } else {
        board();
        std::cout << "==> The game ends in a tie!";
    }
    std::cin.ignore();
    std::cin.get();
    return 0;
}