# Celina Gonçalves Lemos
# M1

Agenda pBuffer

Faça uma agenda com o seguinte menu:
1- Adicionar Pessoa (Nome, Idade, email)
2- Remover Pessoa
3- Buscar Pessoa
4- Listar todos
5- Sair
 
O desafio é não poder criar variáveis e sim um buffer de memória (void *pBuffer). 
Nisso vocês terão que fazer o trabalho que o Sistema Operacional faz para vocês ao organizar a memória.
 
Regras:
Nenhuma variável pode ser declarada em todo o programa, somente ponteiros. 
Todos os dados do programa devem ser guardados dentro do pBuffer.
Nem mesmo como parâmetro de função. Só ponteiros que apontam para dentro do pBuffer.
Exemplo do que não pode: int c; char a; int v[10];  void Funcao(int parametro)
Não pode usar struct em todo o programa.

Entregar link de um vídeo explicando o código e mostrando alguns testes e ao final o resultado do 
DrMemory ou Valgrind.

Testes: 
Adicionar pessoas
Procurar uma pessoa na lista
Remover uma pessoa do meio da lista
Remover uma pessoa do começo da lista
Remover uma pessoa do final da lista