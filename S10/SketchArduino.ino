char dato;
int pin;
int estado;
int OK = 1;
int NOK = 0;
int test = 13;

void setup(void)
{
  Serial.begin(9600);
  pinMode(test,OUTPUT);
  
}

void loop(void)
{
  if(Serial.available()==1)
  {
      dato = Serial.read();
      pin = (dato >> 4) & 0x0F;
      estado = dato & 0x01;
      if(pin >= 0 && pin <= 13 && estado <= 1 )
      {
      digitalWrite(pin, estado);
      Serial.write(OK);
      }
      else
      {
       Serial.write(NOK);
      }
      
  }
}
