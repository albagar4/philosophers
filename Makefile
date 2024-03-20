NAME = philo
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I . -I include

PHILO_SRCS = src/main.c
PHILO_OBJS = $(PHILO_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(PHILO_OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(PHILO_OBJS) -o philo

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(PHILO_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re