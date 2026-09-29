#define speaker 14

int START_SIGNAL[5] = {1, 1, 1, 0, 1};

int FREQUENCIES[2] = {500, 1000};

int sig = 0;
int freq = 500;

void setup() {
  
}

void loop() {
  for (int i = 0; i <= 5; i++) {
    sig = START_SIGNAL[i];
    freq = FREQUENCIES[sig];

    tone(speaker, freq, 1000);
    delay(1000);
  }

}
