; #define_on_funcscript.s - Macros e constantes FuncScript

; Exemplo de macro/define
; Sintaxe: DEFINE nome valor
; O interpretador FuncScript vai substituir automaticamente

DEFINE TRUE 1
DEFINE FALSE 0
DEFINE PI 3.14159
DEFINE APP_NAME "FuncScript"

; Uso de macro em "código FuncScript"
; Aqui a ideia é que o interpretador substitua antes da execução

; Exemplo de função usando macros
FUNC print_constants
    PRINT "TRUE = ", TRUE
    PRINT "FALSE = ", FALSE
    PRINT "PI = ", PI
    PRINT "APP_NAME = ", APP_NAME
END_FUNC

; Chamando a função
CALL print_constants
