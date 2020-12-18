#include <Utilities.h>

#include <fstream>
#include <string>

namespace Utilities {

    // ------------------ Other ------------------

    std::string &loadFile(const std::string &fileLocation) {

        auto result = new std::string;
        std::fstream file(fileLocation);

        if (!file.is_open()) {
            printf("ERROR: Couldn't locate file %s", fileLocation.c_str());
            return *result;
        }

        std::string line;
        while(std::getline(file, line)) {
            result->append(line + "\n");
        }

        return *result;

    }

}

namespace Maths {

    template <class T, int N>
    Vector<T, N>::Vector(T elements[N]) {

        for (int i = 0; i < N; i++) {
            m_elements[i] = elements->at(i);
        }

    }

    template <class T, int N>
    T Vector<T, N>::operator[](int index) {
        return m_elements[index];
    }

    template <class T, int N>
    Vector<T, N> Vector<T, N>::operator+ (Vector<T, N> vec) {

        Vector<T, N> result;

        for (int i = 0; i < N; i++) {
            result[i] = m_elements[i] + vec[i];
        }

        return result;

    }

    template <class T, int N>
    Vector<T, N> Vector<T, N>::operator- (Vector<T, N> vec) {

        Vector<T, N> result;

        for (int i = 0; i < N; i++) {
            result[i] = m_elements[i] - vec[i];
        }

        return result;

    }

    template <class T, int N>
    Vector<T, N> Vector<T, N>::operator* (T scalar) {

        Vector<T, N> result;

        for (int i = 0; i < N; i++) {
            result[i] = m_elements[i] * scalar;
        }

        return result;

    }

    template <class T, int N>
    Vector<T, N> Vector<T, N>::operator/ (T scalar) {

        Vector<T, N> result;

        for (int i = 0; i < N; i++) {
            result[i] = m_elements[i] / scalar;
        }

        return result;

    }

    template <class T, int N>
    void Vector<T, N>::operator+=(Vector<T, N> vec) {
        for (int i = 0; i < N; i++) {
            m_elements[i] += vec[i];
        }
    }

    template <class T, int N>
    void Vector<T, N>::operator-=(Vector<T, N> vec) {
        for (int i = 0; i < N; i++) {
            m_elements[i] -= vec[i];
        }
    }

    template <class T, int N>
    void Vector<T, N>::operator*=(T scalar) {
        for (int i = 0; i < N; i++) {
            m_elements[i] *= scalar;
        }
    }

    template <class T, int N>
    void Vector<T, N>::operator/=(T scalar) {
        for (int i = 0; i < N; i++) {
            m_elements[i] /= scalar;
        }
    }




}
