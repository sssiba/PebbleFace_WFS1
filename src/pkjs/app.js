function locationSuccess(pos) {
  // We will request the weather here
}
 
function locationError(err) {
  console.log('Error requesting location!');
}
 
function getWeather() {
  navigator.geolocation.getCurrentPosition(
    locationSuccess,
    locationError,
    {timeout: 15000, maximumAge: 60000}
  );
}
 
// Listen for when the watchface is opened
Pebble.addEventListener('ready', 
  function(e) {
    console.log('PebbleKit JS ready!');
 
    // Get the initial weather
    getWeather();
  }
); 

var xhrRequest = function (url, type, callback) {
  var xhr = new XMLHttpRequest();
  xhr.onload = function () {
    callback(this.responseText);
  };
  xhr.open(type, url);
  xhr.send();
};
                
function locationSuccess(pos) {
  // Construct URL
  var url = 'http://api.openweathermap.org/data/2.5/weather?lat=' +
      pos.coords.latitude + '&lon=' + pos.coords.longitude +
      "&APPID=ca2fb42b72ef30fc83564af579306423";
 
  console.log( "req:" + url );
  
  // Send request to OpenWeatherMap
  xhrRequest(url, 'GET', 
    function(responseText) {
      // responseText contains a JSON object with weather info
      var json = JSON.parse(responseText);
      
      console.log( "res:" + responseText );
 
      // Temperature in Kelvin requires adjustment
      var temperature = Math.round(json.main.temp - 273.15);
      console.log('Temperature is ' + temperature);
 
      // Conditions
      var conditions = json.weather[0].main;      
      console.log('Conditions are ' + conditions);
      
      // 天気ID
      var wid = json.weather[0].id;
      console.log('weather id:' + wid );
      
      //　アイコン名(末尾の d, n は除去)
      var tmp = json.weather[0].icon.slice( 0, 2 );
      var icon = parseInt( tmp );
      console.log('weather icon:' + icon );
      
      
      // Assemble dictionary using our keys
      var dictionary = {
        'KEY_WEATHER': conditions,
        'KEY_TEMPERATURE': temperature,
        'KEY_WEATHER_ID': wid,
        'KEY_WEATHER_ICON': icon,
      };
      // Send to Pebble
      Pebble.sendAppMessage(dictionary,
        function(e) {
          console.log('Weather info sent to Pebble successfully!');
        },
        function(e) {
          console.log('Error sending weather info to Pebble!');
        }
      );
    }
  );
}

// Listen for when an AppMessage is received
Pebble.addEventListener('appmessage',
  function(e) {
    console.log('AppMessage received!');
    getWeather();
  }                     
);
