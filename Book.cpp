/*
Lamar Almoaiqel and Classmate
*/

#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

class Book
{
	string Book_Title;
	int Number_of_Pages;
	string Format_Type;	
	public:	
		Book()
		{
			string Book_Title = "";
			int Number_of_Pages = 0;
			string Format_Type = "print";	
		}
		Book(string a_title,int num_pages, string is_audio)
		{
			Book_Title = a_title;
			Number_of_Pages = num_pages;
			Format_Type = is_audio;
		}
		string get_name() const
		{
			return Book_Title;
		}
		int get_numPages() const
		{
			return Number_of_Pages;
		}
		bool isAudio() const
		{
			if(Format_Type == "audio")
			{			
			return true;
			}
			else
			{
				return false;
			}
		}
		bool readBook(ifstream&fin)
		{
			string title;
			int pages;
			string format;
			if (fin>>title>>pages>>format)
			{
				Book_Title = title;
				Number_of_Pages = pages;
				Format_Type = format;
				return true;
			}
			else
			{
				return false;
			}	
			
		}
		
		void printBook() const
		{
			cout<<setw(37)<<Book_Title<<setw(5)<<Number_of_Pages<<setw(7)<<Format_Type<<endl;			
		}
		
		
	
};

// Write your main and functions below

int readData(ifstream &FileIn, Book bookArray[50])
{
	int index = 0;
	while(bookArray[index].readBook(FileIn) && index < 50)
	{
		index++;
	}
	return index;
}

bool bookMatch(Book book1, Book book2)
{
	if (book1.get_name() == book2.get_name() && book1.get_numPages() == book2.get_numPages())
	{
		return true;
	}
	
	return false;
	
} 



int main()
{
	ifstream finP("print.txt");  
	ifstream finA("audio.txt");
	if(!finP)
	{
		cout << "unable to open print.txt" << endl;
		return EXIT_FAILURE;
	}
	if(!finA)
	{
		cout << "unable to open audio.txt" << endl;
		return EXIT_FAILURE;
	}
	

	Book bookArray[50];
	Book audioArray[50];
	int bookNum =  0;
	int audioNum = 0;
	
	bookNum = readData(finP, bookArray);
	audioNum = readData(finA, audioArray);
	//cout << booknum << audionum;
	

	cout << "A list of audio books" << endl;
	for(int counter = 0; counter < audioNum; counter++)
	{
		audioArray[counter].printBook();
	}
	
	cout << endl;
	cout << "A list of printed books" << endl;
	
	bool bookCompare = false;
	for(int bookCount = 0; bookCount < bookNum ; bookCount++)
	{
		for(int audioCount = 0; audioCount < audioNum; audioCount++)
		{
			if(bookMatch(bookArray[bookCount], audioArray[audioCount]) == true) 
			{
				audioCount = audioNum;
				bookCompare = true;
			}
			else
			{
				bookCompare = false;
			}
		}
		if(!bookCompare)
		{
			bookArray[bookCount].printBook();
		}
	}
	
	
	finP.close();  
	finA.close();  
	system("PAUSE");  
	return EXIT_SUCCESS;
}

/*
A list of audio books
  The_Hitchhikers_Guide_To_The_Galaxy  180  audio
                  The_Grapes_Of_Wrath  416  audio
                       The_Life_Of_Pi  352  audio
                        The_Alchemist  167  audio
                    A_Game_Of_Thrones  864  audio
                    Lord_Of_The_Flies  285  audio
                         Little_Women  248  audio
                         Frankenstein  288  audio
                          Vanity_Fair  883  audio
                     The_Hunger_Games  374  audio
                  Pride_And_Prejudice  398  audio
                 The_Age_Of_Innocence  301  audio
           The_Picture_of_Dorian_Gray  224  audio
                        Amongst_Women  184  audio
                    Wuthering_Heights  354  audio
                The_Devil_Wears_Prada  360  audio
                                 Dune  412  audio
                          The_Martian  369  audio
                            Jane_Erye  950  audio
                       The_Book_Thief  584  audio
                            Moby_Dick  720  audio
                     The_Great_Gatsby  184  audio
                          Disappeared  384  audio

A list of printed books
                   A_Clockwork_Orange  158  print
                      Brave_New_World  201  print
                            If_I_Stay  224  print
              A_Brief_History_Of_Time  241  print
                   The_Scarlet_Letter  250  print
                                 Wild  315  print
                The_Girl_On_The_Train  316  print
                      The_Maze_Runner  371  print
                                 Emma  474  print
                          Don_Quixote 1056  print
                              Ulysses  719  print
                      Life_After_Life  622  print
                   The_Sun_Also_Rises  247  print
                     The_Longest_Ride  568  print
                       Milk_And_Honey  226  print
                    A_Christmas_Carol  100  print
                  The_Love_Hypothesis  384  print
                         The_Notebook  214  print
                          I_Am_Malala  288  print
                                Smile  213  print
              Becoming_Michelle_Obama  448  print
             The_Chronicles_Of_Narnia  766  print
                 Crime_And_Punishment  492  print
                   The_Wise_Mans_Fear  994  print
*/


