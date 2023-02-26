##
## EPITECH PROJECT, 2021
## makefile
## File description:
## generate binary
##

SRC_MAIN	=	main.cpp	\
				utils/BinaryOperation.cpp	\
				circuit/Circuit.cpp	\
				parser/Parser.cpp	\
				interpreter/CommandInterpreter.cpp	\

SRC_CREATOR	=	OrCreator.cpp	\
				InputCreator.cpp	\
				OutputCreator.cpp	\
				FalseCreator.cpp	\
				TrueCreator.cpp	\
				ClockCreator.cpp	\
				AndCreator.cpp	\
				FourAndCreator.cpp	\
				FourNandCreator.cpp	\
				FourNorCreator.cpp	\
				FourXorCreator.cpp	\
				SixInverterCreator.cpp	\
				XorCreator.cpp	\
				DualFlipFlopCreator.cpp	\
				FourBitAdderCreator.cpp	\
				JohnsonDecadeCreator.cpp	\
				FourOrCreator.cpp	\
				NotCreator.cpp	\
				LoggerCreator.cpp	\
				BitCounterCreator.cpp	\
				DecoderCreator.cpp	\

SRC_ERROR 	=	ComputeError.cpp	\
				MappingError.cpp	\
				ParsingError.cpp	\

SRC_COMPONENT =	AComponent.cpp	\
				simpleComponents/AndComponent.cpp	\
				simpleComponents/NotComponent.cpp	\
				simpleComponents/XorComponent.cpp	\
				simpleComponents/OrComponent.cpp	\
				simpleComponents/FourXorComponent.cpp	\
				simpleComponents/SixInverterComponent.cpp	\
				simpleComponents/FourAndComponent.cpp	\
				simpleComponents/FourNandComponent.cpp	\
				simpleComponents/FourNorComponent.cpp	\
				simpleComponents/FourOrComponent.cpp	\
				complexComponents/FourBitAdderComponent.cpp	\
				complexComponents/DualFlipFlopComponent.cpp	\
				complexComponents/JohnsonDecadeComponent.cpp	\
				complexComponents/LoggerComponent.cpp	\
				complexComponents/BitCounterComponent.cpp	\
				complexComponents/DecoderComponent.cpp	\
				specialComponents/ClockComponent.cpp	\
				specialComponents/TrueComponent.cpp	\
				specialComponents/FalseComponent.cpp	\
				specialComponents/InputComponent.cpp	\
				specialComponents/OutputComponent.cpp	\

SRC	=	$(addprefix src/, $(SRC_MAIN))	\
		$(addprefix src/creator/, $(SRC_CREATOR))	\
		$(addprefix src/errors/, $(SRC_ERROR))	\
		$(addprefix src/components/, $(SRC_COMPONENT))	\

OBJ	=	$(SRC:.cpp=.o)

CPPFLAGS	=	-I./src/components/include	\
				-I./src/components/specialComponents/include	\
				-I./src/components/complexComponents/include	\
				-I./src/components/simpleComponents/include	\
				-I./src/circuit/include	\
				-I./src/parser/include	\
				-I./src/creator/include	\
				-I./src/errors/include	\
				-I./src/interpreter/include	\

DEBUGFLAGS	=	-ggdb3 -W -Wall -Werror

NAME	=	nanotekspice

all:	$(NAME)

$(NAME):	$(OBJ)
	g++ -o $(NAME) $(OBJ) $(CPPFLAGS) $(LIB)

clean:
	rm -f $(OBJ);
	rm -f *~;
	rm -f *.gc*
	rm -f vgcore*
	rm -f unit_tests

fclean : clean
	rm -f $(NAME)
	make fclean -C tests/

re: fclean all

debug: fclean
	g++ -o $(NAME) $(SRC) $(CPPFLAGS) $(DEBUGFLAGS) $(LIB)

tests_run:
	make fclean -C tests/
	make -C tests/
	./unit_tests

.PHONY: all clean fclean re tests_run
