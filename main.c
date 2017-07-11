#include "wz.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define INIT_RUN (PKT_DATA != _PKT_DATA)

static char python_call[] = "cd py && python handler.py ?";

void input_parameters() {
	FILE *fp = fopen("py/py.dat", "r");
	fscanf(fp, "%hhd %hhd", power_index + WIFI, power_index + ZIG);
	fclose(fp);
}

void output_parameters() {
	FILE *fp = fopen("py/c.dat", "w");
	fprintf(fp, "%hhd %hhd %ld %ld %ld %ld %ld",
		power_index[WIFI], power_index[ZIG],
		(wifi_split > 0) ? packet_count[WIFI] * 100 / wifi_split : 0,
		(PKT_DATA > wifi_split) ? packet_count[ZIG] * 100 / (PKT_DATA - wifi_split) : 0,
		PKT_DATA / TIME_BLOCK, thruput[WIFI], thruput[ZIG]);
	fclose(fp);
}

int main(int argn, char *argv[]) {
	ms_timer(2);
	wz_init();
	if (ACTIVE_DEV) {
		if (argn != 3) {
			printf("usage: %s <number of packets per batch> <number of batches to transmit>\n", argv[0]);
			exit(0);
		}
		python_call[sizeof(python_call) - 2] = '1';
		PKT_DATA = atoi(argv[1]); N_BATCH = atoi(argv[2]);
		power_index[ZIG] = -1;

		while(1) {
			wz_transmit_block(BLOCK_DATA);
			if (batch_id == N_BATCH) {
				printf("done\t%lu\n", ms_timer(3));
				wz_end(); exit(0);
			}
			if (packet_count[WIFI] >= 0) {
				output_parameters();
				system(python_call);
				input_parameters();
			}
		}
	} else {
		//query_2650(TI_RECV, 0);
		while(1) wz_receive_block();
	}
	return 0;
}
