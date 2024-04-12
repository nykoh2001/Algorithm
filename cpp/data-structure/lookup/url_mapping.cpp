#include <iostream>
#include <unordered_map>

using namespace std;

class url_converter
{
private:
  unordered_map<string, string> container;

public:
  void insert(string origin, string tiny)
  {
    // 단축 url로부터 원본 url 검색
    container[tiny] = origin;
    cout << "{" << tiny << ": " << origin << "} 추가" << endl;
  }

  string search(string tiny)
  {
    return container[tiny];
  }
};

int main()
{
  url_converter converter = url_converter();

  converter.insert("https://www.openai.com/really/long/url/with/a/lot/of/subdirectories/and/query/parameters/that/are/very/long/indeed?utm_source=example&utm_medium=website&utm_campaign=shorturl",
                   "https://extremelyshort.link/1aB2cD3");
  converter.insert("https://www.thisisareallylongandcomplicatedexampleurl.com/with/many/subdirectories/and/query/parameters?utm_source=example&utm_medium=website&utm_campaign=longurl",
                   "https://ultrashort.url/AbCdEf");
  converter.insert("https://www.reallyreallyreallyreallyreallyreallyreallyreallylongurl.com/with/numerous/subfolders/and/query/parameters/that/seem/tobeendless?utm_source=example&utm_medium=website&utm_campaign=superlongurl",
                   "https://tiny.link/123XYZ");

  cout << converter.search("https://ultrashort.url/AbCdEf") << endl;
}
