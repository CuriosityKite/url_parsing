#pragma once
/*
Необходимо написать парсер URL строки с использованием регулярных выражении regex.
Структура URL:
    <схема>:[//[<логин>[:<пароль>]@]<хост>[:<порт>]][/<URL‐путь>][?<параметры>][#<якорь>]

*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <regex>

class URL
{
    private:
        std::string scheme;
        std::string username;
        std::string password;
        std::string ost;
        std::string port;
        std::string path;
        std::string query;
        std::string fragment;
    public:
        URL(const std::string& sch, const std::string& usname, const std::string& passw, const std::string& os,
            const std::string& prt, const std::string& pth, const std::string& quer, const std::string& frag)
            : scheme(sch), username(usname), password(passw), ost(os), port(prt), path(pth), query(quer), fragment(frag) {}

        void print() const
        {
            std::cout << "scheme: " << scheme
                << " username: " << username
                << " password: " << password
                << " ost: " << ost
                << " port: " << port
                << " path: " << path
                << " query: " << query
                << " fragment: " << fragment << std::endl;
        }

        bool operator==(const URL& other) const
        {
            return scheme == other.scheme &&
                username == other.username &&
                password == other.password &&
                ost == other.ost &&
                port == other.port &&
                path == other.path &&
                query == other.query &&
                fragment == other.fragment;
        }

        static bool compareURLs(const URL url1, const URL url2)
        {
            return url1 == url2;
        }

        static URL parsing(const std::string& urlString)
        {
            std::regex log_regex(R"~(^([a-z]+):\/\/(?:([a-z0-9.-]+):([a-z0-9.-]+)@)?([a-z0-9.-]+)(?::(\d+))?(?:\/([^?#]*))?(?:\?([^#]*))?(?:#(.*))?$)~");
            std::smatch match;
            if (std::regex_search(urlString, match, log_regex))
            {
                URL entry(match[1], match[2], match[3], match[4], match[5], match[6], match[7], match[8]);
                return entry;
            }
            else
                return URL("", "", "", "", "", "", "", "");
        }
};