#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <vector>
# include <deque>
# include <cstdlib>
# include <cctype>
# include <cmath>
# include <algorithm>
# include <limits>
# include <stdexcept>
# include <exception>
# include <ctime>
# include <utility>
# include <sstream>
# include <iomanip>

/**
 * @class PmergeMe
 * @brief Implements the Ford-Johnson (merge-insert) sorting algorithm using two container types
 * 
 * This class provides functionality to sort a sequence of positive integers using
 * the Ford-Johnson algorithm (also known as merge-insert sort). The algorithm is
 * implemented for both std::deque and std::vector containers to compare performance.
 * 
 * The Ford-Johnson algorithm is designed to minimize the number of comparisons needed
 * to sort a list by using a recursive approach with carefully ordered insertions based
 * on the Jacobsthal sequence.
 */
class PmergeMe
{
    private:
        std::deque<int> _deque;       // Sequence to be sorted using deque
        std::vector<int> _vector;     // Same sequence to be sorted using vector
        int _straggler;               // Holds extra element if sequence has odd length
        double _dequeTime;            // Time taken to sort with deque (in milliseconds)
        double _vectorTime;           // Time taken to sort with vector (in milliseconds)

        /**
         * @brief Generates the Jacobsthal sequence up to a given number
         * 
         * The Jacobsthal sequence is defined as J(0) = 0, J(1) = 1, J(n) = J(n-1) + 2*J(n-2) for n > 1.
         * This sequence is used to determine the optimal insertion order in the Ford-Johnson algorithm.
         * 
         * @tparam T Container type (std::deque or std::vector)
         * @param n Upper limit for the sequence
         * @return A container of type T containing the Jacobsthal sequence
         */
        template <typename T>
        T generateJacobsthalSequence(int n);

        /**
         * @brief Generates the insertion sequence based on Jacobsthal numbers
         * 
         * This creates the optimal order in which elements should be inserted
         * to minimize the number of comparisons in the Ford-Johnson algorithm.
         * 
         * @tparam T Container type (std::deque or std::vector)
         * @param jacobsthal The Jacobsthal sequence
         * @param size Size of the Jacobsthal sequence
         * @return A container of type T with the insertion order
         */
        template <typename T>
        T generateInsertionSequence(T jacobsthal, int size);

        /**
         * @brief Inserts a value into a sorted sequence using binary search
         * 
         * Uses std::lower_bound for efficient insertion position finding.
         * 
         * @tparam T Container type (std::deque or std::vector)
         * @param sequence The sorted sequence to insert into
         * @param value The value to insert
         */
        template <typename T>
        void binaryInsert(T &sequence, int value);

        /**
         * @brief Implements the Ford-Johnson algorithm for the deque container
         * 
         * Recursively sorts the sequence using the merge-insert approach.
         * 
         * @param pairs Container of pairs used in the recursive sorting process
         */
        void recursiveSortDeque(std::deque<std::pair<int, int> > &pairs);
        
        /**
         * @brief Implements the Ford-Johnson algorithm for the vector container
         * 
         * Recursively sorts the sequence using the merge-insert approach.
         * 
         * @param pairs Container of pairs used in the recursive sorting process
         */
        void recursiveSortVector(std::vector<std::pair<int, int> > &pairs);
        
        /**
         * @brief Displays a sequence with a prefix string
         * 
         * Used to show the before and after states of the sequence.
         * 
         * @param prefix String to display before the sequence
         * @param sequence The sequence to display
         */
        void displaySequence(const std::string &prefix, const std::deque<int> &sequence) const;

        /**
         * @brief Validates if a string represents a positive integer
         * 
         * Checks if the string contains only digits and represents a value
         * that is positive and doesn't exceed INT_MAX.
         * 
         * @param str The string to validate
         * @return true if the string is a valid positive integer
         */
        static bool isPositiveInteger(const std::string &str);

        /**
         * @brief Checks if a value already exists in a sequence
         * 
         * Used to detect and prevent duplicate values in the input.
         * 
         * @param sequence The sequence to check against
         * @param value The value to look for
         * @throws std::invalid_argument if the value is found in the sequence
         */
        static void checkForDuplicates(const std::deque<int> &sequence, int value);

    public:
        /**
         * @brief Default constructor
         */
        PmergeMe();

        /**
         * @brief Copy constructor
         * 
         * @param src Source object to copy from
         */
        PmergeMe(const PmergeMe &src);

        /**
         * @brief Destructor
         */
        ~PmergeMe();

        /**
         * @brief Assignment operator
         * 
         * @param rhs Right-hand side object to assign from
         * @return Reference to this object
         */
        PmergeMe &operator=(const PmergeMe &rhs);

        /**
         * @brief Parses and validates command line arguments
         * 
         * Checks that all arguments are valid positive integers,
         * ensures there are no duplicates, and loads the values
         * into the provided containers.
         * 
         * @param argc Argument count
         * @param argv Argument values
         * @param deque Deque container to fill
         * @param vector Vector container to fill
         * @throws std::invalid_argument for invalid inputs
         */
        static void parseInput(int argc, char **argv, std::deque<int> &deque, std::vector<int> &vector);
        
        /**
         * @brief Loads a sequence to be sorted
         * 
         * Initializes the internal containers with the provided sequences
         * and displays the unsorted sequence.
         * 
         * @param dequeInput Sequence to load into the deque container
         * @param vectorInput Sequence to load into the vector container
         */
        void loadSequence(const std::deque<int> &dequeInput, const std::vector<int> &vectorInput);

        /**
         * @brief Sorts the sequence using the deque implementation
         * 
         * Applies the Ford-Johnson algorithm to the deque container
         * and measures the time taken.
         */
        void sortDeque();

        /**
         * @brief Sorts the sequence using the vector implementation
         * 
         * Applies the Ford-Johnson algorithm to the vector container
         * and measures the time taken.
         */
        void sortVector();

        /**
         * @brief Displays the sorted sequence and timing results
         * 
         * Shows the sorted sequence and the time taken by each container
         * implementation in milliseconds.
         */
        void displayResults() const;
};

// Template implementations
template <typename T>
T PmergeMe::generateJacobsthalSequence(int n)
{
    T jacobsthal;
    jacobsthal.push_back(0);
    jacobsthal.push_back(1);

    int i = 2;
    while (true)
    {
        int next = jacobsthal[i - 1] + 2 * jacobsthal[i - 2];
        if (next > n)
            break;
        jacobsthal.push_back(next);
        i++;
    }
    jacobsthal.push_back(n);
    return jacobsthal;
}

template <typename T>
T PmergeMe::generateInsertionSequence(T jacobsthal, int size)
{
    T insertionSequence;

    for (int i = 1; i < size; i++) {
        int current = jacobsthal[i];
        while (current > jacobsthal[i - 1])
        {
            insertionSequence.push_back(current - 1);
            current--;
        }
    }
    return insertionSequence;
}

template <typename T>
void PmergeMe::binaryInsert(T &sequence, int value)
{
    typename T::iterator it = std::lower_bound(sequence.begin(), sequence.end(), value);
    sequence.insert(it, value);
}

#endif