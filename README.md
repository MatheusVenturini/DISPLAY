git # Projeto: Controle de LEDs e Interação com PC no RP2040

Este projeto explora diferentes funcionalidades do microcontrolador RP2040, com foco em **entrada de caracteres via PC**, **controle de botões físicos** e **gerenciamento de LEDs e displays**. As principais funcionalidades incluem entrada de dados pelo **Serial Monitor**, exibição no **display SSD1306**, controle de **LEDs RGB** e uma matriz de LEDs **WS2812**. A interação com os botões é feita por meio de interrupções, com tratamento de **bouncing** implementado via software. Para comunicação, utilizamos os protocolos **UART** e **I2C**.

## Funcionalidades

### Entrada de Caracteres via PC
- O usuário digita caracteres no **Serial Monitor** do VS Code, que são enviados para o microcontrolador.
- Cada caractere digitado é exibido no **display SSD1306**.
- Caracteres numéricos (0 a 9) acionam símbolos correspondentes na matriz de LEDs **5x5 WS2812**.

### Interação com o Botão A
- **Alterna o estado** do LED RGB **Verde** (ligado/desligado).
- O estado do LED é exibido no **display SSD1306**.
- Uma mensagem descritiva é enviada ao **Serial Monitor** para indicar a mudança.

### Interação com o Botão B
- **Alterna o estado** do LED RGB **Azul** (ligado/desligado).
- O estado do LED é mostrado no **display SSD1306**.
- Uma mensagem descritiva é enviada ao **Serial Monitor** para informar a alteração.

### Outros Recursos
- **Controle de LEDs WS2812**: Exibição de padrões visuais em resposta a entradas numéricas.
- **Debouncing via Software**: Tratamento do efeito de bouncing nos botões de forma eficiente.
- **Comunicação UART**: Transmissão de dados e mensagens descritivas ao Serial Monitor.
- **Display SSD1306 (I2C)**: Exibição de caracteres e mensagens informativas com suporte a letras maiúsculas e minúsculas.

## Tecnologias Utilizadas

- **Microcontrolador**: Raspberry Pi Pico (RP2040)
- **Linguagem de Programação**: C (utilizando o **Pico SDK**)
- **Ambiente de Desenvolvimento**: Visual Studio Code (VSCode) com Pico SDK
- **Hardware**:
  - **Display SSD1306** (128x64 pixels) com comunicação I2C
  - **Matriz de LEDs WS2812** (5x5)
  - **LEDs RGB comuns**
  - **Botões físicos**

## Instruções de Uso

**Entrada de Caracteres**:

- Abra o **Serial Monitor no VS Code**.
- Digite caracteres individualmente, que serão exibidos no display SSD1306.
- Números de 0 a 9 ativam os símbolos correspondentes na matriz WS2812.

**Interação com o Botão A**:

- Pressione o botão A para alternar o estado do LED RGB Verde.
- O estado será exibido no display e uma mensagem será enviada ao Serial Monitor.

**Interação com o Botão B**:

- Pressione o botão B para alternar o estado do LED RGB Azul.
- O estado será exibido no display e uma mensagem será enviada ao Serial Monitor.

**Feedback Visual e Auditivo**:

- Observe as mudanças no display, LEDs e no Serial Monitor conforme interage com os botões e caracteres.

**LINK DOS VÍDEOS:** 

- https://youtube.com/shorts/Tbu5z-IPoCY?si=K4kDmrXccKXMPK4L
-https://youtube.com/shorts/_S1kGdJBPKI?si=MrggB9mVcV45lK8R