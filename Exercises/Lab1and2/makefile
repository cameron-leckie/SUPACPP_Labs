COMPILER=g++
FLAGS=-std=c++20 -w # Compiler flags
TARGET=AnalyseData # Executable
OBJECTS=AnalyseData.o CustomFunctions.o

# Make target from object
${TARGET}:${OBJECTS} # Use OBJECTS to make TARGET
		@echo "Linking..."
		${COMPILER} ${FLAGS} ${OBJECTS} -o ${TARGET}
		@make clean

AnalyseData.o : AnalyseData.cpp
		${COMPILER} ${FLAGS} -c AnalyseData.cpp

CustomFunctions.o : CustomFunctions.cpp
		${COMPILER} ${FLAGS} -c CustomFunctions.cpp

clean : 
		@rm -f *.o

cleanTarget : 
		@rm -f ${TARGET} 

cleanAll : 
		@make clean
		@make cleanTarget
