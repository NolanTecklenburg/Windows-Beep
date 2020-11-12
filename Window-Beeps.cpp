/*Program Name: Scale Practice Helper
Purpose: To play a major or minor scale based on the input of the user. The key is also chosen by the user. 
Author: Nolan Tecklenburg
Date Last Modified: 5/6/2019
*/
#include <iostream>
#include <windows.h>
#include <string.h>
#include <cmath>
#include <chrono>
#include <thread>

using namespace std;

int main()
{
	//establishing variables
	double scaleFreqs[118];
	int scaleTones[9];
	int i, fundamental, wholeStep, halfStep, keyOfScale, choice;
	/*			
				I intentionally switch the capitalizations when it comes to the black key scales
				I understand this isn't correct code etiquette, but it is correct music etiquette
	*/
	int aScale, BbScale, bScale, cScale, DbScale, dScale, EbScale, eScale, fScale, GbScale, gScale, AbScale;
	double mult;
	string tuning, repeat, tonality, key;
	
	
	// initiallizing scale variables
	aScale=56;
	BbScale=57;
	bScale=58;
	cScale=59;
	DbScale=60;
	dScale=61;
	EbScale=62;
	eScale=63;
	fScale=64;
	GbScale=65;
	gScale=66;
	AbScale=67;
	
	// initiallizing steps
	wholeStep=2;
	halfStep=1;
	
	// rhythyms
	int bpm=90;
	double halfNote=0;
	double quarterNote=0;
	double quarterNoteTriplet=0;
	double eigthNote=0;
	
	// fundamental
	fundamental=440;
	
	scaleFreqs[56]=fundamental;
	mult = pow(2, 0.08333333333);
			
	//used to find all the hertz values depending on the value of the fundamental
	for (i=0; i<60; i++)
		{
		scaleFreqs[57+i]=mult*scaleFreqs[56+i];
		}
		
	for (i=0; i<55; i++)
		{
		scaleFreqs[55-i]=scaleFreqs[56-i]/mult;
		}

	//prompt for menu
	cout << "Menu\n1. Change Pitch Standard\n2. Super Mario Brothers Main Theme\n3. Scale Helper\n";
	cin >> choice;
	
	//if statement so if you change pitch standard you can still choose to play the song or the scale helper
	if (choice==1)
	{
			system("CLS");
			cout << "Change the pitch Standard (default is A=440): ";
			cin >> fundamental;
			
			scaleFreqs[56]=fundamental;
			mult = pow(2, 0.08333333333);
			
			//used to find all the hertz values depending on the value of the fundamental
			for (i=0; i<60; i++)
			{
			scaleFreqs[57+i]=mult*scaleFreqs[56+i];
		
			}
		for (i=0; i<55; i++)
			{
			scaleFreqs[55-i]=scaleFreqs[56-i]/mult;
			}
			system("CLS");
			cout <<"2. Super Mario Brothers Main Theme\n3. Scale Helper\n";
			cin >> choice;
	}
		
	switch (choice)
	{
		case 2:
		{
			
			/*Mario Theme
			bpm calculation
			This does not work because the song stops working when the bpm is above 93 due to "Beeps" not working well within 400ms of each other
			
			cout << "What BPM would you like the song to be? ";
			cin >> bpm;*/
			
			quarterNote=60000/bpm;
			halfNote=quarterNote*2;
			quarterNoteTriplet=quarterNote/3;
			eigthNote=quarterNote/2;

			/*C4: 	47 Db4:	48 D4: 	49 Eb4:	50 E4:	51 F4:	52 Gb4:	53 G4:	54 Ab4:	55 A4:	56 Bb4:	57 B4:	58 
			  C5:	59 Db5:	60 D5:	61 Eb5:	62 E5:	63 F5:	64 Gb5:	65 G5:	66 Ab5:	67 A5:	68 Bb5:	69 B5:	70
			*/
			system("CLS");
			cout << "Super Mario Brothers: Main Theme Overworld by Koji Kondo\n";
			
			// measure 1
			Beep(scaleFreqs[63],eigthNote);
			Beep(scaleFreqs[63],eigthNote);
			Sleep(eigthNote);
			Beep(scaleFreqs[63],eigthNote);
			Sleep(quarterNote);
			Beep(scaleFreqs[59],eigthNote);
			Beep(scaleFreqs[63],quarterNote);
			// 2
			Beep(scaleFreqs[66],quarterNote);
			Sleep(halfNote);
			Beep(scaleFreqs[54],quarterNote);
			Sleep(halfNote);
			
			for (i=0;i<2;i++)
			{
			// 3
			Beep(scaleFreqs[59],quarterNote);
			Sleep(eigthNote);
			Beep(scaleFreqs[54],quarterNote);
			Sleep(eigthNote);
			Beep(scaleFreqs[51],quarterNote);
			// 4
			Sleep(eigthNote);
			Beep(scaleFreqs[56],quarterNote);
			Beep(scaleFreqs[58],quarterNote);
			Beep(scaleFreqs[57],eigthNote);
			Beep(scaleFreqs[56],quarterNote);
			// 5
			Beep(scaleFreqs[54], quarterNoteTriplet);
			Beep(scaleFreqs[63], quarterNoteTriplet);
			Beep(scaleFreqs[66], quarterNoteTriplet);
			Beep(scaleFreqs[68], quarterNote);
			Beep(scaleFreqs[64], eigthNote);
			Beep(scaleFreqs[66], eigthNote);
			// 6
			Sleep(eigthNote);
			Beep(scaleFreqs[63],quarterNote);
			Beep(scaleFreqs[59],eigthNote);
			Beep(scaleFreqs[61],eigthNote);
			Beep(scaleFreqs[58],quarterNote);
			Sleep(eigthNote);
			}
			
			for (i=0;i<2;i++)
			{
			// 7
			Sleep(quarterNote);
			Beep(scaleFreqs[66],eigthNote);
			Beep(scaleFreqs[65],eigthNote);
			Beep(scaleFreqs[64],eigthNote);
			Beep(scaleFreqs[62],quarterNote);
			Beep(scaleFreqs[63],eigthNote);
			// 8
			Sleep(eigthNote);
			Beep(scaleFreqs[55],eigthNote);
			Beep(scaleFreqs[56],eigthNote);
			Beep(scaleFreqs[59],eigthNote);
			Sleep(eigthNote);
			Beep(scaleFreqs[56],eigthNote);
			Beep(scaleFreqs[59],eigthNote);
			Beep(scaleFreqs[61],eigthNote);
			// 9
			Sleep(quarterNote);
			Beep(scaleFreqs[66],eigthNote);
			Beep(scaleFreqs[65],eigthNote);
			Beep(scaleFreqs[64],eigthNote);
			Beep(scaleFreqs[62],quarterNote);
			Beep(scaleFreqs[63],eigthNote);
			// 10
			Sleep(eigthNote);
			Beep(scaleFreqs[71],quarterNote);
			Beep(scaleFreqs[71],eigthNote);
			Beep(scaleFreqs[71],quarterNote);
			Sleep(quarterNote);
			// 11
			Sleep(quarterNote);
			Beep(scaleFreqs[66],eigthNote);
			Beep(scaleFreqs[65],eigthNote);
			Beep(scaleFreqs[64],eigthNote);
			Beep(scaleFreqs[62],quarterNote);
			Beep(scaleFreqs[63],eigthNote);
			// 12
			Sleep(eigthNote);
			Beep(scaleFreqs[55],eigthNote);
			Beep(scaleFreqs[56],eigthNote);
			Beep(scaleFreqs[59],eigthNote);
			Sleep(eigthNote);
			Beep(scaleFreqs[56],eigthNote);
			Beep(scaleFreqs[59],eigthNote);
			Beep(scaleFreqs[61],eigthNote);
			// 13
			Sleep(quarterNote);
			Beep(scaleFreqs[62],quarterNote);
			Sleep(eigthNote);
			Beep(scaleFreqs[61],quarterNote);
			Sleep(eigthNote);
			// 14
			Beep(scaleFreqs[59],quarterNote);
			Sleep(quarterNote*3);
			}
			// 15
			Beep(scaleFreqs[59],eigthNote);
			Beep(scaleFreqs[59],eigthNote);
			Sleep(eigthNote);
			Beep(scaleFreqs[59],eigthNote);
			Sleep(eigthNote);
			Beep(scaleFreqs[59],eigthNote);
			Beep(scaleFreqs[61],quarterNote);
			// 16
			Beep(scaleFreqs[63],eigthNote);
			Beep(scaleFreqs[59],eigthNote);
			Sleep(eigthNote);
			Beep(scaleFreqs[56],eigthNote);
			Beep(scaleFreqs[54],halfNote);
			// 17
			Beep(scaleFreqs[59],eigthNote);
			Beep(scaleFreqs[59],eigthNote);
			Sleep(eigthNote);
			Beep(scaleFreqs[59],eigthNote);
			Sleep(eigthNote);
			Beep(scaleFreqs[59],eigthNote);
			Beep(scaleFreqs[61],eigthNote);
			Beep(scaleFreqs[63],eigthNote);
			// 18
			Sleep(halfNote*2);
			// 19
			Beep(scaleFreqs[59],eigthNote);
			Beep(scaleFreqs[59],eigthNote);
			Sleep(eigthNote);
			Beep(scaleFreqs[59],eigthNote);
			Sleep(eigthNote);
			Beep(scaleFreqs[59],eigthNote);
			Beep(scaleFreqs[61],quarterNote);
			// 20
			Beep(scaleFreqs[63],eigthNote);
			Beep(scaleFreqs[59],eigthNote);
			Sleep(eigthNote);
			Beep(scaleFreqs[56],eigthNote);
			Beep(scaleFreqs[54],halfNote);
			// 21
			Beep(scaleFreqs[63],eigthNote);
			Beep(scaleFreqs[63],eigthNote);
			Sleep(eigthNote);
			Beep(scaleFreqs[63],eigthNote);
			Sleep(eigthNote);
			Beep(scaleFreqs[59],eigthNote);
			Beep(scaleFreqs[63],quarterNote);
			// 22
			Beep(scaleFreqs[66],quarterNote);
			Sleep(quarterNote);
			Beep(scaleFreqs[54],quarterNote);
			Sleep(quarterNote);
			// 23
			Beep(scaleFreqs[59],quarterNote);
			
			cout << "Thanks for Listening!\n";
			return 0;
		}
		case 3:
		{
		system("CLS");
		cout << "Scale Practice Helper\n\n"; // prompt showing what the program is
		cout << "Would you like a tuning note? "; // asking if you would like a tuning note
		cin >> tuning;
		if ((tuning == "Yes") || (tuning == "yes") || (tuning == "Y") || (tuning == "y"))
		{
			Beep(fundamental, 5000);
			cout << "Would you like another tuning note? ";
			cin >> repeat;
		
			while ((repeat == "Yes") || (repeat == "yes") || (repeat == "Y") || (repeat == "y")) // while loop that will repeat tuning note until user says no
			{
				Beep(fundamental, 5000);
				cout << "Would you like another tuning note? ";
				cin >> repeat;
				if ((repeat == "No") || (repeat == "no") || (repeat == "N") || (repeat == "n"))
					break;
			}
		}
		cout << "What is the key of the scale you would like to practice? "; //prompting what key to practice
		cin >> key; // string of key
		cout << "Would you like it to be major or minor? "; // prompting the tonality
		cin >> tonality; // storying tonality in string
		
		//this decides what key the scale will be in based on the "key" string
			if ((key == "A") || (key == "a"))
		{
			keyOfScale=aScale;
			scaleTones[0]=scaleFreqs[keyOfScale];
		}
			else if ((key == "Bb") || (key == "bb") || (key == "A#") || (key == "a#"))
		{
			keyOfScale=BbScale;
			scaleTones[0]=scaleFreqs[keyOfScale];
		}
			else if ((key == "B") || (key == "b") || (key == "Cb") || (key == "cb"))
		{
			keyOfScale=bScale;
			scaleTones[0]=scaleFreqs[keyOfScale];
		}
			else if ((key == "C") || (key == "c") || (key == "B#") || (key == "b#"))
		{
			keyOfScale=cScale;
			scaleTones[0]=scaleFreqs[keyOfScale];
		}
			else if ((key == "Db") || (key == "db") || (key == "C#") || (key == "c#"))
		{
			keyOfScale=DbScale;
			scaleTones[0]=scaleFreqs[keyOfScale];
		}
			else if ((key == "D") || (key == "d"))
		{
			keyOfScale=dScale;
			scaleTones[0]=scaleFreqs[keyOfScale];
		}
			else if ((key == "Eb") || (key == "eb") || (key == "D#") || (key == "d#"))
		{
			keyOfScale=EbScale;
			scaleTones[0]=scaleFreqs[keyOfScale];
		}
			else if ((key == "E") || (key == "e") || (key == "Fb") || (key == "fb"))
		{
			keyOfScale=eScale;
			scaleTones[0]=scaleFreqs[keyOfScale];
		}
			else if ((key == "F") || (key == "f") || (key == "E#") || (key == "e#"))
		{
			keyOfScale=fScale;
			scaleTones[0]=scaleFreqs[keyOfScale];
		}
			else if ((key == "Gb") || (key == "gb") || (key == "F#") || (key == "f#"))
		{
			keyOfScale=GbScale;
			scaleTones[0]=scaleFreqs[keyOfScale];
		}
			else if ((key == "G") || (key == "g"))
		{
			keyOfScale=gScale;
			scaleTones[0]=scaleFreqs[keyOfScale];
		}
			else if ((key == "Ab") || (key == "ab") || (key == "G#") || (key == "g#"))
		{
			keyOfScale=AbScale;
			scaleTones[0]=scaleFreqs[keyOfScale];
		}
			else // if the input isn't recognized
			{
			cout << "Please restart the program and enter a correct key from a-g\n";
			return 0;
			}
	
	
			// decided what tonality
			if ((tonality == "Major") || (tonality == "major"))
			{
				for (i=0; i<2; i++) // scale degree 1
				{
					scaleTones[1+i]=scaleFreqs[keyOfScale+=wholeStep]; // 2	3
				}
				scaleTones[3]=scaleFreqs[keyOfScale+=halfStep]; // 4
				for (i=0; i<3; i++)
				{
					scaleTones[4+i]=scaleFreqs[keyOfScale+=wholeStep]; // 5	6	7
				}
				scaleTones[7]=scaleFreqs[keyOfScale+halfStep]; // 8
			}
			else if ((tonality == "Minor") || (tonality == "minor"))
			{
				scaleTones[1]=scaleFreqs[keyOfScale+=wholeStep]; // 2
				scaleTones[2]=scaleFreqs[keyOfScale+=halfStep]; // 3
				for
					(i=0; i<2; i++)
					{
						scaleTones[3+i]=scaleFreqs[keyOfScale+=wholeStep]; // 4	5
					}
				scaleTones[5]=scaleFreqs[keyOfScale+=halfStep]; // 6
					for
						(i=0; i<2; i++)
						{
						scaleTones[6+i]=scaleFreqs[keyOfScale+=wholeStep]; // 7	8
						}
			}
			else // if the input is incorrect
			{
			cout << "Please restart the program and enter a correct key of either minor or major";
			return 0;
			}
	
		// for loops that play the scale
		for (i=0; i<8; i++) //ascending the scale
		{
			Beep(scaleTones[0+i], 500);
		}
		for (i=0; i<7; i++) //descending the scale
		{
			Beep(scaleTones[6-i], 500);
		}
		cout << "Thank you for using my program\n";
		return 0;
		}
		default :
			{
				system("CLS");
				cout << "Please restart the program and enter either 1, 2, or 3\n";
				return 0;
			}
			
	}
}