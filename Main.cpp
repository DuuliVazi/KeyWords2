#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>
#include <cctype>
#include <cstdlib>
#include <array>
#include <random>
#include <chrono>

using namespace std;

int main()
{
    string name;
    // Display Title of the program to the user
    cout << "This is the Keywords II Code Breaker Training Simulation Program.";
    // Ask the recruit to log in using their name
    cout << " Can you please log in with your first name?\n";
    cin >> name;

    // Hold the recruit's name in a var, and address them by it throughout the simulation

    // Display an overview of what Keywords II is to the recruit
    cout << "\nWe love the work you have been showing us recruit " << name << ". Recently the enemy is using single scrambled low-tech keywords to signal other enemies to start attacks which our current code decryption programs have not been successful against. Here at the CIA we are developing a new codebreaking team that relies on human expertise to detect these low tech scrambled keywords.\n";
    // Display directions to the recruit on how to use Keywords
    cout << "\nTo start, I have a list of 10 words of which I will pick 3 random words out of. And you will have to guess the letters for the secret words that I pick out.\n";

    // Create a collection of 10 words you had written down manually

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    array<string, 10> WORDS{"QUESTION", "ANSWER", "FORCES", "ALIGN", "CENTER", "EARTH", "PLANET", "ARTIFICIAL", "CAP", "BOND"};
    // Shuffles the words and picks a random one.
    shuffle(WORDS.begin(), WORDS.end(), std::default_random_engine(seed));

    // Create an int var to count the number of simulations being run starting at 1
    int counter = 1;
    // Display the simulation # is starting to the recruit
    cout << "You are starting at simulation " << counter << "\n";
    //The number of incorrect guesses
    int wrong = 0;
    //That it maximum number of incorrect guesses allowed
    int nomore = 8;
    // Pick new 3 random words from your collection as the secret code word the recruit has to guess
    const string THE_WORD1 = WORDS[0];   // The word to guess
    string soFar(THE_WORD1.size(), '-'); //The word guessed so far
    string already = "";                 // The letters that already guessed
    // While recruit hasn’t made too many incorrect guesses and hasn’t guessed the secret word
    while ((wrong < nomore) && (soFar != THE_WORD1))
    {
        // Increment the number of incorrect guesses the recruit has made
        nomore - wrong++;
        // Tell recruit how many incorrect guesses he or she has left
        cout << "\n\nYou have " << (nomore - wrong) << " guesses left\n";
        // Show recruit the letters he or she has guessed
        cout << "\nYou've used the following letters:\n"
             << already << "\n\n";
        char guess;
        cout << "Go ahead and enter your guess.\n";

        // Get recruit ’s guess
        cin >> guess;
        guess = toupper(guess);
        // While recruit has entered a letter that he or she has already guessed
        while (already.find(guess) != string::npos)
        {

            // Show player how much of the secret word he or she has guessed
            cout << "\nYou've already guessed " << guess << endl;
            // Get recruit's next guess
            cin >> guess;
            guess = toupper(guess);
        }
        // Add the new guess to the group of used letters
        already += guess;

        // If the guess is in the secret word
        if (THE_WORD1.find(guess) != string::npos)
        {
            // Tell the recruit the guess is correct
            cout << "It's right!! " << guess << " is in the word.\n";
            // Update the word guessed so far with the new letter
            for (int i = 0; i < THE_WORD1.length(); ++i)
            {
                if (THE_WORD1[i] == guess)
                {
                    soFar[i] = guess;
                }
            }
        }
        else if ((THE_WORD1.find(guess) != string::npos) && (wrong < nomore))
        {
            cout << "It's right!! " << guess << " is in the word.\n";
        }
        // Otherwise
        else
        {
            // Tell the recruit the guess is incorrect
            cout << "Sorry," << guess << " isn't in the word.\n";
            // Putting the incrementer here does not work with my program
        }
    }
    // If the recruit has made too many incorrect guesses
    if (wrong == nomore)
    {
        // Tell the recruit that he or she has failed the Keywords II course
        // Ask the recruit if they would like to run the simulation again
        cout << "\nYou have failed recruit, if you would like to play again, enter Y and if not enter N.";
        char playagain;
        cin >> playagain;
        // If the recruit wants to run the simulation again
        if (playagain == 'Y' || playagain == 'y')
        {
            counter++;
            // Increment the number of simulations ran counter
            cout << "You are now on simulation " << counter++ << "\n";
            // Move program execution back up to // Display the simulation # is starting to the recruit
            return main();
        }
        // Otherwise
        else if (playagain == 'N' || playagain == 'n')
        {
            // Display End of Simulations to the recruit
            cout << "Simulation " << counter << " is now over.\n";
            // Pause the Simulation with press any key to continue
            cout << system("pause");
        }
    }
    // Otherwise
    else
    {
        // Congratulate the recruit on guessing the secret words
        cout << "\nYou guessed the right letter recruit!";
    }
    cout << "\nThe word was " << THE_WORD1 << endl;

    return 0;
}
