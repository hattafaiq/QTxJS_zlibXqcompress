# QTxJS_zlibXqcompress
simulasi kompresi internal qt to zlib<br />
LZ77 compression <br />
******DEFLATE Compressed Data Format Specification***** <br />
......................    /\..............Symbol    Code <br />
                         0  1             ------    ---- <br />
                        /    \                A      00  <br />
                       /\     B               B       1  <br /> 
                      0  1                    C     011  <br />
                     /    \                   D     010  <br />
                    A     /\                             <br />
                         0  1                            <br />
                        /    \                           <br />
                       D      C                          <br />

https://datatracker.ietf.org/doc/html/rfc1951 <br />
isinya rfc1951 kalau di js minta dipotong 4byte baru bisa di deflation <br />
  0   1   2   3   4... <br />
  +---+---+---+---+================================+ <br />
  |  LEN  | NLEN  |... LEN bytes of literal data...| <br />
  +---+---+---+---+================================+ <br />
