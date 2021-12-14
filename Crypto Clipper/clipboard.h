#pragma once

class Clipboard
{
public:
    Clipboard()
    {
        if (!OpenClipboard(nullptr))
            return;
    }

    ~Clipboard()
    {
        CloseClipboard();
    }

private:
    Clipboard(const Clipboard&);
    Clipboard& operator=(const Clipboard&);
};

class TextGlobalLock
{
public:
    explicit TextGlobalLock(HANDLE hData)
        : m_hData(hData)
    {
        m_psz = static_cast<const char*>(GlobalLock(m_hData));
        if (!m_psz)
            return;
    }

    ~TextGlobalLock()
    {
        GlobalUnlock(m_hData);
    }

    const char* Get() const
    {
        return m_psz;
    }

private:
    HANDLE m_hData;
    const char* m_psz;

    TextGlobalLock(const TextGlobalLock&);
    TextGlobalLock& operator=(const TextGlobalLock&);
};

std::string get_clipboard_text()
{
    Clipboard clipboard;

    HANDLE hData = GetClipboardData(CF_TEXT);
    if (hData == nullptr)
        return xorstr("error");

    TextGlobalLock textGlobalLock(hData);
    std::string text(textGlobalLock.Get());

    return text;
}

void set_clipboard_text(const char* text)
{
    sleep(100);

    int size = ::MultiByteToWideChar(CP_UTF8, 0, text, -1, nullptr, 0);
    if (size < 0) {
        return;
    }

    if (::OpenClipboard(NULL)) {
        ::EmptyClipboard();
        HGLOBAL hGlobal = ::GlobalAlloc(GMEM_ZEROINIT | GMEM_MOVEABLE | GMEM_DDESHARE, (size + 1) * sizeof(WCHAR));
        if (hGlobal != NULL) {
            LPWSTR lpszData = (LPWSTR)::GlobalLock(hGlobal);
            if (lpszData != nullptr) {
                ::MultiByteToWideChar(CP_UTF8, 0, text, -1, lpszData, size);
                ::GlobalUnlock(hGlobal);
                ::SetClipboardData(CF_UNICODETEXT, hGlobal);
            }
        }
        ::CloseClipboard();
    }
}