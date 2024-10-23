# Define o nome do executável principal
MAIN = gerenciadorCredenciais

# Define o compilador C
CC = gcc

# Define as flags de compilação (warnings)
CFLAGS = -Wall

# Define as variáveis para os arquivos fonte, headers e objetos
SOURCES = $(wildcard ./src/*.c)
HEADERS = $(wildcard ./src/*.h)
OBJECTS = $(SOURCES:.c=.o)

# Define o diretório do programa
PROGRAMDIR = .

# Regra principal: compila o programa e limpa os objetos
all: $(MAIN) clean_objects

# Regra para compilar o programa principal
$(MAIN): $(OBJECTS)
	$(CC) $(CFLAGS) $(LIBS) $(OBJECTS) -o $(PROGRAMDIR)/$(MAIN)
	@echo "Programa compilado com sucesso!"
	@echo "Execute: $(PROGRAMDIR)/$(MAIN)"

# Regra genérica para compilar arquivos .c em .o
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) $(LIBS) -c $< -o $@

# Regra para limpar os arquivos objeto
clean_objects:
	@rm -f $(OBJECTS)

# Regra para limpar o executável e os arquivos objeto
clean:
	rm -f $(PROGRAMDIR)/$(MAIN) $(OBJECTS)
	@echo "Executável e arquivos objeto removidos."