; bootloader_on_funcscript.s - Bootloader FuncScript

; Definições e macros
DEFINE SYSTEM_INIT "init_system"
DEFINE LOAD_MODULE "load_module"
DEFINE START_MAIN "start_main"
DEFINE LOG_PREFIX "[BOOT] "

; Funções do bootloader

FUNC print_log(message)
    PRINT LOG_PREFIX, message
END_FUNC

FUNC init_system
    CALL print_log("Inicializando sistema FuncScript...")
    ; Aqui você poderia inicializar variáveis globais, configurações e FS
    CALL print_log("Sistema inicializado com sucesso!")
END_FUNC

FUNC load_module(module_name)
    CALL print_log("Carregando módulo: " + module_name)
    ; Simula a importação de arquivos .fs, .cc, .c, .h, .hpp ou .kern
    CALL import_module(module_name)
    CALL print_log("Módulo " + module_name + " carregado!")
END_FUNC

FUNC start_main
    CALL print_log("Iniciando função principal...")
    ; Aqui chamaria a função principal do seu código FuncScript
    CALL main
    CALL print_log("Execução finalizada!")
END_FUNC

; Função principal do bootloader
FUNC bootloader_main
    CALL init_system
    ; Carregando módulos essenciais
    CALL load_module("import.cc")
    CALL load_module("let.cc")
    CALL load_module("define_variable.cc")
    CALL load_module("stdbool.fs")
    CALL load_module("filesystem_on_funcscript.s")
    CALL start_main
END_FUNC

; Chamando o bootloader
CALL bootloader_main
