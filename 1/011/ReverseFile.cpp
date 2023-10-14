#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <string>
#include <array>
#include <algorithm>

using namespace std;

void reverse_file(const string& filename) {
    constexpr int chunk = 128;
    array <char, chunk> lbuf, rbuf;
    fstream lfs{filename, ios_base::binary}, rfs{filename, ios_base::binary};
    if (!lfs || !rfs) {
        throw runtime_error{"can't open file"};
    }
    rfs.seekg(0, ios_base::end);
    streampos lpos = lfs.tellg(), rpos = rfs.tellg();
    while (lpos < rpos) {
        lpos = lfs.tellg();
        
        int n = (rpos - lpos)/2;
        if (chunk < n) n = chunk;

        rpos -= n;
        rfs.seekg(rpos);
        lfs.read(lbuf.data(), n);
        rfs.read(rbuf.data(), n);

        reverse(lbuf.begin(), lbuf.begin() + n);
        reverse(rbuf.begin(), rbuf.begin() + n);

        lfs.seekp(lpos);
        rfs.seekp(rpos);

        lfs.write(lbuf.data(), chunk);
        rfs.write(rbuf.data(), chunk);
    }
}

int main() {
    char c = '1';
    cout << sizeof(c);
}