#include <stdlib.h>
#include "Detection.h"

int THRESHOLD1 = 2000;
int THRESHOLD2 = 1000;
int SPKF = 4000;
int NPKF = 2000;

int isMaximum(int x, int y, int z) {

	if (x < y && y > z) {
		return 1;
	} else {
		return 0;
	}

}

int isRPeak(int x) {
	if (x > THRESHOLD1) {

		updateValues(x);
		printf("%i\n", THRESHOLD1);
		return 1;
	} else {
		updateValues2(x);
		return 0;
	}
}

void updateValues(int x) {
	SPKF = 0.125 * x + 0.875 * SPKF;
	THRESHOLD1 = NPKF + 0.25 * (SPKF - NPKF);
	THRESHOLD2 = 0.5 * THRESHOLD1;

}

void updateValues2(int x) {
	NPKF = 0.125 * x + 0.875 * NPKF;
	THRESHOLD1 = NPKF + 0.25 * (SPKF - NPKF);
	THRESHOLD2 = 0.5 * THRESHOLD1;


}

