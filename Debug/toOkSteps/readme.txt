记录是怎么一步步做好这个MakeFile的

Makefile1

Makefile2
1.用ObjFiles替换main.o net.o file.o
2.去掉每个.o 编译中的头文件依赖项
3.用$(SrcDir)替换其中的/home/ruanbo/Codes/MakefileTest


Makefile3
1. 将单个的依赖项的编译合并：%.o: $(SrcDir)/%.cpp
.
.
Makefile4
一个Makefile文件就可以编译整个项目。
但是有一个问题：直接用gcc编译各个cpp文件，可能导致有依赖关系的编译，编译的前后不同导致出错。
如UtilBase.hpp UtilBase.cpp， Util2.cpp依赖UtilBase的实现，但直接编译是不行的
.

