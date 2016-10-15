#include <pebble.h>
#include "winmain.h"
#include "main.h"

static GBitmap *s_bmpWICON;

// BEGIN AUTO-GENERATED UI CODE; DO NOT MODIFY
static Window *s_window;
static GFont s_res_gothic_18_bold;
static GFont s_res_font_code8x8_20;
static BitmapLayer *s_lyrBmpBG;
static Layer *s_lyrHands;
static TextLayer *s_lyrTxtTimeShadow;
static TextLayer *s_lyrTxtTime;
static TextLayer *s_lyrTxtDateShadow;
static TextLayer *s_lyrTxtDate;
static TextLayer *s_lyrTxtWeatherShadow;
static TextLayer *s_lyrTxtWeather;
static BitmapLayer *s_lyrBmpWeather;
static TextLayer *s_lyrTxtHealthShadow;
static TextLayer *s_lyrTxtHealth;

static void initialise_ui(void) {
  s_window = window_create();
  window_set_background_color(s_window, GColorBlack);
  #ifndef PBL_SDK_3
    window_set_fullscreen(s_window, true);
  #endif
  
  s_res_gothic_18_bold = fonts_get_system_font(FONT_KEY_GOTHIC_18_BOLD);
  s_res_font_code8x8_20 = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FONT_CODE8x8_20));
  // s_lyrBmpBG
  s_lyrBmpBG = bitmap_layer_create(GRect(0, 0, 144, 168));
  bitmap_layer_set_background_color(s_lyrBmpBG, GColorBlack);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_lyrBmpBG);
  
  // s_lyrHands
  s_lyrHands = layer_create(GRect(1, 1, 32, 32));
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_lyrHands);
  
  // s_lyrTxtTimeShadow
  s_lyrTxtTimeShadow = text_layer_create(GRect(36, 2, 50, 20));
  text_layer_set_background_color(s_lyrTxtTimeShadow, GColorClear);
  text_layer_set_text(s_lyrTxtTimeShadow, "Text layer");
  text_layer_set_font(s_lyrTxtTimeShadow, s_res_gothic_18_bold);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_lyrTxtTimeShadow);
  
  // s_lyrTxtTime
  s_lyrTxtTime = text_layer_create(GRect(34, 0, 50, 24));
  text_layer_set_background_color(s_lyrTxtTime, GColorClear);
  text_layer_set_text_color(s_lyrTxtTime, GColorWhite);
  text_layer_set_text(s_lyrTxtTime, "Text layer");
  text_layer_set_font(s_lyrTxtTime, s_res_gothic_18_bold);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_lyrTxtTime);
  
  // s_lyrTxtDateShadow
  s_lyrTxtDateShadow = text_layer_create(GRect(88, 6, 50, 20));
  text_layer_set_background_color(s_lyrTxtDateShadow, GColorClear);
  text_layer_set_text(s_lyrTxtDateShadow, "Text layer");
  text_layer_set_text_alignment(s_lyrTxtDateShadow, GTextAlignmentCenter);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_lyrTxtDateShadow);
  
  // s_lyrTxtDate
  s_lyrTxtDate = text_layer_create(GRect(86, 4, 50, 20));
  text_layer_set_background_color(s_lyrTxtDate, GColorClear);
  text_layer_set_text_color(s_lyrTxtDate, GColorWhite);
  text_layer_set_text(s_lyrTxtDate, "Text layer");
  text_layer_set_text_alignment(s_lyrTxtDate, GTextAlignmentCenter);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_lyrTxtDate);
  
  // s_lyrTxtWeatherShadow
  s_lyrTxtWeatherShadow = text_layer_create(GRect(36, 43, 40, 20));
  text_layer_set_background_color(s_lyrTxtWeatherShadow, GColorClear);
  text_layer_set_text(s_lyrTxtWeatherShadow, "Text layer");
  text_layer_set_text_alignment(s_lyrTxtWeatherShadow, GTextAlignmentCenter);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_lyrTxtWeatherShadow);
  
  // s_lyrTxtWeather
  s_lyrTxtWeather = text_layer_create(GRect(34, 41, 40, 20));
  text_layer_set_background_color(s_lyrTxtWeather, GColorClear);
  text_layer_set_text_color(s_lyrTxtWeather, GColorWhite);
  text_layer_set_text(s_lyrTxtWeather, "Text layer");
  text_layer_set_text_alignment(s_lyrTxtWeather, GTextAlignmentCenter);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_lyrTxtWeather);
  
  // s_lyrBmpWeather
  s_lyrBmpWeather = bitmap_layer_create(GRect(1, 33, 32, 32));
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_lyrBmpWeather);
  
  // s_lyrTxtHealthShadow
  s_lyrTxtHealthShadow = text_layer_create(GRect(2, 148, 144, 20));
  text_layer_set_background_color(s_lyrTxtHealthShadow, GColorClear);
  text_layer_set_text(s_lyrTxtHealthShadow, "Text layer");
  text_layer_set_font(s_lyrTxtHealthShadow, s_res_font_code8x8_20);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_lyrTxtHealthShadow);
  
  // s_lyrTxtHealth
  s_lyrTxtHealth = text_layer_create(GRect(0, 146, 144, 20));
  text_layer_set_background_color(s_lyrTxtHealth, GColorClear);
  text_layer_set_text_color(s_lyrTxtHealth, GColorWhite);
  text_layer_set_text(s_lyrTxtHealth, "Text layer");
  text_layer_set_font(s_lyrTxtHealth, s_res_font_code8x8_20);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_lyrTxtHealth);
}

static void destroy_ui(void) {
  window_destroy(s_window);
  bitmap_layer_destroy(s_lyrBmpBG);
  layer_destroy(s_lyrHands);
  text_layer_destroy(s_lyrTxtTimeShadow);
  text_layer_destroy(s_lyrTxtTime);
  text_layer_destroy(s_lyrTxtDateShadow);
  text_layer_destroy(s_lyrTxtDate);
  text_layer_destroy(s_lyrTxtWeatherShadow);
  text_layer_destroy(s_lyrTxtWeather);
  bitmap_layer_destroy(s_lyrBmpWeather);
  text_layer_destroy(s_lyrTxtHealthShadow);
  text_layer_destroy(s_lyrTxtHealth);
  fonts_unload_custom_font(s_res_font_code8x8_20);
}
// END AUTO-GENERATED UI CODE

static void handle_window_unload(Window* window) {
  destroy_ui();
}


//***************************************************************************
//***************************************************************************
//***************************************************************************
static const GPathInfo MINUTE_HAND_POINTS = {
#if 0
  4, (GPoint []) {
    { -2,  2 },
    {  2,  2 },
    {  2, -14 },
    { -2, -14 },
  }
#else
  6, (GPoint []) {
    { -2,  2 },
    {  2,  2 },
    {  2, -6 },
    {  1, -15},
    { -1, -15 },
    { -2, -6 },
  }
#endif
};

static const GPathInfo HOUR_HAND_POINTS = {
#if 0
  4, (GPoint []){
    {-2,  2},
    { 2,  2},
    { 2, -11},
    {-2, -11},
  }
#else
  6, (GPoint []){
    {-2,  2},
    { 2,  2},
    { 2, -5},
    { 1, -12},
    {-1, -12},
    {-2, -5},
  }
#endif
};

/*****************************************
毎分更新
*****************************************/
static void tick_handler(struct tm *tick_time, TimeUnits units_changed)
{
//  AccelData accel = (AccelData) { .x = 0, .y = 0, .z = 0 };
//  accel_service_peek(&accel);
  
  /** Display the Time **/
  time_t temp = time(NULL);
//  struct tm *tick_time = localtime(&temp);
  tick_time = localtime(&temp);

  //time
  static char s_time_buffer[8];
  strftime(s_time_buffer, sizeof(s_time_buffer), clock_is_24h_style() ? "%H:%M" : "%I:%M", tick_time);
  text_layer_set_text(s_lyrTxtTime, s_time_buffer);
  text_layer_set_text(s_lyrTxtTimeShadow, s_time_buffer);
  
  //date
  static char s_date_buffer[16];
  strftime( s_date_buffer, sizeof(s_date_buffer), "%d %a", tick_time );
  text_layer_set_text(s_lyrTxtDate, s_date_buffer);
  text_layer_set_text(s_lyrTxtDateShadow, s_date_buffer);
  
  //health
  HealthValue step = health_service_sum_today( HealthMetricStepCount );
  HealthValue active = health_service_sum_today( HealthMetricActiveSeconds );
  HealthValue sleep = health_service_sum_today( HealthMetricSleepSeconds );
  static char health[128];
  snprintf( health, sizeof(health), "Step:%d  Act:%d  Sleep:%d",
           (int)step,
           (int)active,
           (int)sleep
          );
  text_layer_set_text( s_lyrTxtHealth, health );
  text_layer_set_text( s_lyrTxtHealthShadow, health );
    
}


/***************************************************************
analog 表示更新
***************************************************************/
//static GPath *s_tick_paths[NUM_CLOCK_TICKS];
static GPath *s_minute_arrow, *s_hour_arrow;
static void layer_updateCB(Layer *layer, GContext *ctx)
{
  GRect bounds = layer_get_bounds(layer);
  GPoint center = grect_center_point(&bounds);

  //base fill
  graphics_context_set_fill_color(ctx, GColorDarkGray );
  graphics_context_set_stroke_color( ctx, GColorDarkGray );
//  graphics_draw_circle( ctx, GPoint( bounds.size.w/2, bounds.size.h/2 ), bounds.size.w/2-1 );
  graphics_fill_circle( ctx, GPoint( bounds.size.w/2, bounds.size.h/2 ), bounds.size.w/2-1 );
  
  
  
//  const int16_t second_hand_length = PBL_IF_ROUND_ELSE((bounds.size.w / 2) - 19, bounds.size.w / 2);
  const int16_t second_hand_length = 10;

  time_t now = time(NULL);
  struct tm *t = localtime(&now);
  
#if 01
  //*** normal line
  // minute/hour hand
  const int16_t mhlen = bounds.size.w / 2 - 2;
  const int16_t hhlen = bounds.size.w / 2 - 5;
  //minute
  int32_t mang = TRIG_MAX_ANGLE * t->tm_min / 60;
  GPoint mhand = {
    .x = (int16_t)(sin_lookup(mang) * (int32_t)mhlen / TRIG_MAX_RATIO) + center.x,
    .y = (int16_t)(-cos_lookup(mang) * (int32_t)mhlen / TRIG_MAX_RATIO) + center.y,
  };
  graphics_context_set_stroke_color(ctx, GColorWhite);
  graphics_context_set_stroke_width( ctx, 2 ); //線幅:こっちで調節した方がいい？
  graphics_draw_line(ctx, mhand, center);
  //hour
  int32_t hang = (TRIG_MAX_ANGLE * ((t->tm_hour % 12)*60 + t->tm_min)) / (12*60);
  GPoint hhand = {
    .x = (int16_t)(sin_lookup(hang) * (int32_t)hhlen / TRIG_MAX_RATIO) + center.x,
    .y = (int16_t)(-cos_lookup(hang) * (int32_t)hhlen / TRIG_MAX_RATIO) + center.y,
  };
  graphics_context_set_stroke_color(ctx, GColorRed);
  graphics_context_set_stroke_width( ctx, 3 ); //線幅:こっちで調節した方がいい？
  graphics_draw_line(ctx, hhand, center);
#else
  //*** filled line
  graphics_context_set_stroke_width( ctx, 1 ); //線幅:こっちで調節した方がいい？
  // minute
  gpath_rotate_to(s_minute_arrow, TRIG_MAX_ANGLE * t->tm_min / 60);
  graphics_context_set_stroke_color(ctx, GColorBlack);
  graphics_context_set_fill_color(ctx, GColorWhite);
  gpath_draw_filled( ctx, s_minute_arrow );
  // hour
  gpath_rotate_to(s_hour_arrow, (TRIG_MAX_ANGLE * (((t->tm_hour % 12) * 6) + (t->tm_min / 10))) / (12 * 6));
  graphics_context_set_stroke_color(ctx, GColorBlack);
  graphics_context_set_fill_color(ctx, GColorRed);
  gpath_draw_filled( ctx, s_hour_arrow );
#endif
}

/***************************************************************
天気情報更新
***************************************************************/
void updateWeather(void)
{
  //weather
  APP_LOG( APP_LOG_LEVEL_INFO, "u:%s", getTxtWeather() );
  APP_LOG( APP_LOG_LEVEL_INFO, "u:%s", getTxtTemperature() );

  static char s_weather_buffer[32];
  snprintf( s_weather_buffer, sizeof(s_weather_buffer), "%s°",
           getTxtTemperature()
           );
  text_layer_set_text( s_lyrTxtWeather, s_weather_buffer );
  text_layer_set_text( s_lyrTxtWeatherShadow, s_weather_buffer );

#if 01
  //icon 更新
  int rid = -1;
  switch( getWeatherICON() ) {
    case 1: rid = RESOURCE_ID_IMAGE_WEATHER_ICON_01; break;
    case 2: rid = RESOURCE_ID_IMAGE_WEATHER_ICON_02; break;
    case 3: rid = RESOURCE_ID_IMAGE_WEATHER_ICON_03; break;
    case 4: rid = RESOURCE_ID_IMAGE_WEATHER_ICON_04; break;
    case 9: rid = RESOURCE_ID_IMAGE_WEATHER_ICON_09; break;
    case 10: rid = RESOURCE_ID_IMAGE_WEATHER_ICON_10; break;
    case 11: rid = RESOURCE_ID_IMAGE_WEATHER_ICON_11; break;
    case 13: rid = RESOURCE_ID_IMAGE_WEATHER_ICON_13; break;
    case 50: rid = RESOURCE_ID_IMAGE_WEATHER_ICON_50; break;
  }
  
  if( rid >= 0 ) {
    if( s_bmpWICON ) gbitmap_destroy( s_bmpWICON );
  
    s_bmpWICON = gbitmap_create_with_resource( rid );
    bitmap_layer_set_compositing_mode( s_lyrBmpWeather, GCompOpSet );
    bitmap_layer_set_bitmap( s_lyrBmpWeather, s_bmpWICON );
  }
#endif
}


//***************************************************************************
//***************************************************************************
static GBitmap *s_bmpBG;
static unsigned int s_bmpidx = 0;

//***************************************************************************
void destroy_winmain(void)
{
  app_log( APP_LOG_LEVEL_INFO, __FILE__, __LINE__, "destroy" );
  hide_winmain();
  
  if( s_bmpBG ) {
    gbitmap_destroy( s_bmpBG );
  }
  
  if( s_bmpWICON ) {
    gbitmap_destroy( s_bmpWICON );
  }
  
//  window_destroy( s_window );
  app_log( APP_LOG_LEVEL_INFO, __FILE__, __LINE__, "destroy end" );
}


//***************************************************************************
void tap_winmain(void)
{
  static int tbl[] = {
    RESOURCE_ID_IMAGE_SP61,
    RESOURCE_ID_IMAGE_SP64,
    RESOURCE_ID_IMAGE_SP69,
    RESOURCE_ID_IMAGE_SP671,
  };
  
  if( s_bmpBG ) gbitmap_destroy( s_bmpBG );
  
  s_bmpBG = gbitmap_create_with_resource( tbl[s_bmpidx] );
//  s_bmpBG = gbitmap_create_with_resource( RESOURCE_ID_IMAGE_WEATHER_ICON_01 );
  bitmap_layer_set_bitmap( s_lyrBmpBG, s_bmpBG );
  
  if( ++s_bmpidx >= (sizeof(tbl)/sizeof(int)) ) {
    s_bmpidx = 0;
  }
  
}

GFont s_font_custom;
void show_winmain(void) {
  initialise_ui();
  window_set_window_handlers(s_window, (WindowHandlers) {
    .unload = handle_window_unload,
  });
  window_stack_push(s_window, true);

// s_font_custom = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FONT_CODE8x8_12));
// text_layer_set_font(s_lyrTxtHealth, s_font_custom);  
// text_layer_set_font(s_lyrTxtHealthShadow, s_font_custom);  
  
  // init hand paths
  s_minute_arrow = gpath_create(&MINUTE_HAND_POINTS);
  s_hour_arrow = gpath_create(&HOUR_HAND_POINTS);

  Layer *window_layer = window_get_root_layer(s_window);
  GRect bounds = layer_get_bounds( s_lyrHands );
  GPoint center = grect_center_point(&bounds);
  gpath_move_to(s_minute_arrow, center);
  gpath_move_to(s_hour_arrow, center);

#if 0
  for (int i = 0; i < NUM_CLOCK_TICKS; ++i) {
    s_tick_paths[i] = gpath_create(&ANALOG_BG_POINTS[i]);
  }
#endif
  
  //BG
  tap_winmain();
  
  
  //--------------- 更新用関数
  //  layer_set_update_proc( Layer* layer, LayerUpdateProc update_proc ); <<<< 描画が必要な際に呼ばれるやつ
  layer_set_update_proc( s_lyrHands, layer_updateCB );
  
  // Register with TickTimerService
  // AppTimer * app_timer_register(uint32_t timeout_ms, AppTimerCallback callback, void * callback_data) <<<< ms 単位の好きな時間でできる
  // tick_timer_service_subscribe( TimeUnits tick_units, TickHandler handler ); <<<< 秒、分、時間、日、月、年単位で呼ばれる
  tick_timer_service_subscribe(MINUTE_UNIT, tick_handler);
}

void hide_winmain(void) {
  
  app_log( APP_LOG_LEVEL_INFO, __FILE__, __LINE__, "hide" );
  
  window_stack_remove(s_window, true);

  if( s_minute_arrow ) {
    gpath_destroy(s_minute_arrow);
    s_minute_arrow = NULL;
  }
  if( s_hour_arrow ) {
    gpath_destroy(s_hour_arrow);
    s_hour_arrow = NULL;
  }
  
  if( s_font_custom ) {
    fonts_unload_custom_font(s_font_custom);
  }
#if 0  
  for (int i = 0; i < NUM_CLOCK_TICKS; ++i) {
    gpath_destroy(s_tick_paths[i]);
  }
#endif
  
  tick_timer_service_unsubscribe();

  app_log( APP_LOG_LEVEL_INFO, __FILE__, __LINE__, "hide end" );
}
