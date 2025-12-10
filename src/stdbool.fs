// stdbool.fs - Suporte a booleanos FuncScript
define true = 1
define false = 0

// Função para criar variáveis booleanas
func let_bool(name, value) {
    if value != true && value != false {
        print("Erro: valor deve ser true ou false")
    } else {
        let(name, value)
    }
}

// Exemplo de uso
let_bool("flag", true)
print("Flag:", flag)
