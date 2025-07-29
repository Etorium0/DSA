#include<iostream>
using namespace std;

struct Fish
{
    string name;
    float weight;
    string color;
    float length;
    float age;
    float averageWL;
};

void inputFish(Fish& fish) {
    cin >> fish.name;
    cin >> fish.weight;
    cin >> fish.color;
    cin >> fish.length;
    cin >> fish.age;
    fish.averageWL = (fish.weight + fish.length) / 2;
}

void inputFishArray(Fish* fishArray, int size) {
    for (int i = 0; i < size; i++) {
        inputFish(fishArray[i]);
    }
}

void outputFish(const Fish& fish) {
    cout << fish.name << " ";
    cout << fish.weight << " ";
    cout << fish.color << " ";
    cout << fish.length << " ";
    cout << fish.age << endl;
}

// Hàm in danh sách cá
void outputFishArray(Fish* fishArray, int size) {
    for (int i = 0; i < size; i++) {
        outputFish(fishArray[i]);
    }
}

void FishByAverageWL(Fish* fishArray, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (fishArray[j].averageWL > fishArray[j + 1].averageWL) {
                swap(fishArray[j], fishArray[j + 1]);
            }
        }
    }
}

// Print Fish at k:
void printFishAtK(Fish* fishArray, int k) {
    outputFish(fishArray[k]);
}

void findFishNearestToAverage(Fish* fishArray, int size, float average) {
    float minDiff = 999999.0;
    int nearestIndex = -1;

    for (int i = 0; i < size; i++) {
        float diff = fishArray[i].averageWL - average;
        if (diff < 0) diff = -diff; 
        if (diff < minDiff) {
            minDiff = diff;
            nearestIndex = i;
        }
    }

    if (nearestIndex != -1) {
        outputFish(fishArray[nearestIndex]);
    } else {
        cout << "No fish found." << endl;
    }
}

int main() 
{
    int n;
    cin >> n;
    Fish* fishArray = new Fish[n];
    
    inputFishArray(fishArray, n);

    FishByAverageWL(fishArray, n);

    int k;
    cin >> k;
    if (k >= 0 && k < n) {
        printFishAtK(fishArray, k);
    } else {
        cout << "Invalid index" << endl;
    }

    float aver;
    cin >> aver;
    findFishNearestToAverage(fishArray, n, aver);

    delete[] fishArray;
    return 0;
}