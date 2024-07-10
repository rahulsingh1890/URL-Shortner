#include <iostream>
#include <unordered_map>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class URLShortener {

public:
    URLShortener() {
        srand(time(0));
    }

    string shortenURL(const std::string& longURL) {
        string shortURL = generateShortURL(6);
        urlMap[shortURL] = longURL;
        return shortURL;
    }

    string getLongURL(const std::string& shortURL) {
        if (urlMap.find(shortURL) != urlMap.end()) {

            return urlMap[shortURL];
        }

        return "Short URL not found.";
    }

private:
    unordered_map<std::string, string> urlMap;

    string generateShortURL(size_t len) {
        string shortURL;
        for (size_t i = 0; i < len; ++i) {
            shortURL += 'a' + rand() % 26;
        }
        return shortURL;
    }
};

int main() {
    URLShortener urlShortener;

    string input;

    while (true) {
        
        cout << "Enter a long URL to shorten or a short URL to get the long URL (or 'exit' to quit): ";
        getline(cin, input);

        if (input == "exit") {
            break;
        }

        string longURL = urlShortener.getLongURL(input);
        if (longURL == "Short URL not found.") {
            
            string shortURL = urlShortener.shortenURL(input);
            cout << "Short URL: " << shortURL << endl;
        } else {
      
            cout << "Long URL: " << longURL << endl;
        }
    }

    return 0;
}