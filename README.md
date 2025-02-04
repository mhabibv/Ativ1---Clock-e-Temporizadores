# Semáforo com Raspberry Pi Pico W

Este projeto simula um semáforo utilizando um Raspberry Pi Pico W e LEDs conectados aos pinos GPIO. O semáforo alterna entre três estados: vermelho, amarelo e verde, com um tempo de 3 segundos para cada troca de sinal.

## Requisitos

- **Hardware:**
  - 1 Raspberry Pi Pico W
  - 3 LEDs (Vermelho, Amarelo e Verde)
  - 3 resistores de 330Ω
  - Fios de conexão

- **Software:**
  - Raspberry Pi Pico SDK
  - Ferramenta de compilação `CMake` e `Make`
  - Editor de código (ex: Visual Studio Code, Sublime Text)

## Conexões dos LEDs

Os LEDs devem ser conectados aos seguintes pinos GPIO do Raspberry Pi Pico:

- **Vermelho**: GPIO 13
- **Amarelo**: GPIO 12
- **Verde**: GPIO 11

Cada LED deve ser conectado a um resistor de 330Ω para limitar a corrente.

## Instalação e Compilação

1. **Configuração do ambiente de desenvolvimento**:
   Se você ainda não tiver o ambiente do Raspberry Pi Pico SDK configurado, siga as instruções do [site oficial](https://www.raspberrypi.org/documentation/pico/getting-started/).

2. **Clone o repositório do código**:
  git clone https://github.com/mhabibv/Ativ1---Clock-e-Temporizadores.git

3. **Compilação do programa**:
  Recomendada a extensão Raspberry Pi Pico que tem a função de compilação

4. **Transferência do código para o Raspberry Pi Pico W**:
Conecte o Raspberry Pi Pico W ao computador com o botão `BOOTSEL` pressionado. Isso fará com que o dispositivo seja reconhecido como uma unidade de armazenamento USB.

Copie o arquivo `.uf2` gerado pela compilação para o Raspberry Pi Pico W.

## Funcionamento

O código acende o LED vermelho inicialmente e alterna para o LED amarelo após 3 segundos e, em seguida, para o LED verde. O ciclo se repete indefinidamente, mudando os LEDs a cada 3 segundos.

### **Detalhes do código:**
- O código utiliza um temporizador repetitivo para alterar o estado dos LEDs a cada 3 segundos.
- A função `alterar_sinal()` é chamada a cada 3 segundos, alternando entre os estados `VERMELHO`, `AMARELO` e `VERDE`.
- As mensagens sobre o estado do semáforo são impressas no terminal a cada segundo.




