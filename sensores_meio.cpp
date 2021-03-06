#include "sensores_meio.h"
#include <tcs3200.h>

//Instancias e pinos dos sensores Utilizados;
tcs3200 colorLeft = { 29, 30, 31, 32, 33 };
tcs3200 colorRight = { 35, 36, 37, 38, 39 };
int sensores_meio[3] = { 25 , 27 , 26 };

  
void setSensoresMeio()
{
  for(int i = 0; i < 3; ++i) {
    int index = i;
    pinMode(sensores_meio[index], INPUT); 
   }
}
int sens_pontaDireita() {
  return digitalRead(sensores_meio[0]);
}
int sens_direita() {
  return filter_color_line_right(getWhiteRight());
}
int sens_meio() {
  return digitalRead(sensores_meio[1]);
}
int sens_esquerda() {
  return filter_color_line(getWhiteLeft());
}
int sens_pontaEsquerda() {
  return digitalRead(sensores_meio[2]);
}

int getColorLeft() {
  const int intervalo = 100;
  int estado_anterior = 0;
   
  if (millis() - estado_anterior > intervalo) {
    estado_anterior = millis();
    int green = colorLeft.colorRead('g'); 
    return green;
  }
}

int getColorRight(){
  const int intervalo = 100;
  int estado_anterior = 0;
  
  if (millis() - estado_anterior > intervalo) {
    estado_anterior = millis();
    int green = colorRight.colorRead('g'); 
    return green;
  }
}
int getWhiteRight() {
   int white = colorRight.colorRead('c');
   return white;
}
int getWhiteLeft() {
  int white = colorLeft.colorRead('c');
  return white;
}
bool filter_color_green(int green, int white) {
  if(white <= 50){
    return false;  
  }
  if(green <= 20){
     return false;
  }
  return true;
}
bool verificar_verde(char lado){
  int counter = 0;
  switch(lado) {
    case 'L':
      for(int i = 200; i >= 0; i--){
        if(filter_color_green(getColorLeft(), getWhiteLeft())){
             counter++;
        }
      }
      break;
     case 'R':
     for(int i = 200; i >= 0; i--){
       if(filter_color_green(getColorRight(), getWhiteRight())){
         counter++;
       }
      }
      break;
   }
  if(counter <= 100){
    return false;
   }
  return true;
}
int filter_color_line_right(int white) {
  if(white < 100)
    {
      return 1;
    }
  else
  {
    return 0;
  }
}
int filter_color_line(int white) {
  if(white < 28) {
    return 1;
  }
  else{
    return 0;
  }
}
