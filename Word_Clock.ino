#include <FastLED.h>
#include<Wire.h>
#include <RTC.h>
#define LED_PIN 3
#define NUM_LEDS 132
#define BRIGHTNESS 100

  static DS3231 RTC;
  CRGBArray<NUM_LEDS> leds;
void setup() {
  FastLED.addLeds<WS2812, LED_PIN>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
  RTC.begin();
  Serial.begin(9600);
  
    if (RTC.isRunning())
  {
    Serial.println("RTC is running");
    Serial.print(RTC.getDay());
    Serial.print("-");
    Serial.print(RTC.getMonth());
    Serial.print("-");
    Serial.print(RTC.getYear());
    Serial.print(" ");
    Serial.print(RTC.getHours());
    Serial.print(":");
    Serial.print(RTC.getMinutes());
    Serial.print(":");
    Serial.print(RTC.getSeconds());
    Serial.print("");
      switch (RTC.getMeridiem()) {
      case HOUR_AM:
        Serial.print(" AM");
        break;
      case HOUR_PM:
        Serial.print(" PM");
        break;
      }
    Serial.println("");
    delay(1000);
  }
  else
  {
    delay(1500);

    Serial.println("RTC not running...");
    Serial.println("Setting Time");
    RTC.setHourMode(CLOCK_H12);
    RTC.setDateTime(__DATE__, __TIME__);
    Serial.println("New Time Set");
    Serial.print(__DATE__);
    Serial.print(" ");
    Serial.println(__TIME__);
    RTC.startClock();
  }


  static uint8_t hue;
  for(int i = 0; i < (NUM_LEDS/2)+25; i++) {   
    leds.fadeToBlackBy(40);

    leds[i] = CHSV(hue+=3,255,255);
      
    leds(NUM_LEDS/2,NUM_LEDS-1) = leds(NUM_LEDS/2 - 1 ,0);
    FastLED.delay(45);
  }


}

  
void loop() {

  //Happy Birthday Iman!
  if (RTC.getMonth()==10 && RTC.getDay()==27){
    happyb();
    birth();
    day();
    iman();
  }

  //Happy Birthday Me!
  if (RTC.getMonth()==6 && RTC.getDay()==3){
    happyb();
    birth();
    day();
    derek();
  }

  //Happy anniversary! <3
  if (RTC.getMonth()==1 && RTC.getDay()==10){
    happyb();
    anni();
    versary();
  }

  switch(RTC.getHours()){
    case 1:
      if (RTC.getMinutes() < 30){
        one();
        wipetwelve();
      } else {
        two();
        wipeone();
      }

      break;
    case 2:
      if (RTC.getMinutes() < 30){
        wipeone();
        two();
      } else {
        wipetwo();
        three();
      }
      
      break;
    case 3:
      if (RTC.getMinutes() < 30){
        wipetwo();
        three();
      } else {
        wipethree();
        four();
      }
      break;
    case 4:
      if (RTC.getMinutes() < 30){
        wipethree();
        four();
      } else {
        wipefour();
        fiveh();
      }
      break;
    case 5:
      if (RTC.getMinutes() < 30){
        wipefour();
        fiveh();
      } else {
        wipefiveh();
        six();
      }
      break;
    case 6:
      if (RTC.getMinutes() < 30){
        wipefiveh();
        six();
      } else {
        wipesix();
        seven();
      }
      break;
    case 7:
      if (RTC.getMinutes() < 30){
        wipesix();
        seven();
      } else {
        wipeseven();
        eight();
      }
      break;
    case 8:
      if (RTC.getMinutes() < 30){
        wipeseven();
        eight();
      } else {
        wipeeight();
        nine();
      }
      break;
    case 9:
      if (RTC.getMinutes() < 30){
        wipeeight();
        nine();
      } else {
        wipenine();
        tenh();
      }
      break;
    case 10:
      if (RTC.getMinutes() < 30){
        wipenine();
        tenh();
      } else {
        wipetenh();
        eleven();
      }
      break;
    case 11:
      if (RTC.getMinutes() < 30){
        wipetenh();
        eleven();
      } else {
        wipeeleven();
        twelve();
      }
      break;
    case 12:
      if (RTC.getMinutes() < 30){
        wipeeleven();
        twelve();
      } else {
        wipetwelve();
        one();
      }
      break;
  }
      if(RTC.getMinutes() < 5){
        wipeto();
        wipefivem();
      } else if (RTC.getMinutes() < 10){
        fivem();
        past();
      } else if (RTC.getMinutes() < 15){
        wipefivem();
        tenm();
        past();
      } else if (RTC.getMinutes() < 20){
        wipetenm();
        quarter();
        past();
      } else if (RTC.getMinutes() < 25){
        wipequarter();
        twenty();
        past();
      } else if (RTC.getMinutes() < 30){
        twenty();
        fivem();
        past();
      } else if (RTC.getMinutes() < 35){
        wipetwenty();
        wipefivem();
        half();
        past();
      } else if (RTC.getMinutes() < 40){
        wipepast();
        wipehalf();
        twenty();
        fivem();
        to();
      } else if (RTC.getMinutes() < 45){
        wipefivem();
        twenty();
        to();
      } else if (RTC.getMinutes() < 50){
        wipetwenty();
        quarter();
        to();
      } else if (RTC.getMinutes() < 55){
        wipequarter();
        tenm();
        to();
      } else if (RTC.getMinutes() < 59){
        wipetenm();
        fivem();
        to();
      }

      switch (RTC.getMeridiem()) {
        case HOUR_AM:
          wipepm();
          am();
          break;
        case HOUR_PM:
          wipeam();
          pm();
          break;
      }
}

static uint8_t hue;

void happyb(){
  for (int i=23; i<=27; i++){
    leds[i] = CHSV(hue++,255,255);
  }
}

void birth(){
    for (int i=38; i<=42; i++){
    leds[i] = CHSV(hue++,255,255);
  }
}

void day(){
    for (int i=46; i<=48; i++){
    leds[i] = CHSV(hue++,255,255);
  }
}

void iman(){
    for (int i=62; i<=65; i++){
    leds[i] = CHSV(hue++,255,255);
  }
}

void derek(){
    for (int i=50; i<=54; i++){
    leds[i] = CHSV(hue,255,255);
  }
}

void happya(){
  for (int i=23; i<=27; i++){
    leds[i] = CHSV(105,255,255);
    }
  }


void anni(){
    for (int i=59; i<=63; i++){
    leds[i] = CHSV(105,255,255);
  }
}

void versary(){
    for (int i=67; i<=73; i++){
    leds[i] = CHSV(105,255,255);
  }
}

//=========================================================================================//
//                                 Declaring Words In Clock                                //
//=========================================================================================//

// I realized how to do this better, but I'm not fixing what isnt broken
void its(){
    for (int i=0; i<=3; i++){
    leds[i] = CRGB(255,255,255);
  }
}

void twenty(){
    for (int i=5; i<=10; i++){
      leds[i] = CRGB(255,255,255);
    }
}

void tenm(){
  leds[11] = CRGB(255, 255, 255);leds[12] = CRGB(255, 255, 255);leds[13] = CRGB(255, 255, 255);FastLED.show();
}

void quarter(){
  leds[15] = CRGB(255, 255, 255);leds[16] = CRGB(255, 255, 255);leds[17] = CRGB(255, 255, 255);leds[18] = CRGB(255, 255, 255);leds[19] = CRGB(255, 255, 255);leds[20] = CRGB(255, 255, 255);leds[21] = CRGB(255, 255, 255);FastLED.show();
}

void fivem(){
  leds[28] = CRGB(255, 255, 255);leds[29] = CRGB(255, 255, 255);leds[30] = CRGB(255, 255, 255);leds[31] = CRGB(255, 255, 255);FastLED.show();
}

void half(){
  leds[33] = CRGB(255, 255, 255);leds[34] = CRGB(255, 255, 255);leds[35] = CRGB(255, 255, 255);leds[36] = CRGB(255, 255, 255);FastLED.show();
}

void to(){
  leds[44] = CRGB(255, 255, 255);leds[45] = CRGB(255, 255, 255);FastLED.show();
}

void past(){
  leds[55] = CRGB(255, 255, 255);leds[56] = CRGB(255, 255, 255);leds[57] = CRGB(255, 255, 255);leds[58] = CRGB(255, 255, 255);FastLED.show();
}


void two(){
  leds[74] = CRGB(255, 255, 255);leds[75] = CRGB(255, 255, 255);leds[76] = CRGB(255, 255, 255);FastLED.show();
}

void nine(){
  leds[77] = CRGB(255, 255, 255);leds[78] = CRGB(255, 255, 255);leds[79] = CRGB(255, 255, 255);leds[80] = CRGB(255, 255, 255);FastLED.show();
}

void six(){
  leds[82] = CRGB(255, 255, 255);leds[83] = CRGB(255, 255, 255);leds[84] = CRGB(255, 255, 255);FastLED.show();
}

void one(){
  leds[85] = CRGB(255, 255, 255);leds[86] = CRGB(255, 255, 255);leds[87] = CRGB(255, 255, 255);FastLED.show();
}

void fiveh(){
  leds[88] = CRGB(255, 255, 255);leds[89] = CRGB(255, 255, 255);leds[90] = CRGB(255, 255, 255);leds[91] = CRGB(255, 255, 255);FastLED.show();
}

void eight(){
  leds[91] = CRGB(255, 255, 255);leds[92] = CRGB(255, 255, 255);leds[93] = CRGB(255, 255, 255);leds[94] = CRGB(255, 255, 255);leds[95] = CRGB(255, 255, 255);FastLED.show();
}

void tenh(){
  leds[95] = CRGB(255, 255, 255);leds[96] = CRGB(255, 255, 255);leds[97] = CRGB(255, 255, 255);FastLED.show();
}

void seven(){
  leds[99] = CRGB(255, 255, 255);leds[100] = CRGB(255, 255, 255);leds[101] = CRGB(255, 255, 255);leds[102] = CRGB(255, 255, 255);leds[103] = CRGB(255, 255, 255);FastLED.show();
}

void three(){
  leds[105] = CRGB(255, 255, 255);leds[106] = CRGB(255, 255, 255);leds[107] = CRGB(255, 255, 255);leds[108] = CRGB(255, 255, 255);leds[109] = CRGB(255, 255, 255);FastLED.show();
}

void twelve(){
  leds[110] = CRGB(255, 255, 255);leds[111] = CRGB(255, 255, 255);leds[112] = CRGB(255, 255, 255);leds[113] = CRGB(255, 255, 255);leds[114] = CRGB(255, 255, 255);leds[115] = CRGB(255, 255, 255);FastLED.show();
}

void four() {
  leds[117] = CRGB(255, 255, 255);leds[118] = CRGB(255, 255, 255);leds[119] = CRGB(255, 255, 255);leds[120] = CRGB(255, 255, 255);FastLED.show();
}

void pm(){
  leds[121] = CRGB(255, 255, 255);leds[122] = CRGB(255, 255, 255);FastLED.show();
}

void am(){
  leds[124] = CRGB(255, 255, 255);leds[125] = CRGB(255, 255, 255);FastLED.show();
}

void eleven(){
  leds[126] = CRGB(255, 255, 255);leds[127] = CRGB(255, 255, 255);leds[128] = CRGB(255, 255, 255);leds[129] = CRGB(255, 255, 255);leds[130] = CRGB(255, 255, 255);leds[131] = CRGB(255, 255, 255);FastLED.show();
}

void wipeAll(){
  leds[0] = CRGB(0, 0, 0);leds[1] = CRGB(0, 0, 0);leds[2] = CRGB(0, 0, 0);leds[3] = CRGB(0, 0, 0);leds[4] = CRGB(0, 0, 0);leds[5] = CRGB(0, 0, 0);leds[6] = CRGB(0, 0, 0);leds[7] = CRGB(0, 0, 0);leds[8] = CRGB(0, 0, 0);leds[9] = CRGB(0, 0, 0);leds[10] = CRGB(0, 0, 0);leds[11] = CRGB(0, 0, 0);leds[12] = CRGB(0, 0, 0);leds[13] = CRGB(0, 0, 0);leds[14] = CRGB(0, 0, 0);leds[15] = CRGB(0, 0, 0);leds[16] = CRGB(0, 0, 0);leds[17] = CRGB(0, 0, 0);leds[18] = CRGB(0, 0, 0);leds[19] = CRGB(0, 0, 0);leds[20] = CRGB(0, 0, 0);leds[21] = CRGB(0, 0, 0);leds[22] = CRGB(0, 0, 0);leds[23] = CRGB(0, 0, 0);leds[24] = CRGB(0, 0, 0);leds[25] = CRGB(0, 0, 0);leds[26] = CRGB(0, 0, 0);leds[27] = CRGB(0, 0, 0);leds[28] = CRGB(0, 0, 0);leds[29] = CRGB(0, 0, 0);leds[30] = CRGB(0, 0, 0);leds[31] = CRGB(0, 0, 0);leds[32] = CRGB(0, 0, 0);leds[33] = CRGB(0, 0, 0);leds[34] = CRGB(0, 0, 0);leds[35] = CRGB(0, 0, 0);leds[36] = CRGB(0, 0, 0);leds[37] = CRGB(0, 0, 0);leds[38] = CRGB(0, 0, 0);leds[39] = CRGB(0, 0, 0);leds[40] = CRGB(0, 0, 0);leds[41] = CRGB(0, 0, 0);leds[42] = CRGB(0, 0, 0);leds[43] = CRGB(0, 0, 0);leds[44] = CRGB(0, 0, 0);leds[45] = CRGB(0, 0, 0);leds[46] = CRGB(0, 0, 0);leds[47] = CRGB(0, 0, 0);leds[48] = CRGB(0, 0, 0);leds[49] = CRGB(0, 0, 0);leds[50] = CRGB(0, 0, 0);leds[51] = CRGB(0, 0, 0);leds[52] = CRGB(0, 0, 0);leds[53] = CRGB(0, 0, 0);leds[54] = CRGB(0, 0, 0);leds[55] = CRGB(0, 0, 0);leds[56] = CRGB(0, 0, 0);leds[57] = CRGB(0, 0, 0);leds[58] = CRGB(0, 0, 0);leds[59] = CRGB(0, 0, 0);leds[60] = CRGB(0, 0, 0);leds[61] = CRGB(0, 0, 0);leds[62] = CRGB(0, 0, 0);leds[63] = CRGB(0, 0, 0);leds[64] = CRGB(0, 0, 0);leds[65] = CRGB(0, 0, 0);leds[66] = CRGB(0, 0, 0);leds[67] = CRGB(0, 0, 0);leds[68] = CRGB(0, 0, 0);leds[69] = CRGB(0, 0, 0);leds[70] = CRGB(0, 0, 0);leds[71] = CRGB(0, 0, 0);leds[72] = CRGB(0, 0, 0);leds[73] = CRGB(0, 0, 0);leds[74] = CRGB(0, 0, 0);leds[75] = CRGB(0, 0, 0);leds[76] = CRGB(0, 0, 0);leds[77] = CRGB(0, 0, 0);leds[78] = CRGB(0, 0, 0);leds[79] = CRGB(0, 0, 0);leds[80] = CRGB(0, 0, 0);leds[81] = CRGB(0, 0, 0);leds[82] = CRGB(0, 0, 0);leds[83] = CRGB(0, 0, 0);leds[84] = CRGB(0, 0, 0);leds[85] = CRGB(0, 0, 0);leds[86] = CRGB(0, 0, 0);leds[87] = CRGB(0, 0, 0);leds[88] = CRGB(0, 0, 0);leds[89] = CRGB(0, 0, 0);leds[90] = CRGB(0, 0, 0);leds[91] = CRGB(0, 0, 0);leds[92] = CRGB(0, 0, 0);leds[93] = CRGB(0, 0, 0);leds[94] = CRGB(0, 0, 0);leds[95] = CRGB(0, 0, 0);leds[96] = CRGB(0, 0, 0);leds[97] = CRGB(0, 0, 0);leds[98] = CRGB(0, 0, 0);leds[99] = CRGB(0, 0, 0);leds[100] = CRGB(0, 0, 0);leds[101] = CRGB(0, 0, 0);leds[102] = CRGB(0, 0, 0);leds[103] = CRGB(0, 0, 0);leds[104] = CRGB(0, 0, 0);leds[105] = CRGB(0, 0, 0);leds[106] = CRGB(0, 0, 0);leds[107] = CRGB(0, 0, 0);leds[108] = CRGB(0, 0, 0);leds[109] = CRGB(0, 0, 0);leds[110] = CRGB(0, 0, 0);leds[111] = CRGB(0, 0, 0);leds[112] = CRGB(0, 0, 0);leds[113] = CRGB(0, 0, 0);leds[114] = CRGB(0, 0, 0);leds[115] = CRGB(0, 0, 0);leds[116] = CRGB(0, 0, 0);leds[117] = CRGB(0, 0, 0);leds[118] = CRGB(0, 0, 0);leds[119] = CRGB(0, 0, 0);leds[120] = CRGB(0, 0, 0);leds[121] = CRGB(0, 0, 0);leds[122] = CRGB(0, 0, 0);leds[123] = CRGB(0, 0, 0);leds[124] = CRGB(0, 0, 0);leds[125] = CRGB(0, 0, 0);leds[126] = CRGB(0, 0, 0);leds[127] = CRGB(0, 0, 0);leds[128] = CRGB(0, 0, 0);leds[129] = CRGB(0, 0, 0);leds[130] = CRGB(0, 0, 0);leds[131] = CRGB(0, 0, 0);
}




//==============================================================================================
//                                                   WIPE
//==============================================================================================



void wipetwenty(){
  leds[5] = CRGB(0, 0, 0);leds[6] = CRGB(0, 0, 0);leds[7] = CRGB(0, 0, 0);leds[8] = CRGB(0, 0, 0);leds[9] = CRGB(0, 0, 0);leds[10] = CRGB(0, 0, 0);FastLED.show();
}

void wipetenm(){
  leds[11] = CRGB(0, 0, 0);leds[12] = CRGB(0, 0, 0);leds[13] = CRGB(0, 0, 0);FastLED.show();
}

void wipequarter(){
  leds[15] = CRGB(0, 0, 0);leds[16] = CRGB(0, 0, 0);leds[17] = CRGB(0, 0, 0);leds[18] = CRGB(0, 0, 0);leds[19] = CRGB(0, 0, 0);leds[20] = CRGB(0, 0, 0);leds[21] = CRGB(0, 0, 0);FastLED.show();
}

void wipehappy(){
  leds[23] = CRGB(0, 0, 0);leds[24] = CRGB(0, 0, 0);leds[25] = CRGB(0, 0, 0);leds[26] = CRGB(0, 0, 0);leds[27] = CRGB(0, 0, 0);FastLED.show();
}

void wipefivem(){
  leds[28] = CRGB(0, 0, 0);leds[29] = CRGB(0, 0, 0);leds[30] = CRGB(0, 0, 0);leds[31] = CRGB(0, 0, 0);FastLED.show();
}

void wipehalf(){
  leds[33] = CRGB(0, 0, 0);leds[34] = CRGB(0, 0, 0);leds[35] = CRGB(0, 0, 0);leds[36] = CRGB(0, 0, 0);FastLED.show();
}

void wipebirth(){
  leds[38] = CRGB(0, 0, 0);leds[39] = CRGB(0, 0, 0);leds[40] = CRGB(0, 0, 0);leds[41] = CRGB(0, 0, 0);leds[42] = CRGB(0, 0, 0);FastLED.show();
}

void wipeto(){
  leds[44] = CRGB(0, 0, 0);leds[45] = CRGB(0, 0, 0);FastLED.show();
}

void wipeday(){
  leds[46] = CRGB(0, 0, 0);leds[47] = CRGB(0, 0, 0);leds[48] = CRGB(0, 0, 0);FastLED.show();
}

void wipederek(){
  leds[50] = CRGB(0, 0, 0);leds[51] = CRGB(0, 0, 0);leds[52] = CRGB(0, 0, 0);leds[53] = CRGB(0, 0, 0);leds[54] = CRGB(0, 0, 0);FastLED.show();
}

void wipepast(){
  leds[55] = CRGB(0, 0, 0);leds[56] = CRGB(0, 0, 0);leds[57] = CRGB(0, 0, 0);leds[58] = CRGB(0, 0, 0);FastLED.show();
}

void wipeanni(){
  leds[59] = CRGB(0, 0, 0);leds[60] = CRGB(0, 0, 0);leds[61] = CRGB(0, 0, 0);leds[62] = CRGB(0, 0, 0);leds[63] = CRGB(0, 0, 0);FastLED.show();
}

void wipeiman(){
  leds[62] = CRGB(0, 0, 0);leds[63] = CRGB(0, 0, 0);leds[64] = CRGB(0, 0, 0);leds[65] = CRGB(0, 0, 0);FastLED.show();
}

void wipeversary(){
  leds[67] = CRGB(0, 0, 0);leds[68] = CRGB(0, 0, 0);leds[69] = CRGB(0, 0, 0);leds[70] = CRGB(0, 0, 0);leds[71] = CRGB(0, 0, 0);leds[72] = CRGB(0, 0, 0);leds[73] = CRGB(0, 0, 0);FastLED.show();
}

void wipetwo(){
  leds[74] = CRGB(0, 0, 0);leds[75] = CRGB(0, 0, 0);leds[76] = CRGB(0, 0, 0);FastLED.show();
}

void wipenine(){
  leds[77] = CRGB(0, 0, 0);leds[78] = CRGB(0, 0, 0);leds[79] = CRGB(0, 0, 0);leds[80] = CRGB(0, 0, 0);FastLED.show();
}

void wipesix(){
  leds[82] = CRGB(0, 0, 0);leds[83] = CRGB(0, 0, 0);leds[84] = CRGB(0, 0, 0);FastLED.show();
}

void wipeone(){
  leds[85] = CRGB(0, 0, 0);leds[86] = CRGB(0, 0, 0);leds[87] = CRGB(0, 0, 0);FastLED.show();
}

void wipefiveh(){
  leds[88] = CRGB(0, 0, 0);leds[89] = CRGB(0, 0, 0);leds[90] = CRGB(0, 0, 0);leds[91] = CRGB(0, 0, 0);FastLED.show();
}

void wipeeight(){
  leds[91] = CRGB(0, 0, 0);leds[92] = CRGB(0, 0, 0);leds[93] = CRGB(0, 0, 0);leds[94] = CRGB(0, 0, 0);leds[95] = CRGB(0, 0, 0);FastLED.show();
}

void wipetenh(){
  leds[95] = CRGB(0, 0, 0);leds[96] = CRGB(0, 0, 0);leds[97] = CRGB(0, 0, 0);FastLED.show();
}

void wipeseven(){
  leds[99] = CRGB(0, 0, 0);leds[100] = CRGB(0, 0, 0);leds[101] = CRGB(0, 0, 0);leds[102] = CRGB(0, 0, 0);leds[103] = CRGB(0, 0, 0);FastLED.show();
}

void wipethree(){
  leds[105] = CRGB(0, 0, 0);leds[106] = CRGB(0, 0, 0);leds[107] = CRGB(0, 0, 0);leds[108] = CRGB(0, 0, 0);leds[109] = CRGB(0, 0, 0);FastLED.show();
}

void wipetwelve(){
  leds[110] = CRGB(0, 0, 0);leds[111] = CRGB(0, 0, 0);leds[112] = CRGB(0, 0, 0);leds[113] = CRGB(0, 0, 0);leds[114] = CRGB(0, 0, 0);leds[115] = CRGB(0, 0, 0);FastLED.show();
}

void wipefour() {
  leds[117] = CRGB(0, 0, 0);leds[118] = CRGB(0, 0, 0);leds[119] = CRGB(0, 0, 0);leds[120] = CRGB(0, 0, 0);FastLED.show();
}

void wipepm(){
  leds[121] = CRGB(0, 0, 0);leds[122] = CRGB(0, 0, 0);FastLED.show();
}

void wipeam(){
  leds[124] = CRGB(0, 0, 0);leds[125] = CRGB(0, 0, 0);FastLED.show();
}

void wipeeleven(){
leds[126] = CRGB(0, 0, 0);leds[127] = CRGB(0, 0, 0);leds[128] = CRGB(0, 0, 0);leds[129] = CRGB(0, 0, 0);leds[130] = CRGB(0, 0, 0);leds[131] = CRGB(0, 0, 0);FastLED.show();
}
