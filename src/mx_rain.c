#include "../inc/mx_rain.h"

void mx_rain(){
	initscr();
	curs_set(0);
	mx_initcolor();	

	int row, col;
	getmaxyx(stdscr, row, col);

	int text_begin[col];
	int text_len[col];
	int text_out[col];

	srand(time(0));

	for(int i = 0; i < col; ++i){
		text_len[i] = rand() % (row / 2) ;
		text_begin[i] = (rand() % (col / 2));
		text_out[i] = text_begin[i];
	}

	short temp_color = 1;

	short wb = 2; // white and black

	bool run = true;
	while(run){
		for(int i = 0; i < col; ++i){
			wchar_t wc = (rand() % 93 + 33);
			if(i % 2 == 0) 
				wc = ' ';
			mvwaddch(stdscr, text_out[i] + 1, i, wc | COLOR_PAIR(wb));
			mvwaddch(stdscr, text_out[i], i, wc | COLOR_PAIR(temp_color));
			mvwaddch(stdscr, text_out[i] - text_len[i], i, ' ' | COLOR_PAIR(temp_color));
			if(text_out[i] - text_len[i] > row) 
				text_out[i] = text_begin[i];
		}

		sleep(1);
		nodelay(stdscr, TRUE);
		noecho();

		char c = getch();
		switch(c){
			case 'q':
				run = false;
				clear();
				break;
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



