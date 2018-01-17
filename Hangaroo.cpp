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
char mechanism(); // menampilkan pertanyaan, banyak huruf dalam jawaban, dan menginput jawaban

// struct yang berisi nama pemain dan tahun lahir
struct DataPlayer {
	char name[20];
	int born; // tahun lahir
} DP; // seperti pointer, digunakan untuk memanggil struct

void data() // berisi data player 
{
	int year = 2004; // batas tahun lahir yang diperbolehkan untuk bermain
	
	cout << "\n Masukkan namamu        : ";
	cin >> DP.name; // memasukkan nama dari player
	cout << " Masukkan tahun lahirmu : ";
	cin >> DP.born; // memasukkan tahun lahir dari player
	system("cls"); // clear layar
	
	if ( DP.born <= year ) // pembandingan tahun lahir player dengan batas tahun lahir
	{
		cout << "\n Let's play the game " << DP.name << endl; // jika tahun lahir sesuai ( <= 1999 ) maka permainan akan berlanjut
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
	
	// prosedur 
	data(); // memanggil fungsi data()
	
	// cara bermain
	cout << "\n Cara bermain : \n Pemain harus bisa menjawab dengan benar dari clue yang telah diberikan" << endl;
	getch();
	system("cls");
	
	char retry;
	
	do
	{
	mechanism();
	
	cout << "\n Ingin bermain lagi ? (Y/N) ";
	cin >> retry;
	system("cls");
	} while ( retry == 'y' || retry == 'Y'); // akan berulang bila user menekan 'y' / 'Y'
	
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

char mechanism()
{
	string quest;
	int randomLine = 0;
	int noLine = 0;
	
	// menampilkan clue 
	ifstream question; // ifstream adalah operasi file menampilkan data dari file
	question.open("question.txt");
	srand(time(NULL)); // digunakan untuk merandom baris kata 
	randomLine = rand() % 10 + 1; // 10 % 1 = 0,1,2.....9. proses membaca di file mulai dari angka 1 maka dari itu +1
	while (getline(question, quest)) // proses mendapatkan baris kata
	{
		noLine++;
		if (noLine == randomLine) 
		{
			cout << "\n Clue : \n " << quest << endl;
		}
	}
	question.close(); // menutup file
	
	string correctAnswer;
	string display;
	string saveAnswer;
	int answerLine = 0;
	
	// menampilkan banyak huruf dalam kata
	ifstream theAnswer; // ifstream adalah operasi file menampilkan data dari file
	theAnswer.open("correctAnswer.txt");
	while (getline(theAnswer, correctAnswer)) // proses mendapatkan baris kata
	{
		answerLine++;
		if (answerLine == randomLine) // menyesuaikan jawaban dengan soal/clue
		{
			saveAnswer = correctAnswer; // saveAnswer akan digunakan di prosedur selanjutnya ( mendeklar/memanggil saveAnswer )
			display = correctAnswer; // display digunakan untuk menampilkan banyak huruf dalam kata
			for (int i = 0; i < display.length(); i++) // proses merubah isi display dari 0 ~ n
			{
				display[i] = '*'; // merubah isi display
			}
		}
	}
	theAnswer.close(); // menutup file
			
	int exposed =  0; 
	int guess = 5; // banyaknya kesempatan yang diberikan 
	int wrong = 0; 
	do
	{
		cout << "\n " << display << endl;
		cout << "\n Sisa untuk menjawab : " << guess << endl;
		cout << "\n Masukkan huruf untuk menjawab : ";
		
		char answer;
		cin >> answer;
		exposed++;
		
		// menyimpan jawaban dari player ke file
		ofstream playerAnswer; // ofstream adalah operasi file yang digunakan untuk menulis dalam file
		playerAnswer.open("playerAnswer.txt");
		playerAnswer << answer; // proses memasukkan data ke dalam file
		playerAnswer.close(); // menutup file
		
		bool goodAnswer = false;
		bool duplicate = false;
		for (int i = 0; i < saveAnswer.length(); i++) // proses mencocokkan jawaban perhuruf
		{
			if (answer == saveAnswer[i])
			{
				if (display[i] == saveAnswer[i]) // bila huruf sudah diinput
				{
					cout << " " << answer << " sudah ada dalam kata\n";
					duplicate = true;
					break;
				}
				else // huruf belum diinput
				{
					display[i] = saveAnswer[i]; 
					goodAnswer = true;
				}
			}
		}
		
		if (duplicate) // jika terjadi kesamaan input huruf
		{
			continue;
		}
		
		if (!goodAnswer) // jika tebakan salah
		{
			guess--;
			exposed--;
			cout << "\n " << answer << " bukanlah huruf yang benar\n";
		}
		
		if (guess == wrong) // bila kesempatan menebak habis, maka :
		{
			system("cls");
			cout << " kau kalah\n";
			return 0; // proses kembali
		}
		
		if (display == saveAnswer) // bila display (*) sudah berganti menjadi jawaban yang benar , pemain menjawab tiap huruf dengan benar
		{
			break;
		}
	} while (true); // akan berulang terus ( unlimited )
	
	
	cout << "\n " << saveAnswer << endl;
	cout << "\n Kau benar, jawabannya adalah " << saveAnswer << endl;
}

