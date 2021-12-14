#pragma once
#include "colours.h"

void dupe(std::string path) {
    char filename[MAX_PATH];
    BOOL stats = 0;
    DWORD size = GetModuleFileNameA(NULL, filename, MAX_PATH);
    if (size)
        CopyFile(filename, path.c_str(), stats);
}

bool file_exists(const std::string& name) {
    struct stat buffer;
    return (stat(name.c_str(), &buffer) == 0);
}

std::wstring s2ws(const std::string& s)
{
    int len;
    int slength = (int)s.length() + 1;
    len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
    wchar_t* buf = new wchar_t[len];
    MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
    std::wstring r(buf);
    delete[] buf;
    return r;
}

void sleep(int ms) {
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

void log(std::string message) {
    if (debugging) {
        time_t* rawtime = new time_t;
        struct tm* timeinfo;

        time(rawtime);
        timeinfo = localtime(rawtime);

        Color::Modifier primary(Color::FG_GREEN);
        Color::Modifier secondary(Color::FG_WHITE);

        std::cout << primary << "[" << secondary << timeinfo->tm_hour << primary << ":" << secondary << timeinfo->tm_min << primary << ":" << secondary << timeinfo->tm_hour << primary << "] > " << secondary << message << std::endl;
    }
}