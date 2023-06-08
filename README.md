# QTxJS_zlibXqcompress
simulasi kompresi internal qt to zlib<br />
LZ77 compression <br />
https://datatracker.ietf.org/doc/html/rfc1951 <br />
isinya rfc1951 kalau di js minta dipotong 4byte baru bisa di deflation <br />
  0   1   2   3   4... <br />
  +---+---+---+---+================================+ <br />
  |  LEN  | NLEN  |... LEN bytes of literal data...| <br />
  +---+---+---+---+================================+ <br />
