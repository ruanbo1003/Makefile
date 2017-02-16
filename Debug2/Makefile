

SrcDir = /home/ruanbo/Codes/MakefileTest
BuildDir = /home/ruanbo/Codes/MakefileTest/Debug
IncDir = -I$(SrcDir)

SrcDirs = utils \
comm


#所有的字目录cpp文件
SrcCpps = $(foreach dir,$(SrcDirs),$(wildcard ../$(dir)/*.cpp)) $(wildcard ../*.cpp)

#所有子目录cpp文件对应的.o文件
ObjFilesTmp = $(patsubst %.cpp,%.o,$(SrcCpps))
ObjFiles = $(subst ../,./,$(ObjFilesTmp))


TargetBin = mft
CCFlags=-g -Wall $(IncDir)
MakeCC = g++
RM = -rm -f

$(TargetBin):Outputa $(ObjFiles)
	$(MakeCC) $(ObjFiles) -o $@
	
$(ObjFiles):%.o:../%.cpp
	@echo "compiling $< ==> $@"
	$(MakeCC) $(CCFlags) -c $< -o $@
	@echo 'Finished building: $<'
	@echo ' '

Outputa:
	@echo "========== outputa =============="
	$(foreach dir,$(SrcDirs),$(call $(shell mkdir -p $(dir))))
	@echo "SrcCpps:$(SrcCpps)"
	@echo "ObjFiles:$(ObjFiles)"
	@echo "==========Outputa  ================"




.PHONY:clean
clean:
	$(RM) $(ObjFiles)
	$(RM) $(TargetBin)
