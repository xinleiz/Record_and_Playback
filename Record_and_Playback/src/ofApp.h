#pragma once

#include "ofMain.h"
#define LENGTH 44100 * 6 //6 secs

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    

/************************ Audio Processing Related Functions and variables *********************** */
    
    
    void drawRecordingProgressWithBackground();
    void drawPlaybackProgressWithBackground();
    
    void audioReceived( float * input, int bufferSize, int nChannels );
    void audioRequested( float * output, int bufferSize, int nChannels );

    int ratio = LENGTH / ofGetWidth(); //ratio is the average width(pixels) of each sample
    float buffer[LENGTH]; //audioBuffer
    
    float recordingBuffer[LENGTH]; // buffer for recording sound
    float playbackBuffer[LENGTH];  // buffer for storing playback data;
    
    int recordingProgressIndex;// Index for current recording position
    int playbackProgressIndex;// Index for current playback position
    
    int sampleRate; //sampleRate
    int recPos; //Record位置
    int playPos; //Playback Position
    int mode; //現在のmode、0:off, 1:recording, 2:play
    

    
};
