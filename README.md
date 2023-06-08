# QTxJS_zlibXqcompress
simulasi kompresi internal qt to zlib<br />
LZ77 compression <br />
https://datatracker.ietf.org/doc/html/rfc1950 <br />
isinya rfc1950 ADLER32 / checksum32 itu kalau di js minta dipotong 4 baru bisa di deflation <br />
+=====================+---+---+---+---+ <br />
|...compressed data...|    ADLER32    | <br />
+=====================+---+---+---+---+ <br />
