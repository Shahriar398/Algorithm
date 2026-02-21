#include <iostream>
#include <curl/curl.h>
using namespace std;

int main() {
    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://example.com/login");

        std::string postFields = "studentId=your_id&password=your_pass";
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postFields.c_str());

        curl_easy_setopt(curl, CURLOPT_COOKIEJAR, "cookies.txt");
        curl_easy_setopt(curl, CURLOPT_COOKIEFILE, "cookies.txt");

        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);

        res = curl_easy_perform(curl);

        if (res != CURLE_OK)
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;

        curl_easy_cleanup(curl);
    }

    return 0;
}

