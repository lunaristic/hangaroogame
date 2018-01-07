/* UPDATE TANGGAL 07-01-2018
kekurangan :
	1. mekanisme untuk memasukkan tiap huruf dan mencocokkannya
	2. penggunaan pointer untuk tiap huruf yang sama di jawaban
	3. penghilangan huruf di baris alphabet
*/

#include <iostream>
#include <windows.h> // library untuk menggunakan fungsi gotoxy()
#include <conio.h> // library untuk menggunakan getch()
#include <string> 
#include <cstdlib> // library untuk menggunakan srand
#include <ctime>
#include <fstream> // library untuk menggunakan ifstream dan ofstream

using namespace std;

void gotoxy( int x, int y ); // pengaturan koordinat
void layout ( string s, int y ); // pengaturan tata letak
void title(); // tulisan hangaroo
char alphabet(); // membuat baris alphabet
char mechanism(); // menampilkan pertanyaan
char correctAnswer(); // menyimpan jawaban
char answerBox(); // menampilkan box untuk jawaban

// struct yang berisi nama pemain dan tahun lahir
struct DataPlayer {
	char name[20];
	int born; // anggap tahun lahir
} DP; // seperti pointer, digunakan untuk memanggil struct

void data() // berisi data player 
{
	int year = 2004; // batas tahun lahir yang diperbolehkan untuk bermain
	
	cout << "Masukkan namamu        : ";
	cin >> DP.name; // memasukkan nama dari player
	cout << "Masukkan tahun lahirmu : ";
	cin >> DP.born; // memasukkan tahun lahir dari player
	system("cls"); // clear layar
	
	if ( DP.born <= year ) // pembandingan tahun lahir player dengan batas tahun lahir
	{
		cout << "Let's play the game " << DP.name << endl; // jika tahun lahir sesuai ( <= 1999 ) maka permainan akan berlanjut
		getch();
		system("cls");
	}
	else
	{
		cout << "Sorry " << DP.name << ", you can't continue." << endl; // jika tahun lahir tidak sesuai maka permainan berhenti
		exit(0); // digunakan untuk menghentikan secara langsung program ( angka 0 artinya 
	}
}

int main ()
{
	// tampilan awal sebelum permainan dimulai
	layout ( "*************** SELAMAT DATANG ****************", 2 ); // seperti yang ada di fungsi layout, kalimat "selamat datang" disesuaikan dengan koordinat x , dan letak di y = 2
	layout ( "DI ", 4 ); // seperti yang ada di fungsi layout, kata "di" disesuaikan dengan koordinat x ( rumus di fungsi layout ) , dan letak di y = 4
	cout << "\n\n"; // \n berfungsi untuk membuat baris baru
	title(); // memanggil fungsi title()
	layout ( " Press any key to continue ", 28 ); // seperti yang ada di fungsi layout, kalimat "Press any key to continue" disesuaikan dengan koordinat x, dab letak di y = 28
	getch(); // berfungsi untuk menekan segala yang ada di keyboard
	system ("cls");
	
	// prosedur ke-2
	data(); // memanggil fungsi data()
	
	// prosedur ke-3
	char retry;
	
	do
	{
	alphabet();
	mechanism();
	
	cout << "Ingin melanjutkan ? (Y/N)";
	cin >> retry;
	system("cls");
	} while ( retry == 'y' || retry == 'Y');
	
}

void gotoxy ( int x, int y ) // fungsi untuk mengatur koordinat x dan y
{
	COORD koordinat = {x,y}; // sudah dari sananya ( sepertinya )
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), koordinat); // sudah dari sananya ( sepertinya )
}

void layout ( string s, int y ) // fungsi yang digunakan untuk mengatur tata letak
{
	gotoxy( 35 - (s.length() / 2 ), y ); // untuk mengatur tata letak yang sesuai dengan yang diinginkan
	cout << s << endl;
}

void title()
{
		char hangaroo[8][75] = {
	{"  <      > <======> <-      > <======> <======> <======> <======> <======>"},
	{"  |      | |      | | =     | |        |      | |      | |      | |      |"},
	{"  |      | |      | |  =    | |        |      | |      | |      | |      |"},
	{"  [======] [======] |   =   | |  ====> [======] [=====+} |      | |      |"},
	{"  |      | |      | |    =  | |      | |      | |     |  |      | |      |"},
	{"  |      | |      | |     = | |      | |      | |     |  |      | |      |"},		
	{"  {      } {      } {      {} {======} {      } {     {  {======} {======}"}
	};
	
	// perulangan untuk merubah isi dari array hangaroo
	for ( int i = 0; i < 8; i++ )
	{
		for ( int j = 0; j < 75; j++ )
		{
			char x = hangaroo [i][j]; // x digunakan untuk mempersingkat pendeklarasian
			
			// untuk melihat perubahan = char(...) cari di google dengan keyword ascii table
			if ( x == '|' ) // perubahan 
			{
				cout << char(186);
			}
			else if ( x == '[' ) // perubahan
			{
				cout << char(204);
			}
			else if ( x == '=' ) // perubahan
			{
				cout << char(205);
			}
			else if ( x == ']' ) // perubahan
			{
				cout << char(185);
			}
			else if ( x == '<' ) // perubahan
			{
				cout << char(201);
			}
			else if ( x == '>' ) // perubahan
			{
				cout << char(187);
			}
			else if ( x == '{' ) // perubahan
			{
				cout << char(200);
			}
			else if ( x == '}' ) // perubahan
			{
				cout << char(188);
			}
			else if ( x == '+' ) // perubahan
			{
				cout << char(203);
			}
			else if ( x == '-' ) // perubahan
			{
				cout << char(187);
			}
			else // bila tidak ada perubahan seperti diatas, maka akan diprint sesuai aslinya
			{
				cout << x;
			}
		}
		cout << endl;
	}
}

char alphabet()
{
	char letter[3][106] = {
		{"<===t===t===t===t===t===t===t===t===t===t===t===t===t===t===t===t===t===t===t===t===t===t===t===t===t===>"},
		{"| A | B | C | D | E | F | G | H | I | J | K | L | M | N | O | P | Q | R | S | T | U | V | W | X | Y | Z |"},
		{"[===-===-===-===-===-===-===-===-===-===-===-===-===-===-===-===-===-===-===-===-===-===-===-===-===-===]"}
	};
	
	for ( int i = 0; i < 3; i++ )
	{
		for ( int j = 0; j < 106; j++ )
		{
			char a = letter[i][j];
			
			if( a == '|' ) 
			{
				cout << char(186);
			}
			else if( a == '=' )
			{
				cout << char(205);
			}
			else if( a == 't' )
			{
				cout << char(203);
			}
			else if( a == '<' )
			{
				cout << char(201);
			}
			else if( a == '>' )
			{
				cout << char(187);
			}
			else if( a == '[' )
			{
				cout << char(200);
			}
			else if( a == ']' )
			{
				cout << char(188);
			}
			else if( a == '-' )
			{
				cout << char(202);
			}
			else
				cout << a;
		}
		cout << endl;
	}
}

char mechanism()
{
	int coba = 4;
	
	string quest;
	int randomLine = 0;
	int noLine = 0;
	
	ifstream question;
	question.open("question.txt");
	srand( time(NULL) );
	randomLine = rand() % 10 + 1; // % 10 = 0,1,2,3,4,5,6,7,8,9. untuk pembacaan baris di .txt dimulai dari angka 1
	while( getline( question, quest)) 
	{
    	++noLine;
   		if( noLine == randomLine ) 
		{
        	cout << " Clue : " << quest << endl;
    	}
	}
	cout << endl;
	question.close();
	
	int answerLine = 0;
	string answer;
	string save;
	ifstream correctAnswer;
	correctAnswer.open("correctAnswer.txt");
	while ( getline( correctAnswer, answer ))
	{
		++answerLine;
		if ( answerLine == randomLine )
		{
			save = answer;
			for ( int k = 1; k <= answer.length(); k++ )
			{
				cout << " _ " ;
			}
		}
	}
	cout << endl;
	correctAnswer.close();
	
	cout << endl;
	string jawab;
	cin >> jawab;
	ofstream playerAnswer;
	playerAnswer.open("PlayerAnswer.txt");
	playerAnswer << jawab;
	playerAnswer.close();
	cout << endl;
	
	if ( jawab == save )
	{
		cout << "Kau benar" << endl;
	}
	else
	{
		cout << "Kau salah" << endl;
		--coba;
	}
	cout << coba << endl;
}
