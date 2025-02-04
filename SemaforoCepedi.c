#include "pico/stdlib.h"
#include "hardware/timer.h"
#include <stdio.h>

#define TEMPO_TROCA_SINAL 3000  // Tempo em milissegundos para troca de sinal

typedef enum { VERMELHO, AMARELO, VERDE } EstadoSemaforo;

volatile EstadoSemaforo estado_semaforo = VERMELHO;
volatile uint8_t pinos_leds[3] = {13, 12, 11};  

void configurar_leds();
bool alterar_sinal(struct repeating_timer *t);

int main() {

    stdio_init_all();
    configurar_leds();

    struct repeating_timer temporizador;
    add_repeating_timer_ms(TEMPO_TROCA_SINAL, alterar_sinal, NULL, &temporizador);

    gpio_put(pinos_leds[VERMELHO], 1);  // Começa com o vermelho aceso

    while (1) {
        sleep_ms(1000);
        printf("Sinal atual: %s\n", 
               estado_semaforo == VERMELHO ? "Vermelho" : 
               estado_semaforo == AMARELO ? "Amarelo" : "Verde");
    }
}

void configurar_leds() {
    for (uint8_t i = 0; i < 3; i++) {
        gpio_init(pinos_leds[i]);
        gpio_set_dir(pinos_leds[i], GPIO_OUT);
        gpio_put(pinos_leds[i], 0);
    }
}

bool alterar_sinal(struct repeating_timer *t) {
    // Apaga todos os LEDs
    for (uint8_t i = 0; i < 3; i++) {
        gpio_put(pinos_leds[i], 0);
    }

    // Alterna para o próximo estado do semáforo
    if (estado_semaforo == VERMELHO) {
        estado_semaforo = AMARELO;
    } else if (estado_semaforo == AMARELO) {
        estado_semaforo = VERDE;
    } else {
        estado_semaforo = VERMELHO;  
    }

    // Acende o LED correspondente ao novo estado
    gpio_put(pinos_leds[estado_semaforo], 1);

    return true;
}
