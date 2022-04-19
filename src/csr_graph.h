//
// Created by sen on 2022/3/26.
//


#ifndef CSR_GRAPH_CSR_GRAPH_H
#define CSR_GRAPH_CSR_GRAPH_H

#include <stdio.h>
#include <stdlib.h>

// 定义Sparse_CSR类
typedef struct Sparse_CSR{
	size_t n_rows;
	size_t n_cols;
	size_t n_nz;

	size_t *row_ptrs;
	size_t *col_indices;
	double *values;
}Sparse_CSR;

// 初始化CSR
int create_sparse_csr(
		const double * A,
		size_t n_rows,
		size_t n_cols,
		// 非0元素的个数
		size_t n_nz,
		struct Sparse_CSR* A_csr
		);

int create_sparse_csr2(
		size_t n_rows,
		size_t n_cols,
		// 非0元素的个数
		size_t n_nz,
		struct Sparse_CSR* A_csr
		);

// 将CSR格式的数据输出为 coo标准型格式
int print_sparse_csr(const Sparse_CSR* A_csr);


int matrix_vector_sparse_csr(
		const struct Sparse_CSR *A_oo,
		const double * vec,
		double *res
);

// 释放所有指针
int free_sparse_csr(Sparse_CSR* A_csr);

// 将csr数组输出到文件6
void print_to_file(Sparse_CSR *A_csr);

#endif //CSR_GRAPH_CSR_GRAPH_H
