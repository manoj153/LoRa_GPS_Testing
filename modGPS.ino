#include <TinyGPS++.h>
#include <SoftwareSerial.h>
/*
   This sample code demonstrates the normal use of a TinyGPS++ (TinyGPSPlus) object.
   It requires the use of SoftwareSerial, and assumes that you have a
   4800-baud serial GPS device hooked up on pins 4(rx) and 3(tx).
*/
static const int RXPin = 4, TXPin = 3;
static const uint32_t GPSBaud = 9600;
double longi, lati;
uint32_t lg; uint32_t la;
// The TinyGPS++ object
TinyGPSPlus gps;

// The serial connection to the GPS device
SoftwareSerial ss(RXPin, TXPin);

void setup()
{
  //longi = (gps.location.lng()*1000000);
  //lati  = (gps.location.lat()*1000000);
  Serial.begin(57600);
  ss.begin(GPSBaud);
  for (int x = 0; x < 1; x ++)
  {
  Serial.print("radio set pwr 12\r\n");
  delay(50);
  //Serial.print("mac set ch dcycle 0 1\r\n");
  delay(50);
  Serial.print("mac set ch dcycle 1 1\r\n");
  delay(25);
  Serial.print("mac set ch dcycle 2 1\r\n");
  delay(25);
  Serial.print("mac set ch dcycle 3 1\r\n");
  delay(25);
  Serial.print("mac set ch dcycle 4 1\r\n");
  delay(25);
  Serial.print("mac set ch dcycle 4 1\r\n");
  delay(25);
  Serial.print("radio set sf sf12\r\n");
  delay(25);
  
//
  Serial.print("mac join otaa\r\n");
  delay(5000);
  Serial.print("mac forceENABLE\r\n");
  
  delay(6000);
//  //Serial.println("mac tx uncnf 2" + x+y +"\r\n");
  }
//
//  Serial.println(F("FullExample.ino"));
//  Serial.println(F("An extensive example of many interesting TinyGPS++ features"));
//  Serial.print(F("Testing TinyGPS++ library v. ")); Serial.println(TinyGPSPlus::libraryVersion());
//  Serial.println(F("by Mikal Hart"));
//  Serial.println();
//  Serial.println(F("Sats HDOP Latitude   Longitude   Fix  Date       Time     Date Alt    Course Speed Card  Distance Course Card  Chars Sentences Checksum"));
//  Serial.println(F("          (deg)      (deg)       Age                      Age  (m)    --- from GPS ----  ---- to London  ----  RX    RX        Fail"));
//  Serial.println(F("---------------------------------------------------------------------------------------------------------------------------------------"));
}

void loop()
{
  
  delay(2000);
   if(1)
   {
    String x;
    String y;
    longi = (gps.location.lng());
    lati  = (gps.location.lat());
    lg = longi*1000000;
    la = lati*1000000;
    x = String(lg, HEX);
    y = String(la, HEX);
    if(x.length() != 8)
    {
    x = "0" + x ;
    }
     if(y.length() != 8)
    {
    y = "00" + y ;
    }
   // Serial.print(x);Serial.print(" , "); Serial.print(lati);
//    Serial.print(x+y);
//    Serial.println();
//for (int x = 0; x < 1; x ++)
//  {
//  Serial.print("radio set pwr 14\r\n");
//  delay(50);
//  //Serial.print("mac set ch dcycle 0 1\r\n");
//  delay(50);
//  Serial.print("mac set ch dcycle 1 1\r\n");
//  delay(25);
//  Serial.print("mac set ch dcycle 2 1\r\n");
//  delay(25);
//  Serial.print("mac set ch dcycle 3 1\r\n");
//  delay(25);
//  Serial.print("mac set ch dcycle 4 1\r\n");
//  delay(25);
//  Serial.print("mac set ch dcycle 4 1\r\n");
//  delay(25);
////
//  Serial.println("mac join otaa\r\n");
//  delay(6000);
////  //Serial.println("mac tx uncnf 2" + x+y +"\r\n");
//  }
//Serial.print("mac join otaa\r\n");
delay(6000);
Serial.print("mac tx uncnf 2 " + x+y +"\r\n");
delay(100);
  
   }

//  printInt(gps.satellites.value(), gps.satellites.isValid(), 5);
//  printInt(gps.hdop.value(), gps.hdop.isValid(), 5);
 // printFloat(gps.location.lat(), gps.location.isValid(), 11, 6);
 //printFloat(gps.location.lng(), gps.location.isValid(), 12, 6);
  
//  printInt(gps.location.age(), gps.location.isValid(), 5);
//  printDateTime(gps.date, gps.time);
//  printFloat(gps.altitude.meters(), gps.altitude.isValid(), 7, 2);
//  printFloat(gps.course.deg(), gps.course.isValid(), 7, 2);
//  printFloat(gps.speed.kmph(), gps.speed.isValid(), 6, 2);
//  printStr(gps.course.isValid() ? TinyGPSPlus::cardinal(gps.course.deg()) : "*** ", 6);

//  unsigned long distanceKmToLondon =
//    (unsigned long)TinyGPSPlus::distanceBetween(
//      gps.location.lat(),
//      gps.location.lng(),
//      LONDON_LAT, 
//      LONDON_LON) / 1000;
//  printInt(distanceKmToLondon, gps.location.isValid(), 9);
//
//  double courseToLondon =
//    TinyGPSPlus::courseTo(
//      gps.location.lat(),
//      gps.location.lng(),
//      LONDON_LAT, 
//      LONDON_LON);
//
//  printFloat(courseToLondon, gps.location.isValid(), 7, 2);
//
//  const char *cardinalToLondon = TinyGPSPlus::cardinal(courseToLondon);
//
//  printStr(gps.location.isValid() ? cardinalToLondon : "*** ", 6);
//
//  printInt(gps.charsProcessed(), true, 6);
//  printInt(gps.sentencesWithFix(), true, 10);
//  printInt(gps.failedChecksum(), true, 9);
//  Serial.println();
//  
 smartDelay(1000);

//  if (millis() > 5000 && gps.charsProcessed() < 10)
//    Serial.println(F("No GPS data received: check wiring"));
}

// This custom version of delay() ensures that the gps object
// is being "fed".
static void smartDelay(unsigned long ms)
{
  unsigned long start = millis();
  do 
  {
    while (ss.available())
      gps.encode(ss.read());
  } while (millis() - start < ms);
}

static void printFloat(float val, bool valid, int len, int prec)
{
  if (!valid)
  {
    while (len-- > 1)
      Serial.print('*');
    Serial.print(' ');
  }
  else
  {
    Serial.print(val, prec);
    int vi = abs((int)val);
    int flen = prec + (val < 0.0 ? 2 : 1); // . and -
    flen += vi >= 1000 ? 4 : vi >= 100 ? 3 : vi >= 10 ? 2 : 1;
    for (int i=flen; i<len; ++i)
      Serial.print(' ');
  }
  smartDelay(0);
}

static void printInt(unsigned long val, bool valid, int len)
{
  char sz[32] = "*****************";
  if (valid)
    sprintf(sz, "%ld", val);
  sz[len] = 0;
  for (int i=strlen(sz); i<len; ++i)
    sz[i] = ' ';
  if (len > 0) 
    sz[len-1] = ' ';
  Serial.print(sz);
  smartDelay(0);
}

static void printDateTime(TinyGPSDate &d, TinyGPSTime &t)
{
  if (!d.isValid())
  {
    Serial.print(F("********** "));
  }
  else
  {
    char sz[32];
    sprintf(sz, "%02d/%02d/%02d ", d.month(), d.day(), d.year());
    Serial.print(sz);
  }
  
  if (!t.isValid())
  {
    Serial.print(F("******** "));
  }
  else
  {
    char sz[32];
    sprintf(sz, "%02d:%02d:%02d ", t.hour(), t.minute(), t.second());
    Serial.print(sz);
  }

  printInt(d.age(), d.isValid(), 5);
  smartDelay(0);
}

static void printStr(const char *str, int len)
{
  int slen = strlen(str);
  for (int i=0; i<len; ++i)
    Serial.print(i<slen ? str[i] : ' ');
  smartDelay(0);
}
