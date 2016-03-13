//Yaskovich Dmitry ISBO-05-15. Lab 9. Variant 4
//Dimini Inc, 2016
#include <conio.h>
#include <iostream.h>
#include <string.h>
#include <ctype.h>

void inputData(char *inputString);//defining prototypes of string input
void replacement (char *inputString ); //replacement of numbers
void outputData(char *word);//words output

const symbolsQuantity=1000;//quantity of max symbols in string

void main()
{
	char inputString[symbolsQuantity];
	inputData(inputString);//input of string
	replacement(inputString);//replacement of numbers
	getch();//waiting for user reaction
}

void inputData(char *inputString)
{
	cout<<"s: ";//request of input
	cin.getline(inputString,symbolsQuantity); //reading whole string
}

void outputData(char *word)
{
	cout<<word<<" ";//output of word
}

void replacement (char *inputString )
{
	char *word; //pointer to next word
	char symbol[1];//checking symbol
	int replaceFlag, counter;//requirement of replacement flag and counter
	char separator[]=" ,.!?:;-()'"; //word separators
	word=strtok(inputString,separator); //find first word
	while(word!=0)//ccycle of all words
	{
		replaceFlag=0;//flag reset
		for (counter = 0; counter < strlen(word); counter++)//cycle by all symbols in word
		{
			strncpy(symbol, word+counter, 1);//copy of next symbol
			if (isdigit(*symbol))//counter of numbers quantity in word
				replaceFlag++;
		}
		if (replaceFlag==strlen(word))//checking whenever word consists only of numbers
			word="*";//replacement
		outputData(word);//output of word
		word=strtok(0,separator); // finding next word
	}
}
