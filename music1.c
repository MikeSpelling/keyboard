#include "midi_lib.h"
#include <stdio.h>
#include <conio.h>


int main(void)
{

	int key, velocity;
	int x, y;
	int instrument;
	int old;
	int next = 1;
	int channel = 1;

	y = 0;
	instrument = 0;

	while(y==0) {

		x = 0;
		channel = next;

		while (instrument < 1  || instrument > 128) {
			printf("Enter Instrument: ");
			scanf("%d", &instrument);
			if (instrument < 1  || instrument > 128)
				printf("No such instrument\n");
		}

		velocity = 120;
		program_change(channel, instrument);
			
		
		while(x==0) {

			key = getch();

			switch (key) {
	
				case 'q':
					key = 60;
					x = 1;
					next++;
					break;
		
				case 'w':
					key = 62;
					x = 1;
					next++;
					break;
		
				case 'e':
					key = 64;
					x = 1;
					next++;
					break;

				case 'r':
					key = 65;
					x = 1;
					next++;
					break;

				case 't':
					key = 67;
					x = 1;
					next++;
					break;

				case 'y':
					key = 69;
					x = 1;
					next++;
					break;

				case 'u':
					key = 71;
					x = 1;
					next++;
					break;

				case 'i':
					key = 72;
					x = 1;
					next++;
					break;

				case 'o':
					key = 74;
					x = 1;
					next++;
					break;

				case 'p':
					key = 76;
					x = 1;
					next++;
					break;

				case '2':
					key = 61;
					x = 1;
					next++;
					break;

				case '3':
					key = 63;
					x = 1;
					next++;
					break;

				case '5':
					key = 66;
					x = 1;
					next++;
					break;

				case '6':
					key = 68;
					x = 1;
					next++;
					break;

				case '7':
					key = 70;
					x = 1;
					next++;
					break;

				case '9':
					key = 73;
					x = 1;
					next++;
					break;

				case '0':
					key = 75;
					x = 1;
					next++;
					break;

				case 'z':
					key = 48;
					x = 1;
					next++;
					break;

				case 's':
					key = 49;
					x = 1;
					next++;
					break;

				case 'x':
					key = 50;
					x = 1;
					next++;
					break;

				case 'd':
					key = 51;
					x = 1;
					next++;
					break;

				case 'c':
					key = 52;
					x = 1;
					next++;
					break;

				case 'v':
					key = 53;
					x = 1;
					next++;
					break;

				case 'g':
					key = 54;
					x = 1;
					next++;
					break;

				case 'b':
					key = 55;
					x = 1;
					next++;
					break;

				case 'h':
					key = 56;
					x = 1;
					next++;
					break;

				case 'n':
					key = 57;
					x = 1;
					next++;
					break;

				case 'j':
					key = 58;
					x = 1;
					next++;
					break;

				case 'm':
					key = 59;
					x = 1;
					next++;
					break;

				case ',':
					key = 60;
					x = 1;
					next++;
					break;

				case 'l':
					key = 61;
					x = 1;
					next++;
					break;

				case '.':
					key = 62;
					x = 1;
					next++;
					break;

				case 'é':
					key = 63;
					x = 1;
					next++;
					break;

				case '-':
					key = 64;
					x = 1;
					next++;
					break;
					
				case '$':
						instrument = 0;
						midi_note(old, channel, 0);
						while (instrument < 1  || instrument > 128) {
						printf("Enter Instrument: ");
						scanf("%d", &instrument);
						if (instrument < 1  || instrument > 128)
							printf("No such instrument\n");
						}
						program_change(channel, instrument);
					break;
				
				case ' ':
						midi_note(old, channel, 0);
						break;

				default:
					break;
			}			
		}

		midi_note(old, channel, 0);
		midi_note(key, channel, velocity);
		old = key;
		if(next > 9) next = 1;
	}
	return 0;
}