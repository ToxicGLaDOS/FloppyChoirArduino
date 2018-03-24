int* makePeriods(int inArray [], const int len){
  int* outArray = new int [len];
  for(int i=0; i<len; i++){
    outArray[i] = 1.0/inArray[i];
  }
  return outArray;
}

int* copyArray(int inArray [], const int len){
  int* outArray = new int[len];
  for(int i=0; i<len; i++){
    outArray[i] = inArray[i];
  }
  return outArray;
}

int min(const int inArray [], const int len){
    // Gets index of minimum value in int array
    int min = 0;
    for(int i=0; i<len; i++){
        if(inArray[i] < min){
            min = i;
        }
    }
    return min;
}

void setup() {
  // put your setup code here, to run once:

}

void loop() {
    const int arraySize = 10;
    int frequencies [arraySize];
    const int* notePeriodsOrig = makePeriods(frequencies, arraySize);
    int* notePeriods = makePeriods(frequencies, arraySize);


    int minIndex = min(notePeriods, arraySize);
    int minimum = notePeriods[minIndex];
    

    for(int i=0; i<arraySize; i++){
        notePeriods[i] -= minimum;
    }

    // Reset that period back to full length because we have to wait 
    // another full period before it plays again
    notePeriods[minIndex] = notePeriodsOrig[minIndex];

    // wait for "minimum" time
    // step a motor

    





}

int main(){
    setup();
    while (1){
        loop();
    }
}