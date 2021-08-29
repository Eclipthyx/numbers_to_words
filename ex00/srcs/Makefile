MKDIR   := mkdir
RMDIR   := rm -rf
CC      := gcc
OBJ     := ./obj
INCLUDE := ./include
SRC     := .
SRCS    := $(wildcard $(SRC)/*.c)
OBJS    := $(patsubst $(SRC)/%.c,$(OBJ)/%.o,$(SRCS))
EXE     := ./rush-02
CFLAGS  := -Wall -Werror -Wextra -I$(INCLUDE)
LDLIBS  := -lm

.PHONY: all run clean

all: $(EXE)

$(EXE): $(OBJS)
	$(CC) $(LDFLAGS) $^ -o $@ $(LDLIBS)

$(OBJ)/%.o: $(SRC)/%.c | $(OBJ)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ):
	$(MKDIR) $@

run: $(EXE)
	$<

clean:
	$(RMDIR) $(OBJ) $(EXE)