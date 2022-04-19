//
// Created by sen on 2022/3/26.
// 简单的练习 读文件 写文件
//

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <unistd.h>

const char in_file[] = "/tmp/ClionPro/CSR_graph/res/data.dat";
const char out_file[] = "/tmp/ClionPro/CSR_graph/res/sort_data.dat";


int main(){
	FILE * file;
	char *buffer = NULL;

	file = fopen(in_file, "r");
	if (!file) {
		printf("%s\n", "文件打开失败!");
		exit(-1);
	}

	size_t len = 0;
	int counter = 0;  // 输出100行数据

	while (getline(&buffer, &len, file) != -1 && counter < 100) {
		printf("%s", buffer);
		counter++;
	}



	fclose(file);
	free(buffer);

	return 0;
}

