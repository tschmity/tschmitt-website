// Tyler Schmitt 
// csc-1710
// 4-8-21
// ~/csc1710/prog3/hangman.cpp
// A program that picks a word out of a text file of words and uses it for a hangman game 

// For my program I chose to do all of the "Grade A" options, along with BONUS2 (ASCII picture) and BONUS3 (data file)
// for a max grade of 100

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string randWord();  // Chooses one word out of a list

string letterGuess(string word);    // Large function to take a letter and determine what to output

void duplicateLetter(char &letter, const char lettersArray[]);   // Figures out of a letter has already been entered

void partsAdded(int iGuesses);  // Tells you what part was added when you guess wrong

void hangman(int iGuesses);    // Outputs the hangman ASCII image

void results(string word, string mysteryWord);  // Final function to decide if you won or not

int main ()
{
  string word;
  string mysteryWord;

  word = randWord();
  
  cout << "This is a hangman game, you have 10 incorrect guesses, try to figure out the word." << endl;
  
  mysteryWord = letterGuess(word);

  results(word,mysteryWord);
   
  return 0;
} 




string letterGuess(string word)
{

  string mysteryWord(word.length(),'-');  // Makes the word you are seeing as you guess the same length as the word
                                          // and makes the string only '-' characters

  int iGuesses=0,i,totalGuesses=0;  
  char letter;
  char lettersArray[52]={' '};  // Array is filled with blank spaces since it would output random letters sometimes
  bool correctGuess;            // Array size is 52 because 26 (letters in the alphabet) times 2 since half are blanks
  

  while (iGuesses < 10 && mysteryWord != word)
  {
    correctGuess = false;  // resets the bool value
 
    hangman(iGuesses);  // Inserts ASCII image
  
    cout << endl;
    cout << "The word is " << mysteryWord << endl;
    cout << "You have made " << iGuesses << " incorrect guesses" << endl;
    cout << "The letters you have guessed are: " << lettersArray << endl;
    cout << "Enter a letter:" << endl;
    cin >> letter;


    duplicateLetter(letter,lettersArray);  // Check for duplicate letters

    
    // Displays what letters you have guessed
    lettersArray[totalGuesses] = letter;
    totalGuesses++;
    lettersArray[totalGuesses] = ' ';  // Needed to add a space again because after the first letter, 
    totalGuesses++;                    // it would not show any others
   
    // Checks if any part of the word matches the letter entered
    for (i = 0; i <= mysteryWord.length(); i++)
    {
      if (letter == word[i])      
      {
        mysteryWord[i] = letter;  
        correctGuess = true;
      }
    }
    // If bool value is not make true, it means there was not a match and adds an incorrect guess and outputs accordingly
    if (correctGuess == false)
    {
      cout << endl << "Sorry! " << letter << " was not a letter!" << endl;
      iGuesses++;
      partsAdded(iGuesses);
    }
    else
    { 
      cout << endl << "Yes! " << letter << " was a letter!" << endl;  // If bool was true, lets you know it was a letter
    }
  }
  

  return mysteryWord;
} 



string randWord()
{

  ifstream inData;
  string datafile;    
  string word;
  string words[30];     // Creates an array of 30 spots because the data file I was using had 30 words
  int i;

  // Allows user to enter in what data file they want to use
  cout << "What data file do you want to use for the hangman game?" << endl;
  cin >> datafile;
  cout << endl;

  inData.open(datafile);  // Opens whatever data file they enter
  
  for(i = 0; i < 30; i++)  // Enters words into the array
  {
    inData >> words[i]; 
  }
  
  srand(time(0));
  word = words[rand() % 30];  // Makes the word equal to some random word in the array

  inData.close();

  return word;
}


void duplicateLetter(char &letter, const char letterArray[])
{
  int i;

  for (i = 0; i < 52; i++)   // Checks if a letter has already been entered and does not move on until it isn't 
  {
    while (letter == letterArray[i])
    {
      cout << endl << "You already guessed this letter! Please enter another letter:" << endl;
      cin >> letter;
    } 
  }  
}


void partsAdded(int iGuesses)  // Separate function from hangman pictures, so it only outputs when a letter is wrong
{
  if (iGuesses == 1)
    cout << "The head was added!" << endl;

  if (iGuesses == 2)
    cout << "The torso was added!" << endl;

  if (iGuesses == 3)
    cout << "The left arm was added!" << endl;

  if (iGuesses == 4)
    cout << "The right arm was added!" << endl;

  if (iGuesses == 5)
    cout << "The left leg was added!" << endl;

  if (iGuesses == 6)
    cout << "The right leg was added!" << endl;

  if (iGuesses == 7)
    cout << "The left eye was added!" << endl;

  if (iGuesses == 8)
    cout << "The right eye was added!" << endl;
  
  if (iGuesses == 9)
    cout << "The nose was added!" << endl;

  if (iGuesses == 10)
    cout << "The mouth was added!" << endl;
}



void hangman(int iGuesses)
{
  if (iGuesses == 0)
  {
    cout << " ___________________    " << endl;
    cout << "  |                     " << endl;
    cout << "  |                     " << endl;
    cout << "  |                     " << endl;
    cout << "  |                     " << endl;
    cout << "  |                     " << endl;
    cout << "  |                     " << endl;
    cout << "  |                     " << endl;
    cout << "  |                     " << endl;
    cout << "  |                     " << endl;
    cout << "  |                     " << endl;
    cout << "  |                     " << endl;
    cout << "  |                     " << endl;
    cout << "__|__                   " << endl;
  }
  if (iGuesses == 1)
  {
    cout << " ___________________    " << endl;
    cout << "  |             |       " << endl;
    cout << "  |           _____     " << endl;
    cout << "  |           |   |     " << endl;
    cout << "  |           \\___/    " << endl;
    cout << "  |                     " << endl; 
    cout << "  |                     " << endl;
    cout << "  |                     " << endl;
    cout << "  |                     " << endl;
    cout << "  |                     " << endl;
    cout << "  |                     " << endl; 
    cout << "  |                     " << endl;
    cout << "  |                     " << endl;
    cout << "__|__                   " << endl;
  }
  if (iGuesses == 2)
  {
    cout << " ___________________    " << endl;
    cout << "  |             |       " << endl;
    cout << "  |           _____     " << endl;
    cout << "  |           |   |     " << endl;
    cout << "  |           \\___/    " << endl;
    cout << "  |             |       " << endl;
    cout << "  |             |       " << endl;
    cout << "  |             |       " << endl;
    cout << "  |             |       " << endl;
    cout << "  |                     " << endl;
    cout << "  |                     " << endl;
    cout << "  |                     " << endl;
    cout << "  |                     " << endl;
    cout << "__|__                   " << endl;
  }
  if (iGuesses == 3)
  { 
    cout << " ___________________    " << endl;
    cout << "  |             |       " << endl;
    cout << "  |           _____     " << endl;
    cout << "  |           |   |     " << endl;
    cout << "  |           \\___/    " << endl;
    cout << "  |             |       " << endl;
    cout << "  |            /|       " << endl;
    cout << "  |           / |       " << endl;
    cout << "  |          /  |       " << endl;
    cout << "  |                     " << endl;
    cout << "  |                     " << endl;
    cout << "  |                     " << endl;
    cout << "  |                     " << endl;
    cout << "__|__                   " << endl; 
  }
  if (iGuesses == 4)
  {
    cout << " ___________________    " << endl;
    cout << "  |             |       " << endl;
    cout << "  |           _____     " << endl;
    cout << "  |           |   |     " << endl;
    cout << "  |           \\___/    " << endl;
    cout << "  |             |       " << endl;
    cout << "  |            /|\\     " << endl;
    cout << "  |           / | \\    " << endl;
    cout << "  |          /  |  \\   " << endl;
    cout << "  |                     " << endl;
    cout << "  |                     " << endl;
    cout << "  |                     " << endl;
    cout << "  |                     " << endl;
    cout << "__|__                   " << endl;
  }
  if (iGuesses == 5)
  {
    cout << " ___________________     " << endl;
    cout << "  |             |        " << endl;
    cout << "  |           _____      " << endl;
    cout << "  |           |   |      " << endl;
    cout << "  |           \\___/     " << endl;
    cout << "  |             |        " << endl;
    cout << "  |            /|\\      " << endl;
    cout << "  |           / | \\     " << endl;
    cout << "  |          /  |  \\    " << endl; 
    cout << "  |            /         " << endl;
    cout << "  |           /          " << endl;
    cout << "  |          /           " << endl;
    cout << "  |                      " << endl;
    cout << "__|__                    " << endl;
  }
  if (iGuesses == 6)
  {
    cout << " ___________________     " << endl;
    cout << "  |             |        " << endl;
    cout << "  |           _____      " << endl;
    cout << "  |           |   |      " << endl;
    cout << "  |           \\___/     " << endl;
    cout << "  |             |        " << endl;
    cout << "  |            /|\\      " << endl;
    cout << "  |           / | \\     " << endl;
    cout << "  |          /  |  \\    " << endl;
    cout << "  |            / \\      " << endl;
    cout << "  |           /   \\     " << endl;
    cout << "  |          /     \\    " << endl;
    cout << "  |                      " << endl;
    cout << "__|__                    " << endl;
  } 
  if (iGuesses == 7)
  {
    cout << " ___________________     " << endl;
    cout << "  |             |        " << endl;
    cout << "  |           _____      " << endl;
    cout << "  |           |-  |      " << endl;
    cout << "  |           \\___/     " << endl;
    cout << "  |             |        " << endl;
    cout << "  |            /|\\      " << endl;
    cout << "  |           / | \\     " << endl;
    cout << "  |          /  |  \\    " << endl;
    cout << "  |            / \\      " << endl;
    cout << "  |           /   \\     " << endl;
    cout << "  |          /     \\    " << endl;
    cout << "  |                      " << endl;
    cout << "__|__                    " << endl;
  }
  if (iGuesses == 8)
  {
    cout << " ___________________     " << endl;
    cout << "  |             |        " << endl;
    cout << "  |           _____      " << endl;
    cout << "  |           |- -|      " << endl;
    cout << "  |           \\___/     " << endl;
    cout << "  |             |        " << endl;
    cout << "  |            /|\\      " << endl;
    cout << "  |           / | \\     " << endl;
    cout << "  |          /  |  \\    " << endl;
    cout << "  |            / \\      " << endl;
    cout << "  |           /   \\     " << endl;
    cout << "  |          /     \\    " << endl;
    cout << "  |                      " << endl;
    cout << "__|__                    " << endl;
  }
  if (iGuesses == 9) 
  {
    cout << " ___________________     " << endl;
    cout << "  |             |        " << endl;
    cout << "  |           _____      " << endl;
    cout << "  |           |-.-|      " << endl;
    cout << "  |           \\___/     " << endl;
    cout << "  |             |        " << endl;
    cout << "  |            /|\\      " << endl;
    cout << "  |           / | \\     " << endl;
    cout << "  |          /  |  \\    " << endl;
    cout << "  |            / \\      " << endl;
    cout << "  |           /   \\     " << endl;
    cout << "  |          /     \\    " << endl;
    cout << "  |                      " << endl;
    cout << "__|__                    " << endl;
  }

}


void results(string word, string mysteryWord)  // Final function that determines if you guessed the word
{
  if (mysteryWord == word)
    cout << endl << "congratulations! You win! The word was " << word << endl;
  else
    { 
   // Need the final picture here because the loop stops once it hits 10 incorrect guesses
    cout << " ___________________     " << endl;
    cout << "  |             |        " << endl;
    cout << "  |           _____      " << endl;
    cout << "  |           |-.-|      " << endl;
    cout << "  |           \\_o_/     " << endl;
    cout << "  |             |        " << endl;
    cout << "  |            /|\\      " << endl;
    cout << "  |           / | \\     " << endl;
    cout << "  |            / \\      " << endl;
    cout << "  |           /   \\     " << endl;
    cout << "  |          /     \\    " << endl;
    cout << "  |                      " << endl;
    cout << "__|__                    " << endl;
  
  
    cout << endl << "You lose! The word was " << word << endl;
    }
}
