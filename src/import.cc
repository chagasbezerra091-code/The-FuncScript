// import.cc - Gerenciador de imports da linguagem FuncScript
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>

namespace fs = std::filesystem;

class ImportManager {
public:
    // Extensões suportadas pelo FuncScript
    const std::vector<std::string> supportedExtensions = {
        ".fs",     // FuncScript
        ".cc",     // C++
        ".c",      // C
        ".h",      // Header C
        ".hpp",    // Header C++
        ".kern"    // KernelScript
    };

    // Carrega um arquivo dado o caminho
    bool loadFile(const std::string& path) {
        std::string ext = getExtension(path);
        if (!isSupported(ext)) {
            std::cerr << "Erro: Extensão de arquivo não suportada: " << ext << "\n";
            return false;
        }

        std::ifstream file(path);
        if (!file.is_open()) {
            std::cerr << "Erro: Não foi possível abrir o arquivo: " << path << "\n";
            return false;
        }

        std::string line;
        while (std::getline(file, line)) {
            // Aqui você pode implementar a lógica de parsing de cada linguagem
            // Por enquanto, só vamos imprimir o conteúdo
            std::cout << line << "\n";
        }

        file.close();
        return true;
    }

private:
    // Verifica se a extensão é suportada
    bool isSupported(const std::string& ext) {
        for (const auto& s : supportedExtensions) {
            if (s == ext) return true;
        }
        return false;
    }

    // Retorna a extensão de um arquivo
    std::string getExtension(const std::string& path) {
        size_t pos = path.rfind('.');
        if (pos == std::string::npos) return "";
        return path.substr(pos);
    }
};

int main() {
    ImportManager manager;

    // Exemplo de uso
    manager.loadFile("exemplo.fs");
    manager.loadFile("codigo.cc");
    manager.loadFile("kernel.kern");

    return 0;
}
