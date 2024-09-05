#ifndef INCLUDE_BREAKPOINTS_HH
#define INCLUDE_BREAKPOINTS_HH

#include <filesystem>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <iostream>

namespace music {

template<class T, typename = typename std::enable_if<std::is_arithmetic<T>::value>::type>
T stoa(std::string s) {
    try {
        if (std::is_floating_point<T>::value) {
            return std::stof(s);
        } else {
            return std::stoi(s);
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 0;
    }
};

template<class T, class V, typename = typename std::enable_if<
    std::is_arithmetic<T>::value && 
    std::is_arithmetic<V>::value
>::type>
class Breakpoints {
    private:
        std::string fname;
        std::map<T, V> points;

    public:
        Breakpoints() = default;
        Breakpoints(std::string fname): 
            fname { fname }
        {
            std::ifstream is(fname);
            if (!is.good()) {
                return;
            }

            std::string line;

            while (!is.eof()) {
                std::string t, v;
                is >> t >> v;

                if (t.size() && v.size()) {
                    points[stoa<T>(t)] = stoa<V>(v);
                }                
            }
        };

        V& operator[](const T t) noexcept {
            return points[t];
        }

        Breakpoints<T, V>& operator+=(T shift) {
            std::map<T, V> shifted;

            for (auto it = points.begin(); it != points.end(); ++it) {
                shifted[it->first + shift] = it->second;
            }

            points = shifted;
            return *this;
        }

        Breakpoints<T, V> operator+(Breakpoints<T, V>& b) {
            auto a = *this;

            Breakpoints<T, V> bp;

            auto ai = a.begin();
            auto bi = b.begin();

            while (ai != a.end() || bi != b.end()) {
                if (ai == a.end() || ((bi != b.end()) && bi->first <= ai->first)) {
                    bp[bi->first] = bi->second;
                    ++bi;
                } else {
                    bp[ai->first] = ai->second;
                    ++ai;
                }
            }

            return bp;
        }

        decltype(points.begin()) begin() noexcept {
            return points.begin();
        }

        decltype(points.end()) end() noexcept {
            return points.end();
        }

        size_t size() const noexcept {
            return points.size();
        }

        std::string name(std::string fname) {
            if (fname == "") {
                return this->fname;
            }

            this->fname = fname;
            return this->fname;
        }

        void save() {
            if (fname == "") {
                return;
            }

            std::ofstream os(fname);
            for (auto it = points.begin(); it != points.end(); ++it) {
                os << std::to_string(it->first) << ' ' << std::to_string(it->second) << '\n';
            }

            os.flush();
            os.close();
        }
};

}

#endif