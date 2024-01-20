#ifndef power_h
#define power_h


double power(double n, int p)
{
  double pow = 1;
  int i;
  
  for (i = 0; i < p; i++)
    pow *= n;

  return pow;
}


#endif
