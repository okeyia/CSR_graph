//
// Created by sen on 2022/3/26.
// 处理原始的数据
// 将原始的data.txt中的数据 处理为从第0个顶点开始
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const char in_file[] = "./res/data.dat";
const char out_file[] = "./res/sort_data.dat";

int main(){
	FILE * read_file;
	FILE * write_file;

	read_file = fopen(in_file, "r");
	if (!read_file) {
		printf("%s\n", "文件打开失败!");
		exit(-1);
	}

	write_file = fopen(out_file, "w+");
	if (!write_file) {
		printf("%s\n", "文件打开失败!");
		exit(-1);
	}


	int a, b;
	srand((unsigned)time(NULL));
	while ( fscanf(read_file, "%d%d", &a, &b)!=-1) {
		//printf("%d %d", a-1, b-1);

		int index = rand() % 10;

		fprintf(write_file, "%d %d", a-1, b-1);
		fprintf(write_file,"\n");

	}

	fclose(write_file);
	fclose(read_file);

	return 0;
}

