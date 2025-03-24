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
        const std::string SEPARATOR_DOUBLE = "═══════════════════════════════════════════════════════";
        const std::string SEPARATOR_SINGLE = "───────────────────────────────────────────────────────";
        const std::string SEPARATOR_FANCY  = "•❈•══════════════════════════════════════════════════•❈•";
    }

    namespace Art {
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
                << BOLD << BRIGHT_YELLOW << std::setw(20) << icon << "  " << BLINK << title
                << std::setw(18) << "" << RESET
                << BRIGHT_CYAN << LINE << RESET << "\n"
                << BRIGHT_CYAN << BOTTOM << RESET << "\n";
        }else{
            std::cout << BRIGHT_CYAN << LINE << RESET
                << BOLD << BRIGHT_YELLOW << std::setw(20) << "   " << BLINK << title
                << std::setw(18) << "" << RESET
                << BRIGHT_CYAN << LINE << RESET << "\n"
                << BRIGHT_CYAN << BOTTOM << RESET << "\n";
        }

    }

    inline void printPrompt(const std::string& message) {
        std::cout << Color::BRIGHT_RED << Format::BOLD
                 << "➤ " << message << Color::RESET;
    }

    inline void printHint(const std::string& hint) {
        std::cout << Color::BRIGHT_YELLOW << Format::ITALIC
                 << "💡 " << hint << Color::RESET;
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
                 << "✓ " << message << Color::RESET ;
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
