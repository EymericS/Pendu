ifeq ($(OS), Windows_NT) # Détecte Windows comme OS pour W10, W8, W7, WXP, W_NT
	RM_FILE ?= del /f /s /q
	RM_DIR ?= rmdir /Q /S
	TOUCH ?= type nul >
	MK_DIR ?= mkdir
	SLASH ?= $\\
	SYS ?= Windows
else
	RM_FILE ?= rm -f
	RM_DIR ?= rm -rf
	TOUCH ?= touch
	MK_DIR ?= mkdir
	SLASH ?= /
	SYS ?= Unix
endif

CC = gcc # Compilateur utilisé
LD = gcc # Compilateur de lien utilisé
CFLAGS = -g -Wall -Wextra -pedantic -pedantic-errors # Options pour le compilateur
LDFLAGS = # Option pour le compilateur de lien
DEPFLAGS = -MM # Option pour la création des fichiers de dépendance

SRC_DIR = src
INC_DIR = $(SRC_DIR)/header
BIN_DIR = bin
OBJ_DIR = obj
BIN_DIR_SYS = $(BIN_DIR)/$(SYS)
OBJ_DIR_SYS = $(OBJ_DIR)/$(SYS)

APP = app
EXEC = $(BIN_DIR_SYS)/app

conv = $(subst /,$(SLASH),$(1))


all: $(EXEC)

DEPS = $(OBJ_DIR_SYS)/main.o $(OBJ_DIR_SYS)/pendu.o $(OBJ_DIR_SYS)/chaineCaractere.o
$(EXEC): $(DEPS) $(BIN_DIR_SYS)/.dirstamp
	@echo Linking of $(call conv,$(DEPS)) for $(call conv,$@) ...
	@$(LD) $(LDFLAGS) $(DEPS) -o $@
	@echo Linking done !

$(OBJ_DIR_SYS)/main.o: $(SRC_DIR)/main.c $(INC_DIR)/pendu.h $(OBJ_DIR_SYS)/.dirstamp
	@echo Building of $(call conv,$@) ...
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo Building done !

$(OBJ_DIR_SYS)/pendu.o: $(SRC_DIR)/pendu.c $(INC_DIR)/pendu.h $(OBJ_DIR_SYS)/.dirstamp
	@echo Building of $(call conv,$@) ...
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo Building done !

$(OBJ_DIR_SYS)/chaineCaractere.o: $(SRC_DIR)/chaineCaractere.c $(INC_DIR)/chaineCaractere.h $(OBJ_DIR_SYS)/.dirstamp
	@echo Building of $(call conv,$@) ...
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo Building done !

.PRECIOUS: %/.dirstamp
%/.dirstamp:
	@echo Building missing directory .stamp of $(call conv,$@) ...
	@$(MK_DIR) $(call conv,${@D}) &
	@$(TOUCH) $(call conv,$@) &
	@echo Building done !

.PHONY: clean
clean:
	@echo Removing all .o files from $(call conv,$(OBJ_DIR_SYS)) ...
	@$(RM_FILE) $(call conv,$(OBJ_DIR_SYS)/)*.o
	@echo Removing done !

.PHONY: mrproper
mrproper: clean
	@echo Removing directory $(call conv,$(OBJ_DIR)) and $(call conv,$(BIN_DIR)) ...
	@$(RM_DIR) $(call conv,$(OBJ_DIR))
	@$(RM_DIR) $(call conv,$(BIN_DIR))
	@echo Removing done !

.PHONY: run
run:
	@echo Running $(call conv,$(EXEC)) ...
	@./$(EXEC)