# 🛡️ so_long – A 2D Adventure Game

> Projeto desenvolvido como parte do currículo da 42 School  
> Um mini-jogo 2D em C utilizando a biblioteca gráfica MiniLibX

---

## 🎮 Sobre o Jogo

**so_long** é um jogo estilo Donkey Kong 2D onde você controla um escudeiro em uma missão épica:  
colecionar todos os baús mágicos, derrotar inimigos e escapar por uma porta secreta.  
Cada passo conta, e os inimigos não vão facilitar sua jornada!

---

## 🧩 Funcionalidades

✅ Mapa carregado a partir de arquivo `.ber`  
✅ Validação completa do mapa (bordas, elementos, caminhos válidos)  
✅ Movimento do jogador com animações (WASD)  
✅ Inimigos que se movem e atacam automaticamente 
✅ Sistema de armadilhas que matam jogador ao encostar 
✅ Sistema de combate: o jogador pode matar inimigos  
✅ Porta que abre após coletar todos os baús  
✅ Contador de movimentos exibido na tela  
✅ Detecção de vitória ou derrota (game over)

---

## 🗺️ Estrutura do Projeto

```
so_long/
├── textures/           # Sprites do jogador, inimigos, baús, etc.
├── maps/               # Mapas .ber para testar
├── movement/           # Códigos de movimentação (jogador, inimigos, teclas)
├── srcs/               # Códigos principais do jogo
├── utils/              # Funções auxiliares e verificações
├── includes/           # Arquivos .h (headers)
├── Makefile            # Compilador do jogo
├── so_long.c           # Função principal
└── README.md           # Este arquivo
```

---

## 🧠 Como Jogar

- **WASD**: movimenta o personagem
- **ESC**: sai do jogo
- **Objetivo**:  
  1. Colete todos os baús (💰)  
  2. Evite ou mate os inimigos (👾)  
  3. A porta (🚪) abrirá após coletar todos os baús  
  4. Saia pela porta para vencer!

---

## 🏁 Como Compilar e Rodar

### 🔧 Requisitos

- Linux com GCC
- MiniLibX instalada (use a versão da 42 ou ajuste no Makefile)

### 📦 Instalação

Tem que baixar tambem a pasta mlx senao nao roda.
Basta baixar a pasta mlx , se o nome da pasta nao for este mudar para mlx e deixar na root do projeto.

```bash
git clone https://github.com/vinimoura99/so_long.git
cd so_long
make
```

### 🚀 Executar o jogo

```bash
./so_long maps/mapa1.ber
```

---

## ✅ Regras do Mapa `.ber`

O mapa deve conter:

- 1 jogador (`P`)
- Pelo menos 1 saída (`E`)
- Pelo menos 1 colecionável (`C`)
- Bordas fechadas com `1`
- Caminho válido para todos os elementos

---

## 🧪 Exemplo de Mapa

```
1111111
1P0C0E1
1010101
1C0C0C1
1111111
```

---

## 🛠️ Makefile

| Comando      | Ação                            |
|--------------|---------------------------------|
| `make`       | Compila o jogo                  |
| `make clean` | Remove objetos                  |
| `make fclean`| Remove binário e objetos        |
| `make re`    | Recompila do zero               |

---

## 👾 Créditos

Desenvolvido por **Vinícius Moura**  
Aluno da [42 Porto](https://www.42porto.com/)  
GitHub: [vinimoura99](https://github.com/vinimoura99)

---

## 📜 Licença

Este projeto está sob a licença MIT.  
Sinta-se livre para estudar, modificar e compartilhar!

---

## 🧠 Observações Finais

Este projeto foi feito com foco em lógica, manipulação de arquivos, gerenciamento de memória e uso de bibliotecas gráficas simples.  
É um dos primeiros passos na criação de jogos em C e no uso de *event loops*, *rendering*, e *input handling*.

---
