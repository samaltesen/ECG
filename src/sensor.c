#include <stdio.h>
#include <stdlib.h>
#include "sensor.h"

 static FILE *file;
 static int first = 1;

int getNextData(){

	int value;
	fscanf(file, "%i", &value);

	return value;
}

int fileNotEmpty() {

	static int first = 1;
	if(first) {
	file = fopen("ECG.txt", "r");
	first = 0;
	}

	if (!feof (file)) {
		return 1;
	} else {
		return 0;
	}
}
