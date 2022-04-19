### 使用CSR格式保存图的数据

 从COO数据文件中读取图,  读取为CSR格式, 然后再以COO格式输出, 判断转换是否错误。

#### 一  Intro res

- data.txt中保存原本的数据, 从顶点1开始 .  Nodes: 4039 Edges: 176468
- sort_data, 使用Practice/handle_graph.c 将图处理为从顶点0开始
- el_to_csr:  从sort_data中读取数据后, 转化为csr格式, 通过csr格式输出

#### 二  Intro src

csr_graph中包含CSR结构, 以及创建CSR、打印CSR、将CSR数据输出到文件。 main函数中包含从矩阵中读取数据，转化为CSR，再以COO格式输出。

#### 三 注意事项

由于本项目中, 读写文件都是使用相对路径, 注意在clion中配置工作目录.
![工作目录](https://cdn.jsdelivr.net/gh/okeyia/PictBed/Blogimg/202204051124982.png)

> [参考链接][1]

[1]: https://www.youtube.com/watch?v=a2LXVFmGH_Q "Youtube"