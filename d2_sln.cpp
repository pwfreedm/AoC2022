#include <iostream>
#include <fstream>
#include <string>
#include <stack>

using std::string;
using std::getline;
using std::cout;
using std::endl;

int playRound(std::stack<int> &c);
int pR_hard(std::stack<int> &c);
int getScore(int command, int play);

int main(int argc, char const *argv[])
{
    std::ifstream i ("d2_input.txt");
    char cur;
    //using ASCII to skip some cases in the easy puzzle
    std::stack<int> c;
    int score = 0;
    while(i.peek() != EOF) {
        cur = i.get();
        if(int(cur) >= 65 && int(cur) <= 90) {
            c.push((int)cur);
        }
        if(c.size() == 2) {
            //to simulate easy, switch this method call to playRound
            score += pR_hard(c);
        }
        
    }
    cout << score << endl;
    return 0;
}
/** Simulates one game of rock paper scissors
 * 
 * @return - the score of the game. 
 * 
*/
int playRound(std::stack<int> &c) {
    int scoreToAdd = 0;
    int game = c.top();
        c.pop();
        //if 24 or 21, we won
        if(game - c.top() == 24 || game - c.top() == 21) {
            scoreToAdd += 6;
        } else if (game - c.top() == 23) {
            scoreToAdd += 3;
        }
        c.pop();
        return scoreToAdd += (game - 87);
}
/**
 * Simulates one game of rock paper scissors according to
 * the rules of the hard problem.
 * 
 * @return the score to be added
*/
int pR_hard(std::stack<int> &c) {
    int command = c.top();
    c.pop();
    int play = c.top();
    c.pop();
    return getScore(command, play);
}

/**
 * Helper to calculate score for pR_hard.
 * 
 * @return the value to be added to the total score.
*/
int getScore(int command, int play) {
    //lose cases
    if(command == 88) {
        if(play == 65) {return 3;}
        if(play == 66) {return 1;}
        if(play == 67) {return 2;}
        
    }
    //draw case
    if(command == 89) {return 3 + (play - 64);}
    //win cases
    if(play == 65) {return 8;}
    if(play == 66) {return 9;}
    //last case: you win with rock
    return 7;
    
}

