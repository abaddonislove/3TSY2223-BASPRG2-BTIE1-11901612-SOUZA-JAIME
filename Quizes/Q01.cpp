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

void printStatus(int w, int mmLeft, int round)
{
    cout << "Round: " << round << endl;
    cout << "moneyEarned: " << w << endl; 
    cout << "Millimeters left: " << mmLeft << endl;
}

void printCards(string pCards[5], string eCards[5])
{

    cout << "Player Cards: ";

    for (int i = 0; i < 5; i++)
        {
            if (pCards[i] != "")
            {
                cout << "[" << pCards[i] << "] ";
            }
        }
    cout << endl;

    cout << "Bot Cards: ";

    for (int j = 0; j < 5; j++)
        {
            if (eCards[j] != "")
            {
                cout << "[" << eCards[j] << "] ";
            }
        }
    
    cout << endl << endl;
}

int setBet(int mmLeft)
{
    int bet;

    do
    {
        cout << "\nInput bet: ";
        cin >> bet;
    } while (bet <= 0|| bet > mmLeft);
    
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
int chooseCard(string cards[])
{
    int choice;

    do
    {
        cout << "Choose card (1-5): ";
        cin >> choice;
        cout << endl << cards[choice-1];
        
    } while (cards[choice-1] == "");
    
    return choice - 1;
}

int eChooseCard(string cards[])
{
    int choice;

    do
    {
        choice = rand() % 5;
        
    } while (cards[choice] == "");
    
    return choice;
}


void removeCard(string& card)
{
    card = ""; 
}

int compareCard(string pCards[5], string eCards[5], int p, int e)
{
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

void transactBet(int win, string cards[5], int& w, int& mmLeft, int bet)
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
        // deduct mmLeft
        mmLeft -= bet;
    }

    if (win == 2)
    {
        cout << "tied\n";
    }
}

void playRound(int round, int& moneyEarned, int& mmLeft)
{
    string pStart;
    string eStart;
    int pulls = 0;
    if (round < 3 || (round - round % 3) % 2 == 0)
    {
        pStart = "emperor";
        eStart = "slave";
    }
    if (((round - round % 3) + 3) % 2 == 0)
    {
        pStart = "slave";
        eStart = "emperor";
    }
    
    string pCards[] = {pStart,"civilian","civilian","civilian","civilian"};
    string eCards[] = {eStart,"civilian","civilian","civilian","civilian"};

    int bet = 0;

    while (true)
    {
        system("CLS");

        printStatus(moneyEarned, mmLeft, round);

        if (pulls == 0)
        {
            bet = setBet(mmLeft);
        }

        //cout << pCards[0] << endl; //checks 1st card in hand
        printCards(pCards, eCards);

        // choosing of cards
        int p = chooseCard(pCards);
        int e = eChooseCard(eCards);

        // checks for win, loss, draw
        int win = compareCard(pCards, eCards, p , e);

        //cout << "win: " << win << endl; 
        //cout << bet << endl;
        // prints tied, applies loss/ win
        transactBet(win, pCards, moneyEarned, mmLeft, bet);

        // removes card from hand if tied
        removeCard(pCards[p]);
        removeCard(eCards[e]);

        system("pause");
        pulls ++;
        // checks if not draw to move to next round
        if (win != 2 || pulls == 3)
        {
            break;
        }
    }
    
}

// emperor, civilian, slave
int main()
{

    int mmLeft = 30;
    int moneyEarned = 0;
    int winCondition = 2000000;
    int round = 1;
    int rounds = 12;
    string pStart = "emperor";
    string eStart = "slave";

    while (round != rounds+1)
    {
        playRound(round, moneyEarned, mmLeft);

        // checks if won/ lost game
        if (moneyEarned >= winCondition)
        {   
            printStatus(moneyEarned, mmLeft, round);
            cout << "\nYou win!";
            return 0;
        }

        if (mmLeft == 0)
        {
            printStatus(moneyEarned, mmLeft, round);
            cout << "\nEardrum popped! You lose.";
            return 0;
        }

        round ++;
    }

    
    
    printStatus(moneyEarned, mmLeft, 12);
    cout << "Rounds over! You lose.";

    // for (int i = 0, j = 1; i < rounds-1; i++ ,j++)
    // {
    //     string pCards[] = {pStart,"civilian","civilian","civilian","civilian"};
    //     string eCards[] = {eStart,"civilian","civilian","civilian","civilian"};

    //     while (true)
    //     {
    //         system("CLS");

    //         printStatus(moneyEarned, mmLeft, i+1);

    //         int bet = setBet(mmLeft);

    //         //cout << pCards[0] << endl; //checks 1st card in hand
    //         printCards(pCards, eCards);

    //         // choosing of cards
    //         int p = chooseCard(pCards);
    //         int e = eChooseCard(eCards);

    //         // checks for win, loss, draw
    //         int win = compareCard(pCards, eCards, p , e);

    //         //cout << "win: " << win << endl; 
            
    //         // prints tied, applies loss/ win
    //         transactBet(win, pCards, moneyEarned, mmLeft, bet);

    //         // removes card from hand if tied
    //         removeCard(pCards[p]);
    //         removeCard(eCards[e]);

    //         // checks if won/ lost game
    //         if (moneyEarned >= winCondition)
    //         {   
    //             printStatus(moneyEarned, mmLeft, i+1);
    //             cout << "\nYou win!";
    //             return 0;
    //         }

    //         if (mmLeft == 0)
    //         {
    //             printStatus(moneyEarned, mmLeft, i+1);
    //             cout << "\nEardrum popped! You lose.";
    //             return 0;
    //         }

    //         system("pause");

    //         // checks if not draw to move to next round
    //         if (win != 2)
    //         {
    //             break;
    //         }
    //     }
    //return 0;
}