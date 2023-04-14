


struct type_time {
  int month;
  int day;
  int hour;
  int minutes;
  int seconds;
};

type_time get_time()
{
  struct type_time local_time;
  //your logic that reads the RTC chip
  local_time.month = 0;
local_time.day = 0;
local_time.hour = 0;
local_time.minutes = 0;
local_time.seconds = 0;

return local_time;



  
}
