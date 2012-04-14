#ifndef Interval_h
#define Interval_h

class Interval
{
  private:
    unsigned long duration;
    unsigned long nextTime;

    int isTime( unsigned long );
    void update();
  public:
    Interval( int );
    int go();

};

#endif
