#include <Snoring_Detection_inferencing.h>
#define MIC_PIN A0
SnoringDetection snoreDetector;
void setup() {
  snoreDetector.init();
  snoreDetector.startMic(MIC_PIN);
}
void loop() {
  // Get the microphone data
  float* micData = snoreDetector.getMicData();

  // Classify the microphone data as snoring or not snoring
  bool isSnoring = snoreDetector.classify(micData);

  // If the microphone data is classified as snoring, print a message to the serial monitor
  if (isSnoring) {
    Serial.println("Snoring detected!");
  } else {
    Serial.println("Not snoring");
  }
}
