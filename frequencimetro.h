int pin = PB0;
unsigned long durationH;
unsigned long durationL;

 
void init_frequencimetro()
{
  pinMode(pin, INPUT);
}

unsigned long getPeriodo()
{
  durationH = pulseIn(pin, HIGH,750000);
  durationL = pulseIn(pin, LOW ,750000);

  return durationH+durationL;
}

float getFreq()
{ 
  float periodo = (float)getPeriodo();
  float freq=  0;
  if(periodo != 0.0)
  {
    freq= 1/(periodo*0.000001);
  }
  return freq; 
}


bool triggerHIGH;
bool triggerLOW;
bool completeH;
bool completeL;
unsigned long tHIGH;
unsigned long tLOW;

unsigned long getPeriodo2()
{

  if(!completeH && !completeL)
  {
      //semiciclo HIGH
      if(gpio_read_bit( GPIOB, 0) && !triggerHIGH)
      {
        triggerHIGH = true;
        tHIGH = micros();
        
      }
      else
      if(!gpio_read_bit( GPIOB, 0) && triggerHIGH)
      {
        durationH = micros()-tHIGH;
        triggerHIGH = false;
        completeH = true;
      }
    
      //semiciclo LOW
      if(gpio_read_bit( GPIOB, 0) && !triggerLOW)
      {
        triggerLOW = true;
        tLOW = micros();
        
      }
      else
      if(!gpio_read_bit( GPIOB, 0) && triggerLOW)
      {
        durationL = micros()-tLOW;
        triggerLOW = false;
        completeL = true;
      }
      return 0;
  }
  else
  {
    completeH = completeL = false;
    return durationH+durationL;
    
     
  }
}

float getFreq2()
{ 
  float periodo = (float)getPeriodo2();
  float freq=  0;
  if(periodo != 0.0)
  {
    freq= 1/(periodo*0.000001);
  }
  return freq; 
}
