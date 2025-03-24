#include "SFile/SFile.h"
#include "SKbrd/SKbrd.h"
#include "SQueue/SQueue.h"
#include "Freq/Freq.h"
#include "Diap/Diap.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "styles/styles.h"


void createSampleFile(const std::string& filename);

// captures the output of a processor
template<typename T>
std::string captureOutput(const T& processor) {
    std::stringstream ss;
    ss << processor;
    return ss.str();
}

int main() {

    createSampleFile("numbers.txt");

    // instances of data suppliers
    SFile fileSupplier("numbers.txt");
    SKbrd kbrdSupplier;
    SQueue queueSupplier(5);

    // instances of processors
    Freq freqProcessor;
    Diap diapProcessor;


    // file input
    Style::printHeader("Файловый ввод ");
    Style::printPrompt("Обработка частот:");
    freqProcessor.Calc(&fileSupplier);
    Style::printResult(captureOutput(freqProcessor));

    // new file
    SFile fileSupplier2("numbers.txt");
    Style::printPrompt("\nОбработка диапазона:");
    diapProcessor.Calc(&fileSupplier2);
    Style::printResult(captureOutput(diapProcessor));




    // keyboard input
    Style::printHeader("Клавиатурный ввод");
    Style::printPrompt("Введите числа для анализа частот:");
    Style::printHint("Введите -1 для завершения ввода");



    freqProcessor.Calc(&kbrdSupplier);
    Style::printResult(captureOutput(freqProcessor));

    Style::printPrompt("\nВведите числа для анализа диапазона:");
    Style::printHint("Введите -1 для завершения ввода");
    diapProcessor.Calc(&kbrdSupplier);
    Style::printResult(captureOutput(diapProcessor));



    // with queue input
    Style::printHeader("Очередь ввод :");
    Style::printPrompt("Обработка частот:");
    
    freqProcessor.Calc(&queueSupplier);
    Style::printResult(captureOutput(freqProcessor));

    // new queue
    SQueue queueSupplier2(5);
    Style::printPrompt("\nОбработка диапазона:");
    diapProcessor.Calc(&queueSupplier2);
    Style::printResult(captureOutput(diapProcessor));


    return 0;
}



void createSampleFile(const std::string& filename) {
    std::ofstream file(filename);
    file << "1 2 3 2 4 1 5 3 2 1\n";
    file.close();
}