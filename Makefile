# Enzo CADONI G2
# TP supplementaire
# Makefile

SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin

EXE_PAGE 	:= $(BIN_DIR)/remplacement
EXE_BENCH := $(BIN_DIR)/benchmark
EXE_GEN 	:= $(BIN_DIR)/generation_fichier
ALL_EXE  	:= $(EXE_PAGE) $(EXE_BENCH) $(EXE_GEN)
SRC 			:= $(wildcard $(SRC_DIR)/*.c)
OBJ 			:= $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJ_PAGE  := $(filter-out %_benchmark.o, $(filter-out %_generation.o, $(OBJ)))
OBJ_BENCH := $(filter-out %main_remplacement.o, $(filter-out %main_generation.o, $(OBJ)))
OBJ_GEN := $(filter-out %_remplacement.o, $(filter-out %_benchmark.o, $(OBJ)))

CC := gcc
CPPFLAGS := -Iinc -MMD -MP
CFLAGS   := -Wall -pedantic -g -O2 `pkg-config --cflags MLV`
LDFLAGS  := `pkg-config --libs-only-other --libs-only-L MLV`
LDLIBS   := -lm `pkg-config --libs-only-l MLV`

.PHONY: all clean

all: $(ALL_EXE)

$(EXE_PAGE): $(OBJ_PAGE) | $(BIN_DIR)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

$(EXE_BENCH): $(OBJ_BENCH) | $(BIN_DIR)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

$(EXE_GEN): $(OBJ_GEN) | $(BIN_DIR)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@

clean:
	@$(RM) -rv $(OBJ_DIR)

clean_all:
	@$(RM) -rv $(BIN_DIR) $(OBJ_DIR)

-include $(OBJ:.o=.d)
