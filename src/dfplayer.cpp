#include "dfplayer.h"

//------------------------------------------------------------------------
// ERROR HANDLE CLASS (REQUIRED)
//------------------------------------------------------------------------
class Mp3Notify
{
public:
  static void PrintlnSourceAction(DfMp3_PlaySources source, const char* action)
  {
    if (source & DfMp3_PlaySources_Sd) 
    {
        Serial.print("SD Card, ");
    }
    if (source & DfMp3_PlaySources_Usb) 
    {
        Serial.print("USB Disk, ");
    }
    if (source & DfMp3_PlaySources_Flash) 
    {
        Serial.print("Flash, ");
    }
    Serial.println(action);
  }
  static void OnError(DFMiniMp3<SoftwareSerial, Mp3Notify>& mp3,uint16_t errorCode)
  {
    // see DfMp3_Error for code meaning
    Serial.println();
    Serial.print("Com Error ");
    Serial.println(errorCode);
  }
  static void OnPlayFinished(DFMiniMp3<SoftwareSerial, Mp3Notify>& mp3, DfMp3_PlaySources source, uint16_t track)
  {
    Serial.print("Play finished for #");
    Serial.println(track);  
  }
  static void OnPlaySourceOnline(DFMiniMp3<SoftwareSerial, Mp3Notify>& mp3, DfMp3_PlaySources source)
  {
    PrintlnSourceAction(source, "online");
  }
  static void OnPlaySourceInserted(DFMiniMp3<SoftwareSerial, Mp3Notify>& mp3, DfMp3_PlaySources source)
  {
    PrintlnSourceAction(source, "inserted");
  }
  static void OnPlaySourceRemoved(DFMiniMp3<SoftwareSerial, Mp3Notify>& mp3, DfMp3_PlaySources source)
  {
    PrintlnSourceAction(source, "removed");
  }
};

//------------------------------------------------------------------------
// OBJECTS
//------------------------------------------------------------------------
// Use a digital pin as a serial bus with the SoftwareSerial library
SoftwareSerial secondarySerial(GPIO_DFPLAYER_RX, GPIO_DFPLAYER_TX); // RX, TX
DFMiniMp3<SoftwareSerial, Mp3Notify> mp3(secondarySerial);

//------------------------------------------------------------------------
// INITIALIZATION FUNCTIONS 
//------------------------------------------------------------------------
void dfplayer_setup() {

  Serial.println("Initializing DFplayer...");  // Only for DEBUG
  mp3.begin();                                 // Initialize DFplayer object
  mp3.setVolume(VOLUME);                       // Set volume (from 0 to 30)

}

//------------------------------------------------------------------------
// ACTION FUNCTIONS 
//------------------------------------------------------------------------
void dfplayer_play(int *audio_folder, int *audio_position) {

  // sd:/audio_folder/00XX.mp3 (XX=button_Position)
  mp3.playFolderTrack16 (*audio_folder,*audio_position);
  
}