##
## EPITECH PROJECT, 2024
## makefile
## File description:
## makefile
##

all:
	make all -C Zappy_server
	make all -C Zappy_cli

debug:
	make debug -C Zappy_server
	make debug -C Zappy_cli

clean:
	make clean -C Zappy_server
	make clean -C Zappy_cli

fclean: clean
	make fclean -C Zappy_server
	make fclean -C Zappy_cli

re:
	make re -C Zappy_server
	make re -C Zappy_cli

unit_tests:
	make unit_tests -C Zappy_server
	make unit_tests -C Zappy_cli

tests_run:
	make tests_run -C Zappy_server
	make tests_run -C Zappy_cli

.PHONY: all clean fclean re tests_run
