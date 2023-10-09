#include <iostream>
#include <random>
#include <conio.h>

using namespace std;
void dessinerDe(int valeur) {
    switch (valeur) {
        case 1:
            std::cout << "+---------+" << std::endl;
            std::cout << "|         |" << std::endl;
            std::cout << "|    *    |" << std::endl;
            std::cout << "|         |" << std::endl;
            std::cout << "+---------+" << std::endl;
            break;
        case 2:
            std::cout << "+---------+" << std::endl;
            std::cout << "| *       |" << std::endl;
            std::cout << "|         |" << std::endl;
            std::cout << "|       * |" << std::endl;
            std::cout << "+---------+" << std::endl;
            break;
        case 3:
            std::cout << "+---------+" << std::endl;
            std::cout << "| *       |" << std::endl;
            std::cout << "|    *    |" << std::endl;
            std::cout << "|       * |" << std::endl;
            std::cout << "+---------+" << std::endl;
            break;
        case 4:
            std::cout << "+---------+" << std::endl;
            std::cout << "| *     * |" << std::endl;
            std::cout << "|         |" << std::endl;
            std::cout << "| *     * |" << std::endl;
            std::cout << "+---------+" << std::endl;
            break;
        case 5:
            std::cout << "+---------+" << std::endl;
            std::cout << "| *     * |" << std::endl;
            std::cout << "|    *    |" << std::endl;
            std::cout << "| *     * |" << std::endl;
            std::cout << "+---------+" << std::endl;
            break;
        case 6:
            std::cout << "+---------+" << std::endl;
            std::cout << "| *  *  * |" << std::endl;
            std::cout << "|         |" << std::endl;
            std::cout << "| *  *  * |" << std::endl;
            std::cout << "+---------+" << std::endl;
            break;
        default:
            std::cout << "Valeur de dé incorrecte !" << std::endl;
            break;
    }
}


int throwDice() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(1, 6);

    int randomNumber = distr(gen);
    return randomNumber;
}

char playerTurn() {
    char numDice;
    int score = 0;
    int roll1 = 0;
    int roll2 = 0;


    do {
        cout << "Voulez-vous lancer 1 ou 2 des ?" << endl;
        numDice = _getch();
    } while (numDice != '1' && numDice != '2');

    int numberOfDice = numDice - '0'; 
    cout << numberOfDice;// Convertir char en int

    for (int i = 0; i < numberOfDice; i++) {
        int roll = throwDice();
        cout << "Resultat du roll numero" << i + 1 << ": " << roll << endl;
        dessinerDe(roll);

        if (i == 0) {
            roll1 = roll;
        }
        else {
            roll2 = roll;
        }
    }

    score = roll1 + roll2; // Additionner les resultats des deux lancers pour le score
    if (numDice == 2 && roll1 == roll2) {
        cout << "Les dés sont identiques. Le score diminue de " << score << endl;
        return -score;
    }
    else {
        cout << "Le score augmente de " << score << endl;
        return score;
    }

    
}

int main() {
    

    int score1 = 0, score2 = 0;

    while (score1 < 30 && score2 < 30) {
        cout << "Tour du Joueur 1:" << endl;
        score1 += playerTurn();
        cout << "Score du Joueur 1: " << score1 << endl;

        if (score1 >= 30) {
            break;
        }

        cout << "Tour du Joueur 2:" << endl;
        score2 += playerTurn();
        cout << "Score du Joueur 2: " << score2 << endl;
    }

    if (score1 == score2) {
        cout << "Match nul !" << endl;
    }
    else if (score1 >= 30) {
        cout << "Joueur 1 remporte la partie !" << endl;
    }
    else {
        cout << "Joueur 2 remporte la partie !" << endl;
    }

    return 0;
}

