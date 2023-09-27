#include <iostream>
#include <vector>
#include <string>

class Livro {
public:
    std::string nome;
    float espessura;

    Livro(std::string n, float e) : nome(n), espessura(e) {}
};

class Prateleira {
public:
    std::vector<Livro> livros;

    bool adicionarLivro(Livro livro) {
        if (livros.size() < 6) {
            livros.push_back(livro);
            return true;
        }
        return false;
    }
};

class Estante {
public:
    std::vector<Prateleira> prateleiras;

    // Adiciona um livro na primeira prateleira que couber
    bool adicionarLivro(Livro livro) {
        for (int i = 0; i < prateleiras.size(); ++i) {
            Prateleira& prateleira = prateleiras[i];
            if (prateleira.adicionarLivro(livro)) {
                return true;
            }
        }
        // Se chegou aqui, nao coube em nenhuma prateleira
        Prateleira prateleira;
        prateleira.adicionarLivro(livro);
        prateleiras.push_back(prateleira);
        return true;
    }
};

int main() {
    Estante estante;

    // Adicionando livros
    estante.adicionarLivro(Livro("1984", 2.5));
    estante.adicionarLivro(Livro("Uma Breve Historia do Tempo", 1.8));
    estante.adicionarLivro(Livro("Uma Comovente Obra de Espantoso Talento", 1.2));
    estante.adicionarLivro(Livro("Muito Longe de Casa", 0.9));
    estante.adicionarLivro(Livro("Mau Comeco", 1.7));
    estante.adicionarLivro(Livro("Uma Dobra no Tempo", 2.0));
    estante.adicionarLivro(Livro("Selected Stories, 1968-1994 ", 1.5));
    estante.adicionarLivro(Livro("Voce esta ai, Deus? Sou eu, Margaret", 1.0));
     estante.adicionarLivro(Livro("1984", 2.5));
    estante.adicionarLivro(Livro("Uma Breve Historia do Tempo", 1.8));
    estante.adicionarLivro(Livro("Uma Comovente Obra de Espantoso Talento", 1.2));
    estante.adicionarLivro(Livro("Muito Longe de Casa", 0.9));
    estante.adicionarLivro(Livro("Mau Comeco", 1.7));
    estante.adicionarLivro(Livro("Uma Dobra no Tempo", 2.0));
    estante.adicionarLivro(Livro("Selected Stories, 1968-1994 ", 1.5));
    estante.adicionarLivro(Livro("Voce esta ai, Deus? Sou eu, Margaret", 1.0));
     estante.adicionarLivro(Livro("1984", 2.5));
    estante.adicionarLivro(Livro("Uma Breve Historia do Tempo", 1.8));
    estante.adicionarLivro(Livro("Uma Comovente Obra de Espantoso Talento", 1.2));
    estante.adicionarLivro(Livro("Muito Longe de Casa", 0.9));
    estante.adicionarLivro(Livro("Mau Comeco", 1.7));
    estante.adicionarLivro(Livro("Uma Dobra no Tempo", 2.0));
    estante.adicionarLivro(Livro("Selected Stories, 1968-1994 ", 1.5));
    estante.adicionarLivro(Livro("Voce esta ai, Deus? Sou eu, Margaret", 1.0));
     estante.adicionarLivro(Livro("1984", 2.5));
    estante.adicionarLivro(Livro("Uma Breve Historia do Tempo", 1.8));
    estante.adicionarLivro(Livro("Uma Comovente Obra de Espantoso Talento", 1.2));
    estante.adicionarLivro(Livro("Muito Longe de Casa", 0.9));
    estante.adicionarLivro(Livro("Mau Comeco", 1.7));
    estante.adicionarLivro(Livro("Uma Dobra no Tempo", 2.0));
    estante.adicionarLivro(Livro("Selected Stories, 1968-1994 ", 1.5));
    estante.adicionarLivro(Livro("Voce esta ai, Deus? Sou eu, Margaret", 1.0));
     estante.adicionarLivro(Livro("1984", 2.5));
    estante.adicionarLivro(Livro("Uma Breve Historia do Tempo", 1.8));
    estante.adicionarLivro(Livro("Uma Comovente Obra de Espantoso Talento", 1.2));
    estante.adicionarLivro(Livro("Muito Longe de Casa", 0.9));
    estante.adicionarLivro(Livro("Mau Comeco", 1.7));
    estante.adicionarLivro(Livro("Uma Dobra no Tempo", 2.0));
    estante.adicionarLivro(Livro("Selected Stories, 1968-1994 ", 1.5));
    estante.adicionarLivro(Livro("Voce esta ai, Deus? Sou eu, Margaret", 1.0));
     estante.adicionarLivro(Livro("1984", 2.5));
    estante.adicionarLivro(Livro("Uma Breve Historia do Tempo", 1.8));
    estante.adicionarLivro(Livro("Uma Comovente Obra de Espantoso Talento", 1.2));
    estante.adicionarLivro(Livro("Muito Longe de Casa", 0.9));
    estante.adicionarLivro(Livro("Mau Comeco", 1.7));
    estante.adicionarLivro(Livro("Uma Dobra no Tempo", 2.0));
    estante.adicionarLivro(Livro("Selected Stories, 1968-1994 ", 1.5));
    estante.adicionarLivro(Livro("Voce esta ai, Deus? Sou eu, Margaret", 1.0));
    

    //Mostrar estantes
    for (int i = 0; i < estante.prateleiras.size(); ++i) {
        Prateleira& prateleira = estante.prateleiras[i];
        std::cout << "Prateleira " << i << std::endl;
        for (int j = 0; j < prateleira.livros.size(); ++j) {
            Livro& livro = prateleira.livros[j];
            std::cout << "Livro " << j << ": " << livro.nome << std::endl;
        }
    }


    return 0;
}
