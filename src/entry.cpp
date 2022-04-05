#include <array>
#include <string.h>
#include <iostream>
#include <memory>

std::string GetSystemOutput(const char *cmd)
{
    std::array<char, 128> buffer;
    std::string result;
#if defined(_WIN32)
    std::unique_ptr<FILE, decltype(&_pclose)> pipe(_popen(cmd, "r"), _pclose);
#elif defined(_WIN64)
    std::unique_ptr<FILE, decltype(&_pclose)> pipe(_popen(cmd, "r"), _pclose);
#elif defined(__linux__)
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
#endif

    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr)
        result += buffer.data();

    return result;
}

int main()
{

    std::cout << GetSystemOutput("find . -name '\*'.py -type f -printf '%p\n' -delete");
    return 0;
}