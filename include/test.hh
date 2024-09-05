#ifndef INCLUDE_TEST_HH
#define INCLUDE_TEST_HH

#include <functional>
#include <vector>
#include <string>
#include <iostream>

namespace test {

/**
 * @brief Simple test suite: Add a test name and its boolean function, then evaluate them.
 * 
 * Test names can be used to group tests with matching prefixes. 
 * The test runner accepts a prefix argument and will filter out tests not matching.
 */
class Test {
    public:
        /**
         * @brief The named test functions
         */
        static std::vector<std::pair<std::string, std::function<bool()>>> tests;

        /**
         * @brief Add a function to the test suite
         * 
         * @param name The test name. Use to group tests together with prefixes
         * @param test The test function. Takes no arguments, evaluates to true (PASS) or false (FAIL)
         */
        static void add(std::string name, std::function<bool()> test) {
            Test::tests.emplace_back(std::pair<std::string, std::function<bool()>> { name, test });
        }

        /**
         * @brief Run the test suite
         * 
         * @param prefix If non-empty, only tests with names whose prefix is equal will be run
         */
        static void run(std::string prefix = "") {
            std::vector<std::string> pass;
            std::vector<std::string> fail;

            auto eval = [&pass, &fail](decltype(tests.begin())& it) -> void {
                if (it->second()) {
                    pass.push_back(it->first);
                } else {
                    fail.push_back(it->first);
                }
            };

            if (prefix == "") {
                for (auto it = Test::tests.begin(); it != Test::tests.end(); ++it) {
                    eval(it);
                }
            } else {
                for (auto it = Test::tests.begin(); it != Test::tests.end(); ++it) {
                    if (it->first.find(prefix) != 0) {
                        continue;
                    }
                    
                    eval(it);
                }
            }

            std::cout << '\n';

            for (auto it = pass.begin(); it != pass.end(); ++it) {
                std::cout << "Passed: " << *it << "\n";
            }

            std::cout << "\n---\n";

            for (auto it = fail.begin(); it != fail.end(); ++it) {
                std::cout << "Failed: " << *it << '\n';
            }

            std::cout << "\nNo. PASSED: " << pass.size() << "\nNo. FAILED: " << fail.size() << '\n' << std::endl;
        }
};

/**
 * @brief Allows a test to be added to the suite before execution of main().
 * 
 * Simply declare a static global variable and pass the name and test function to the constructor:
 * 
 * ```
 * static auto _ = AddTest("some test", []() -> bool {
 *      return true;
 * })
 * ```
 * 
 */
class AddTest {
    public:
        AddTest(std::string name, std::function<bool()> test) {
            Test::add(name, test);
        }
};

}

#endif