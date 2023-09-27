#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Livro {
public:
    std::string nome;
    float espessura;

    Livro(std::string n, float e) : nome(n), espessura(e) {}
};

class Prateleira {
public:
    std::vector<Livro> livros;
    float tamanho = 90.0;

    bool adicionarLivro(Livro livro) {
        if (livros.size() < 6 && tamanho >= livro.espessura) {
            livros.push_back(livro);
            tamanho -= livro.espessura;
            return true;
        }
        return false;
    }
};

class Estante {
public:
    std::vector<Prateleira> prateleiras;
    float tamanho = 90.0;

    bool adicionarLivro(Livro livro) {
        for (int i = 0; i < prateleiras.size(); ++i) {
            Prateleira& prateleira = prateleiras[i];
            if (prateleira.adicionarLivro(livro)) {
                return true;
            }
        }
       
        Prateleira prateleira;
        if(prateleira.adicionarLivro(livro)){
            prateleiras.push_back(prateleira);
            return true;
        }
        return false;
    }
};

int main() {
     Estante estante;
     std::string entrada = "/O Senhor dos Aneis,8.5/Harry Potter e a Pedra Filosofal,5.2/Crime e Castigo,6.7/Guerra e Paz,7.8/Moby Dick,4.9/O Pequeno Prencipe,3.2\\O Codigo Da Vinci,4.7/Guinness World Records,2.8/As Cronicas de Gelo e Fogo,9.1/O Alquimista,3.5/Em Busca do Tempo Perdido,8.9\\Orgulho e Preconceito,5.5/Dom Quixote,7.2/A Revolucao dos Bichos,2.4/O Hobbit,4.0/O Iluminado,3.7\\";
    
    std::string livroNome = "";
    std::string livroEspessuraStr = "";
    bool capturandoNome = true;

    for (char c : entrada) {
        if (c == '/' || c == '\\') {
            if (livroNome != "" && livroEspessuraStr != "") {
                float livroEspessura = std::stof(livroEspessuraStr);
                estante.adicionarLivro(Livro(livroNome, livroEspessura));
                livroNome = "";
                livroEspessuraStr = "";
                capturandoNome = true;
            }
        } else if (c == ',') {
            capturandoNome = false;
        } else {
            if (capturandoNome) {
                livroNome += c;
            } else {
                livroEspessuraStr += c;
            }
        }
    }
   

    for (int i = 0; i < estante.prateleiras.size(); ++i) {
        Prateleira& prateleira = estante.prateleiras[i];
        std::cout << "Prateleira " << i << std::endl;
        for (int j = 0; j < prateleira.livros.size(); ++j) {
            Livro& livro = prateleira.livros[j];
            std::cout << "    " << livro.nome << std::endl;
        }
    }

    std::cout << std::endl;
    //ordena
    for (int i = 0; i < estante.prateleiras.size(); ++i) {
        Prateleira& prateleira = estante.prateleiras[i];
        std::sort(prateleira.livros.begin(), prateleira.livros.end(), [](Livro& a, Livro& b) {
            return a.nome < b.nome;
        });
    }

    //imprime
    for (int i = 0; i < estante.prateleiras.size(); ++i) {
        Prateleira& prateleira = estante.prateleiras[i];
        std::cout << "Prateleira " << i << std::endl;
        for (int j = 0; j < prateleira.livros.size(); ++j) {
            Livro& livro = prateleira.livros[j];
            std::cout << "    " << livro.nome << std::endl;
        }
    }
}
