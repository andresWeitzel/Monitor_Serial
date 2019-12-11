#include "sistem.h"
#include "cmdOP.h"
#include "cmdAD.h"
#include "cmdP1.h"
#include "arduino.h"


extern String str; //var global definida en el .ino
extern bool watchDog;//La usaremos para el tittileo de loa leds
extern int lect_pot;



void cmdP1()
{
  String accion=str.substring(0,1); //se queda con  Q o S
  if(accion=="Q")
  {
    rP1();
  }
  if(accion=="S")
  {
    sP1();
  }
}

//mens de respuesta
void rP1()
{
  char str1[10];
  int numP1=str.substring(3,5).toInt(); //QP102 captura 02
  int x=getP1(numP1);
  sprintf(str1,">RP1%04d%d<",numP1,x);
  Serial.println(str1);
}

//SP1021
void sP1()
{
  int numP1=str.substring(3,7).toInt(); //SP1xxxx captura el valor del sp1
  setP1(numP1);
  rP1();
}

void setP1(int numP1)
{
  
   if(lect_pot > numP1){

    digitalWrite(OP00,1);
    delay(300);
    digitalWrite(OP00,0);
    delay(300);
    
  }
    
    
}

//devuelve el estado de la salida pasada como argumento
int getP1(int numP1)
{
  int resp;
  switch(numP1)
  {
    case 0:
    {
      resp=digitalRead(OP00);
      break;
    }
    case 1:
    {
      resp=digitalRead(OP01);
      break;
    }
    case 2:
    {
      resp=digitalRead(OP02);
      break;
    }
  }
  return resp;
}
