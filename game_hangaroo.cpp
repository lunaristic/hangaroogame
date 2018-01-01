#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <fstream>

using namespace std;

void gotoxy ( int x, int y )
{
	COORD koordinat = {x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), koordinat);
}

void layout ( string a, int y )
{
	gotoxy( 30 - (a.length() / 2 ), y );
	cout << a << endl;
}

char clue();
char playerAnswer();
char correctAnswer();

int main ()
{
	// tampilan awal sebelum permainan dimulai
	layout ( "**************** WELCOME ****************", 5 );
	layout ( "TO", 6 );
	layout ( "HANGAROO GAME", 7 );
	layout ( " Press any key to continue ", 20 );
	getch();
	system ("cls");
	
	// peraturan
	layout ( "CARA BERMAIN : ", 5 );
	layout ( "Pemain harus menjawab dengan benar dari clue yang diberikan" , 7 );
	layout ( " Press any key to continue ", 20 );
	getch();
	system ("cls");
	
	// permainan
	// menggunakan do while***
	clue();
	playerAnswer();
	correctAnswer();
}

// petunjuk atau pertanyaan
char clue()
{
	string petunjuk;
	int randomLine;
	int noLine = 0;
	
	ifstream clue;
	clue.open("Clue.txt");
	srand(getpid());
	randomLine = rand() % 10 + 1; // % 10 = 0,1,2,3,4,5,6,7,8,9. untuk pembacaan baris di .txt dimulai dari angka 1
	while(getline(clue, petunjuk)) 
	{
    	noLine++;
   		if( noLine == randomLine ) 
		{
        	cout << "\n Clue : \n" << "\n " << petunjuk << endl;
    	}
	}
	cout << endl;
}

// jawaban dari pemain
char playerAnswer()
{
	char answer;
	cout << " Answer : ";
	cin >> answer;
	
	ofstream playerAnswer;
	playerAnswer.open("PlayerAnswer.txt");
	playerAnswer << answer;
	playerAnswer.close();
	cout << endl;
}

// jawaban yang benar
// pencocokan dengan jawaban player***
char correctAnswer()
{
	string correct;
	
	ifstream correctAnswer;
	correctAnswer.open("CorrectAnswer.txt");
	if ( correctAnswer.is_open() )
	{
		while ( getline ( correctAnswer, correct ) )
    	{
      		cout << correct;
    	}
		
	}
	correctAnswer.close();
	cout << endl;
}



