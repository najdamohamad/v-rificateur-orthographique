# Compilateur
CC=gcc
# Options de compilation
CFLAGS=-std=c99 -Wall -Wextra -lm -g -pg

# DÃ©finition des rÃ©pertoires de travail
SRC_DIR=src
EXE_DIR=exe
BIN_DIR=bin
INC_DIR=include
INC=-I$(INC_DIR)

# Identification des fichiers source dans le rÃ©pertoire SRC_DIR
SRC_FILES=$(wildcard $(SRC_DIR)/*.c)

# Identification des fichiers source dans le rÃ©pertoire EXE_DIR
EXE_FILES=$(wildcard $(EXE_DIR)/*.c)

# GÃ©nÃ©ration de la liste des exÃ©cutables
BIN_FILES=$(patsubst $(EXE_DIR)/%.c, $(BIN_DIR)/%, $(EXE_FILES))

# RÃ¨gle par dÃ©faut (make)
all: $(BIN_FILES)

# RÃ¨gle gÃ©nÃ©rique
$(BIN_DIR)/%: $(EXE_DIR)/%.c | $(BIN_DIR)
	$(CC) $^ $(CFLAGS) $(SRC_FILES) $(INC) -o $@

$(BIN_DIR):
	mkdir $@

clear:
	rm -rf $(BIN_DIR)
	rm -f gmon.out
