## Exemplo Blink com Testes Unitarios

Esse é um exemplo básico para um projeto com a placa Franzininho C0.

Foram configurados os seguintes periféricos:
- LED1 - Pino PB6 - OUTPUT
- LED2 - Pino PB7 - OUTPUT
- Button - Pino PA8 - INPUT - PULL UP
- Clock do sistema: interno 48 MHz

Aplicação exemplo:

Inverte o estado do LED 1 a cada 1 segundo
Le o estado do Botão, se pressionado inverte o LED2

## Software

STM32CubeIDE Version: 1.17.0

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
│   ├── Inc
│   └── Src
└── test
    ├── cpputest
    └── Src
```

### `Core`

Primariamente arquivos gerados pelo STM32CubeIDE, incluindo configuração da lib HAL para os periféricos ativos, códigos de inicialização e função `main`.

É geralmente o local para implementação da camada de aplicação e bibliotecas do projeto.

### `Drivers`

Bibliotecas STM32 HAL DRIVER e CMSIS fornecidas pelo STM32CubeIDE. Não possui código customizado pelo projeto.

### `Lib`

Local dedicado para implementação de códigos de aplicação e bibliotecas do projeto. Implementações desta pasta estarão disponíveis para o projeto de firmware e também para execução nos testes unitários.

### `Test`

Destinado à implementação de testes unitários e mocks de bibliotecas.

## Testes

Este repositório possui suporte à implementação de testes unitários utilizando o framework [CppUTest](https://cpputest.github.io/). Este componente é importado durante a configuração do projeto pelo CMake utilizando o módulo FetchContent.

Os testes estão implementados na pasta `Test` e validam os arquivos implementados na pasta `Lib`.

Códigos de teste tem as mesmas configurações de include utilizadas pela aplicação e suas bibliotecas, ou seja, códigos do próprio projeto e bibliotecas fornecidas pelo STM32CubeIDE.

A configuração para compilação dos testes utiliza CMake, sendo completamente independente do projeto principal utilizado pelo STM32CubeIDE.

### Requisitos

- `CMake`
- `gcc` e `g++`
- `gcc-multilib` e `g++-multilib` (suporte à compilação 32bits)

Verificação de dependências:
```bash
$ cmake --version

$ gcc --version  
gcc (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0

$ g++ --version
g++ (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0

# Para sistemas baseados em Debian
$ apt list --installed | grep multilib
g++-multilib/jammy,now 4:11.2.0-1ubuntu1 amd64 [installed]
gcc-multilib/jammy,now 4:11.2.0-1ubuntu1 amd64 [installed]
```

Sugestão de instalação para sistemas baseados em Debian:
```bash
$ sudo apt update
$ sudo apt install -y build-essential cmake gcc-multilib g++-multilib
```

### Compilação e execução

```bash
# Configurar projeto CMake
$ cmake -B build .

# Compilar
$ cmake --build build

# Executar testes
$ ./build/Test/run_tests -v -c
```
