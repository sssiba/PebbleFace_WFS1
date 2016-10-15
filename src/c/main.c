//******************************************************************
#include <pebble.h>

#include "winmain.h"

//******************************************************************
enum {
#if 0
  KEY_WEATHER,
  KEY_TEMPERATURE,
#else  
  //x!x! 10000 から？
  KEY_WEATHER = 10000,
  KEY_TEMPERATURE = 10001,
  KEY_WEATHER_ID = 10002,
  KEY_WEATHER_ICON = 10003,
#endif
};

//******************************************************************
Window *g_win;



//******************************************************************
//******************************************************************
//******************************************************************
static void UIinit()
{
  show_winmain();
}

static void UIdeinit()
{
  destroy_winmain();
}


static void accTapCB(AccelAxisType axis, int32_t direction)
{
//    if( (axis == ACCEL_AXIS_Z) && (direction > 0) ) {
        tap_winmain();
//    }
}

//******************************************************************
// Store incoming information
static char temperature_buffer[8];
static char conditions_buffer[32];
static char weather_layer_buffer[32];

static int s_weatherID;
static int s_weatherICON;

const char* getTxtWeather()
{
  return conditions_buffer;
}

const char* getTxtTemperature()
{
  return temperature_buffer;
}

int getWeatherID()
{
  return s_weatherID;
}

int getWeatherICON()
{
  return s_weatherICON;
}

static void inbox_received_callback(DictionaryIterator *iterator, void *context) {
  APP_LOG(APP_LOG_LEVEL_INFO, "Message recived!");
  // Read first item
  Tuple *t = dict_read_first(iterator);
 
  // For all items
  while(t != NULL) {
    // Which key was received?
    switch(t->key) {    
    case KEY_WEATHER:
      snprintf(conditions_buffer, sizeof(conditions_buffer), "%s", t->value->cstring);
      APP_LOG( APP_LOG_LEVEL_INFO, "%s", getTxtWeather() );
      break;
    case KEY_TEMPERATURE:
      snprintf(temperature_buffer, sizeof(temperature_buffer), "%d", (int)t->value->int32);
      APP_LOG( APP_LOG_LEVEL_INFO, "%s", getTxtTemperature() );
      break;
    case KEY_WEATHER_ID:
      s_weatherID = (int)t->value->int32;
      APP_LOG( APP_LOG_LEVEL_INFO, "%d", (int)t->value->int32 );
      break;  
    case KEY_WEATHER_ICON:
      s_weatherICON = (int)t->value->int32;
      APP_LOG( APP_LOG_LEVEL_INFO, "%d", (int)t->value->int32 );
      break;
    default:
      APP_LOG(APP_LOG_LEVEL_ERROR, "Key %d not recognized!", (int)t->key);
      break;
    }
 
    // Look for next item
    t = dict_read_next(iterator);
  }
  
  updateWeather();
}
static void inbox_dropped_callback(AppMessageResult reason, void *context) {
  APP_LOG(APP_LOG_LEVEL_ERROR, "Message dropped!");
}
 
static void outbox_failed_callback(DictionaryIterator *iterator, AppMessageResult reason, void *context) {
  APP_LOG(APP_LOG_LEVEL_ERROR, "Outbox send failed!");
}
 
static void outbox_sent_callback(DictionaryIterator *iterator, void *context) {
  APP_LOG(APP_LOG_LEVEL_INFO, "Outbox send success!");
}

static void MSGinit()
{
  // Register callbacks
  app_message_register_inbox_received(inbox_received_callback);
  app_message_register_inbox_dropped(inbox_dropped_callback);
  app_message_register_outbox_failed(outbox_failed_callback);
  app_message_register_outbox_sent(outbox_sent_callback);
  // Open AppMessage
  app_message_open(app_message_inbox_size_maximum(), app_message_outbox_size_maximum());
}

static void MSGdeinit()
{
}



//*****************************************************************[ init ]
void handle_init(void)
{
//  accel_data_service_subscribe(0, NULL);
  accel_tap_service_subscribe( accTapCB );
  
  MSGinit();
  
  UIinit();
  
//  app_timer_register( 16, appTimerCB, NULL );
}

void handle_deinit(void)
{
//  accel_data_service_unsubscribe();
  accel_tap_service_unsubscribe();

  MSGdeinit();
  
  UIdeinit();
}

int main(void) {
  app_log( APP_LOG_LEVEL_INFO, __FILE__, __LINE__, "**** start ****" );
  
  handle_init();
  app_event_loop();

  app_log( APP_LOG_LEVEL_INFO, __FILE__, __LINE__, "*** exit event loop" );
  
  handle_deinit();
}
