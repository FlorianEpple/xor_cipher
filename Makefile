CC := cc
CFLAGS := -Wall -Werror -Wextra

SRCS_DIR := srcs
INCS_DIR := srcs

CFILES := file_content.c main.c xor_cipher.c
SRCS_FILES := $(addprefix $(SRCS_DIR)/, $(CFILES))
OFILES := $(SRCS_FILES:.c=.o)
HEADER := $(INCS_DIR)/types.h

NAME := xor-cipher

all: $(NAME)

$(NAME): $(OFILES)
	$(CC) $(CFLAGS) -o $@ $(OFILES)

$(OFILES): %.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I$(INCS_DIR) -c $< -o $@

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
