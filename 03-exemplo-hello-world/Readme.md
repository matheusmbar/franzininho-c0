## Exemplo Hello World

Envia uma mensagem pela serial durante inicialização da placa.

Foram configurados os seguintes periféricos:
- USART1:	PA9 - TX; PA10 - RX
- Clock do sistema: interno 48 MHz

## Software

STM32CubeIDE Version: 1.13.0

## Estrutura do projeto

```bash
$ tree -d -L 2
.
├── Core
│   ├── Inc
│   ├── Src
│   └── Startup
├── Drivers
│   ├── CMSIS
│   └── STM32C0xx_HAL_Driver
├── Lib
│   ├── include
│   └── src
└── test
    ├── cpputest
    └── src
```

### `Core`

Primariamente arquivos gerados pelo STM32CubeIDE, incluindo configuração da lib HAL para os periféricos ativos, códigos de inicialização e função `main`.

É geralmente o local para implementação da camada de aplicação e bibliotecas do projeto.

### `Drivers`

Bibliotecas STM32 HAL DRIVER e CMSIS fornecidas pelo STM32CubeIDE. Não possui código customizado pelo projeto.

### `Lib`

Local dedicado para implementação de códigos de aplicação e bibliotecas do projeto. Implementações desta pasta estarão disponíveis para o projeto de firmware e também para execução nos testes unitários.

### `test`

Destinado à implementação de testes unitários e mocks de bibliotecas.

## Testes

Este repositório possui suporte à implementação de testes unitários utilizando o framework [CppUTest](https://cpputest.github.io/). Este componente é importado como um git submodule, portanto é necessário inicializá-lo após clonar o repositório com este comando:

```bash
$ git submodule init && git submodule update
```

Os testes estão implementados na pasta `test` e validam os arquivos implementados na pasta `Lib`.

Códigos de teste tem as mesmas configurações de include utilizadas pela aplicação e suas bibliotecas, ou seja, códigos do próprio projeto e bibliotecas fornecidas pelo STM32CubeIDE.

A configuração para compilação dos testes utiliza CMake, sendo completamente independente do projeto principal.

Seguir este procedimento para

```bash
# Configurar projeto CMake
$ cmake -B build

# Compilar
$ cmake --build build

# Executar testes
$ ./build/test/run_tests -v -c
```
