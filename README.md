# QTxJS_zlibXqcompress
<ul>
<li>simulasi kompresi internal qt to zlib </li>
<li> LZ77 compression </li>
<li>******DEFLATE Compressed Data Format Specification***** </li>  
<li>......................    /\..............Symbol    Code  </li>
<li>                         0  1             ------    ----  </li>
<li>                        /    \                A      00   </li>
<li>                       /\     B               B       1   </li>
<li>                      0  1                    C     011   </li>
<li>                     /    \                   D     010   </li>
<li>                    A     /\                              </li>
<li>                         0  1                             </li>
<li>                        /    \                            </li>
<li>                       D      C                           </li>
<li>                                                          </li>
<li>https://datatracker.ietf.org/doc/html/rfc1951             </li>
<li>isinya rfc1951 kalau di js minta dipotong 4byte baru bisa di deflation </li>
<li>  0   1   2   3   4... </li>
<li>  +---+---+---+---+================================+ </li>
<li>  |  LEN  | NLEN  |... LEN bytes of literal data...| </li>
<li>  +---+---+---+---+================================+ </li>
<li>
</ul>
