#pragma once

bool is_console_visible()
{
    return ::IsWindowVisible(::GetConsoleWindow()) != FALSE;
}

void hide_console()
{
    if (is_console_visible)
        ::ShowWindow(::GetConsoleWindow(), SW_HIDE);
}

void show_console()
{
    if (!is_console_visible)
        ::ShowWindow(::GetConsoleWindow(), SW_SHOW);
}