//
//  main.cpp
//  SIngleCycleCheck
//
//  Created by adeeb mohammed on 01/05/20.
//  Copyright © 2020 adeeb mohammed. All rights reserved.
// program to find whether an array has a single cycle

#include <iostream>
#include <vector>

int getNextIndex(int currentIndex, std::vector<int> &array){
    int nextNumber = array.at(currentIndex);
    int nextIdx = (nextNumber+currentIndex) % (int)array.size();
    return  nextIdx >= 0 ? nextIdx : (int)array.size() + nextIdx;
}


bool hasSingleCycle(std::vector<int> array) {
    int numVisits = 0;
    int currentIndex = 0;
    while (numVisits < array.size()) {
        if (numVisits > 0 && currentIndex == 0) {
            return false;
        }
        currentIndex = getNextIndex(currentIndex, array);
        numVisits++;
    }
    return currentIndex == 0;
}


int main(int argc, const char * argv[]) {
    std::cout << "Single Cycle check in an array" << std::endl;
    std::cout << hasSingleCycle({2,4,5,-1,6});
    return 0;
}
