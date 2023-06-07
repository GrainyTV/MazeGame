# OBJ_SOURCE specifies which files to compile as part of the project
OBJ_SOURCE = main.c sources/*.c

# OBJ_LIB specifies which headers and libraries to link
OBJ_LIB = -I headers -I SDL/include -Lresources -Wl,-rpath=./resources -lSDL2main -lSDL2 -lSDL2_mixer -lSDL2_image

# OBJ_NAME specifies the name of our exectuable
OBJ_NAME = Maze

# This is the target that compiles our executable
all : $(OBJ_SOURCE)
	gcc $(OBJ_SOURCE) -w $(OBJ_LIB) -o $(OBJ_NAME)
