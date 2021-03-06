/*
 * 
 */

#include "frequencimetro.h"
#include "capacimetro.h"
#include "lcd_16x2.h"
#include "btns.h"


#define frq_meter 1
#define cap_meter 2
#define res_meter 3
#define ind_meter 4

btn_matrix botao1(btn1,PA0);
btn_matrix botao2(btn2,PA0);
btn_matrix botao3(btn3,PA0);
btn_matrix botao4(btn4,PA0);

float freq_refresh = 0.0;
int select_funcao=1;

HardwareTimer timer_4(4);//usa o timer 4

void setup()
{
  Serial.begin(230400);
    // define interrupção canal 1
    timer_4.pause();
    timer_4.setPeriod(5);//em us, calcula automaticamente prescale e overflow                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
    timer_4.setChannel1Mode(TIMER_OUTPUT_COMPARE);
    timer_4.setCompare(TIMER_CH1, 1);  
    timer_4.attachCompare1Interrupt(handler_get_freq);
    timer_4.refresh();
    timer_4.resume();

    
   //Define o número de colunas e linhas do LCD
  init_frequencimetro();
  init_lcd_16x2();
  pinMode(PB1,PWM);//debug

  
  
  //setStrings("str1","str2");//debug
 
}
 
void loop()
{
  
  if(botao1.isPressed())select_funcao=frq_meter;
  if(botao2.isPressed())select_funcao=cap_meter;
  if(botao3.isPressed())select_funcao=res_meter;
  if(botao4.isPressed())select_funcao=ind_meter;

  switch(select_funcao)
  {
    case frq_meter:setStrings("Frequencia (Hz)",(String)freq_refresh);break;
    case cap_meter:setStrings("Capacitor  (F)",getCapString(freq_refresh));break;
    case res_meter:setStrings("Resistor   (R)", (String)freq_refresh);break;
    case ind_meter:setStrings("Indutor    (L)", (String)freq_refresh);break;
  }

 //setStrings((String)getFreq()+"Hz",(String)getPeriodo()+"us");
   
   //setStrings("Capacitor (uF)",(String)(calcCapacitor(getFreq())*1000000));
 //setStrings("  Capacimetro ",getCapString(getFreq()));

}

void handler_get_freq(void)
{
  freq_refresh = getFreq2();
 
}
