COMPILADOR := g++ -std=c++11

all: programa

programa:
	@$(COMPILADOR) -o programa *.cpp

run: programa
	@./programa -d docentes.csv -v veiculos.csv -p publicacoes.csv -q qualis.csv -r regras.csv -a 2017

clean:
	@rm *.o *.csv programa 2> /dev/null
