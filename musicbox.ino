#include <avr/pgmspace.h>

#define DO 0
#define RE 2
#define MI 4
#define FA 5
#define SOL 7
#define LA 9
#define CI 11

#define DI +1
#define BE -1

unsigned TEMP;

float freq[] = {261.6, 277.2, 293.7, 311.1, 329.6, 349.2, 370.0, 392.0, 415.3, 440, 466.2, 493.9};

float FREQ(int n, int oct)
{
  if (n < 0)
  {
    return 0.5 * FREQ(n + 12, oct - 1);
  }
  if (n >= 12)
  {
    return 2 * FREQ(n - 12, oct + 1);
  }
  if (oct == 0)
  {
    return freq[n];
  }
  else if (oct < 0)
  {
    return 0.5 * FREQ(n, oct + 1);
  }
  else
  {
    return 2.0 * FREQ(n, oct - 1);
  }
}

int pin[] = {15, 15, 16, 16, 17, 18, 18, 19, 19, 20, 20, 21};

void play(int n, int oct, int dur, int dot = 0)
{
  //tone(8, FREQ(n, oct));
  tone(3, FREQ(n, oct));
  digitalWrite(pin[n], 1);
  delay(TEMP / dur * (dot ? 1.5 : 1) - 5);
  digitalWrite(pin[n], 0);
  //noTone(8);
  noTone(3);
  delay(5);
}

void Elochka()
{
  TEMP = 1867;
  
  play(SOL, 1, 4);
  play(MI, 1, 8);
  play(MI, 1, 8);
  play(SOL, 1, 4);
  play(MI, 1, 8);
  play(MI, 1, 8);
  
  play(SOL, 1, 8);
  play(FA, 1, 8);
  play(MI, 1, 8);
  play(RE, 1, 8);
  play(DO, 1, 4, 1);
}

void Zaratustra()
{
  TEMP = 1867;
  
  play(DO, 1, 1);
  play(SOL, 1, 1);
  play(DO, 2, 1);
  play(MI, 2, 8);
  play(RE DI, 2, 2, 1);
  delay(TEMP);

  play(DO, 1, 1);
  play(SOL, 1, 1);
  play(DO, 2, 1);
  play(RE DI, 2, 8);
  play(MI, 2, 2, 1);
  delay(TEMP);
  
  play(DO, 1, 1);
  play(SOL, 1, 1);
  play(DO, 2, 1);
  play(MI, 2, 8);
  play(LA, 2, 2, 1);
  delay(TEMP);  
  
  play(LA, 1, 8);
  play(CI, 1, 8);
  play(DO, 2, 2, 1);
  play(RE, 2, 2, 1);
  play(MI, 2, 4);
  play(FA, 2, 4);
  play(SOL, 2, 4);
  play(MI, 2, 4);
  play(DO, 2, 1);
  
  delay(TEMP);
  
  play(LA, 2, 1);
  play(CI, 2, 1);
  play(DO, 3, 1);
  play(DO, 3, 1);

}

void Empire()
{
  TEMP = 1867;
  
  play(MI, 1, 4);
  play(MI, 1, 4);
  play(MI, 1, 4);
  play(DO, 1, 8, 1);
  
  play(SOL, 1, 16);
  play(MI, 1, 4);
  play(DO, 1, 8, 1);
  
  play(SOL, 1, 16);
  play(MI, 1, 4);
  delay(TEMP / 4);
  
  play(CI, 1, 4);
  play(CI, 1, 4);
  play(CI, 1, 4);
  play(DO, 2, 8, 1);
  
  play(LA, 1, 16);
  play(RE DI, 1, 4);
  play(DO, 1, 8, 1);
  play(SOL, 1, 16);
  play(MI, 1, 4);
  delay(TEMP / 4);
  
  play(MI, 2, 4);
  play(MI, 1, 8, 1);
  play(MI, 1, 16);
  
  play(MI, 2, 4);
  play(RE DI, 2, 8, 1);
  play(RE, 2, 16);
  
  play(DO DI, 2, 16);
  play(DO, 2, 16);
  
  play(DO DI, 2, 16);
  delay(TEMP / 8);
  
  play(SOL, 1, 8);
  play(DO DI, 2, 4);
  play(DO, 2, 8, 1);
  play(CI, 1, 16);

  play(LA DI, 1, 16);
  play(LA, 1, 16);
  play(LA DI, 1, 8);
  delay(TEMP/8);

  play(DO, 1, 8);
  play(MI, 1, 4);
  play(DO, 1, 8, 1);
  play(SOL, 1, 16);
  play(MI, 1, 4);
  play(DO, 1, 8, 1);
  play(SOL, 1, 16);
  play(MI, 1, 4);

  delay(TEMP  /4);

}

void OdaToJoy()
{
  TEMP = 4000;
  
  play(MI, 1, 16);
  play(MI, 1, 16);
  play(FA, 1, 16);
  play(SOL, 1, 16);
  play(SOL, 1, 16);
  play(FA, 1, 16);
  play(MI, 1, 16);
  play(RE, 1, 16);
  play(DO, 1, 16);
  play(DO, 1, 16);
  play(RE, 1, 16);
  play(MI, 1, 16);
  play(MI, 1, 16, 1);
  play(RE, 1, 8);
  play(RE, 1, 4);
  
  play(MI, 1, 16);
  play(MI, 1, 16);
  play(FA, 1, 16);
  play(SOL, 1, 16);
  play(SOL, 1, 16);
  play(FA, 1, 16);
  play(MI, 1, 16);
  play(RE, 1, 16);
  play(DO, 1, 16);
  play(DO, 1, 16);
  play(RE, 1, 16);
  play(MI, 1, 16);
  play(RE, 1, 16, 1);
  play(DO, 1, 8);
  play(DO, 1, 8, 1);
  
}

  
typedef void(*Song)();
  
void setup()
{
  pinMode(8, OUTPUT);
  digitalWrite(8, 0);
  pinMode(9, OUTPUT);
  digitalWrite(9, 0);
  
  for (int i = 0; i < sizeof(pin)/ sizeof(int); ++i)
  {
    pinMode(pin[i], OUTPUT);
  }

  //OdaToJoy();
  //for(;;);
  
  Song songs[] = {Empire, Elochka, Zaratustra, OdaToJoy};
  
  randomSeed(analogRead(0));
  for(;;)
  songs[random(4)]();
  
  pinMode(9, OUTPUT);
  digitalWrite(9, 0);
  pinMode(8, OUTPUT);
  digitalWrite(8, 0);
  for(;;);
}

void loop()
{
}
