NAME = libft.a

GCC = gcc -c -Wall -Wextra -Werror

SRCS =	ft_isdigit.c ft_memcpy.c ft_split.c ft_strlen.c ft_tolower.c \
		ft_atoi.c ft_isprint.c ft_memmove.c ft_strchr.c ft_strmapi.c ft_toupper.c \
		ft_bzero.c ft_itoa.c ft_memset.c ft_strdup.c ft_strncmp.c \
		ft_calloc.c ft_putchar_fd.c ft_striteri.c ft_strnstr.c \
		ft_isalnum.c ft_putendl_fd.c ft_strjoin.c ft_strrchr.c \
		ft_isalpha.c ft_memchr.c ft_putnbr_fd.c ft_strlcat.c ft_strtrim.c \
		ft_isascii.c ft_memcmp.c ft_putstr_fd.c ft_strlcpy.c ft_substr.c  \

SRCS_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
			 ft_lstlast.c ft_lstadd_back.c \
			 ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
			 ft_lstmap.c \

OBJS = $(SRCS:.c=.o) 

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)
$(NAME):
	@$(GCC) $(SRCS) -I .
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

bonus: $(NAME)
	@$(GCC) $(SRCS_BONUS) -I .
	@ar rc $(NAME) $(OBJS_BONUS)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
