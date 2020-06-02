
String linha1 = "----------------";
String linha2 = "----------------";
//Carrega a biblioteca LiquidCrystal

#include <LiquidCrystal.h>
#define d4 PA3
#define d5 PA6
#define d6 PA4
#define d7 PA5
#define RS PA1
#define EN PA2
//Define os pinos que serão utilizados para ligação ao display
LiquidCrystal lcd(RS, EN, d4, d5, d6, d7);//RS EN D4 D5 D6 D7
HardwareTimer timer_3(3);//usa o timer 3

void handler_refresh_lcd(void)
{

    lcd.begin(16, 2);
    
    lcd.clear();
    //Posiciona o cursor na coluna 3, linha 0;
    
    lcd.setCursor(16-linha1.length(), 0);
    lcd.print(linha1);
    lcd.setCursor(16-linha2.length(), 1);
    lcd.print(linha2);
    
 
  

}

void init_lcd_16x2()
{
  lcd.begin(16, 2);
  //lcd.rightToLeft();
   //Limpa a tela
  lcd.clear();
  //Posiciona o cursor na coluna 3, linha 0;
  lcd.setCursor(3, 0);
  //Envia o texto entre aspas para o LCD
  lcd.print("CAPACIMETRO");
  lcd.setCursor(5, 1);
  lcd.print(" v1.0");
  delay(3000);
  
 
    timer_3.pause();
    timer_3.setPeriod(600000);//em us, calcula automaticamente prescale e overflow                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
    timer_3.setChannel1Mode(TIMER_OUTPUT_COMPARE);
    timer_3.setCompare(TIMER_CH1, 1);  
    timer_3.attachCompare1Interrupt(handler_refresh_lcd);
    timer_3.refresh();
    timer_3.resume();
   //Define o número de colunas e linhas do LCD
  
}
void setStrings(String str1, String str2)
{
  
  
  //if(str1 != linha1 || str2 != linha2   ){
    linha1=str1;
    linha2=str2;
    
  //}
}
