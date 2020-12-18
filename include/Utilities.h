#pragma once

#include <iostream>

namespace Utilities {
    std::string &loadFile(const std::string &fileLocation);
}

namespace Maths {

    template <class T, int N>
    class Vector {

    public:

        Vector(T elements[N]);
        T operator[](int index);
        Vector<T, N> operator+ (Vector<T, N> vec);
        Vector<T, N> operator- (Vector<T, N> vec);
        Vector<T, N> operator* (T scalar);
        Vector<T, N> operator/ (T scalar);

        void operator+= (Vector<T, N> vec);
        void operator-= (Vector<T, N> vec);
        void operator*= (T scalar);
        void operator/= (T scalar);

    private:
        T m_elements[N] = {};
    };

}
