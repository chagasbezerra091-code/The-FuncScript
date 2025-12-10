// let.cc - Gerenciador de declaração de variáveis FuncScript
#include <iostream>
#include <string>
#include <unordered_map>

class VariableManager {
public:
    // Armazena variáveis: nome -> valor (como string por enquanto)
    std::unordered_map<std::string, std::string> variables;

    // Declarar variável com let
    void let(const std::string& name, const std::string& value) {
        if (variables.find(name) != variables.end()) {
            std::cerr << "Aviso: Variável '" << name << "' já existe. Atualizando valor.\n";
        }
        variables[name] = value;
        std::cout << "Variável '" << name << "' declarada com valor: " << value << "\n";
    }

    // Obter valor da variável
    std::string get(const std::string& name) {
        if (variables.find(name) == variables.end()) {
            std::cerr << "Erro: Variável '" << name << "' não encontrada.\n";
            return "";
        }
        return variables[name];
    }

    // Mostrar todas as variáveis
    void showAll() {
        std::cout << "--- Variáveis declaradas ---\n";
        for (const auto& [key, value] : variables) {
            std::cout << key << " = " << value << "\n";
        }
        std::cout << "----------------------------\n";
    }
};

// Exemplo de uso
int main() {
    VariableManager vm;
    vm.let("x", "10");
    vm.let("name", "FuncScript");
    vm.showAll();

    std::cout << "Valor de x: " << vm.get("x") << "\n";
    return 0;
}
