; filesystem_on_funcscript.s - Sistema de arquivos FuncScript

; Macros úteis
DEFINE FS_READ "read"
DEFINE FS_WRITE "write"
DEFINE FS_DELETE "delete"
DEFINE FS_EXISTS "exists"

; Funções básicas de filesystem

FUNC fs_create_file(file_name, content)
    ; Cria um arquivo com conteúdo
    PRINT "Criando arquivo: ", file_name
    CALL FS_WRITE_FILE(file_name, content)
END_FUNC

FUNC fs_read_file(file_name)
    ; Lê o conteúdo de um arquivo
    IF CALL FS_FILE_EXISTS(file_name) == FALSE
        PRINT "Erro: arquivo não encontrado -> ", file_name
        RETURN ""
    END_IF
    RETURN CALL FS_READ_FILE(file_name)
END_FUNC

FUNC fs_delete_file(file_name)
    ; Deleta um arquivo
    IF CALL FS_FILE_EXISTS(file_name) == FALSE
        PRINT "Erro: arquivo não encontrado -> ", file_name
        RETURN
    END_IF
    CALL FS_DELETE_FILE(file_name)
    PRINT "Arquivo deletado: ", file_name
END_FUNC

FUNC fs_file_exists(file_name)
    ; Verifica se o arquivo existe
    RETURN CALL FS_FILE_EXISTS(file_name)
END_FUNC

FUNC fs_list_dir(directory)
    ; Lista arquivos dentro de um diretório
    PRINT "Listando arquivos em: ", directory
    RETURN CALL FS_LIST_DIRECTORY(directory)
END_FUNC

; Exemplos de uso
CALL fs_create_file("teste.txt", "Olá FuncScript!")
VAR content = CALL fs_read_file("teste.txt")
PRINT "Conteúdo de teste.txt: ", content
CALL fs_delete_file("teste.txt")
