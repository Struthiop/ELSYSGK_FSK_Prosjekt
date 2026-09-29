#define speaker 14

int START_SIGNAL[] = {1, 1, 1, 0, 1};
int FREQUENCIES[] = {500, 1000};

char letters[] = "HELLO";

int encodeLetters(m) {
  
}

int PAYLOAD[] = {0, 1, 0, 1, 0, 1, 0, 1};

const int START_SIZE = sizeof(START_SIGNAL) / 4;
const int PAYLOAD_SIZE = sizeof(PAYLOAD) / 4;
const int MSG_SIZE = START_SIZE + PAYLOAD_SIZE; 

int message[MSG_SIZE];

int sig = 0;
int freq = 500;

int BANDRATE = 2;

void setup() {
  for (int i = 0; i < START_SIZE; i++) {
    message[i] = START_SIGNAL[i];
  }

  for (int i = 0; i < PAYLOAD_SIZE; i++) {
    message[START_SIZE + i] = PAYLOAD[i];
  }
}

void loop() {
  for (int i = 0; i < MSG_SIZE; i++) {
    sig = message[i];
    Serial.print(sig);
    
    freq = FREQUENCIES[sig];

    tone(speaker, freq, 1000/BANDRATE);
    
    delay(1000/BANDRATE);
  }

}
