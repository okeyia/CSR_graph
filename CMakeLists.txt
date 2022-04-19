cmake_minimum_required(VERSION 3.16)
project(CSR_graph C)

set(CMAKE_C_STANDARD 11)

add_executable(CSR_graph main.c src/csr_graph.h src/csr_graph.c)
add_executable(read_graph_from_file practice/read_graph_from_file.c)
add_executable(handle practice/handle_graph.c)
add_executable(el_csr src/el_csr.c src/csr_graph.h src/csr_graph.c)