## Project Documentation
----------

Project Structure
---------------

```
Inheritance/
├── SBase/                 #  Base class for number suppliers
│   └── SBase.h            #  Abstract base class definition
├── SFile/                 #  File input implementation
│   ├── SFile.h            #  File input header
│   └── SFile.cpp          #  File input implementation
├── SKbrd/                 #  Keyboard input implementation
│   ├── SKbrd.h            #  Keyboard input header
│   └── SKbrd.cpp          #  Keyboard input implementation
├── SQueue/                #  Queue input implementation
│   ├── SQueue.h           #  Queue input header
│   └── SQueue.cpp         #  Queue input implementation
├── Freq/                  #  Frequency processor
│   ├── Freq.h             #  Frequency processor header
│   └── Freq.cpp           #  Frequency processor implementation
├── Diap/                  #  Range processor
│   ├── Diap.h             #  Range processor header
│   └── Diap.cpp           #  Range processor implementation
├── styles/                #  Style implemenation
│   └── styles.h           #  Style and ASCII art for CLI
├── main.cpp               #  Main program entry point
└── Makefile               #  Makefile to build the program
```

Code Documentation
----------------

1. Base Class : `SBase`
###### `SBase/SBase.h`
```cpp
#ifndef SBASE_H
#define SBASE_H

class SBase {
public:
    virtual ~SBase() = default;
    virtual int Get() = 0; // to get next number
};

#endif // SBASE_H
```

2. File Input : `SFile`
###### `SFile/SFile.h`
```cpp
#ifndef SFILE_H
#define SFILE_H

#include "../SBase/SBase.h"
#include <fstream>
#include <string>

class SFile : public SBase {
private:
    std::ifstream file;

public:
    explicit SFile(const std::string& filename);
    ~SFile() override;
    int Get() override;
};

#endif // SFILE_H
```

###### `SFile/SFile.cpp`
```cpp
#include "SFile.h"

SFile::SFile(const std::string& filename) {
    file.open(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file: " + filename);
    }
}

SFile::~SFile() {
    if (file.is_open()) {
        file.close();
    }
}

int SFile::Get() {
    int num;
    if (file >> num) {
        return num;
    }
    return -1; // end of file is reached
}
```

3. Keyboard Input : `SKbrd`
##### `SKbrd/SKbrd.h`
```cpp
#ifndef SKBRD_H
#define SKBRD_H

#include "../SBase/SBase.h"

class SKbrd : public SBase {
public:
    SKbrd() = default;
    ~SKbrd() override = default;
    int Get() override;
};

#endif // SKBRD_H
```

##### `SKbrd/SKbrd.cpp`
```cpp
#include "SKbrd.h"
#include <iostream>

int SKbrd::Get() {
    int num;
    std::cout << "Enter a number (-1 to end): ";
    if (std::cin >> num) {
        return num;
    }
    return -1;
}
```

4. Queue Input : `SQueue`
##### `SQueue/SQueue.h`
```cpp
#ifndef SQUEUE_H
#define SQUEUE_H

#include "../SBase/SBase.h"
#include <vector>
#include <cstddef>

class SQueue : public SBase {
private:
    std::vector<int> numbers;
    size_t current_index;

public:
    explicit SQueue(size_t length);
    ~SQueue() override = default;
    int Get() override;
};

#endif // SQUEUE_H
```

##### `SQueue/SQueue.cpp`
```cpp
#include "SQueue.h"
#include <random>

SQueue::SQueue(size_t length) : current_index(0) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 100);

    numbers.reserve(length);
    for (size_t i = 0; i < length; ++i) {
        numbers.push_back(dis(gen));
    }
}

int SQueue::Get() {
    if (current_index < numbers.size()) {
        return numbers[current_index++];
    }
    return -1;
}
```

5. Frequency Processor : `Freq`
##### `Freq/Freq.h`
```cpp
#ifndef FREQ_H
#define FREQ_H

#include "../SBase/SBase.h"
#include <map>
#include <iostream>

class Freq {
protected:
    std::map<int, int> frequencies;
    int total_sum;

public:
    Freq() : total_sum(0) {}
    virtual ~Freq() = default;
    
    virtual void Calc(SBase* source);
    
    friend std::ostream& operator<<(std::ostream& os, const Freq& freq);
};

#endif // FREQ_H
```

##### `Freq/Freq.cpp`
```cpp
#include "Freq.h"

void Freq::Calc(SBase* source) {
    frequencies.clear();
    total_sum = 0;
    
    while (true) {
        int num = source->Get();
        if (num < 0) break;
        
        frequencies[num]++;
        total_sum += num;
    }
}

std::ostream& operator<<(std::ostream& os, const Freq& freq) {
    os << "Number frequencies:\\n";
    for (const auto& pair : freq.frequencies) {
        os << "Number " << pair.first << " appears " << pair.second << " times\\n";
    }
    os << "Total sum: " << freq.total_sum << "\\n";
    return os;
}
```

6. Range Processor : `Diap`
##### `Diap/Diap.h`
```cpp

#ifndef DIAP_H
#define DIAP_H

#include "../Freq/Freq.h"
#include <limits>

class Diap : public Freq {
private:
    int min_value;
    int max_value;
    int count;

public:
    Diap() : min_value(std::numeric_limits<int>::max()), 
             max_value(std::numeric_limits<int>::min()),
             count(0) {}
    
    void Calc(SBase* source) override;
    
    friend std::ostream& operator<<(std::ostream& os, const Diap& diap);
};

#endif // DIAP_H
```

##### `Diap/Diap.cpp`
```cpp
#include "Diap.h"

void Diap::Calc(SBase* source) {
    min_value = std::numeric_limits<int>::max();
    max_value = std::numeric_limits<int>::min();
    count = 0;
    
    while (true) {
        int num = source->Get();
        if (num < 0) break;
        
        min_value = std::min(min_value, num);
        max_value = std::max(max_value, num);
        count++;
    }
}

std::ostream& operator<<(std::ostream& os, const Diap& diap) {
    if (diap.count > 0) {
        os << "Range statistics:\\n"
           << "Minimum value: " << diap.min_value << "\\n"
           << "Maximum value: " << diap.max_value << "\\n"
           << "Number count: " << diap.count << "\\n";
    } else {
        os << "No numbers were processed\\n";
    }
    return os;
}
```

7. Main Program (`main.cpp`)
```cpp
#include "SFile/SFile.h"
#include "SKbrd/SKbrd.h"
#include "SQueue/SQueue.h"
#include "Freq/Freq.h"
#include "Diap/Diap.h"
#include "styles/styles.h"
#include <iostream>
#include <fstream>
#include <sstream>


void createSampleFile(const std::string& filename);

// captures the output of a processor
template<typename T>
std::string captureOutput(const T& processor) {
    std::stringstream ss;
    ss << processor;
    return ss.str();
}

int main() {
    std::cout << Style::Color::BRIGHT_MAGENTA 
        << Style::Format::BOLD 
        << Style::Art::WELCOME 
        << Style::Color::RESET << "\n\n";


    createSampleFile("numbers.txt");

    // instances of data suppliers
    SFile fileSupplier("numbers.txt");
    SKbrd kbrdSupplier;
    SQueue queueSupplier(5);

    // instances of processors
    Freq freqProcessor;
    Diap diapProcessor;


    // file input
    Style::printHeader("Файловый ввод ", Style::Art::FILE_SECTION);
    Style::printPrompt("Обработка частот:");
    freqProcessor.Calc(&fileSupplier);
    Style::printResult(captureOutput(freqProcessor));

    // new file
    SFile fileSupplier2("numbers.txt");
    Style::printPrompt("\nОбработка диапазона:");
    diapProcessor.Calc(&fileSupplier2);
    Style::printResult(captureOutput(diapProcessor));


    // keyboard input
    Style::printHeader("Клавиатурный ввод", Style::Art::KEYBOARD_SECTION);
    Style::printPrompt("Введите числа для анализа частот:");
    Style::printHint("Введите -1 для завершения ввода");


    freqProcessor.Calc(&kbrdSupplier);
    Style::printResult(captureOutput(freqProcessor));

    Style::printPrompt("\nВведите числа для анализа диапазона:");
    Style::printHint("Введите -1 для завершения ввода");
    diapProcessor.Calc(&kbrdSupplier);
    Style::printResult(captureOutput(diapProcessor));


    // with queue input
    Style::printHeader("Очередь ввод  ", Style::Art::QUEUE_SECTION);
    Style::printPrompt("Обработка частот:");
    
    freqProcessor.Calc(&queueSupplier);
    Style::printResult(captureOutput(freqProcessor));

    // new queue
    SQueue queueSupplier2(5);
    Style::printPrompt("\nОбработка диапазона:");
    diapProcessor.Calc(&queueSupplier2);
    Style::printResult(captureOutput(diapProcessor));


    Style::printSeparator("fancy");
    std::cout << Style::Color::BRIGHT_MAGENTA 
              << Style::Format::BOLD 
              << Style::Art::COMPLETION 
              << Style::Color::RESET << "\n";

    return 0;
}



void createSampleFile(const std::string& filename) {
    std::ofstream file(filename);
    file << "1 2 3 2 4 1 5 3 2 1\n";
    file.close();
}
```


##### `main.cpp` Without Styling
```cpp
#include "SFile/SFile.h"
#include "SKbrd/SKbrd.h"
#include "SQueue/SQueue.h"
#include "Freq/Freq.h"
#include "Diap/Diap.h"
#include <iostream>
#include <fstream>

// Helper function to create a sample input file
void createSampleFile(const std::string& filename) {
    std::ofstream file(filename);
    file << "1 2 3 2 4 1 5 3 2 1\n";
    file.close();
}

int main() {
    // Create a sample input file
    createSampleFile("numbers.txt");

    // Create instances of data suppliers
    SFile fileSupplier("numbers.txt");
    SKbrd kbrdSupplier;
    SQueue queueSupplier(5); // Queue with 5 random numbers

    // Create instances of processors
    Freq freqProcessor;
    Diap diapProcessor;

    // Test with file input
    std::cout << "\n=== Testing with file input ===\n";
    std::cout << "Processing frequencies:\n";
    freqProcessor.Calc(&fileSupplier);
    std::cout << freqProcessor;

    // Create a new file supplier since the previous one reached EOF
    SFile fileSupplier2("numbers.txt");
    std::cout << "\nProcessing range:\n";
    diapProcessor.Calc(&fileSupplier2);
    std::cout << diapProcessor;

    // Test with keyboard input
    std::cout << "\n=== Testing with keyboard input ===\n";
    std::cout << "Enter numbers for frequency analysis:\n";
    freqProcessor.Calc(&kbrdSupplier);
    std::cout << freqProcessor;

    std::cout << "\nEnter numbers for range analysis:\n";
    diapProcessor.Calc(&kbrdSupplier);
    std::cout << diapProcessor;

    // Test with queue input
    std::cout << "\n=== Testing with queue input ===\n";
    std::cout << "Processing frequencies:\n";
    freqProcessor.Calc(&queueSupplier);
    std::cout << freqProcessor;

    // Create a new queue supplier since the previous one is exhausted
    SQueue queueSupplier2(5);
    std::cout << "\nProcessing range:\n";
    diapProcessor.Calc(&queueSupplier2);
    std::cout << diapProcessor;

    return 0;
}
```

8. Styles 
##### `styles/styles.h`
```cpp
#ifndef CLI_STYLE_H
#define CLI_STYLE_H

#include <string>
#include <iostream>
#include <iomanip>

namespace Style {
    namespace Color {
        const std::string RESET        = "\033[0m";
        const std::string BLACK        = "\033[30m";
        const std::string RED          = "\033[31m";
        const std::string GREEN        = "\033[32m";
        const std::string YELLOW       = "\033[33m";
        const std::string BLUE         = "\033[34m";
        const std::string MAGENTA      = "\033[35m";
        const std::string CYAN         = "\033[36m";
        const std::string WHITE        = "\033[37m";
        const std::string BRIGHT_BLACK   = "\033[90m";
        const std::string BRIGHT_RED     = "\033[91m";
        const std::string BRIGHT_GREEN   = "\033[92m";
        const std::string BRIGHT_YELLOW  = "\033[93m";
        const std::string BRIGHT_BLUE    = "\033[94m";
        const std::string BRIGHT_MAGENTA = "\033[95m";
        const std::string BRIGHT_CYAN    = "\033[96m";
        const std::string BRIGHT_WHITE   = "\033[97m";
    }

    namespace Format {
        const std::string BOLD          = "\033[1m";
        const std::string DIM           = "\033[2m";
        const std::string ITALIC        = "\033[3m";
        const std::string UNDERLINE     = "\033[4m";
        const std::string BLINK         = "\033[5m";
        const std::string REVERSE       = "\033[7m";
        const std::string HIDDEN        = "\033[8m";
        const std::string DOUBLE_UNDERLINE = "\033[21m";
    }

    namespace Background {
        const std::string BLACK   = "\033[40m";
        const std::string RED     = "\033[41m";
        const std::string GREEN   = "\033[42m";
        const std::string YELLOW  = "\033[43m";
        const std::string BLUE    = "\033[44m";
        const std::string MAGENTA = "\033[45m";
        const std::string CYAN    = "\033[46m";
        const std::string WHITE   = "\033[47m";
    }

    namespace Frame {
        const std::string TOP     = "╔════════════════════════════════════════════════════╗";
        const std::string BOTTOM  = "╚════════════════════════════════════════════════════╝";
        const std::string LINE    = "║";
        const std::string LIGHT_TOP    = "┌────────────────────────────────────────────────────┐";
        const std::string LIGHT_BOTTOM = "└────────────────────────────────────────────────────┘";
        const std::string LIGHT_LINE   = "│";
        const std::string SEPARATOR_DOUBLE = "═══════════════════════════════════════════════════════";
        const std::string SEPARATOR_SINGLE = "───────────────────────────────────────────────────────";
        const std::string SEPARATOR_FANCY  = "•❈•════════════════════════════════════════════════════════════════════•❈•";
    }

    namespace Art {
        const std::string WELCOME = R"(
            ╔══════════════════════════════════════════════════════════════╗
            ║  ████████                                                    ║
            ║   ██   ██                                   ███              ║
            ║   ██   ██  █████   █████    █████  █████      ██  ██   ██    ║
            ║   ██   ██ ██   ██ ██       ██  ██ ██   ██   ████  ██   ██    ║
            ║   ██   ██ ██   ██ ██       ██  ██ ██████   ██  ██ ███████    ║
            ║   ██   ██ ██   ██ ██       ██  ██ ██      ██   ██ ██   ██    ║
            ║   ██   ██  █████   █████  ██   ██  █████   █████  ██   ██    ║
            ║                                                              ║
            ║            █████   █████        █████  ████    █████         ║
            ║           ██  ██  ██  ██       ██  ██     ██  ██             ║
            ║            █████   █████       ██  ██  █████  ██████         ║
            ║           ██  ██  ██  ██       ██  ██ ██  ██  ██   ██        ║
            ║          ██   ██ ██   ██      ██   ██  ████   ██████         ║
            ╚══════════════════════════════════════════════════════════════╝)";

        const std::string COMPLETION = R"(
            ★・・・・・・★・・・・・・★・・・・・・★・・・・・・★
            ・        🎉 Program Completed Successfully! 🎉     ・  
            ★・・・・・・★・・・・・・★・・・・・・★・・・・・・★)";

        const std::string FILE_SECTION = "📂";
        const std::string KEYBOARD_SECTION = "⌨️";
        const std::string QUEUE_SECTION = "🔄";

    }

    inline void printHeader(const std::string& title, const std::string& icon = "") {
        using namespace Color;
        using namespace Format;
        using namespace Frame;

        std::cout << BRIGHT_CYAN << TOP << RESET << "\n";
        if (!icon.empty()) {
            std::cout << BRIGHT_CYAN << LINE << RESET 
                << BOLD << BRIGHT_YELLOW << std::setw(20) << icon << "  " << title 
                << std::setw(18) << "" << RESET 
                << BRIGHT_CYAN << LINE << RESET << "\n"
                << BRIGHT_CYAN << BOTTOM << RESET << "\n";
        }else{
            std::cout << BRIGHT_CYAN << LINE << RESET 
                << BOLD << BRIGHT_YELLOW << std::setw(20) << "   " << title 
                << std::setw(18) << "" << RESET 
                << BRIGHT_CYAN << LINE << RESET << "\n"
                << BRIGHT_CYAN << BOTTOM << RESET << "\n";
        }

    }

    inline void printPrompt(const std::string& message) {
        std::cout << Color::BRIGHT_GREEN << Format::BOLD 
                 << "➤ " << message << Color::RESET << "\n";
    }

    inline void printHint(const std::string& hint) {
        std::cout << Color::BRIGHT_YELLOW << Format::ITALIC 
                 << "💡 " << hint << Color::RESET << "\n";
    }

    inline void printResult(const std::string& result) {
        std::cout << Color::BRIGHT_BLUE << Format::BOLD 
                 << result << Color::RESET;
    }

    inline void printError(const std::string& error) {
        std::cout << Color::BRIGHT_RED << Format::BOLD 
                 << "❌ " << error << Color::RESET << "\n";
    }

    inline void printSuccess(const std::string& message) {
        std::cout << Color::BRIGHT_GREEN << Format::BOLD 
                 << "✓ " << message << Color::RESET << "\n";
    }

    inline void printSeparator(const std::string& style = "double") {
        if (style == "double") {
            std::cout << Color::BRIGHT_CYAN << Frame::SEPARATOR_DOUBLE << Color::RESET << "\n";
        } else if (style == "fancy") {
            std::cout << Color::BRIGHT_MAGENTA << Frame::SEPARATOR_FANCY << Color::RESET << "\n";
        } else {
            std::cout << Color::BRIGHT_WHITE << Frame::SEPARATOR_SINGLE << Color::RESET << "\n";
        }
    }
}

#endif // CLI_STYLE_H
```