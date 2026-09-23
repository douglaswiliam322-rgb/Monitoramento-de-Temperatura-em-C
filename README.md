Projeto: Sistema de Monitoramento de Temperatura


Nome do Aluno: Douglas Wilham De Queiroz Filho 

Disciplina: Algoritmos e Pensamento Computacional

Professora: Profa. Karla Sartin

-------------------------------------------- Monitoramento Continuo de Temperatura em C -----------------------------------------

2. Objetivo

Esse programa serve para monitorar a temperatura de um ambiente de forma automatizada. Ele ajuda a avisar quando a temperatura passa de um limite definido pelo usuario seguro e fecha sozinho se a temperatura ficar alta demais por muito tempo seguido em que foi definido 3 vezes.

3. Funcionamento do Programa

Limite : Logo no começo, o usuário digita qual é a temperatura máxima permitida por ele.

Como as leituras são feitas: O programa solicita uma temperatura de cada vez no teclado.

Valores inválidos: Se o usuário digitar um limite absurdo, (fora de -50 até 150) ou uma temperatura estranha (fora de -100 até 200), o programa avisa que ta errado e pede para digitar de novo sem quebrar o código.

Temperaturas acima do limite: O programa compara cada valor digitado com o limite inicial. Se for maior, ele soma 1 no contador de alertas.

Contagem de consecutivas: Se der alerta ele soma 1 no contador de consecutivas. Mas se o usuário digitar uma temperatura normal depois de um alerta, esse contador de consecutivas volta pra zero, reniciando a contagem.

Condição de encerramento: O programa para imediatamente assim que atingir 3 temperaturas altas seguidas e depois mostra um relatório com a média, a maior e a menor temperatura lida.

4. Estruturas de Repetição Utilizadas

No projeto foi usado o do while e o while:

do while: Usei na parte de pedir o limite inicial de temperatura. Escolhi ele porque precisava pedir a temperatura pelo menos uma vez antes de testar se o valor era válido.

while: Usei no laço principal onde fica lendo as temperaturas direto. Escolhi ele porque a gente precisa checar a condição (se o contador de consecutivas é menor que 3) antes de deixar o usuário digitar uma nova temperatura.

5. Como Executar

Para rodar o programa no terminal usando o compilador GCC, faça o seguinte:

gcc monitoramento.c -o monitoramento

./monitoramento

6. Testes Realizados

Teste 1: Validação de entradas inválidas

O que foi feito: Digitei um limite de 300°C (inválido) e depois uma temperatura de -500°C (inválida).

Resultado: O programa bloqueou os dois valores, exibiu mensagem de erro e pediu pra digitar valores válidos novamente. 
Print em: evidencias/teste01.png

Teste 2: Temperaturas acima do limite, mas não consecutivas

O que foi feito: Defini o limite em 150°C e digitei: 155°C alta, 165°C alta, 120°C normal e 155°C alta.

Resultado: O programa deu alerta nas temperaturas altas, mas quando entrou a temperatura normal ele zerou a contagem de consecutivas e continuou rodando normalmente. 
Print em: evidencias/teste02.png

Teste 3: Três temperaturas consecutivas acima do limite

O que foi feito: Defini o limite em 150°C e digitei: 199°C, 188°C e 199°C seguidas.

Resultado: No terceiro valor acima do limite, o programa encerrou sozinho na hora e mostrou o relatório final completo certinho. Print em: evidencias/teste03.png


Questão Final de Reflexão


Escolhi usar a combinação das duas estruturas porque cada uma facilitou uma parte diferente do código, ajudando a entender o codigo e diminuir o tamanho dele. A diferença entre testar antes ou depois foi super importante no começo, para validar o limite inicial, usar o do while fez mais sentido porque eu precisava primeiro executar a leitura do valor digitado para depois testar se ele era válido ou não. Já no laço das leituras, o while testando a condição antes evitou que o programa pedisse mais uma entrada depois que a terceira temperatura consecutiva já tinha estourado o limite de tentativas, evitando possiveis conflitos no codigo.
