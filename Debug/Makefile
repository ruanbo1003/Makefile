
IncludeDir = -I/home/ruanbo/Codes/MakefileTest
CCFlags = -g -Wall $(IncludeDir)

#中间文件(.o)
SrcDir = /home/ruanbo/Codes/MakefileTest
BuildDir = /home/ruanbo/Codes/MakefileTest/Debug
CppPathFiles = $(wildcard $(SrcDir)/*.cpp)
CppFiles = $(notdir $(CppPathFiles))

Objfiles = $(patsubst %.cpp,%.o,$(CppFiles)) 

#SubDirs = $(shell ls -l $(SrcDir) | grep ^d | awk {'if($$9 != "Debug") print $$9'})

#所有的子目录，包括子目录的子目录
SubDirs += utils \
comm

#所有的字目录cpp文件
SubCpps = $(foreach dir,$(SubDirs),$(wildcard $(SrcDir)/$(dir)/*.cpp))

#所有子目录cpp文件对应的.o文件
SubObjs = $(patsubst %.cpp,%.o,$(SubCpps))

#
DebugSubObjs = $(foreach obj,$(SubObjs),$(subst $(SrcDir),$(BuildDir),$(obj)))

mft:$(DebugSubObjs) $(Objfiles)
	@echo $(CppFiles)
	@echo $(Objfiles)
	gcc -o mft $(DebugSubObjs) $(Objfiles)

$(DebugSubObjs):%.o %.cpp
	@echo "Compiling $< ==> $@"
	
	gcc $(CCFlags) -c $< -o $@


.PHONY:clean
clean:
	rm mft $(DebugSubObjs) $(Objfiles)



