COMPILER := g++

LDFLAGS := -I. -L. -lglfw -lGLEW -lGLU -lGL -lm -lX11 -lpthread -lXi -lXrandr -ldl -g
CFLAGS := -I. -L. -g -c

SRC := ${wildcard src/*.cpp}
SRC += ${wildcard src/graphics/*.cpp}

HDR := ${wildcard src/*.h}
HDR += ${wildcard src/graphics/*.h}

OBJ := ${SRC:.cpp=.o}
EXEC := chapi

all: ${SRC} ${OBJ} ${EXEC}

${EXEC}: ${OBJ}
	${COMPILER} $^ ${LDFLAGS} -o $@

%.o: %.cpp ${HDR}
	${COMPILER} ${CFLAGS} $< -o $@

clean:
	rm -rf ${OBJ} ${EXEC}