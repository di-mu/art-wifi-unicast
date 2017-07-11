#include <stdio.h>

void main () {
	FILE *fp = fopen("input.dat", "w");
	int buffer[7] = {16, -3, 98, 88, 1000, 789, 220};
	int i;
	for (i=0; i<sizeof(buffer)/sizeof(int); i++)
		fprintf(fp, "%d ", buffer[i]);
}
