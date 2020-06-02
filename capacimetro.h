
 float RA = 20110.0;
 float RB = 22498.0;

 float calcCapacitor(float fr)
 {
  //freq555 = 1.44/ (Ra +2RB)C 
  return 1.44/((RA+(2*RB))*fr);
 }
 
String getCapString(float f)
{ 
  float cap=calcCapacitor(f);
  if(cap >2E-10){
  if (cap <1E-9 )
  return (String)(cap*1E12)+"pF";
  else
  if (cap <1E-6)//0.000001
  return (String)(cap*1E9)+"nF";
  else
  if (cap <1E-3)
  return (String)(cap*1E6)+"uF";
  else
  if (cap <1)
  return (String)(cap*1E3)+"mF";
  else
  return "     0.00 ";
  }else return "     0.00 ";
}
