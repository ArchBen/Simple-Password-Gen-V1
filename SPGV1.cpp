#include<iostream>
#include<cstdlib>
int main() 
{
    //Rand Seed
    srand((unsigned) time(NULL));
    bool numbersB = false;
    bool speicialsB = false;

    char nCheck = 'y';
    char sCheck = 'y';

    std::string letters ="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string numbers = "0123456789";
    std::string specials = "#£&_-@()=+':%/*,.$€[]{}<>^`;÷";
    std::string password = "";

    int length = 0;
    int lettersL = letters.length();
    int numbersL = numbers.length();
    int specialsL = specials.length();

    std::cout << "Password Generator - Ben Archard\n";
    std::cout << "Please enter length of desired password: ";
    std::cin >> length;
    std::cout << "Do you wish to have numbers included (y/n): ";
    std::cin >> nCheck;
    std::cout << "Do you wish to have speicial chars included (y/n): ";
    std::cin >> sCheck;

    switch (nCheck) {
        case 'y':
            numbersB = true;
            break;
        case 'n':
            break;
    }

    switch (sCheck) {
        case 'y':
            speicialsB = true;
            break;
        case 'n':
            break;
    }

    for (int i = 0; i < length; i++) {
        if (password.length() >= length) {
            break;
        } else {
           switch (numbersB){
               case true:
                   password += numbers[0 + (std::rand() % numbersL)];
                   break;
               case false:
                   break;
            }
            if (password.length() >= length) {
               break;
            } else {
                   switch (speicialsB){
                        case true:
                           password += specials[0 + (std::rand() % specialsL)];
                           break;
                        case false:
                            break;
                    }
                    if (password.length() >= length) {
                       break;
                    } else {
                      password += letters[0 + (std::rand() % lettersL)];
                    } 
                } 

        }   
    }

    std::cout << "Your password is: "<< password << std::endl;
}