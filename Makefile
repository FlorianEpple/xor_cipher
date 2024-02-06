MY_CFILES = xor_cipher.c
MY_OBJECTS = $(MY_CFILES:.c=.o)
NAME = xor
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(MY_OBJECTS)
	cc $(CFLAGS) -o $(NAME) $(MY_OBJECTS)

%.o: %.c
	cc $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(MY_OBJECTS)

fclean: clean
	rm -f $(NAME)
