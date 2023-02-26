##
## EPITECH PROJECT, 2023
## B-PDG-300-BDX-3-1-PDGD09-elouan.savy-camaret
## File description:
## Makefile
##

SRC	=		utils/BinaryOperation.cpp	\
			components/AComponent.cpp	\
			components/simpleComponents/AndComponent.cpp	\
			components/simpleComponents/NotComponent.cpp	\
			components/simpleComponents/XorComponent.cpp	\
			components/simpleComponents/OrComponent.cpp	\
			components/simpleComponents/FourXorComponent.cpp	\
			components/simpleComponents/SixInverterComponent.cpp	\
			components/simpleComponents/FourAndComponent.cpp	\
			components/simpleComponents/FourNandComponent.cpp	\
			components/simpleComponents/FourNorComponent.cpp	\
			components/simpleComponents/FourOrComponent.cpp	\
			components/complexComponents/FourBitAdderComponent.cpp	\
			components/complexComponents/DualFlipFlopComponent.cpp	\
			components/complexComponents/JohnsonDecadeComponent.cpp	\
			components/complexComponents/BitCounterComponent.cpp	\
			components/complexComponents/LoggerComponent.cpp	\
			components/complexComponents/DecoderComponent.cpp	\
			components/specialComponents/ClockComponent.cpp	\
			components/specialComponents/TrueComponent.cpp	\
			components/specialComponents/FalseComponent.cpp	\
			components/specialComponents/InputComponent.cpp	\
			components/specialComponents/OutputComponent.cpp	\
			circuit/Circuit.cpp	\
			errors/ComputeError.cpp	\
			errors/ParsingError.cpp	\
			parser/Parser.cpp	\
			creator/OrCreator.cpp	\
			creator/InputCreator.cpp	\
			creator/OutputCreator.cpp	\
			creator/FalseCreator.cpp	\
			creator/TrueCreator.cpp	\
			creator/ClockCreator.cpp	\
			creator/AndCreator.cpp	\
			creator/FourAndCreator.cpp	\
			creator/FourNandCreator.cpp	\
			creator/FourNorCreator.cpp	\
			creator/FourXorCreator.cpp	\
			creator/SixInverterCreator.cpp	\
			creator/XorCreator.cpp	\
			creator/DualFlipFlopCreator.cpp	\
			creator/FourBitAdderCreator.cpp	\
			creator/JohnsonDecadeCreator.cpp	\
			creator/FourOrCreator.cpp	\
			creator/NotCreator.cpp	\
			creator/BitCounterCreator.cpp	\
			creator/LoggerCreator.cpp	\
			creator/DecoderCreator.cpp	\

SRC_TEST	=	TestsAnd.cpp	\
				TestsOr.cpp	\
				TestsXor.cpp	\
				TestsBinaryOperation.cpp	\
				TestsFourAnd.cpp	\
				TestsFourOr.cpp	\
				TestsFourXor.cpp	\
				TestsFourBitAdder.cpp	\
				TestsClock.cpp	\
				TestsFourNand.cpp	\
				TestsFourNor.cpp	\
				TestsSixInverter.cpp	\
				TestsFlipFlop.cpp	\
				TestsNot.cpp	\
				TestJohnson.cpp	\
				TestParsingSubject.cpp	\
				TestParsingErrors.cpp	\
				TestCounter.cpp	\
				TestDecoder.cpp	\

CPPFLAGS	=	-I../src/components/include	\
				-I../src/components/specialComponents/include	\
				-I../src/components/complexComponents/include	\
				-I../src/components/simpleComponents/include	\
				-I../src/circuit/include	\
				-I../src/errors/include	\
				-I ../src/parser/include	\
				-I ../src/creator/include	\

NAME	=	unit_tests
TESTFLAGS = --coverage -lcriterion

all:	$(NAME)

$(NAME):
	g++ -o $(NAME) $(SRC_TEST) $(addprefix ../src/, $(SRC)) $(TESTFLAGS) $(CPPFLAGS)
	cp unit_tests ../

clean:
	rm -f $(NAME)
	rm -f ../$(NAME)

fclean: clean
	rm -f unit_tests
	rm -f *~
	rm -f *.gc*

re: fclean all

.PHONY: all clean fclean re
