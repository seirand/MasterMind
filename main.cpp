
#include <iostream>
#include <string>
#include <cstdlib>
#include <stdlib.h>
using namespace std;

/* As this is a small part of a much bigger system, we use a
   MasterMind class which is reusable object */

class MasterMind {
  public:
    string codeProducer();
    int acceptableGuess(string guess);
    string get_acceptable_guess();
    void play_game();
  private:
    string guess;
    int num_guess;
    string s = "BGOPRY";
};


/* get_acceptable_guess is a function which gets the guess and
   if it is not acceptable, informs the player */

string MasterMind::get_acceptable_guess()
{
  string guess;


  while(1) {
    cout <<"An acceptable guess is an uppercase string with length 4 and without space or blanks \n";
    cout <<"[B:Blue, G:Green, O:Orange, P:Pink, R:Red, Y:Yellow] \n ";
    cout << "CodeBreaker: Make an acceptable guess please: ";
    cin >> guess;
    if (acceptableGuess(guess)) return guess;
    cout <<  "This is not an acceptable guess.\n";
  }
}


/* acceptableGuess is a function which checks the guess is an
   acceptable 4 digit answer without blanks */

int MasterMind::acceptableGuess(string guess)
{
  string s = "BGOPRY";
  if (guess.length()!= 4 || guess == " ") return 0;
  //else if ( s.find(guess[0]) && s.find(guess[1]) && s.find(guess[2]) && s.find(guess[3]))return 1;
  else return 1;
}

//generate a random secret code

string MasterMind::codeProducer()
{
 int k,c;
 string s = "BGOPRY";
 string code = "";
 for (k=0; k<4; k++){

          c = rand()%5;
          code = code + s[c];
 }
    return code;
}

void MasterMind::play_game()
{
  string code  ;
  string guess;
  char gFirst, gSecond, gThird, gFourth;
  char cFirst, cSecond, cThird, cFourth;
  int correct_color;
  int correct_guess;


  code = codeProducer();
  cFirst = code[0];
  cSecond = code[1];
  cThird = code[2];
  cFourth = code[3];

  num_guess = 1;

  while (1) {

    guess = get_acceptable_guess();

    if (guess == code) {
      cout << "Correct! You guessed in " << num_guess << " guesses ";

      return;
   } else {

      gFirst = guess[0];
      gSecond = guess[1];
      gThird = guess[2];
      gFourth = guess[3];



      correct_guess = 0;
      correct_color = 0;
      if (gFirst == cFirst) correct_guess++;
      else if (cFirst == gSecond || cFirst == gThird || cFirst == gFourth) correct_color++;
      if (gSecond == cSecond) correct_guess++;
      else if (cSecond == gFirst || cSecond == gThird || cSecond == gFourth) correct_color++;
      if (cThird == gThird) correct_guess++;
      else if (cThird == gFirst || cThird == gSecond || cThird == gFourth) correct_color++;
      if (gFourth == cFourth) correct_guess++;
      else if (cFourth == gFirst || cFourth == gSecond || cFourth == gThird) correct_color++;



      cout << "Correct guess: " << correct_guess << endl;
      cout << "Correct color:  " << correct_color << endl;
    }
    num_guess++;
    if (num_guess> 10) return ;
  }

  return;
  }


int main()
{
  MasterMind game;

  game.play_game();

  return 0;
}

