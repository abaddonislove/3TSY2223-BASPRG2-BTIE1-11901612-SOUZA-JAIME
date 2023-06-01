#include <iostream>
#include <stdlib.h> 
using namespace std;

// emperor, civilian, slave

// 1. choose bet
// 2. set deck
// 3. choose card
// 4. compare cards 
// 5. check winner
// 6. add gold or lose life
// 7. check if win or loss
// 8. end game after 12 rounds

void printStatus(int w, int hp, int round)
{
    cout << "Round: " << round << endl;
    cout << "Wallet: " << w << endl; 
    cout << "Millimeters left: " << hp << endl;
}

void printCards(string pCards[5], string eCards[5])
{

    cout << "Player Cards: ";

    for (int i = 0; i < 5; i++)
        {
            cout << "[" << pCards[i] << "] ";
        }
    cout << endl;

    cout << "Bot Cards: ";

    for (int j = 0; j < 5; j++)
        {
            cout << "[" << eCards[j] << "] ";
        }
    
    cout << endl << endl;
}

int setBet(int hp)
{
    int bet;

    do
    {
        cout << "\nInput bet: ";
        cin >> bet;
    } while (bet <= 0|| bet > hp);
    
    cout << endl;
    return bet;
}

// setting deck
void setDeck(string& card)
{
    if (card == "slave")
    {
        card = "emperor";
    }
    else 
    {
        card = "slave";
    }
}

// choosing card
int chooseCard()
{
    int choice;
    cout << "Choose card (1-5): ";
    cin >> choice;
    cout << endl;
    return choice - 1;
}

int compareCard(string pCards[5], string eCards[5])
{
    int p = chooseCard();
    int e = rand() % 5;
    cout << "P: [" << pCards[p] << "]\n";
    cout << "E: [" << eCards[e] << "]\n\n";

    if (pCards[0] == "slave")
    {

        if (p == 0 && e == 0)
        {
            return 0;
        }
        if (p == 0 && e > 0 || p > 0 && e == 0)
        {
            return 1;
        }
        if (p > 0 && e > 0)
        {
            return 2;
        }

    }    

    if (pCards[0] == "emperor")
    {
        if (p == 0 && e == 0 || p > 0 && e == 0)
        {
            // player loses
            return 1;
        }
        if (p == 0 && e > 0)
        {
            // player loses
            return 0;
        }
        if (p > 0 && e > 0)
        {
            // tie
            return 2;
        }
    }

    return 0;
}

// 5. check winner
// 6. add gold or lose life

void transactBet(bool win, string cards[5], int& w, int& hp, int bet)
{
    int gain = 100000;

    if (win == 0)
    {
        if (cards[0] == "emperor")
        {
            // add 100,000 * bet
            w += bet * gain;
        }

        if (cards[0] == "slave")
        {
            // add 100,000 * bet * 5
            w += bet * gain * 5;
        }
    }

    if (win == 1)
    {
        // deduct hp
        hp -= bet;
    }

}

// emperor, civilian, slave
int main()
{

    int hp = 30;
    int wallet = 0;
    int winCondition = 2000000;
    int rounds = 12;
    string pCards[] = {"emperor","civilian","civilian","civilian","civilian"};
    string eCards[] = {"slave","civilian","civilian","civilian","civilian"};

    for (int i = 0, j = 1; i < rounds-1; i++ ,j++)
    {
        system("CLS");

        printStatus(wallet, hp, i+1);

        int bet = setBet(hp);

        printCards(pCards, eCards);

        bool win = compareCard(pCards, eCards);
        
        transactBet(win, pCards, wallet, hp, bet);

        if (j == 3)
        {
            setDeck(pCards[0]);
            setDeck(eCards[0]);
        }

        if (wallet >= winCondition)
        {   
            printStatus(wallet, hp, i+1);
            cout << "\nYou win!";
            return 0;
        }

        if (hp == 0)
        {
            printStatus(wallet, hp, i+1);
            cout << "\nEardrum popped! You lose.";
            return 0;
        }

        system("pause");
    }
    printStatus(wallet, hp, 12);
    cout << "Rounds over! You lose.";
    //return 0;
}