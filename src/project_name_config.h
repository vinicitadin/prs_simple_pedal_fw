#ifndef PROJECT_NAME_CONFIG_H
#define PROJECT_NAME_CONFIG_H

#define CALIB_VALUE 82400 // Define o fator de calibração da célula de carga que eu usei
#define CALIB_MAX 255 // Define o fator de calibração máximo dos módulos HX711
#define CALIB_MIN 100 // Define o fator de calibração mínimo dos módulos HX711
#define CALIB_MULT 10 // Define o múltiplo dos valores tratados que serão enviados para o joystick

// Definindo as pinagens dos sensores

#define DAT1 PB1
#define CLK1 PB0

#define DAT2 PB11
#define CLK2 PB10

#define DAT3 PB12
#define CLK3 PB13

#endif 
