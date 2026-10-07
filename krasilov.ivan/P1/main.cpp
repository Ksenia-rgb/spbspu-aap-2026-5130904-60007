#include <cctype>
#include <charconv>
#include <iostream>
#include <limits>
#include <string>
#include <system_error>

static bool parse_int(const std::string& s, int& out)
{
    const char* first = s.data();
    const char* last = first + s.size();
    if (first != last && *first == '+') {
        ++first;
        if (first == last || !std::isdigit(static_cast<unsigned char>(*first)))
            return false;
    }
    auto [ptr, ec] = std::from_chars(first, last, out);
    return ec == std::errc() && ptr == last;
}

int main()
{
    std::ios::sync_with_stdio(false);
    int prev = 0;
    bool have_prev = false;
    unsigned long long count = 0;
    bool overflow = false;
    std::string token;
    for (;;) {
        if (!(std::cin >> token)) {
            std::cerr << "Error: sequence is not terminated by zero\n";
            return 1;
        }

        int cur = 0;
        if (!parse_int(token, cur)) {
            std::cerr << "Error: input is not a valid sequence of integers\n";
            return 1;
        }
        if (cur == 0)
            break;
        if (have_prev && cur > prev) {
            if (count == std::numeric_limits<unsigned long long>::max())
                overflow = true;
            else
                ++count;
        }
        prev = cur;
        have_prev = true;
    }
    if (overflow) {
        std::cerr << "Error: sequence is too long, counter overflow\n";
        return 2;
    }
    std::cout << count << '\n';
    return 0;
}
