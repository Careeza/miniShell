CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude -g -fsanitize=address
LDFLAGS = -lreadline

BUILD_DIR = build
OBJS_DIR = $(BUILD_DIR)/objs
DEPS_DIR = $(BUILD_DIR)/deps

PRECOMPILE = mkdir -p $(dir $@)
POSTCOMPILE = sleep 0

ifndef NODEPS

PRECOMPILE += ;mkdir -p $(dir $(DEPS_DIR)/$*)
CFLAGS += -MT $@ -MMD -MP -MF $(DEPS_DIR)/$*.Td
POSTCOMPILE += ;mv -f $(DEPS_DIR)/$*.Td $(DEPS_DIR)/$*.d && touch $@

endif

include src.mk

OBJS = $(patsubst src/%.c, $(OBJS_DIR)/%.o, $(SRC))
OBJS_TEST = $(filter $(OBJS_DIR)/Test/%, $(OBJS))
OBJS_UTILS = $(filter $(OBJS_DIR)/Utils/%, $(OBJS))
OBJS_COMMON = $(filter $(OBJS_DIR)/Common/%, $(OBJS))


all: minishell

$(OBJS_DIR)/%.o: src/%.c Makefile
	@$(PRECOMPILE)
	$(CC) $(CFLAGS) -c -o $@ $<
	@$(POSTCOMPILE)

minishell: $(OBJS_TEST) $(OBJS_UTILS) $(OBJS_COMMON)

minishell:
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

clean:
	rm -rf build

fclean: clean
	rm -rf minishell
	rm -rf minishell2

re:
	$(MAKE) fclean
	$(MAKE) all

include $(wildcard $(DEPS_DIR)/**/*.d)

.PHONY: all clean fclean re test
