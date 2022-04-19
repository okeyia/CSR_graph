//
// Created by sen on 2022/3/26.
//
#include "csr_graph.h"

const char in_file[] = "./res/data.dat";
const char out_file[] = "./res/el_to_csr.dat";



int create_sparse_csr(
		const double *A,
		/*
		 * 它是一种“整型”类型，里面保存的是一个整数，就像int、long那样。
		 * 这种整数用来记录一个大小（size）。size_t的全称应该是size type，
		 * 就是说“一种用来记录大小的数据类型”。
		 * */
		size_t n_rows,
		size_t n_cols,
		size_t n_nz,
		Sparse_CSR* A_csr) {

	A_csr->n_rows = n_rows;
	A_csr->n_cols = n_cols;
	A_csr->n_nz = n_nz;

	/*
	 * malloc与calloc的区别
	 * malloc(size)：在内存的动态存储区中分配一块长度为“size”字节的连续区域，返回该区域的首地址
	 * calloc(n，size)：在内存的动态存储区中分配n块长度为“size”字节的连续区域，返回首地址。
	 * */
	A_csr->row_ptrs = calloc(n_rows + 1, sizeof(size_t));
	A_csr->col_indices = calloc(n_nz, sizeof(size_t));
	A_csr->values = calloc(n_nz, sizeof(double));

	// 定义 非0元素的开始 id
	size_t nz_id = 0;

	for (size_t i = 0; i < n_rows; ++i) {
		A_csr->row_ptrs[i] = nz_id;
		for (size_t j = 0; j < n_cols; ++j) {
			// 行数*每行的元素个数
			if (A[i * n_cols + j] != 0.0) {
				A_csr->col_indices[nz_id] = j;
				A_csr->values[nz_id] = A[i * n_cols + j];
				nz_id++;
			}
		}
	}

	// row_ptrs 比 n_row 多一个元素
	A_csr->row_ptrs[n_rows] = nz_id;


	return 0;
}

int print_sparse_csr(const Sparse_CSR *A_csr) {

	printf("row\tcol\tval");
	printf("------\n");

	for (size_t i = 0; i < A_csr->n_rows; ++i) {

		size_t nz_start = A_csr->row_ptrs[i];
		size_t nz_end = A_csr->row_ptrs[i + 1];
		for (size_t nz_id = nz_start; nz_id < nz_end; ++nz_id) {
			size_t j = A_csr->col_indices[nz_id];
			double val = A_csr->values[nz_id];

			// 输出为 coo格式
			printf("%zu\t%zu\t%02.2f\n", i, j, val);
		}
	}

	return 0;
}

int matrix_vector_sparse_csr(const Sparse_CSR *A_csr, const double *vec, double *res) {

	for (size_t i = 0; i < A_csr->n_rows; ++i) {
		res[i] = 0.0;

		size_t nz_start = A_csr->row_ptrs[i];
		size_t nz_end = A_csr->row_ptrs[i + 1];
		for (size_t nz_id = nz_start; nz_id < nz_end; nz_id++) {
			size_t j = A_csr->col_indices[nz_id];
			double val = A_csr->values[nz_id];

			res[i] = res[i] + val * vec[j];
		}
	}

	return 0;
}


int free_sparse_csr(Sparse_CSR *A_csr) {
	free(A_csr->row_ptrs);
	free(A_csr->col_indices);
	free(A_csr->values);

	return 0;
}

int create_sparse_csr2(
		size_t n_rows,
		size_t n_cols,
		size_t n_nz,
		struct Sparse_CSR *A_csr){

	A_csr->n_rows = n_rows;
	A_csr->n_cols = n_cols;
	A_csr->n_nz = n_nz;

	A_csr->row_ptrs = calloc(n_rows + 1, sizeof(size_t));
	A_csr->col_indices = calloc(n_nz, sizeof(size_t));
	A_csr->values = calloc(n_nz, sizeof(double));


}

void print_to_file(Sparse_CSR *A_csr){
	FILE *write;
	write = fopen(out_file, "w+");

	for (size_t i = 0; i < A_csr->n_rows; ++i) {

		size_t nz_start = A_csr->row_ptrs[i];
		size_t nz_end = A_csr->row_ptrs[i + 1];
		for (size_t nz_id = nz_start; nz_id < nz_end; ++nz_id) {
			size_t j = A_csr->col_indices[nz_id];

			// 输入图无权重,所以注释掉了
			// double val = A_csr->values[nz_id];

			fprintf(write, "%zu\t%zu\n", i, j);
		}
	}
}