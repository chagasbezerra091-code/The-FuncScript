// define_variable.cc - Define variáveis FuncScript
#include <iostream>
#include <string>
#include <unordered_map>

class DefineVariable {
public:
    std::unordered_map<std::string, std::string> vars;

    // Função para definir qualquer variável
    void define(const std::string& name, const std::string& value) {
        if (vars.find(name) != vars.end()) {
            std::cerr << "Aviso: Variável '" << name << "' já existe. Atualizando valor.\n";
        }
        vars[name] = value;
        std::cout << "Variável '" << name << "' definida com valor: " << value << "\n";
    }

    // Recuperar valor
    std::string getValue(const std::string& name) {
        if (vars.find(name) == vars.end()) {
            std::cerr << "Erro: Variável '" << name << "' não encontrada.\n";
            return "";
        }
        return vars[name];
    }
};

// Exemplo de uso
int main() {
    DefineVariable dv;
    dv.define("pi", "3.14159");
    dv.define("language", "FuncScript");

    std::cout << "Valor de pi: " << dv.getValue("pi") << "\n";
    std::cout << "Valor de language: " << dv.getValue("language") << "\n";
    return 0;
}
