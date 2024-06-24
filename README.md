# PRS Simple Pedal - Firmware

Um projeto em desenvolvimento de um pedal simples com três eixos construidos com base em células de carga. 

O objetivo é ser um pedal básico para testes diversos.

### Pré-requisitos

Componentes físicos (mínimos) necessários para conseguir testar o firmware:

```
1x Módulo HX711
1x Célula de carga
1x Placa STM32F103C8T6 (modelo que utilizei, mas pode ser outra placa de sua escolha)
```

### Configuração

* Abra os arquivos do projeto na sua IDE preferida (recomendação: VS CODE)
  
* No arquivo "platformio" você pode alterar para a placa que desejar (verificar a compatibiladade com as bibliotecas utilizadas)
```C++
platform = ststm32
board = genericSTM32F103C8
```

* No arquivo "project_name_config" altere os pinos para os utilizados em seus testes
```C++
#define DAT1 PB1
#define CLK1 PB0

#define DAT2 PB11
#define CLK2 PB10

#define DAT3 PB12
#define CLK3 PB13
```

* É interessante fazer testes na sua célula de carga para obter o melhor valor de calibração da sua célula de carga
```C++
#define CALIB_VALUE 82400 // Define o fator de calibração da célula de carga que eu usei
#define CALIB_MAX 255 // Define o fator de calibração máximo dos módulos HX711
#define CALIB_MIN 100 // Define o fator de calibração mínimo dos módulos HX711
#define CALIB_MULT 10 // Define o múltiplo dos valores tratados que serão enviados para o joystick
```

Depois e só compilar o código para sua placa de uso

## Testes

Após passar o código para sua placa e a mesma estiver recebendo e lendo informações das células de carga, você monitorar esses valores no joystick do windows (se este for seu sistema operacional).

Digite o comandos "win + R" e digite o comando "joy.cpl" para abrir os monitoramento dos contraladores de jogo.

Na parte superior da janela você poderá ver os eixos variando conforme a aplicação de determinada força na célula de carga.
![Captura de tela 2024-06-24 112346](https://github.com/vinicitadin/prs_simple_pedal_fw/assets/167343994/0f7deeea-aec8-4548-8466-30d4806ad946)


## Construído com

* [Visual Studio Code](https://code.visualstudio.com/) - IDE utilizada
* [PlatformIO](https://platformio.org/) - Extensão utilizada no VS Code
