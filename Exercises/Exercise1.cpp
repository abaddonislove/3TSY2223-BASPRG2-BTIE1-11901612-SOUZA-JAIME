#include <iostream>
#include <stdlib.h> 
using namespace std;

int wallet = 1000;

// Ex 1-1 (Bet)
int bet(int& w)
{
    int b = 0;
    do
    {
        cout << "Input bet: ";
        cin >> b;
    } while (b <= 0 || b > w);
    
    w -= b;
    return b;
}

void vbet(int w)
{
    int b = 0;
    do
    {
        cout << "Input bet: ";
        cin >> b;
    } while( b <= 0 || b > w);
}

// Ex 1-2 (Dice Roll)
void roll(int& r1, int& r2)
{
    r1 = rand() % 6 + 1;
    r2 = rand() % 6 + 1;
}

// Ex 1-3 (Payout)
void payOut(int& w, int bet, int bRoll[2], int pRoll[2])
{
    int bot = bRoll[0] + bRoll[1];
    int pla = pRoll[0] + pRoll[1];
    

    if (pla == 2)
    {
        w += bet * 3;
        cout << "Snake Eyes! Player won." << endl;
        cout << "Gold : " << w << endl;
        return;
    }

    if (pla > bot)
    {
        w += bet * 2;
        cout << "Player won." << endl;
        cout << "Gold : " << w << endl;
        return;
    }

    if (pla == bot)
    {
        w += bet;
        cout << "Tie. No winners." << endl;
        cout << "Gold : " << w << endl;
        return;
    }

    else 
    {
        cout << "Player lost." << endl;
        cout << "Gold : " << w << endl;
        return;
    }

}

// Ex 1-4 (Play Round)
void playRound(int& w)
{
    int wager = bet(w);

    int bDice[2] = {};
    int pDice[2] = {};

    roll(bDice[0], bDice[1]);
    roll(pDice[0], pDice[1]);
    
    cout << "Bot rolled " << bDice[0] << ", " << bDice[1] <<  endl;
    cout << "Player rolled " << pDice[0] << ", " << pDice[1] <<  endl;

    payOut(w, wager, bDice, pDice);
}

int main()
{
    cout << "Gold : " << wallet << endl;
    while (wallet > 0)
    {
        playRound(wallet);
    }
    
    return 0;
}