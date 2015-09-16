#include <stdlib.h>
#include "sensor.h"

int lowpass(int yn1,int yn2,int xn,int xn6,int xn12 ) {

	int yn =2*yn1 - yn2 + (xn - 2*xn6 + xn12)/32;

	return yn;
}

int highpass(int yn1, int xn, int xn16, int xn17, int xn32) {

	int yn = yn1 - (xn/32) + xn16-xn17 + (xn32/32);

	return yn;
}


int derivative(int xn, int xn1, int xn3, int xn4) {

	int yn = (float)1/8 * (2*xn +xn1 - xn3 - 2*xn4);

	return yn;

}


int squared(int xn) {

	return xn * xn;

}

int mwiFilter(int sum) {
	int yn = sum/30 ;
	return yn;
}



