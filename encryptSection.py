# to get the offset : readelf -S test then
# look at the column offset (Off)

import sys

def main():
    encryptionKey = 0xAA
    startOffset = int(sys.argv[1], 16)
    endOffset = int(sys.argv[2], 16)
    programPath = sys.argv[3]

    with open(programPath, 'rb') as f:
        data = bytearray(f.read())

    for i in range(startOffset, endOffset):
        data[i] ^= encryptionKey

    with open(programPath+"Encrypted", 'wb') as f:
        f.write(data)

main()