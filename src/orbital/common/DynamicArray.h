//
// Created by jim on 05.02.18.
//

#pragma once

#include <array>
#include <cassert>
#include <ostream>
#include <stdexcept>

/**
 * A fixed-maximum sized array, with a dynamic count of actual values.
 * Efficient when maximum number of elements is known at compile-time, such a quadratic formula solutions.
 *
 * Elements must be default constructable and assignable.
 *
 * Therefore, this class is only efficient for lightweight structures, but it optimizes the heap away, since everything
 * is stored directly on the stack.
 */

template<class T, std::size_t N>
class DynamicArray
{

public:

    /**
     * Create an empty array.
     */
    constexpr DynamicArray()
    {
        static_assert(N > 0, "Dynamic array must have at least one value");
    }

    /**
     * Create an array with pre-initialized content.
     * @param il Initializing elements. Can be less than needed.
     */
    constexpr DynamicArray(
            std::initializer_list<T> const &il
    )
            : DynamicArray{}
    {
        if (il.size() > N)
        {
            throw std::runtime_error{"Initializer list is too long for dynamic array"};
        }
        for (const auto e : il)
        {
            mArray[mLength] = std::move(e);
            ++mLength;
        }
    }

    /**
     * Append one element.
     * @param value Value to append.
     * @return Reference to appended element.
     * @throw If maximum element count is about to be exceeded.
     */
    constexpr T &
    push_back(
            T const value
    )
    {
        if (mLength >= N)
        {
            throw std::runtime_error{"Exceeding maximum dynamic array size"};
        }

        mArray[mLength] = value;
        ++mLength;
        return mArray[mLength - 1];
    }

    /**
     * Construct a new element in-place.
     * @param args Arguments passed to constructor.
     * @return Reference to appended element.
     * @throw If maximum element count is about to be exceeded.
     */
    template<class... TArgs>
    constexpr T &
    emplace_back(
            TArgs &&...args
    )
    {
        if (mLength >= N)
        {
            throw std::runtime_error{"Exceeding maximum dynamic array size"};
        }

        mArray[mLength] = T{std::forward<TArgs>(args)...};
        ++mLength;
        return mArray[mLength - 1];
    }

    /**
     * Give reference to first element.
     * @attention Do not call this if array is empty.
     * @return First element.
     */
    constexpr T &
    front()
    {
        return mArray.front();
    }

    /**
     * Give reference to last element.
     * @attention Do not call this if array is empty.
     * @return Last element.
     */
    constexpr T &
    back()
    {
        return mArray[mLength - 1];
    }

    /**
     * @return Begin iterator.
     */
    constexpr auto
    begin()
    {
        return mArray.begin();
    }

    /**
     * @return End iterator.
     */
    constexpr auto
    end()
    {
        return mArray.begin() + mLength;
    }

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"

    /**
     * Give reference to first element.
     * @attention Do not call this if array is empty.
     * @return First element.
     */
    constexpr T const &
    front() const
    {
        return mArray.front();
    }

    /**
     * Give reference to last element.
     * @attention Do not call this if array is empty.
     * @return Last element.
     */
    constexpr T const &
    back() const
    {
        return mArray[mLength - 1];
    }

    /**
     * @return Constant begin iterator.
     */
    constexpr auto const
    begin() const
    {
        return mArray.begin();
    }

    /**
     * @return Constant end iterator.
     */
    constexpr auto const
    end() const
    {
        return mArray.begin() + mLength;
    }

#pragma clang diagnostic pop

    /**
     * Get size of array. The array's size changes when elements are added to it.
     * The size will never exceed the capacity.
     * @return Current array length.
     */
    constexpr std::size_t
    size() const
    {
        return mLength;
    }

    /**
     * Get maximum array length. This value is constant at set at compile-time.
     * @return Maximum array length.
     */
    constexpr std::size_t
    capacity() const
    {
        return N;
    }

    /**
     * Give a reference to an element by index.
     * @attention No bounds checking is performed, accessing elements beyond current array size returns
     * initialized memory.
     * @param index Index denoting element to return.
     * @return Element reference.
     */
    constexpr T &
    operator[](
            std::size_t const index
    )
    {
        return mArray[index];
    }

    /**
     * Give a constant reference to an element by index.
     * @attention No bounds checking is performed, accessing elements beyond current array size returns
     * initialized memory.
     * @param index Index denoting element to return.
     * @return Element reference.
     */
    constexpr const T &
    operator[](
            std::size_t const index
    ) const
    {
        return mArray[index];
    }

    /**
     * @return Serialize array to output stream.
     */
    friend std::ostream &
    operator<<(
            std::ostream &os,
            DynamicArray const &array
    )
    {
        os << "[ ";
        for (auto iter = array.begin(); iter != array.end(); iter++)
        {
            os << *iter;
            if (iter + 1 != array.end())
            {
                os << ", ";
            }
        }
        os << " ]";
        return os;
    }

    /**
     * Size or shrunk the length of active elements directly.
     * @param size New array size.
     */
    constexpr void
    resize(
            size_t const size
    )
    {
        assert(size <= N);
        mLength = size;
    }

    constexpr bool const
    empty()
    {
        return 0 == mLength;
    }

private:

    std::size_t mLength{0};
    std::array<T, N> mArray;

};
