// @Author Caio Lucas Pereira da Silva 22.1.4006

#include <stdio.h>
#include "colors.h"

// Função para mostrar o título e as opções do jogo
void printTitle() {
  printf("\n");
  printf(BLUE(   "\t     ██╗ █████╗  ██████╗  █████╗   ██████╗  █████╗   ██╗   ██╗███████╗██╗     ██╗  ██╗ █████╗\n"));
  printf(CYAN(   "\t     ██║██╔══██╗██╔════╝ ██╔══██╗  ██╔══██╗██╔══██╗  ██║   ██║██╔════╝██║     ██║  ██║██╔══██╗\n"));
  printf(MAGENTA("\t     ██║██║  ██║██║  ██╗ ██║  ██║  ██║  ██║███████║  ╚██╗ ██╔╝█████╗  ██║     ███████║███████║\n"));
  printf(RED(    "\t██╗  ██║██║  ██║██║  ╚██╗██║  ██║  ██║  ██║██╔══██║   ╚████╔╝ ██╔══╝  ██║     ██╔══██║██╔══██║\n"));
  printf(YELLOW( "\t╚█████╔╝╚█████╔╝╚██████╔╝╚█████╔╝  ██████╔╝██║  ██║    ╚██╔╝  ███████╗███████╗██║  ██║██║  ██║\n"));
  printf(GREEN(  "\t ╚════╝  ╚════╝  ╚═════╝  ╚════╝   ╚═════╝ ╚═╝  ╚═╝     ╚═╝   ╚══════╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝\n"));
  printf("\n\n\n\tBem vindo ao Jogo da Velha\n\n");
  printf("\t0. Sair do Jogo\n\t1. Começar um novo jogo\n\t2. Continuar um jogo salvo\n\t3. Continuar o jogo atual\n\t4. Exibir o ranking\n");
}
