#include <iostream>
#include <string>
#include <curl/curl.h>

// Callback function to handle data received from cURL
size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

// Function to get weather data
void getWeather(const std::string& city) {
    CURL* curl;
    CURLcode res;
    std::string readBuffer;

    // Initialize cURL
    curl = curl_easy_init();
    if(curl) {
        // Set the URL for the request
        std::string url = "https://api.weatherapi.com/v1/current.json?key=de1a91d7ed3f4617881231245240709&q=" + city + "&aqi=yes";
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        // Perform the request
        res = curl_easy_perform(curl);
        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            // Output the raw JSON response
            std::cout << readBuffer << std::endl;
        }

        // Cleanup cURL
        curl_easy_cleanup(curl);
    }
}
