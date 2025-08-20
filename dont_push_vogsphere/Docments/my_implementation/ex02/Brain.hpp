#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain {
private:
    static const int IDEAS_COUNT = 100;
    std::string ideas[IDEAS_COUNT];

public:
    Brain();
    Brain(const Brain &other);
    Brain &operator=(const Brain &other);
    ~Brain();

    void setIdea(int index, const std::string &idea);
    std::string getIdea(int index) const;
    void printIdeas() const;
};

#endif
