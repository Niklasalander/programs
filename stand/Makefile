#OBJS specifies which files to compile
OBJS = stand.c

#CC specifies which compiler we're using
CC = gcc

#INCLUDE_PATHS
INCLUDE_PATHS = -IC:\libraries\SDL2\include\SDL2 -IC:\libraries\SDL2_image\include\SDL2 -IC:\libraries\SDL2_mixer\include\SDL2

#LIBRARY_PATHS
LIBRARY_PATHS = -LC:\libraries\SDL2\lib -LC:\libraries\SDL2_image\lib -LC:\libraries\SDL2_mixer\lib

#COMPILER_FLAGS

#-w suppresses all warnings
# -Wl,-subsystem,windows gets rid of the console window
COMPILER_FLAGS = -w
#

#LINKER_FLAGS
LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -std=c99

#OBJ_NAME specifies the name of our executable
OBJ_NAME = stad
#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(OBJS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)