/*
Rebecca van der Lee
C++ fall 2020
Due:11/2/2020
Lab Name: Lab 5 Number Guessing Game
Description: Write a number-guessing game in which the computer selects a random number in the range of 0 to 100, and users get
a maximum of 20 attempts to guess it. At the end of each game, users should be told whether they won or lost, and then be asked
whether they want to play again. When the user quits, the program should output the total number of wins and losses. 
To make the game more interesting, the program should vary the wording of the messages that it outputs for winning, for losing,
and for asking for another game. Create 10 different messages for each of these cases, and use random numbers to choose among
them. This application should use at least one Do-While loop and at least one Switch statement. Write your C++ code using good
style and documenting comments. You should use functions in your code as well. Your source code file should be called Lab5.cpp.
*/


#include <iostream> //This is used for basic function in c++
#include <stdlib.h> // This is used for the random number generator
#include <time.h> // This is used for the time seed
#include <cassert>// This is used for the assert function
using namespace std;



void game(int& wincount, int&losecount); /*precondition: The flow of control is valid and the main function's do while loop is active
										   
										   postcondition:  "input" and "rNum" are initialized. A statement is outputted to screen to ask
										   the user for a number.In the statement is guessNum called. Then there is a value inputted into "input"
										   the condition in the if statetements are tested and outputted. "losingmessage" is potentially called.
										   Winning message is called when the user guessed the right number. The loop exits when rNum is equal to
										   the input and continues if rNum is not equal to the input. 
										   Lastly, the "score" function is called*/

// The upcommig functions are called within in the "game" function.
void guessNum(int);/*Precondition: The flow of conrol has changed to "game" function and its for loop is acitve. 
				     Postcondition: A statement is outputs "guessses". */


void winningmessage();/* precondition: The flow of control has moved to the "game" function and its for loop is active.
					                   The variables "input and "rNum" are initialized and (cin) is valid. The assertion 
									   ("input"=rNum") is true.
						 postcondition: The variable "ranwin" is initialized. And there  will be outputted a random statement based
						                on the value of "ranwin"*/ 
void losingmessage(int);/*precondition: The flow of control has moved to "game" function and its for loop is active. "Input" 
						                and "rNum" are initialized. (cin) is valid. The assertion ("input = rnum") is not true
										and the assertion ("guesses" != 20 && "input" != "rNum") is not true.
						 postcondition: The variable ranloss is initialized. And there  will be outputted a random statement based
						                on the value of "ranloss"*/


void score(int, int, int& wincount, int& losnecount); /*precondition: The flow of control has moved to the "game" function and the variables
													                  "input" and "Rnum" are initialized. (cin) is valid. The for loop has
																	   exited
														 postcondition: The value for "wincount" or the value of "losecount" will be incremented depending
														                on if the "input" was equal to "rNum"*/
void playagainPrompt();/* precondition: The flow of control is valid and the main function's do while loop is active. The game "function"
										has exited and (cin) is valid.
						  postcondition: "ranprompt" is initialized and a random. And there  will be outputted a random statement based
										on the value of "ranprompt" */

int main()//Definition of the main function.
{
	
	

	
	cout << "Welcome to the number guessing game"<<endl;
	int losecount = 0; // declaration of losecount
	int wincount = 0;// declaration of wincount
	int playagain;//declaration of playagain

	cout << "This game will calculate a random number between 0 and 100."<< endl;// welcome statement is ouputted to the screen
    cout << "Your goal is to guess the number that the computer calculated."<< endl;
	cout <<"In each game you have 20 guesses the number."<<endl<< endl;
	do// The game is contained wihtin a do looop so that the user can choose to play again
	{  
		game(wincount, losecount);// The game function is called
		playagainPrompt();//The playagain function is called
		cin >> playagain;// The user puts in whole number into the playagain variable
		
		cout << endl;

		
		
	} while (playagain==1);//The test for the do loop

	cout << "Your score was: " << wincount << " wins and " << losecount<< " loses\n";//ouputs the score after a game hasd ende
	return 0;
}

//This is the function definition for the game function. This fucntions contains a for loop that will check if
//the "input" is valid, and this function contain the call for the score function
void game(int& wincount, int&losecount)
{
	
	int input;//The variable for input is declared
	srand(time(NULL));//time seed is initialized
	int rNum = rand() % 100 + 0;//the number that has to be guessed is calculated
	

	//This loop contains the part where the user puts in a guess, then it determines how is should react. 
	//This loop can have a maximum of 20 iterations.
	for (int guess = 1; guess <= 20; guess++)
	{

		cout << "\nInput your "; guessNum(guess); cout << " guess and press enter" << endl;
		cin >> input;//The user inputs your guess
		if (!cin)//this checking if the varable is valid.
		{
			cout << "\n Invalid input. Please make sure that you put in a number. You cannot use characters";

		}
		assert(cin);// This will close the program if the input is invalid. 
		if (input < 0 || input > 100)//This is checking if the input is within the range.
		{
			cout << "The value you entered was not in the range"<<endl; //prompt

		}
		else if (input == rNum)//checking if the user's input is correct
		{
			winningmessage();
			guess = 21;

		}
		else if (guess != 20 && input != rNum)//if the guess is incorrect, messages is outputted to the screen
		{
			cout << "\n wrong, you can try again";
			
		}
		else//if the user did not guess the number within 20 guesses
			 //a losingmessage function will be called
		{
			losingmessage(rNum);
		}

	}
	
	score(rNum, input, wincount, losecount );//The score function is called
	
}
//This is the function definition for the guessnum fucntion.
//It will determine which number of guess that the user is on.
void guessNum(int guess)
{
	switch (guess)            // This switch statement takes the number of the guess
	{                           // and deciders which statement should be oututted.
	case 1: cout << "first";
		break;
	case 2: cout << "second";
		break;
	case 3: cout << "third";
		break;
	case 4: case 5: case 6: case 7: case 8: case 9: case 10: case 11:
	case 12: case 13: case 14: case 15: case 16: case 17: case 19: case 20:
		cout << guess << "th";
		break;
	default: cout << "error";
	}
}
void winningmessage()
{
	srand((time(NULL)));                // A random number is generated. This number will determine which statement is outputted on the screen. 
	int ranwin = rand() % 10 + 1;      // an output statment for the guessed the right number
	switch (ranwin)                    // A switchstatement is used for the selection of 10 winning messages
	{
	case 1: cout << "\nYou guessed the right number";
		break;
	case 2: cout << "\nAmazing!! Your guess was right";
		break;
	case 3: cout << "\nYou are superhero, you guessed the right number";
		break;
	case 4: cout << "\nGood job! You were right!";
		break;
	case 5: cout << "\nWell done! Your guess was right";
		break;
	case 6: cout << "\nAmazing! You guessed the right number";
		break;
	case 7: cout << "\nAwesome! You were right!";
		break;
	case 8: cout << "\nUnbelievable! Your guess was right";
		break;
	case 9: cout << "\nCongratulations you won";
		break;
	case 10: cout << "\n You are lucky, you guessed the right number";
	default: cout << "randum number generator needs to be fixed";
	}
}





//This is the function definition for the losinmessage function. It chooses a loosing message to ouput randomly. 
void losingmessage(int rNum)
{
	srand((time(NULL)));    // A random number is generated. This number will determine which statement is outputted on the screen. 
	int ranloss = rand() % 10 + 1;     // an output statment for the user when they lose.
	switch (ranloss)                   // A switchstatement is used for the selection of 10 losing statements
	{
	case 1:  cout << "\nUnfortunately, you lost this game";
		break;
	case 2:  cout << "\nOh no, your could not guess the right number";
		break;
	case 3:  cout << "\nIt is alright you cannot always win";
		break;
	case 4:  cout << "\nYou lost, but it will be alright anyways";
		break;
	case 5:  cout << "\nYou were unlucky, your could not guess the right number";
		break;
	case 6:  cout << "\nYou almost guessed the right number, maybe next time you will guess it";
		break;
	case 7:  cout << "\nBad luck, you did not guess the number that the computer came up with.";
		break;
	case 8:  cout << "\nSadly, you could not guess the number. Don't worry there always be a next time";
		break;
	case 9:  cout << "\nWow... your'e bad, you could not guess the right number";
		break;
	case 10: cout << "\noopsie all your guesses were wrong.";
		break;
	default: cout << "randum number generator needs to be fixed";
	}
}
// This is the function defintion for the score fucntion. 
//This  fucntion will keep track of the wins and the loses by using pass by reference values
void score(int rNum, int input, int& wincount, int& losecount)
{
	if (input != rNum)
	{
		losecount++;// When the user wins 1 is added to its original value

	}
	else
	{

		wincount++;//When the user loses 1 is added to its original value.
	}
}
//This is the function definition for the playing promt function.
//This fuction choose a message randomly to prompt the user if he wants to play again

void playagainPrompt()
{                                      
	srand(int(time(NULL)));    // A random number is generated. This number will determine which statement is outputted on the screen. 
	int ranprompt = rand() % 10 + 1;   // the message will ask them to play again. A switch statemennt is used for the selection of 10 prompts
	switch (ranprompt)                
	{
	case 1:  cout << "\n\nDo you wanna play agian? Input 1 for yes and 2 for no: ";
		break;
	case 2:  cout << "\n\nWould you like to play again? If you want to play again input 1 if not input 2: ";
		break;
	case 3:  cout << "\n\nDo you want to try again? Input 1 to play again and 2 to exit: ";
		break;
	case 4:  cout << "\n\nIt is amazing to play this game, right? So, you would like to try another time? Press 1 if you want to play again, and press 2 to quit. ";
		break;
	case 5:  cout << "\n\nDo you want to try another time? If you wamt to play agian input 2 if not input 1: ";
		break;
	case 6:  cout << "\n\nDo you want another shot? Input 1 to play again and 2 to stop: ";
		break;
	case 7:  cout << "\n\nThis game is fun right. So, would you like to play another time? Input 1 to play again and 2 to stop: ";
		break;
	case 8:  cout << "\n\nLosing is always anoying but you can play again if you want. Input 1 to play again and 2 to exit: ";
		break;
	case 9:  cout << "\n\nThis game is free, so you wanna play again? Input 1 to keep going and 2 if your'e done ";
		break;
	case 10: cout << "\n\nDo want to continue playing this game? Input 1 for yes and 2 for no: ";
		break;
	default: cout << "randum number generator needs to be fixed";
	}
}

	





	
	









