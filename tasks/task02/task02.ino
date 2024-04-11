#include <TaskManagerIO.h>

#define setFixedRate(i) \
  taskManager.scheduleFixedRate(DELTA[i], [] {  \
    if(state[i] == LOW) \
      state[i] = HIGH;  \
    else  \
      state[i] = LOW; \
  \
    digitalWrite(OUT[i], state[i]); \
  }, TIME_MICROS);  

const int N = 5;

const int OUT[N] = {3, 5, 6, 9, 10};
const int DELTA[N] = {50, 100, 500, 1000, 10000};

int state[N];

void setup() {

  for (int i = 0; i < N; ++i) {

    pinMode(OUT[i], OUTPUT);
    state[i] = LOW;

  }

  setFixedRate(0);
  setFixedRate(1);
  setFixedRate(2);
  setFixedRate(3);
  setFixedRate(4);

}

void loop() {
  taskManager.runLoop();
}

