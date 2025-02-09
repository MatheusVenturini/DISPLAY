#ifndef INIT_I2C_H
#define INIT_I2C_H

#include <stdlib.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "GPIO.h"

#define I2C_PORT i2c1
#define I2C_SDA 14
#define I2C_SCL 15
#define endereco 0x3C
ssd1306_t ssd;
bool cor = true;

void i2c()
{
    // I2C Initialisation. Using it at 400Khz.
    i2c_init(I2C_PORT, 400 * 1000);

    gpio_set_function(I2C_SDA, GPIO_FUNC_I2C);                    // Set the GPIO pin function to I2C
    gpio_set_function(I2C_SCL, GPIO_FUNC_I2C);                    // Set the GPIO pin function to I2C
    gpio_pull_up(I2C_SDA);                                        // Pull up the data line
    gpio_pull_up(I2C_SCL);                                        // Pull up the clock line
    ssd1306_init(&ssd, WIDTH, HEIGHT, false, endereco, I2C_PORT); // Inicializa o display
    ssd1306_config(&ssd);                                         // Configura o display
    ssd1306_send_data(&ssd);                                      // Envia os dados para o display

    // Limpa o display. O display inicia com todos os pixels LIGADOS.
    ssd1306_fill(&ssd, true);
    ssd1306_send_data(&ssd);
}

void desenhar(char c) // atualiza o display com o caractere inserido pelo usuario
{
    ssd1306_fill(&ssd, cor);
    ssd1306_rect(&ssd, 3, 3, 122, 58, !cor, cor);
    ssd1306_draw_string(&ssd, "CARACTERE", 28, 10);
    ssd1306_draw_string(&ssd, &c, 63, 30);
    ssd1306_draw_string(&ssd, "ACIONADO", 20, 48);
    ssd1306_send_data(&ssd);
}

void acionamento_botoes(bool led, bool verde) //trata o acionamento dos botoes, verificando estado e cor dos leds
{
    if (verde)
    {
        gpio_put(LED_BLUE, false);
        gpio_put(LED_GREEN, !gpio_get(LED_GREEN));
        if (led)
        {
            ssd1306_fill(&ssd, cor);
            ssd1306_rect(&ssd, 3, 3, 122, 58, !cor, cor);
            ssd1306_draw_string(&ssd, "BOTAO A", 35, 10);
            ssd1306_draw_string(&ssd, "ACIONADO", 29, 30);
            ssd1306_draw_string(&ssd, "VERDE LIGADO", 16, 48);
            ssd1306_send_data(&ssd);
            printf("Led VERDE foi ligado\n");
        }
        else
        {
            ssd1306_fill(&ssd, cor);
            ssd1306_rect(&ssd, 3, 3, 122, 58, !cor, cor);
            ssd1306_draw_string(&ssd, "BOTAO A", 35, 10);
            ssd1306_draw_string(&ssd, "ACIONADO", 29, 30);
            ssd1306_draw_string(&ssd, "VERDE OFF", 25, 48);
            ssd1306_send_data(&ssd);
            printf("Led VERDE foi desligado\n");
        }
    }
    else
    {
        gpio_put(LED_GREEN, false);
        gpio_put(LED_BLUE, !gpio_get(LED_BLUE));
        if (led)
        {
            ssd1306_fill(&ssd, cor);
            ssd1306_rect(&ssd, 3, 3, 122, 58, !cor, cor);
            ssd1306_draw_string(&ssd, "BOTAO B", 35, 10);
            ssd1306_draw_string(&ssd, "ACIONADO", 29, 30);
            ssd1306_draw_string(&ssd, "AZUL ACESSO", 16, 48);
            ssd1306_send_data(&ssd);
            printf("Led AZUL foi ligado\n");
        }
        else
        {
            ssd1306_fill(&ssd, cor);
            ssd1306_rect(&ssd, 3, 3, 122, 58, !cor, cor);
            ssd1306_draw_string(&ssd, "BOTAO B", 35, 10);
            ssd1306_draw_string(&ssd, "ACIONADO", 29, 30);
            ssd1306_draw_string(&ssd, "AZUL OFF", 25, 48);
            ssd1306_send_data(&ssd);
            printf("Led AZUL foi desligado\n");
        }
    }
}
#endif