// @Author Caio Lucas Pereira da Silva 22.1.4006

#pragma once
// Cores e formato de texto
#define ANSI_RESET            "\x1b[0m"  // Desativa os efeitos anteriores
#define ANSI_BOLD             "\x1b[1m"  // Coloca o texto em negrito
#define ANSI_COLOR_BLACK      "\x1b[30m"
#define ANSI_COLOR_RED        "\x1b[31m"
#define ANSI_COLOR_GREEN      "\x1b[32m"
#define ANSI_COLOR_YELLOW     "\x1b[33m"
#define ANSI_COLOR_BLUE       "\x1b[34m"
#define ANSI_COLOR_MAGENTA    "\x1b[35m"
#define ANSI_COLOR_CYAN       "\x1b[36m"

// Macros para facilitar o uso
#define BOLD(string)       ANSI_BOLD             string ANSI_RESET
#define BLACK(string)      ANSI_COLOR_BLACK      string ANSI_RESET // #000
#define BLUE(string)       ANSI_COLOR_BLUE       string ANSI_RESET // #00f
#define RED(string)        ANSI_COLOR_RED        string ANSI_RESET // #f00
#define GREEN(string)      ANSI_COLOR_GREEN      string ANSI_RESET // #0f0
#define YELLOW(string)     ANSI_COLOR_YELLOW     string ANSI_RESET // #ff0
#define MAGENTA(string)    ANSI_COLOR_MAGENTA    string ANSI_RESET // #f0f
#define CYAN(string)       ANSI_COLOR_CYAN       string ANSI_RESET // #0ff