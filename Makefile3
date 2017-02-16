

SrcDir = /home/ruanbo/Codes/MakefileTest
IncDir = -I$(SrcDir)

SrcDirs = utils \
comm

#所有的字目录cpp文件
SrcCpps = $(foreach dir,$(SrcDirs),$(wildcard $(SrcDir)/$(dir)/*.cpp)) $(wildcard $(SrcDir)/*.cpp)

#所有子目录cpp文件对应的.o文件
ObjFiles = $(patsubst %.cpp,%.o,$(SrcCpps))

TargetBin = mft
CCFlags=-g -Wall $(IncDir)
MakeCC = g++
RM = -rm -f

$(TargetBin):$(ObjFiles)
	$(MakeCC) $(ObjFiles) -o $@
	
$(ObjFiles):%.o:%.cpp
	@echo "compiling $< ==> $@"
	$(MakeCC) $(CCFlags) -c $< -o $@


.PHONY:clean
clean:
	$(RM) $(ObjFiles)
	$(RM) $(TargetBin)
