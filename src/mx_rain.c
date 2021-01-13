#include "../inc/mx_rain.h"

void mx_rain(){
	initscr();
	curs_set(0); // invisible cursor
	mx_initcolor(); // intialize some basic colors

	int row, col;
	getmaxyx(stdscr, row, col);

	int text_begin[col];
	int text_len[col];
	int text_out[col];

	srand(time(0));

	for(int i = 1; i < col; i += 2){
		text_len[i] = rand() % row - 1;
		text_begin[i] = -1 * (rand() % (col / 2)); // '* (-1)' - begin text from top of the screen
		text_out[i] = text_begin[i];
	}

	short temp_color = 1; // green and black by default

	short wb = 2; // white and black

	bool run = true;
	while(run){
		for(int i = 1; i < col; i += 2){
			wchar_t wc = (rand() % 93 + 33);

			attron(COLOR_PAIR(wb));
			mvwaddch(stdscr, text_out[i] + 1, i, wc);
			attroff(COLOR_PAIR(wb));
			
			attron(COLOR_PAIR(temp_color));
			mvwaddch(stdscr, text_out[i], i, wc);
			attroff(COLOR_PAIR(temp_color));

			attron(COLOR_PAIR(temp_color));
			mvwaddch(stdscr, text_out[i] - text_len[i], i, ' ');
			attroff(COLOR_PAIR(temp_color));

			if(text_out[i] - text_len[i] > row) 
				text_out[i] = text_begin[i];

			text_out[i]++;
		}

		int speed = 100;

		usleep(1000 * speed);
		nodelay(stdscr, TRUE);
		noecho();

		char c = getch();
		switch(c){
			case 'q':
				run = false;
				clear();
				break;
			case 'f':	
				if(speed > 1){
					if(speed <= 11) speed--;
					else speed -= 10;
				}
			case 's': 
				if(speed < 200){
					if(speed <= 10) speed++;
					else speed += 10;
				}
			case 'g': temp_color = 1; break;
            case 'w': temp_color = 2; break;
            case 'r': temp_color = 3; break;
            case 'b': temp_color = 4; break;
            case 'y': temp_color = 5; break;
		}
		refresh();
	}

	endwin();
}



