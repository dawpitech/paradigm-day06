##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## Makefile
##

CC	:=	g++

CPPFLAGS	=	-std=c++20
CPPFLAGS	+=	-W
CPPFLAGS	+=	-Wall
CPPFLAGS	+=	-Wextra
CPPFLAGS	+=	-Wundef
CPPFLAGS	+=	-Wshadow
CPPFLAGS	+=	-Wunreachable-code
CPPFLAGS	+=	-Wmissing-prototypes
CPPFLAGS	+=	-pedantic
CPPFLAGS	+=	-iquote include

BDIR	=	.build/release

SRC	=	ex0/Z.cpp

OBJ = $(SRC:%.cpp=$(BDIR)/%.o)

NAME = Z

.PHONY: all
all: $(NAME)

$(BDIR)/%.o: %.c
	@ mkdir -p $(dir $@)
	$(CC) -o $@ -c $< $(CPPFLAGS)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(CPPFLAGS) -o $(NAME)

.PHONY: clean
clean:
	@ rm -f $(OBJ)
	@ rm -rf .build

.PHONY: fclean
fclean: clean
	@ rm -f $(NAME)

.NOTPARRALEL: re
.PHONY: re
re: fclean all
