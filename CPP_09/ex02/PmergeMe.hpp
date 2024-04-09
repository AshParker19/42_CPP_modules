#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <exception>
#include <algorithm>
#include <vector>
#include <list>

class PmergeMe // vector and linked list
{
    private:
        PmergeMe();

        int Jacobstahl[33];

        std::vector<int> vt;
        std::vector<std::pair <int,int> > pairs;
        std::vector<int> vtInSequence;
        // int vector time;

        std::list<int> lt;

    public:
        PmergeMe(const std::string &input);
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();

        // parsing
        bool isNumber(const std::string &str);
        bool containsAlready(const std::vector<int> &vt, int value);
        bool noOverflow(std::string token);
        bool parse(const std::string &input);

        // Jacobstahl sequence
        void generateSequence();

        // vector
        void createVectorPairs();
        void sortHigherValuesRecursively(size_t index);
        void searchInsert();
        void insertSmallest();
        void handleVector();
        void putInSequence();
        void insertJacobstahl(int index);
        void insertInReverseOrder(std::vector<int> group);

        // list
        // void handleList();

        class ErrorException : public std::exception
        {
            public:
                const char *what(void) const throw();
        };

        class OnlyOneIntegerException : public std::exception
        {
            public:
                const char *what(void) const throw();
        };
};

#endif
