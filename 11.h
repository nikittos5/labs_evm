#pragma once

struct scan_info {
	char model[25];
	int price;
	double x_size;
	double y_size;
	int optr;
	int grey;
};

void scan_read_write();

int scan_read(int scan_num); 
