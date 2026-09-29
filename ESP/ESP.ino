#define speaker 14

int START_SIGNAL[] = {1, 1, 1, 0, 1};
int FREQUENCIES[] = {500, 1000};

char LETTERS[] = "HELLO";
int lettercnt = strlen(LETTERS);

int payload[1000] = {};

int decodeLetters(char m[]) {
  lettercnt = strlen(m);

  int num;
  for (int i = 0; i < lettercnt; i++) {
    num = int(m[i]);
    Serial.print(m[i]); Serial.print(" "); Serial.print(num); Serial.print(" ");
    for (int j = 0; j < 8; j++) {
      payload[i*8 + j] = bitRead(num, j);
      Serial.print(bitRead(num, j));
    }
    Serial.println("");
  }
  return {};
}

int message[1000];

int sig = 0;
int freq = 500;

int BANDRATE = 2;

void setup() {
  Serial.begin(115200);
  delay(1000);

  decodeLetters(LETTERS);

  const int START_SIZE = sizeof(START_SIGNAL) / 4;
  const int PAYLOAD_SIZE = sizeof(payload) / 4;
  const int MSG_SIZE = START_SIZE + PAYLOAD_SIZE; 


  for (int i = 0; i < START_SIZE; i++) {
    message[i] = START_SIGNAL[i];
  }

  for (int i = 0; i < PAYLOAD_SIZE; i++) {
    message[START_SIZE + i] = payload[i];
  }
}

void loop() {
  int MSG_SIZE = sizeof(message);
  for (int i = 0; i < MSG_SIZE; i++) {

    sig = message[i];
    Serial.print(sig);
    
    freq = FREQUENCIES[sig];

    tone(speaker, freq, 1000/BANDRATE);
    
    delay(1000/BANDRATE);
  }
  delay(1000);
}
