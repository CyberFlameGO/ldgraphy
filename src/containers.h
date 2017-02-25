/* -*- mode: c++; c-basic-offset: 4; indent-tabs-mode: nil; -*-
 * (c) 2017 Henner Zeller <h.zeller@acm.org>
 *
 * This file is part of LDGraphy http://github.com/hzeller/ldgraphy
 *
 * LDGraphy is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * LDGraphy is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with LDGraphy.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef LDGRAPHY_CONTAINERS_H
#define LDGRAPHY_CONTAINERS_H

#include <strings.h>
#include <stdio.h>

class BitArray {
public:
    BitArray(size_t size)
        : size_(size), buffer_(new uint8_t[(size+7)/8]) {
        Clear();
    }
    ~BitArray() { delete [] buffer_; }

    void Clear() {  bzero(buffer_, (size_+7)/8); }

    void Set(int bit, bool value) {
        if (bit < 0 || bit >= size_) return;
        if (value)
            buffer_[bit / 8] |= 1 << (7 - bit % 8);
        else
            buffer_[bit / 8] &= ~(1 << (7 - bit % 8));
    }

    const uint8_t *buffer() const { return buffer_; }
    int size() const { return size_; }

private:
    const int size_;
    uint8_t *const buffer_;
};


#endif // LDGRAPHY_CONTAINERS_H
