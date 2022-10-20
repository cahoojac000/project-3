#ifndef PROJECT_3_HEADER_H
#define PROJECT_3_HEADER_H

#include <vector>
#include <string>

class Header {
public:
    Header() = default;
    explicit Header(const std::vector<std::string>& header) { this->attributes = header; }
    ~Header() = default;
    std::vector<std::string> attributes;
};


#endif
