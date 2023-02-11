int seg[] = {2,7,11,9,8,3,12};
int digits[] = {4, 5, 6, 13};

int vals[][7] = {
 {1,1,1,1,1,1,0},
 {0,1,1,0,0,0,0},
 {1,1,0,1,1,0,1},
 {1,1,1,1,0,0,1},
 {0,1,1,0,0,1,1},
 {1,0,1,1,0,1,1},
 {1,0,1,1,1,1,1},
 {1,1,1,0,0,0,0},
 {1,1,1,1,1,1,1},
 {1,1,1,1,0,1,1}
};

int LOADING_WAIT = 30;

int oneSegs[][7] = {
  {1,0,0,0,0,0},
  {0,1,0,0,0,0},
  {0,0,1,0,0,0},
  {0,0,0,1,0,0},
  {0,0,0,0,1,0},
  {0,0,0,0,0,1}
};

void clear(){
  for(int i = 0; i < 7; i++){
    digitalWrite(seg[i], LOW);
  }
  for(int i = 0; i<4; i++){
    digitalWrite(digits[i], HIGH);
  }
}

void writeDig(int num[], int digit){
  digitalWrite(digits[digit], LOW);

  for(int i = 0; i<7; i++){
    digitalWrite(seg[i], num[i]);
    delay(0.9);
  }
}

void setup() {
  for(int i = 0; i < 7; i++){
    pinMode(seg[i], OUTPUT);
  }
  for(int i = 0; i<4; i++){
    pinMode(digits[i], OUTPUT);
  }
  clear();
}

void writedigit(int num){
  clear();
  writeDig(vals[(num/1000) % 10], 0);
  clear();
  writeDig(vals[(num/100) % 10], 1);
  clear();
  writeDig(vals[(num/10) % 10], 2);
  clear();
  writeDig(vals[num % 10], 3);
  clear();
}

void loading(){
  writeDig(oneSegs[0], 0);
  delay(LOADING_WAIT);
  clear();
  writeDig(oneSegs[0], 1);
  delay(LOADING_WAIT);
  clear();
  writeDig(oneSegs[0], 2);
  delay(LOADING_WAIT);
  clear();
  writeDig(oneSegs[0], 3);
  delay(LOADING_WAIT);
  clear();
  writeDig(oneSegs[1], 3);
  delay(LOADING_WAIT);
  clear();
  writeDig(oneSegs[2], 3);
  delay(LOADING_WAIT);
  clear();
  writeDig(oneSegs[3], 3);
  delay(LOADING_WAIT);
  clear();
  writeDig(oneSegs[3], 2);
  delay(LOADING_WAIT);
  clear();
  writeDig(oneSegs[3], 1);
  delay(LOADING_WAIT);
  clear();
  writeDig(oneSegs[3], 0);
  delay(LOADING_WAIT);
  clear();
  writeDig(oneSegs[4], 0);
  delay(LOADING_WAIT);
  clear();
  writeDig(oneSegs[5], 0);
  delay(LOADING_WAIT);
  clear();
}

void loop() {
  for(int j = 0; j < 1000; j++){
    for(int i = 0; i < 1; i++){
      writedigit(j);
      delay(1);
    }
  }
  while(1){
    loading();
  }
  exit(0);
//}
}
