
#define btn1 1262
#define btn2 2778
#define btn3 1884
#define btn4 131

struct btn_matrix
{

  bool pressed;
  unsigned long t;
  int btnAdcValue;
  int adc;
  int pinADC;

   btn_matrix(int adcValueBtn,int pin)
  {
    pinMode(PA0,INPUT_ANALOG);
    btnAdcValue = adcValueBtn;
    pinADC = pin;
  }

   bool isPressed()
 {

  if(millis()-t>40)
  {
    
    adc = analogRead(pinADC);
    bool state = adc<(btnAdcValue+50) && adc>(btnAdcValue-50);
    t=millis(); 
    if(!pressed && state )
    {
      pressed = true;
    }
    else
    if(pressed && !state ) 
    {
      pressed = false;
      return true;
    }
  }
  
  return false;
  
 }
};
