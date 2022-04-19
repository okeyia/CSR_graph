//
// Created by sen on 2022/4/4.
// 从文件中读取edge-list的数据, 通过csr结构存储, 在通过coo格式输出到文件
//

#include <stdio.h>
#include "csr_graph.h"



int main() {

	// 4039个顶点  176468条边
	size_t n_rows = 4039;
	size_t n_cols = 4039;
	size_t n_nz = 176468;


	struct Sparse_CSR A_csr;

	create_sparse_csr2( n_rows, n_cols, n_nz, &A_csr);

	print_to_file(&A_csr);

	free_sparse_csr(&A_csr);

	return 0;
}
