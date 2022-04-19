// 练习视频中的代码
// https://www.youtube.com/watch?v=a2LXVFmGH_Q

#include <stdio.h>
#include "src/csr_graph.h"


int main() {

	size_t n_rows = 5;

	size_t n_cols = 5;
	size_t n_nz = 12;

	double A[] ={
			1,  0,  0,  2,  0,
			3,  4,  2,  5,  0,
			5,  0,  0,  8, 17,
			0,  0, 10, 16,  0,
			0,  0,  0,   0, 14
	};

	double x[] = {
		1,
		2,
		3,
		4,
		5
	};

	double Ax[5];

	struct Sparse_CSR A_csr;

	create_sparse_csr(A, n_rows, n_cols, n_nz, &A_csr);

	print_sparse_csr(&A_csr);

	matrix_vector_sparse_csr(&A_csr, x, Ax);

	for (int i = 0; i < n_rows; ++i) {
		printf("%02.2f\n", Ax[i]);
	}

	free_sparse_csr(&A_csr);

	return 0;
}
