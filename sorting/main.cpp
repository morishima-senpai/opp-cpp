/* DSA Lab 1 : Sorting */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <vector>

#include "Sort/Sort.h"
#include "Participant/Participant.h"
#include "styles/styles.h"


bool write_to_file(std::ofstream& file, Participant** participants, size_t total_participants) {
    if (file.is_open()) {
        file
            << std::left
            << std::setw(14) << "Ранг"
            << std::setw(8) << "ID"
            << std::setw(22) << "Решено"
            << std::setw(15) << "Время"
            << std::setw(15) << "Баллов"
            << std::setw(10) << "Попытки"
            << std::endl;
        file << "-------------------------------------------------------------\n";
        for (size_t i = 0; i < total_participants; i++) {
            file
                << std::left
                << std::setw(14) << i
                << std::setw(8) << participants[i]->get_id()
                << std::setw(15) << participants[i]->get_solved()
                << std::setw(10) << participants[i]->get_time_spent()
                << std::setw(10) << participants[i]->get_score()
                << std::setw(10) << participants[i]->get_wrong_attempts()
                << std::endl;
        }
        return true;
    }
    return false;
}

int main() {

    srand(static_cast<unsigned int>(time(0)));


    Style::printHeader("  Сортировка     ", Style::Art::KEYBOARD_SECTION);
    Style::printResult("\n");
    size_t n;
    Style::printPrompt(" Сортировка массива целых чисел\n");
    Style::printHint(" Введите размер массива : ");
    std::cin >> n;


    std::vector<int> numbers(n);
    for (size_t i = 0; i < n; i++) {
        numbers[i] = (rand() % n) + 1;
    }

    std::vector<int*> simple_ptrs(n);
    std::vector<int*> heap_ptrs(n);
    std::vector<int*> quick_ptrs(n);

    for (size_t i = 0; i < n; i++) {
        // std::cout << numbers[i] << " ";
        simple_ptrs[i] = &numbers[i];
        heap_ptrs[i] = &numbers[i];
        quick_ptrs[i] = &numbers[i];
    }



    Style::printResult("\n");
    Style::printSeparator("double");
    Style::printResult("\n");

    if( n < 10'000 ){
        long long simple_comparisons = Sort<int>::simple_sort(simple_ptrs.data(), n);
        Style::printResult("> Выполнено простое короткое сжатие : " + std::to_string(simple_comparisons) + "\n");
        Style::printSuccess("Простая сортировка Сортировано или нет : " + std::string((Sort<int>::is_sorted(simple_ptrs.data(), n)) ? "Да\n" : "Нет\n"));


        Style::printResult("\n");
        Style::printSeparator("double");
        Style::printResult("\n");
    }

    long long heap_comparisons = Sort<int>::heap_sort(heap_ptrs.data(), n);
    Style::printResult("> Сравнение сортировки кучи выполнено : " + std::to_string(heap_comparisons) + "\n");
    Style::printSuccess("Сравнение сортировка Сортировано или нет : " + std::string((Sort<int>::is_sorted(heap_ptrs.data(), n)) ? "Да\n" : "Нет\n"));

    Style::printResult("\n");
    Style::printSeparator("double");
    Style::printResult("\n");

    long long quick_comparisons = Sort<int>::quick_sort(quick_ptrs.data(), 0, n - 1);
    Style::printResult("> Быстрое сравнение сортировок выполнено : " + std::to_string(quick_comparisons) + "\n");
    Style::printSuccess("Быстрое сортировка Сортировано или нет : " + std::string((Sort<int>::is_sorted(quick_ptrs.data(), n)) ? "Да\n" : "Нет\n"));



    /*--------------------------------------------------------------
    ---------------------------------------------------------------/
    |------------------------------------------------------------*/

    Style::printResult("\n");
    Style::printResult("\n");
    Style::printSeparator("fancy");
    Style::printResult("\n");



    Style::printHeader(" Участники    ", Style::Art::FILE_SECTION);
    Style::printResult("\n");
    Style::printPrompt(" Сортировать участников конкурса по программированию\n");

    size_t total_participants;
    Style::printHint(" Введите общее количество участников : ");
    std::cin >> total_participants;

    Participant** participants = new Participant*[total_participants];
    for (size_t i = 0; i < total_participants; i++) {
        participants[i] = new Participant(
            static_cast<int>(i + 1),
            (rand() % 5) + 1,
            (rand() % 241) + 60,
            static_cast<float>((rand() % 25) + 1),
            (rand() % 20) + 1
        );
    }

    Style::printResult("\n");
    Style::printSeparator("double");
    Style::printResult("\n");


    std::ofstream unsorted_file("output/participants_result.txt");

    if (write_to_file(unsorted_file, participants, total_participants)) {
        Style::printSuccess(" Результаты участников сохраняется в файле output/participants_result.txt\n");
    } else {
        Style::printError(" Ошибка открытия выходного файла. (Результаты)\n");
    }
    unsorted_file.close();

    Sort<Participant>::quick_sort(participants, 0, total_participants - 1);

    std::ofstream sorted_file("output/participants_result_sorted.txt");
    if (write_to_file(sorted_file, participants, total_participants)) {
        Style::printSuccess(" Результаты участников в отсортированном формате сохраняются в output/participants_result_sorted.txt\n");
    } else {
        Style::printError(" Ошибка открытия выходного файла. (sorted_file)\n");
    }
    sorted_file.close();

    for (size_t i = 0; i < total_participants; i++) {
        delete participants[i];
    }
    delete[] participants;



    Style::printResult("\n");
    Style::printSeparator("fancy");
    // std::cout << Style::Format::BLINK
    //     << Style::Color::BRIGHT_MAGENTA
    //     << Style::Format::BOLD
    //     << Style::Art::COMPLETION
    //     << Style::Color::RESET << "\n";

    return 0;
}
