// Copyright Adam Warden 2023
// compile with
// g++ stdin_boost.cpp -lboost_regex

// regex_match example
#include <iostream>
#include <string>
#include <boost/regex.hpp>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using boost::regex;
using boost::regex_error;
using boost::regex_constants::error_bad_pattern;
using boost::regex_constants::error_collate;
using boost::regex_constants::error_ctype;
using boost::regex_constants::error_escape;
using boost::regex_constants::error_backref;
using boost::regex_constants::error_brack;
using boost::regex_constants::error_paren;
using boost::regex_constants::error_brace;
using boost::regex_constants::error_badbrace;
using boost::smatch;

int main() {
    string s, rs;
    regex e;

    // see http://www.boost.org/doc/libs/1_55_0/boost/regex/v4/error_type.hpp
    cout << "Here are some helpful error codes you may encounter\n";
    cout << "while constructing your regex\n";
    cout << "error_bad_pattern " << error_bad_pattern << endl;
    cout << "error_collate " << error_collate << endl;
    cout << "error_ctype " << error_ctype << endl;
    cout << "error_escape " << error_escape << endl;
    cout << "error_backref " << error_backref << endl;
    cout << "error_brack " << error_brack << endl;
    cout << "error_paren " << error_paren << endl;
    cout << "error_brace " << error_brace << endl;
    cout << "error_badbrace " << error_badbrace << endl;

    cout << endl;

    cout << "Enter regex > ";
    getline(cin, rs);

    try {
        e = regex(rs);
    } catch (regex_error& exc) {
        cout << "Regex constructor failed with code " << exc.code() << endl;
        exit(1);
    }

    cout << "Enter line > ";

    while (getline(cin, s)) {
        cout << endl;

        if (regex_match(s, e))
            cout << "string object \"" << s << "\" matched\n\n";

        if ( regex_match ( s.begin(), s.end(), e ) )
            cout << "range on \"" << s << "\" matched\n\n";

        smatch sm;    // same as match_results<string::const_iterator> sm;
        regex_match(s, sm, e);
        cout << "string object \"" << s << "\" with " << sm.size() << " matches\n\n";

        if (sm.size() > 0) {
            cout << "the matches were: ";
            for (unsigned i = 0; i < sm.size(); ++i) {
                cout << "[" << sm[i] << "] " << endl;
            }
        }

        cout << endl << endl;

        cout << "Enter line > ";
    }

    return 0;
}
