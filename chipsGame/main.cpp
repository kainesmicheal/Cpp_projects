#include <iostream>
#include <ctime>
#include <cstdlib>
#include <unistd.h>
#include <fstream>

using namespace std;

struct PLAYER{
    string name;
    int totalWins = 0;
};

const int MAX_CHIPS = 100;
const float MAX_TURN = .5;

string getName(PLAYER player[], bool);
void getDetails(PLAYER player[]);
int checkChips( int, PLAYER player[], bool);
void updateWin(PLAYER player[], bool);


int main()
{
    bool player1Turn = true;
    bool gameOver = false;
    int moveCounter = 0;
    int chipsInPile = 0;
    
    char userChoice;
    

    PLAYER player[2];
    getDetails(player);
    srand(time(0));
    do{
        moveCounter = 0;
        chipsInPile = (rand() % MAX_CHIPS) + 1;
        cout << "------------------------------------------------\n";
        cout << "This round will start with " << chipsInPile << " chipes in the pile \n";
        cout << "------------------------------------------------\n";
        while (gameOver == false)
        {
            int chipsTaken = checkChips( chipsInPile, player, player1Turn);
            chipsInPile = chipsInPile - chipsTaken;
            cout << "-------------------------------------\n";
            cout << "There are " << chipsInPile << " chips left in the pile\n";
            cout << "-------------------------------------\n";
            if (chipsInPile == 0) {
                gameOver = true;
                cout << getName(player, player1Turn) << ", wins\n";
                ofstream out;
                out.open("results.txt", ios::app);
                if(!out.fail()){
                    out << getName(player, player1Turn) <<", Won in " << moveCounter << " Turns." << endl;
                }
                updateWin(player,player1Turn);
            }
            else {
                player1Turn = !player1Turn;
                moveCounter++;
            }
        }
        cout << "do you want to play again?(y/n)\n";
        cin >> userChoice;
        if(userChoice == 'y'){
            gameOver = false;
        }
    } while(userChoice == 'y');
    cout << "player: " << player[0].name << " wins: " << player[0].totalWins  << endl;
    cout << "player: " << player[1].name << " wins: " << player[1].totalWins  << endl;
    return  0;
}
string getName(PLAYER player[], bool playerTurn)
{
    if(playerTurn)
    {
        return player[0].name;
    }
    else{
        return player[1].name;
    }
}

void getDetails(PLAYER player[])
{
    cout << "Name of player1 : ";
    cin >> player[0].name;
    
    cout << "Name of player2( enter AI, if you want to play with computer) : ";
    cin >> player[1].name;
}

int checkChips( int chipsInPile, PLAYER player[], bool playerTurn)
{
    int chipsTaken = 0;
    int maxPerTurn = 0;
    do 
    {
        maxPerTurn = (chipsInPile * MAX_TURN);
        cout << getName(player, playerTurn) << ", How many chips would you like?\n"; 
        cout << "You can only take upto "; 
        if (maxPerTurn == 0) {
            cout << "1" << " chips : ";
        } 
        else {
            cout << maxPerTurn << " chips : ";
        }
        if (getName(player,playerTurn) == "AI")
        {
            if (maxPerTurn == 0) {
                sleep(1);
                cout << "\n";
                chipsTaken = 1;
                
            } 
            else {
                sleep(1);
                cout << "\n";
                chipsTaken = (rand() % maxPerTurn) + 1;
            }
        }
        else{
            cin >> chipsTaken;
        }
    
    } while (maxPerTurn < chipsTaken && chipsInPile > 1);
    return chipsTaken;
}

void updateWin(PLAYER player[], bool playerTurn)
{
    if(playerTurn){
        player[0].totalWins += 1;
    }
    else{
        player[1].totalWins += 1;
    }
}