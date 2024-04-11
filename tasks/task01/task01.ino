const int N = 5;

const int OUT[N] = {3, 5, 6, 9, 10};
const int DELTA[N] = {50, 100, 500, 1000, 10000};

unsigned long current_time;
unsigned long timestamp[N];
int state[N];

void setup() {

  current_time = micros();

  for (int i = 0; i < N; ++i) {
    
    timestamp[i] = current_time;

    pinMode(OUT[i], OUTPUT);
    state[i] = LOW;

  }
}

void loop() {

  current_time = micros();

  for (int i = 0; i < N; ++i)

    if (current_time - timestamp[i] > DELTA[i]) {
      
      timestamp[i] = current_time;
      
      if(state[i] == LOW)
        state[i] = HIGH;
      else
        state[i] = LOW;

      digitalWrite(OUT[i], state[i]);

  }
}
