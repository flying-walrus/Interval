#include <Arduino.h>
#include <Interval.h>

Interval::Interval(int aDuration)
{
  duration = (unsigned long)aDuration;
  nextTime = millis();
}

int Interval::go()
{
  int returnme;
  unsigned long now;

  returnme = 0;
  now = millis();

  if( isTime( now ) )
  {
    update();
    returnme = 1;
  }

  return returnme;

}

int Interval::isTime( unsigned long now )
{
  int returnme;

  returnme = 0;

  now = millis();

  
  // the occasional overflow of millis() makes
  // this logic a little more painful.
  if(( now >= nextTime) && (now + duration >= nextTime + duration) )
    returnme = 1;   

  return returnme;

}

void Interval::update()
{
  unsigned long oldTime;

  oldTime = nextTime;

  nextTime += duration;

}
