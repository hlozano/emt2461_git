


#include "rtc.h"

type_time mytime;


//local variables

void timers();
unsigned long int keeping_local_time_timer = 0;

void setup()
{
  mytime = get_time();
}



void loop()
{
  timers();
  update_local_time();
}

void update_local_time()
{
  if (keeping_local_time_timer > 9)
  {
    keeping_local_time_timer = 0;
    mytime.seconds++;
    if ( mytime.seconds > 59)
    {
      mytime.seconds = 0;
      mytime.minutes++;
    }
    if (mytime.minutes > 60)
    {
      mytime.minutes = 0;
      mytime.hour++;
    }
    if  (mytime.hour > 23)
      mytime.hour = 0;

  }

}
void timers()
{
  //my timer to
  //increment with other 100 ms timers.
  keeping_local_time_timer++;


}
