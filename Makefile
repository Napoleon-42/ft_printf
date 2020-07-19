
NAME	= libftprintf.a

LIBFT_PATH	= ./libft

OUTILS_PATH = ./outils

OBJS_PATH	= ./obj/

OBJS	= ${SRCS:.c=.o}

FLAGS	= -Wall -Wextra -Werror


SRCS	= ${LIBFT_PATH}/ft_putchar_fd.c ${LIBFT_PATH}/ft_putstr_fd.c ${LIBFT_PATH}/ft_putendl_fd.c ${LIBFT_PATH}/ft_putnbr_fd.c\
		${LIBFT_PATH}/ft_putnchar_fd.c ${LIBFT_PATH}/ft_putnstr_fd.c\
		\
		${LIBFT_PATH}/ft_split.c ${LIBFT_PATH}/ft_strjoin.c ${LIBFT_PATH}/ft_strmapi.c ${LIBFT_PATH}/ft_substr.c ${LIBFT_PATH}/ft_strtrim.c \
		${LIBFT_PATH}/ft_isalpha.c ${LIBFT_PATH}/ft_isascii.c ${LIBFT_PATH}/ft_isalnum.c ${LIBFT_PATH}/ft_isdigit.c ${LIBFT_PATH}/ft_strlen.c\
		${LIBFT_PATH}/ft_isprint.c ${LIBFT_PATH}/ft_strdup.c ${LIBFT_PATH}/ft_strchr.c ${LIBFT_PATH}/ft_strlcat.c ${LIBFT_PATH}/ft_strlcpy.c \
		${LIBFT_PATH}/ft_strncmp.c ${LIBFT_PATH}/ft_strnstr.c ${LIBFT_PATH}/ft_strrchr.c ${LIBFT_PATH}/ft_tolower.c ${LIBFT_PATH}/ft_toupper.c\
		\
		${LIBFT_PATH}/ft_calloc.c ${LIBFT_PATH}/ft_memccpy.c ${LIBFT_PATH}/ft_memcpy.c ${LIBFT_PATH}/ft_memchr.c ${LIBFT_PATH}/ft_memcmp.c \
		${LIBFT_PATH}/ft_memset.c ${LIBFT_PATH}/ft_memmove.c ${LIBFT_PATH}/ft_bzero.c \
		\
		${LIBFT_PATH}/ft_atoi.c ${LIBFT_PATH}/ft_itoa.c\
		\
		${OUTILS_PATH}/print_i_d.c ${OUTILS_PATH}/print_x_X.c ${OUTILS_PATH}/print_p.c ${OUTILS_PATH}/print_c_s.c\
		${OUTILS_PATH}/ft_printf_outils.c ${OUTILS_PATH}/print_u.c\
		\
		./ft_printf.c


RM		= rm -fr

CC		= gcc

.c.o:
			${CC} ${FLAGS} -c $< -o ${<:.c=.o} 
			
all:		${NAME}

${NAME}:	printf.h ./libft/libft.h ${OBJS}
				ar rc ${NAME} ${OBJS}
				ranlib ${NAME}

clean:		
				${RM} ${OBJS}
				
fclean:		 clean
				${RM} ${NAME}
				
re:			fclean all

my:			${NAME} clean