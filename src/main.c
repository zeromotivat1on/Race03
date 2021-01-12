#include "../inc/mx_rain.h"

int main(int argc, char *argv[]){
	
	if(argc == 1 || argv[0]){
		mx_rain();
	}
	else{
		mx_printerr("usage: ./matrix_rain\n");
	}
	
}


