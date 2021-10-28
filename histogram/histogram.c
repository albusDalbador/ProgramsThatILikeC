#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32
    #include <Windows.h>
#else  
    #include <unistd.h>
#endif

#define DATA_SIZE 1000
#define HIST_WIDTH 50
#define SCALE_HEIGHT 20

float *generateDataForHistogram();
int *parseDataIntoIntArray(float*);
void createHistogram(int*,int*);
int *createScaleForParsedData(int*);

int main (int argc, int *argv[]) {

    // float *data = generateDataForHistogram();

    int *parsedData = parseDataIntoIntArray(generateDataForHistogram());
    int *scale = createScaleForParsedData(parsedData);

    createHistogram(parsedData,scale);

    
    return 0;
}

void createHistogram(int *parsedData, int *scale) {
    
    for (int i = SCALE_HEIGHT; i > 0; i--) {
        for (int j = 0; j < HIST_WIDTH; j++) {
            
            if (parsedData[i] >= SCALE_HEIGHT*scale[i]) printf("|");
            else printf(" ");

        }
        printf("%.2f\n",scale[i]);
    }
}

int *createScaleForParsedData(int *parsedData) {
    int maxValue = 0;
    for (int i = 0 ; i < HIST_WIDTH; i++) {
        if (parsedData[i] > maxValue) maxValue = parsedData[i];
    }

    int *result = malloc(sizeof(int)*SCALE_HEIGHT);

    for (int i = 0; i < SCALE_HEIGHT; i++) {
        result[i] = maxValue/SCALE_HEIGHT*i; //max value will not be shown
    }

    return result;
}

int *parseDataIntoIntArray(float *data) {
    int *result = malloc(sizeof(int) *HIST_WIDTH);

    for (int i = 0; i< HIST_WIDTH; i++) {
        result[i] = 0;
    }
    for (int i = 0; i < DATA_SIZE; i++) {
        int index = (int)(data[i]*HIST_WIDTH);
        result[index]++;
    }

    return result;
}

float *generateDataForHistogram() {
    float *result = malloc(sizeof(float) * 1000);

    // srand(time(NULL));

    for (int i = 0; i < DATA_SIZE; i++) {
        float a = (float)(rand())/RAND_MAX;
        float b = (float)(rand())/RAND_MAX;
        float c = (float)(rand())/RAND_MAX;        
        
        result[i] = (a+b+c)/3;
    }

    return result;
}

