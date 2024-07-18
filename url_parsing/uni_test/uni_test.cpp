#define BOOST_TEST_MODULE MyTest
#include "../parsing/parsing.h"
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_parsing_simple_url)
{
    std::string urlString = "https://ru.m.wikipedia.org/wiki/URL";
    URL expectedURL("https", "", "", "ru.m.wikipedia.org", "", "wiki/URL", "", "");
    URL actualURL = URL::parsing(urlString);

    BOOST_CHECK(URL::compareURLs(expectedURL, actualURL));
}

BOOST_AUTO_TEST_CASE(test_parsing_with_credentials)
{
    std::string urlString = "http://user:password@example.com:8080/path?query#fragment";
    URL expectedURL("http", "user", "password", "example.com", "8080", "path", "query", "fragment");
    URL actualURL = URL::parsing(urlString);

    BOOST_CHECK(URL::compareURLs(expectedURL, actualURL));
}

BOOST_AUTO_TEST_CASE(test_parsing_with_port)
{
    std::string urlString = "https://www.example.com:443/path";
    URL expectedURL("https", "", "", "www.example.com", "443", "path", "", "");
    URL actualURL = URL::parsing(urlString);

    BOOST_CHECK(URL::compareURLs(expectedURL, actualURL));
}

BOOST_AUTO_TEST_CASE(test_parsing_with_query)
{
    std::string urlString = "https://www.example.com/path?param1=value1&param2=value33";
    URL expectedURL("https", "", "", "www.example.com", "", "path", "param1=value1&param2=value33", "");
    URL actualURL = URL::parsing(urlString);

    BOOST_CHECK(URL::compareURLs(expectedURL, actualURL));
}

BOOST_AUTO_TEST_CASE(test_parsing_with_fragment)
{
    std::string urlString = "https://www.example.com/path#fragment";
    URL expectedURL("https", "", "", "www.example.com", "", "path", "", "fragment");
    URL actualURL = URL::parsing(urlString);

    BOOST_CHECK(URL::compareURLs(expectedURL, actualURL));
}

BOOST_AUTO_TEST_CASE(test_parsing_with_empty_path)
{
    std::string urlString = "https://www.example.com/";
    URL expectedURL("https", "", "", "www.example.com", "", "", "", "");
    URL actualURL = URL::parsing(urlString);

    BOOST_CHECK(URL::compareURLs(expectedURL, actualURL));
}

BOOST_AUTO_TEST_CASE(test_parsing_with_empty_query)
{
    std::string urlString = "https://www.example.com/path?";
    URL expectedURL("https", "", "", "www.example.com", "", "path", "", "");
    URL actualURL = URL::parsing(urlString);

    BOOST_CHECK(URL::compareURLs(expectedURL, actualURL));
}

BOOST_AUTO_TEST_CASE(test_parsing_with_empty_fragment)
{
    std::string urlString = "https://www.example.com/path#";
    URL expectedURL("https", "", "", "www.example.com", "", "path", "", "");
    URL actualURL = URL::parsing(urlString);

    BOOST_CHECK(URL::compareURLs(expectedURL, actualURL));
}

BOOST_AUTO_TEST_CASE(test_parsing_with_multiple_slashes)
{
    std::string urlString = "https://www.example.com/path";
    URL expectedURL("https", "", "", "www.example.com", "", "path", "", "");
    URL actualURL = URL::parsing(urlString);

    BOOST_CHECK(URL::compareURLs(expectedURL, actualURL));
}

BOOST_AUTO_TEST_CASE(test_parsing_with_special_characters)
{
    std::string urlString = "https://www.example.com/path?param1=value1%20&param2=value2%23";
    URL expectedURL("https", "", "", "www.example.com", "", "path", "param1=value1%20&param2=value2%23", "");
    URL actualURL = URL::parsing(urlString);

    BOOST_CHECK(URL::compareURLs(expectedURL, actualURL));
}