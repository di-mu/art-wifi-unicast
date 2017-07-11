#include <stdio.h>

void main() {
	unsigned char a,b;
	FILE *fp = fopen("output.dat", "r");
	fscanf(fp, "%hhu\n%hhu", &a, &b);
	fclose(fp);
	printf("%hhu %hhu\n",a,b);
}
