#include <iostream>
#include <ctime>
#include <string>
using namespace std;

enum enChoice { rock = 1, paper, scissor };
enum enWinner { player = 1, computer, draw };

short playerWinTimes = 0;
short ComputerWinTimes = 0;
short drawtimes = 0;
short countOfrounds = 0;

int randomnum(int From, int To) {
    return rand() % (To - From + 1) + From;
}

int ReadHowManyRounds() {
    int numberOfRounds = 0;
    do {
        cout << "Please enter how many rounds you want play [1 TO 10]: ";
        cin >> numberOfRounds;
    } while (numberOfRounds <= 0 || numberOfRounds > 10);

    return numberOfRounds;
}

enChoice player_choice() {
    int choice = 0;
    cout << "Enter your choice: Rock [1], Paper [2], Scissor [3] : ";
    cin >> choice;

    switch (choice) {
    case 1: return enChoice::rock;
    case 2: return enChoice::paper;
    case 3: return enChoice::scissor;
    default: return enChoice::rock;
    }
}

enChoice computer_choice() {
    int choice = randomnum(1, 3);
    return static_cast<enChoice>(choice);
}

string choiceToString(enChoice c) {
    switch (c) {
    case enChoice::rock: return "Rock";
    case enChoice::paper: return "Paper";
    case enChoice::scissor: return "Scissor";
    default: return "Unknown";
    }
}

void results(enChoice player, enChoice computer) {
    cout << "__________________________________ Round : "
        << countOfrounds << " ______________________\n";

    if (computer == player) {
        cout << "computer_choice : " << choiceToString(computer) << endl;
        cout << "player_choice   : " << choiceToString(player) << endl;
        cout << "RoundWinner     : [ No winner ]\n";
        drawtimes++;
        system("color 6F");
    }
    else if ((computer == enChoice::rock && player == enChoice::scissor) ||
        (computer == enChoice::paper && player == enChoice::rock) ||
        (computer == enChoice::scissor && player == enChoice::paper)) {
        cout << "computer_choice : " << choiceToString(computer) << endl;
        cout << "player_choice   : " << choiceToString(player) << endl;
        cout << "RoundWinner     : [ Computer winner ]\n";
        ComputerWinTimes++;
        system("color 4F");
        cout << "\a";
    }
    else {
        cout << "computer_choice : " << choiceToString(computer) << endl;
        cout << "player_choice   : " << choiceToString(player) << endl;
        cout << "RoundWinner     : [ Player winner ]\n";
        playerWinTimes++;
        system("color 2F");
    }
    cout << "--------------------------------------------------------------\n";
}

bool playagain() {
    char answer;
    cout << "Do you want to play again? (Y/N): ";
    cin >> answer;
    return (answer == 'Y' || answer == 'y');
}

void Game_info() {
    cout << "--------------------------------------------\n";
    cout << "               ++ GAME OVER ++              \n";
    cout << "--------------------------------------------\n";

    cout << "Game rounds        : " << countOfrounds << endl;
    cout << "Player win times   : " << playerWinTimes << endl;
    cout << "Computer win times : " << ComputerWinTimes << endl;

    cout << "Final winner";
    if (playerWinTimes > ComputerWinTimes) {
        cout << " : Player wins!\n";
    }
    else if (playerWinTimes < ComputerWinTimes) {
        cout << " : Computer wins!\n";
    }
    else {
        cout << " : No winner\n";
    }
    cout << "--------------------------------------------\n";
}

void startGame() {
    int rounds = ReadHowManyRounds();
    for (int i = 1; i <= rounds; i++) {
        countOfrounds++;
        cout << "\nRound [" << i << "] begins\n";
        enChoice player = player_choice();
        enChoice computer = computer_choice();
        results(player, computer);
    }
    Game_info();
}

int main() {
    srand(unsigned(time(NULL)));
    do {
        startGame();
    } while (playagain());
}
